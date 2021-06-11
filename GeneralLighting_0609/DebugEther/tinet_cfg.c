/* tinet_cfg.c */

#include <kernel.h>
#include <sil.h>
#include "kernel_cfg.h"
#include "tinet_cfg.h"
#include <tinet_defs.h>
#include <tinet_config.h>
#include <net/if.h>
#include <net/if_ppp.h>
#include <net/if_loop.h>
#include <net/ethernet.h>
#include <net/net.h>
#include <net/net_endian.h>
#include <net/net_buf.h>
#include <netinet/in.h>
#include <netinet/in_var.h>
#include <netinet/in_itron.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/tcp_var.h>
#include <netinet/udp_var.h>



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

const ID tmax_tcp_repid = (TMIN_TCP_REPID + TNUM_TCP6_REPID + TNUM_TCP4_REPID - 1);

#if defined(SUPPORT_INET6) && defined(SUPPORT_INET4)
const ID tmax_tcp6_repid = (TMIN_TCP6_REPID + TNUM_TCP6_REPID - 1);
const ID tmax_tcp4_repid = (TMIN_TCP4_REPID + TNUM_TCP4_REPID - 1);
#endif

const ID tmax_tcp_cepid = (TMIN_TCP_CEPID + TNUM_TCP6_CEPID + TNUM_TCP4_CEPID - 1);

#if defined(SUPPORT_INET6) && defined(SUPPORT_INET4)
const ID tmax_tcp6_cepid = (TMIN_TCP_CEPID + TNUM_TCP6_CEPID - 1);
const ID tmax_tcp4_cepid = (TMIN_TCP_CEPID + TNUM_TCP4_CEPID - 1);
#endif

const ID tmax_udp_cepid = (TMIN_UDP_CEPID + TNUM_UDP6_CEPID + TNUM_UDP4_CEPID - 1);

#if defined(SUPPORT_INET6) && defined(SUPPORT_INET4)
const ID tmax_udp6_cepid = (TMIN_UDP6_CEPID + TNUM_UDP6_CEPID - 1);
const ID tmax_udp4_cepid = (TMIN_UDP4_CEPID + TNUM_UDP4_CEPID - 1);
#endif

T_TCP4_REP tcp4_rep[TNUM_TCP4_REPID] = {
	{
		0,
		{ IPV4_ADDRANY, TCP_PORTANY },
#if defined(TCP_CFG_EXTENTIONS)
		TCP_REP_FLG_DYNAMIC,
		SEM_TCP_REP_LOCK0,
#endif
		},
	{
		0,
		{ IPV4_ADDRANY, TCP_PORTANY },
#if defined(TCP_CFG_EXTENTIONS)
		TCP_REP_FLG_DYNAMIC,
		SEM_TCP_REP_LOCK1,
#endif
		},
	{
		0,
		{ IPV4_ADDRANY, TCP_PORTANY },
#if defined(TCP_CFG_EXTENTIONS)
		TCP_REP_FLG_DYNAMIC,
		SEM_TCP_REP_LOCK2,
#endif
		},
	{
		0,
		{ IPV4_ADDRANY, TCP_PORTANY },
#if defined(TCP_CFG_EXTENTIONS)
		TCP_REP_FLG_DYNAMIC,
		SEM_TCP_REP_LOCK3,
#endif
		},
	};

