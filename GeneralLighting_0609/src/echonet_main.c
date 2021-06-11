
#include <kernel.h>
#include <t_syslog.h>
#include <t_stdlib.h>
#include <sil.h>
#include <string.h>
#include "syssvc/serial.h"
#include "syssvc/syslog.h"
#include "kernel_cfg.h"
#include "echonet_main.h"
#include "echonet_cfg.h"
#include "target_kernel_impl.h"
#include "gpio_api.h"
#include "rtc_api.h"
#include "tECNLGeneralLighting_tecsgen.h"

#define MAKER_CODE	0x00, 0x00, 0xB3

/* ノードプロファイルオブジェクト */
struct node_profile_object_t local_node_data = {
	0x30,	/* 動作状態 */
	{ 0x01, 0x0A, 0x01, 0x00 },	/* Ｖｅｒｓｉｏｎ情報 */
	{
		0xFE,	/* 下位通信層IDフィールド */
		{ MAKER_CODE },	/* メーカーコード */
		{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },	/* ユニークID部(メーカー独自) */
	},
	{ MAKER_CODE },	/* メーカーコード */
};

/* 一般照明クラス */
struct general_lighting_t general_lighting_class_data = {
	0x30,	/* 動作状態 */
	0x41,	/* 点灯モード設定 */
	0x00,	/* 設置場所 */
	{ 0x00, 0x00, 'C', 0x00 },	/* 規格Ｖｅｒｓｉｏｎ情報 */
	0x41,	/* 異常発生状態 */
	{ MAKER_CODE },	/* メーカーコード */
};


static void main_initialize();
static int main_get_timer();
static void main_progress(int interval);
static void main_recv_esv(T_EDATA *esv);
static void main_break_wait(uint8_t *brkdat, int32_t len);
static void main_timeout();

void echonet_main_task(intptr_t exinf)
{
	ER ret, ret2;
	SYSTIM prev, now;
	int timer;
	T_EDATA *esv;
	uint8_t brkdat[64];
	int32_t len;

	/* アプリケーションの初期化 */
	main_initialize();

	ret2 = get_tim(&now);
	if (ret2 != E_OK) {
		syslog(LOG_ERROR, "get_tim");
		return;
	}

	for (;;) {
		prev = now;

		/* タイマー取得 */
		timer = main_get_timer();

		/* 応答電文待ち */
		ret = ecn_trcv_esv(&esv, timer);
		if ((ret != E_OK) && (ret != E_BRK) && (ret != E_TMOUT)) {
			syslog(LOG_ERROR, "ecn_trcv_esv");
			break;
		}

		ret2 = get_tim(&now);
		if (ret2 != E_OK) {
			syslog(LOG_ERROR, "get_tim");
			break;
		}

		/* 時間経過 */
		main_progress(now - prev);
		/* Echonet電文受信の場合 */
		if (ret == E_OK) {
			/* Echonet電文受信処理 */
			main_recv_esv(esv);
			/* 領域解放 */
			ret = ecn_rel_esv(esv);
			if (ret != E_OK) {
				syslog(LOG_ERROR, "ecn_rel_esv");
				break;
			}
		}
		/* 応答電文待ちの割り込みの場合 */
		else if (ret == E_BRK) {
			/* 応答電文待ちの割り込みデータ取得 */
			ret = ecn_get_brk_dat(esv, brkdat, sizeof(brkdat), &len);
			if (ret != E_OK) {
				syslog(LOG_ERROR, "ecn_get_brk_dat");
				break;
			}

			/* 応答電文待ちの割り込み処理 */
			main_break_wait(brkdat, len);

			/* 領域解放 */
			ret = ecn_rel_esv(esv);
			if (ret != E_OK) {
				syslog(LOG_ERROR, "ecn_rel_esv");
				break;
			}
		}

		/* タイムアウト処理 */
		main_timeout();
	}
}

enum main_state_t{
	main_state_idle,
};
int main_timer = TMO_FEVR;
enum main_state_t main_state = main_state_idle;

