/* echonet_cfg.c */
#include <kernel.h>
#include <sil.h>
#include "echonet.h"

/*
 *  Include Directives (#include)
 */

#include "target_timer.h"
#include "main.h"
#include <tinet_config.h>
#include <net/net_endian.h>
#include <netinet/in.h>
#include <netinet/in_itron.h>
#include <tinet_nic_defs.h>
#include <netinet/in_var.h>
#include <net/ethernet.h>
#include <net/if6_var.h>
#include <echonet.h>
#include "tTask_tecsgen.h"
#include "tInitializeRoutine_tecsgen.h"
#include "tTerminateRoutine_tecsgen.h"
#include "target_sil.h"
#include <itron.h>
#include <tinet_defs.h>
#include <tinet_config.h>
#include <net/if.h>
#include <net/if_ppp.h>
#include <net/if_loop.h>
#include <net/ethernet.h>
#include <net/if_arp.h>
#include <net/net.h>
#include <net/net_endian.h>
#include <net/net_buf.h>
#include <net/net_timer.h>
#include <net/ppp_var.h>
#include <net/ether_var.h>
#include <netinet/in.h>
#include <netinet/in_var.h>
#include <netinet/ip.h>
#include <netinet/ip_var.h>
#include <netinet/tcp.h>
#include <netinet/tcp_var.h>
#include <netinet/udp_var.h>
#include "device.h"
#include "tinet_target_config.h"
#include "main.h"
#include "netapp/dhcp4_cli.h"
#include "netapp/resolver.h"
#include "ntp_cli.h"
#include "net_misc.h"
#include "ffarch.h"
#include "usb_hbth.h"
#include "ntshell_main.h"
#include "main.h"
#include "echonet.h"
#include "echonet_main.h"
#include "echonet_task.h"
#include "echonet_lcl_task.h"
#include "echonet_lcl_task.h"
#include "echonet_cfg.h"
#include "kernel_cfg.h"


/*
 *  ECHONET Lite Property Functions
 */

/*
 * インスタンス数
 */
const uint8_t _echonet_LOCAL_NODE_EOBJ_inst_count[] = {
	0x0, 0x0, 0x1
};

/*
 * クラス数
 */
const uint8_t _echonet_LOCAL_NODE_EOBJ_class_count[] = {
	0x0, 0x2
};

/*
 * インスタンスリスト
 */
const uint8_t _echonet_LOCAL_NODE_EOBJ_inst_list[] = {
	0x1, 0x2, 0x90, 0x1
};

/*
 * クラスリスト
 */
const uint8_t _echonet_LOCAL_NODE_EOBJ_class_list[] = {
	0x1, 0x2, 0x90
};

/*
 * アナウンスプロパティマップ
 */
const uint8_t _echonet_LOCAL_NODE_EOBJ_anno_prpmap[] = {
	0x1, 0xd5
};

/*
 * SETプロパティマップ
 */
const uint8_t _echonet_LOCAL_NODE_EOBJ_set_prpmap[] = {
	0x1, 0x80
};

/*
 * GETプロパティマップ
 */
const uint8_t _echonet_LOCAL_NODE_EOBJ_get_prpmap[] = {
	0xb, 0x80, 0x82, 0x83, 0x8a, 0x9d, 0x9e, 0x9f, 0xd3, 0xd4, 0xd6, 0xd7
};

/*
 * プロパティ定義
 */
