#include "echonet.h"
#define MAIN_PRIORITY 5
#define ECHONET_MAIN_STACK_SIZE	1024
#define EOJ_X3_NODE_PROFILE 1
#define EOJ_X3_ELECTRIC_WATER_HEATER_CLASS 1
/*Ｖｅｒｓｉｏｎ情報の型*/
struct version_information_t {
    /* メジャーバージョン(小数点以上) */
    uint8_t major_version_number;
    /* マイナーバージョン(小数点以下) */
    uint8_t minor_version_number;
    /* 電文タイプ */
    uint8_t message_type[2];
};

/*メーカーコードの型*/
struct manufacturer_code_t {
	/* メーカーコード */
	uint8_t manufacturer_code[3];
};

/*識別番号の型*/
struct node_identification_number_t {
	/* 下位通信層IDフィールド */
	uint8_t lower_communication_id_field;
	/* メーカーコード */
	struct manufacturer_code_t manufacturer_code;
	/* ユニークID部(メーカー独自) */
	uint8_t unique_id_section[13];
};

/*規格Ｖｅｒｓｉｏｎ情報の型*/
struct standard_version_information_t {
	/* 固定1(for future reserved) */
	uint8_t reserved1;
	/* 固定2(for future reserved) */
	uint8_t reserved2;
	/* リリース順をASCIIで示す */
	uint8_t order_of_release;
	/* 固定4(for future reserved) */
	uint8_t reserved4;
};

/*ノードプロファイルオブジェクト*/
struct node_profile_object_t {
	/* 動作状態 */
	uint8_t operation_status;
	/* Ｖｅｒｓｉｏｎ情報 */
	struct version_information_t version_information;
	/* 識別番号 */
	struct node_identification_number_t identification_number;
	/* メーカーコード */
	struct manufacturer_code_t manufacturer_code;
};
/*電気温水器*/
struct electric_water_heater_t {
    /* 動作状態 */
    uint8_t operation_status;
    /* 設置場所 */
    uint8_t installation_location;
    /* 規格Ｖｅｒｓｉｏｎ情報 */
    struct standard_version_information_t standard_version_information;
    /* 異常発生状態 */
    uint8_t fault_status;
    /* メーカーコード */
    struct manufacturer_code_t manufacturer_code;
   /*エネルギーシフト参加状態*/
    uint8_t participation_in_energy_shift;
};
extern struct node_profile_object_t local_node_data;
extern struct electric_water_heater_t electric_water_heater_class_data;
EPRP_SETTER onoff_prop_set;
EPRP_SETTER alarm_prop_set;
EPRP_SETTER participation_in_energy_shift_prop_set;
void echonet_main_task(intptr_t exinf);
   /*昼間沸き上げシフト時刻１*/
    uint8_t daytime_heating_shift_time_1;
};
extern struct node_profile_object_t local_node_data;
extern struct electric_water_heater_t electric_water_heater_class_data;
EPRP_SETTER onoff_prop_set;
EPRP_SETTER alarm_prop_set;
EPRP_SETTER daytime_heating_shift_time_1_prop_set;
void echonet_main_task(intptr_t exinf);
   /*昼間沸き上げシフト時刻２*/
    uint8_t daytime_heating_shift_time_2;
};
extern struct node_profile_object_t local_node_data;
extern struct electric_water_heater_t electric_water_heater_class_data;
EPRP_SETTER onoff_prop_set;
EPRP_SETTER alarm_prop_set;
EPRP_SETTER daytime_heating_shift_time_2_prop_set;
void echonet_main_task(intptr_t exinf);
   /*風呂自動モード設定*/
    uint8_t automatic_bath_water_heating_mode_setting;
};
extern struct node_profile_object_t local_node_data;
extern struct electric_water_heater_t electric_water_heater_class_data;
EPRP_SETTER onoff_prop_set;
EPRP_SETTER alarm_prop_set;
EPRP_SETTER automatic_bath_water_heating_mode_setting_prop_set;
void echonet_main_task(intptr_t exinf);