static void main_initialize()
{
	/* メインタスクを起動 */
	ER ret = act_tsk(MAIN_TASK);
	if (ret != E_OK) {
		syslog(LOG_ERROR, "act_tsk");
	}
}

static int main_get_timer()
{
	return main_timer;
}

static void main_progress(int interval)
{
	if(main_timer == TMO_FEVR)
		return;

	main_timer -= interval;
	if(main_timer < 0){
		main_timer = 0;
	}
}


static void main_recv_esv(T_EDATA *esv)
{
	ER ret;
	ID eobjid;
	uint8_t epc;
	uint8_t pdc;
	uint8_t p_edt[256];
	T_ENUM_EPC enm;

	eobjid = ecn_get_eobj(esv);
	
	if (eobjid == EOBJ_NULL) {
		syslog(LOG_ERROR, "ecn_get_eobj");
	}

	ret = ecn_itr_ini(&enm, esv);
	if (ret != E_OK) {
		syslog(LOG_ERROR, "ecn_itr_ini");
		return;
	}

	for (;;) {
		while ((ret = ecn_itr_nxt(&enm, &epc, &pdc, p_edt)) == E_OK) {
			switch (epc) {
			case 0x80:
                break;
			}
		}
		if (ret != E_BOVR) {
			syslog(LOG_ERROR, "ecn_itr_nxt");
			break;
		}
		if (enm.is_eof)
			break;
	}
}

static void main_break_wait(uint8_t *brkdat, int32_t len)
{
	switch(main_state){
	case main_state_idle:
		break;
	}
}

static void main_timeout()
{
	if(main_timer != 0)
		return;

	switch(main_state){
	case main_state_idle:
		break;
	}
}


int lighting_mode_setting_prop_set (const EPRPINIB *item, const void *src, int size, bool_t *anno)
{

    if(size != 1)
      return 0;
    *anno = *((uint8_t*)item->exinf) != *((uint8_t*)src);
    switch (*(uint8_t*)src) {
      case 0x41: tECNLGeneralLighting_cGeneralLighting_setLightingModeSetting_Automatic( );
        break;
      case 0x42: tECNLGeneralLighting_cGeneralLighting_setLightingModeSetting_NormalLighting( );
        break;
      case 0x43: tECNLGeneralLighting_cGeneralLighting_setLightingModeSetting_NightLighting( );
        break;
      case 0x45: tECNLGeneralLighting_cGeneralLighting_setLightingModeSetting_ColorLighting( );
        break;
	default:
        return 0;
	}
	return 1;
}

int onoff_prop_set(const EPRPINIB *item, const void *src, int size, bool_t *anno)
{
	/* サイズが１以外は受け付けない */
	if(size != 1)
		return 0;

	*anno = *((uint8_t*)item->exinf) != *((uint8_t*)src);

	switch(*(uint8_t *)src){
	/* ONの場合 */
	case 0x30:
		*((uint8_t *)item->exinf) = *((uint8_t *)src);
		/* TODO: ONの場合の処理*/
		break;
	/* OFFの場合 */
	case 0x31:
		*((uint8_t *)item->exinf) = *((uint8_t *)src);
		/* TODO: OFFの場合の処理*/
		break;
	/* 0x30か0x31以外は受け付けない */
	default:
		return 0;
	}

	return 1;
}

int alarm_prop_set(const EPRPINIB *item, const void *src, int size, bool_t *anno)
{
	ER ret;
	uint8_t data[1];

	/* サイズが１以外は受け付けない */
	if(size != 1)
		return 0;

	*anno = *((uint8_t *)item->exinf) != *((uint8_t *)src);

	switch(*(uint8_t *)src){
	/* 異常発生ありの場合 */
	case 0x41:
	/* 異常発生なしの場合 */
	case 0x42:
		*((uint8_t *)item->exinf) = *((uint8_t *)src);
		break;
	/* 0x41か0x42以外は受け付けない */
	default:
		return 0;
	}

	return 1;
}