const EPRPINIB _echonet_LOCAL_NODE_EOBJ_eprpinib_table[TNUM_LOCAL_NODE_EOBJ_EPRPNO] = {
	{ (0x80), (EPC_RULE_SET | EPC_RULE_GET), (1), ((intptr_t)&local_node_data.operation_status), ((EPRP_SETTER *)onoff_prop_set), ((EPRP_GETTER *)ecn_data_prop_get) },
	{ (0x8A), (EPC_RULE_GET), (3), ((intptr_t)&local_node_data.manufacturer_code), ((EPRP_SETTER *)ecn_data_prop_set), ((EPRP_GETTER *)ecn_data_prop_get) },
	{ (0x82), (EPC_RULE_GET), (4), ((intptr_t)&local_node_data.version_information), ((EPRP_SETTER *)ecn_data_prop_set), ((EPRP_GETTER *)ecn_data_prop_get) },
	{ (0x83), (EPC_RULE_GET), (17), ((intptr_t)&local_node_data.identification_number), ((EPRP_SETTER *)ecn_data_prop_set), ((EPRP_GETTER *)ecn_data_prop_get) },
	{ (0x9D), (EPC_RULE_GET), 0x2, (intptr_t)_echonet_LOCAL_NODE_EOBJ_anno_prpmap, ((EPRP_SETTER *)NULL), ((EPRP_GETTER *)ecn_data_prop_get) },
	{ (0x9E), (EPC_RULE_GET), 0x2, (intptr_t)_echonet_LOCAL_NODE_EOBJ_set_prpmap, ((EPRP_SETTER *)NULL), ((EPRP_GETTER *)ecn_data_prop_get) },
	{ (0x9F), (EPC_RULE_GET), 0xc, (intptr_t)_echonet_LOCAL_NODE_EOBJ_get_prpmap, ((EPRP_SETTER *)NULL), ((EPRP_GETTER *)ecn_data_prop_get) },
	{ (0xD3), (EPC_RULE_GET), (3), (intptr_t)_echonet_LOCAL_NODE_EOBJ_inst_count, ((EPRP_SETTER *)NULL), ((EPRP_GETTER *)ecn_data_prop_get) },
	{ (0xD4), (EPC_RULE_GET), (2), (intptr_t)_echonet_LOCAL_NODE_EOBJ_class_count, ((EPRP_SETTER *)NULL), ((EPRP_GETTER *)ecn_data_prop_get) },
	{ (0xD5), (EPC_RULE_ANNO), sizeof(_echonet_LOCAL_NODE_EOBJ_inst_list), (intptr_t)_echonet_LOCAL_NODE_EOBJ_inst_list, ((EPRP_SETTER *)NULL), ((EPRP_GETTER *)ecn_data_prop_get) },
	{ (0xD6), (EPC_RULE_GET), sizeof(_echonet_LOCAL_NODE_EOBJ_inst_list), (intptr_t)_echonet_LOCAL_NODE_EOBJ_inst_list, ((EPRP_SETTER *)NULL), ((EPRP_GETTER *)ecn_data_prop_get) },
	{ (0xD7), (EPC_RULE_GET), sizeof(_echonet_LOCAL_NODE_EOBJ_class_list), (intptr_t)_echonet_LOCAL_NODE_EOBJ_class_list, ((EPRP_SETTER *)NULL), ((EPRP_GETTER *)ecn_data_prop_get) }
};

/*
 * アナウンスプロパティマップ
 */
const uint8_t _echonet_GENERAL_LIGHTING_CLASS_EOBJ_anno_prpmap[] = {
	0x3, 0x80, 0x81, 0x88
};

/*
 * SETプロパティマップ
 */
const uint8_t _echonet_GENERAL_LIGHTING_CLASS_EOBJ_set_prpmap[] = {
	0x3, 0x80, 0x81, 0xb6
};

/*
 * GETプロパティマップ
 */
const uint8_t _echonet_GENERAL_LIGHTING_CLASS_EOBJ_get_prpmap[] = {
	0x9, 0x80, 0x81, 0x82, 0x88, 0x8a, 0x9d, 0x9e, 0x9f, 0xb6
};

/*
 * プロパティ定義
 */
const EPRPINIB _echonet_GENERAL_LIGHTING_CLASS_EOBJ_eprpinib_table[TNUM_GENERAL_LIGHTING_CLASS_EOBJ_EPRPNO] = {
	{ (0x80), (EPC_RULE_SET | EPC_RULE_GET | EPC_ANNOUNCE), (1), ((intptr_t)&general_lighting_class_data.operation_status), ((EPRP_SETTER *)onoff_prop_set), ((EPRP_GETTER *)ecn_data_prop_get) },
	{ (0xB6), (EPC_RULE_SET | EPC_RULE_GET), (1), ((intptr_t)&general_lighting_class_data.lighting_mode_setting), ((EPRP_SETTER *)lighting_mode_setting_prop_set), ((EPRP_GETTER *)ecn_data_prop_get) },
	{ (0x81), (EPC_RULE_SET | EPC_RULE_GET | EPC_ANNOUNCE), (1), ((intptr_t)&general_lighting_class_data.installation_location), ((EPRP_SETTER *)ecn_data_prop_set), ((EPRP_GETTER *)ecn_data_prop_get) },
	{ (0x82), (EPC_RULE_GET), (4), ((intptr_t)&general_lighting_class_data.standard_version_information), ((EPRP_SETTER *)ecn_data_prop_set), ((EPRP_GETTER *)ecn_data_prop_get) },
	{ (0x88), (EPC_RULE_GET | EPC_ANNOUNCE), (1), ((intptr_t)&general_lighting_class_data.fault_status), ((EPRP_SETTER *)alarm_prop_set), ((EPRP_GETTER *)ecn_data_prop_get) },
	{ (0x8A), (EPC_RULE_GET), (3), ((intptr_t)&general_lighting_class_data.manufacturer_code), ((EPRP_SETTER *)ecn_data_prop_set), ((EPRP_GETTER *)ecn_data_prop_get) },
	{ (0x9D), (EPC_RULE_GET), 0x4, (intptr_t)_echonet_GENERAL_LIGHTING_CLASS_EOBJ_anno_prpmap, ((EPRP_SETTER *)NULL), ((EPRP_GETTER *)ecn_data_prop_get) },
	{ (0x9E), (EPC_RULE_GET), 0x4, (intptr_t)_echonet_GENERAL_LIGHTING_CLASS_EOBJ_set_prpmap, ((EPRP_SETTER *)NULL), ((EPRP_GETTER *)ecn_data_prop_get) },
	{ (0x9F), (EPC_RULE_GET), 0xa, (intptr_t)_echonet_GENERAL_LIGHTING_CLASS_EOBJ_get_prpmap, ((EPRP_SETTER *)NULL), ((EPRP_GETTER *)ecn_data_prop_get) }
};