T_TCP_CEP tcp_cep[TNUM_TCP6_CEPID + TNUM_TCP4_CEPID] = {
	{
		0,
		(void*)NULL,
		0,
		(void*)NULL,
		0,
		(t_tcp_callback)(FP)NULL,
		TCP_CEP_FLG_DYNAMIC|TCP_CEP_FLG_IPV4,
		SEM_TCP_CEP_LOCK1,
		FLG_TCP_CEP_EST1,
		FLG_TCP_CEP_SND1,
		FLG_TCP_CEP_RCV1,
		},
	{
		0,
		(void*)NULL,
		0,
		(void*)NULL,
		0,
		(t_tcp_callback)(FP)NULL,
		TCP_CEP_FLG_DYNAMIC|TCP_CEP_FLG_IPV4,
		SEM_TCP_CEP_LOCK2,
		FLG_TCP_CEP_EST2,
		FLG_TCP_CEP_SND2,
		FLG_TCP_CEP_RCV2,
		},
	{
		0,
		(void*)NULL,
		0,
		(void*)NULL,
		0,
		(t_tcp_callback)(FP)NULL,
		TCP_CEP_FLG_DYNAMIC|TCP_CEP_FLG_IPV4,
		SEM_TCP_CEP_LOCK3,
		FLG_TCP_CEP_EST3,
		FLG_TCP_CEP_SND3,
		FLG_TCP_CEP_RCV3,
		},
	{
		0,
		(void*)NULL,
		0,
		(void*)NULL,
		0,
		(t_tcp_callback)(FP)NULL,
		TCP_CEP_FLG_DYNAMIC|TCP_CEP_FLG_IPV4,
		SEM_TCP_CEP_LOCK4,
		FLG_TCP_CEP_EST4,
		FLG_TCP_CEP_SND4,
		FLG_TCP_CEP_RCV4,
		},
	{
		0,
		(void*)NULL,
		0,
		(void*)NULL,
		0,
		(t_tcp_callback)(FP)NULL,
		TCP_CEP_FLG_DYNAMIC|TCP_CEP_FLG_IPV4,
		SEM_TCP_CEP_LOCK5,
		FLG_TCP_CEP_EST5,
		FLG_TCP_CEP_SND5,
		FLG_TCP_CEP_RCV5,
		},
	{
		0,
		(void*)NULL,
		0,
		(void*)NULL,
		0,
		(t_tcp_callback)(FP)NULL,
		TCP_CEP_FLG_DYNAMIC|TCP_CEP_FLG_IPV4,
		SEM_TCP_CEP_LOCK6,
		FLG_TCP_CEP_EST6,
		FLG_TCP_CEP_SND6,
		FLG_TCP_CEP_RCV6,
		},
	{
		0,
		(void*)NULL,
		0,
		(void*)NULL,
		0,
		(t_tcp_callback)(FP)NULL,
		TCP_CEP_FLG_DYNAMIC|TCP_CEP_FLG_IPV4,
		SEM_TCP_CEP_LOCK7,
		FLG_TCP_CEP_EST7,
		FLG_TCP_CEP_SND7,
		FLG_TCP_CEP_RCV7,
		},
	{
		0,
		(void*)NULL,
		0,
		(void*)NULL,
		0,
		(t_tcp_callback)(FP)NULL,
		TCP_CEP_FLG_DYNAMIC|TCP_CEP_FLG_IPV4,
		SEM_TCP_CEP_LOCK8,
		FLG_TCP_CEP_EST8,
		FLG_TCP_CEP_SND8,
		FLG_TCP_CEP_RCV8,
		},
	};

T_UDP4_CEP udp4_cep[TNUM_UDP4_CEPID] = {
	{
		0,
		{ IPV4_ADDRANY, DHCP4_CLI_CFG_PORTNO },
		(t_udp_callback)(FP)callback_nblk_dhcp4_cli,
		UDP_CEP_FLG_VALID,
		SEM_UDP4_CEP_LOCK1,
		TA_NULL,
		TA_NULL,
		DTQ_UDP4_RCVQ1,
		},
	{
		0,
		{ IPV4_ADDRANY, UDP_PORTANY },
		(t_udp_callback)(FP)NULL,
		UDP_CEP_FLG_VALID,
		SEM_UDP4_CEP_LOCK2,
		TA_NULL,
		TA_NULL,
		DTQ_UDP4_RCVQ2,
		},
	{
		0,
		{ IPV4_ADDRANY, UDP_PORTANY },
		(t_udp_callback)(FP)callback_nblk_ntp_cli,
		UDP_CEP_FLG_VALID,
		SEM_UDP4_CEP_LOCK3,
		TA_NULL,
		TA_NULL,
		DTQ_UDP4_RCVQ3,
		},
	{
		TA_ACT,
		{ IPV4_ADDRANY, 3610 },
		(t_udp_callback)(FP)(FP)callback_nblk_udp,
		UDP_CEP_FLG_VALID,
		SEM_UDP4_CEP_LOCK4,
		TA_NULL,
		TA_NULL,
		DTQ_UDP4_RCVQ4,
		},
	{
		0,
		{ IPV4_ADDRANY, UDP_PORTANY },
		(t_udp_callback)(FP)NULL,
		UDP_CEP_FLG_DYNAMIC,
		SEM_UDP4_CEP_LOCK5,
		TA_NULL,
		TA_NULL,
		DTQ_UDP4_RCVQ5,
		},
	{
		0,
		{ IPV4_ADDRANY, UDP_PORTANY },
		(t_udp_callback)(FP)NULL,
		UDP_CEP_FLG_DYNAMIC,
		SEM_UDP4_CEP_LOCK6,
		TA_NULL,
		TA_NULL,
		DTQ_UDP4_RCVQ6,
		},
	{
		0,
		{ IPV4_ADDRANY, UDP_PORTANY },
		(t_udp_callback)(FP)NULL,
		UDP_CEP_FLG_DYNAMIC,
		SEM_UDP4_CEP_LOCK7,
		TA_NULL,
		TA_NULL,
		DTQ_UDP4_RCVQ7,
		},
	{
		0,
		{ IPV4_ADDRANY, UDP_PORTANY },
		(t_udp_callback)(FP)NULL,
		UDP_CEP_FLG_DYNAMIC,
		SEM_UDP4_CEP_LOCK8,
		TA_NULL,
		TA_NULL,
		DTQ_UDP4_RCVQ8,
		},
	};