/*
 *  ECHONET Lite Object Functions
 */

const ID _echonet_tmax_eobjid = (TMIN_EOBJID + TNUM_EOBJID - 1);

const EOBJINIB _echonet_eobjinib_table[TNUM_EOBJID] = {
	{ (EOBJ_LOCAL_NODE), (EOBJ_NULL), (0), (EOJ_X1_PROFILE), (EOJ_X2_NODE_PROFILE), (EOJ_X3_NODE_PROFILE), _echonet_LOCAL_NODE_EOBJ_eprpinib_table, TNUM_LOCAL_NODE_EOBJ_EPRPNO },
	{ (EOBJ_DEVICE), (LOCAL_NODE_EOBJ), (0), (EOJ_X1_AMENITY), (EOJ_X2_GENERAL_LIGHTING_CLASS), (EOJ_X3_GENERAL_LIGHTING_CLASS), _echonet_GENERAL_LIGHTING_CLASS_EOBJ_eprpinib_table, TNUM_GENERAL_LIGHTING_CLASS_EOBJ_EPRPNO }
};


const int _echonet_tnum_enodid = TNUM_ENODID;

/*
 *  ECHONET Lite Node Functions
 */

/*
 * ノードに所属する機器オブジェクトの一覧
 */
const EOBJINIB *_echonet_LOCAL_NODE_EOBJ_eobjinib_table[TNUM_LOCAL_NODE_EOBJ_EOBJNO] = {
	{ &_echonet_eobjinib_table[GENERAL_LIGHTING_CLASS_EOBJ - 1] }
};

/*
 * ECHONET Liteノード管理ブロック
 */
EOBJCB _echonet_eobjcb_table[TNUM_ENODID] = {
	{ &_echonet_eobjinib_table[LOCAL_NODE_EOBJ - 1], _echonet_LOCAL_NODE_EOBJ_eobjinib_table, TNUM_LOCAL_NODE_EOBJ_EOBJNO }
};

const int _echonet_tnum_enodadr = TNUM_ENODADR;

/*
 *  ECHONET Lite Node Functions
 */

ENODADRB _echonet_enodadrb_table[TNUM_ENODADR] = {
	/* ENOD_MULTICAST_ID	*/ { true, ECHONET_MULTICAST_ADDR },
	/* ENOD_LOCAL_ID		*/ { true, },
	/* ENOD_API_ID			*/ { true, }
};

const ID _echonet_ecn_svc_taskid = ECHONET_SVC_TASK;
const ID _echonet_ecn_udp_taskid = ECHONET_UDP_TASK;
const ID _echonet_ecn_api_dataqueueid = ECHONET_API_DATAQUEUE;
const ID _echonet_ecn_svc_dataqueueid = ECHONET_SVC_DATAQUEUE;
const ID _echonet_ecn_udp_dataqueueid = ECHONET_UDP_DATAQUEUE;
#ifndef ECHONET_USE_MALLOC
const ID _echonet_ecn_mempoolid = ECHONET_MEMPOOL;
#endif


#include "tinet_cfg.h"

const ID _echonet_ecn_udp_cepid = ECHONET_UDP_CEPID;

