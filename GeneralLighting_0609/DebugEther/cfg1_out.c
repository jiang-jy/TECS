/* cfg1_out.c */
#define TOPPERS_CFG1_OUT
#include "kernel/kernel_int.h"
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

#ifdef INT64_MAX
  typedef int64_t signed_t;
  typedef uint64_t unsigned_t;
#else
  typedef int32_t signed_t;
  typedef uint32_t unsigned_t;
#endif

#include "target_cfg1_out.h"

#if defined(SIL_ENDIAN_BIG) && defined(SIL_ENDIAN_LITTLE)
#error Both SIL_ENDIAN_BIG and SIL_ENDIAN_LITTLE are defined.
#endif
#if !defined(SIL_ENDIAN_BIG) && !defined(SIL_ENDIAN_LITTLE)
#error Neither SIL_ENDIAN_BIG nor SIL_ENDIAN_LITTLE is defined.
#endif

const uint32_t TOPPERS_magic_number = 0x12345678;
const uint32_t TOPPERS_sizeof_signed_t = sizeof(signed_t);

const unsigned_t TOPPERS_cfg_CHAR_BIT = (unsigned_t)(CHAR_BIT);
const signed_t TOPPERS_cfg_SCHAR_MAX = (signed_t)(SCHAR_MAX);
const signed_t TOPPERS_cfg_SCHAR_MIN = (signed_t)(SCHAR_MIN);
const unsigned_t TOPPERS_cfg_UCHAR_MAX = (unsigned_t)(UCHAR_MAX);
const signed_t TOPPERS_cfg_CHAR_MAX = (signed_t)(CHAR_MAX);
const signed_t TOPPERS_cfg_CHAR_MIN = (signed_t)(CHAR_MIN);
const signed_t TOPPERS_cfg_SHRT_MAX = (signed_t)(SHRT_MAX);
const signed_t TOPPERS_cfg_SHRT_MIN = (signed_t)(SHRT_MIN);
const unsigned_t TOPPERS_cfg_USHRT_MAX = (unsigned_t)(USHRT_MAX);
const signed_t TOPPERS_cfg_INT_MAX = (signed_t)(INT_MAX);
const signed_t TOPPERS_cfg_INT_MIN = (signed_t)(INT_MIN);
const unsigned_t TOPPERS_cfg_UINT_MAX = (unsigned_t)(UINT_MAX);
const signed_t TOPPERS_cfg_LONG_MAX = (signed_t)(LONG_MAX);
const signed_t TOPPERS_cfg_LONG_MIN = (signed_t)(LONG_MIN);
const unsigned_t TOPPERS_cfg_ULONG_MAX = (unsigned_t)(ULONG_MAX);
const unsigned_t TOPPERS_cfg_TA_HLNG = (unsigned_t)(TA_HLNG);
const unsigned_t TOPPERS_cfg_TA_TFIFO = (unsigned_t)(TA_TFIFO);
const unsigned_t TOPPERS_cfg_TA_WSGL = (unsigned_t)(TA_WSGL);
const unsigned_t TOPPERS_cfg_NUM_IPV4ADDR_STR_BUFF = (unsigned_t)(NUM_IPV4ADDR_STR_BUFF);
const unsigned_t TOPPERS_cfg_NUM_IPV6ADDR_STR_BUFF = (unsigned_t)(NUM_IPV6ADDR_STR_BUFF);
const unsigned_t TOPPERS_cfg_NUM_MACADDR_STR_BUFF = (unsigned_t)(NUM_MACADDR_STR_BUFF);
const unsigned_t TOPPERS_cfg_TMO_IP4_FRAG_GET_NET_BUF = (unsigned_t)(TMO_IP4_FRAG_GET_NET_BUF);
const unsigned_t TOPPERS_cfg_TMO_IP6_FRAG_GET_NET_BUF = (unsigned_t)(TMO_IP6_FRAG_GET_NET_BUF);
const unsigned_t TOPPERS_cfg_TMO_PPP_GET_NET_BUF = (unsigned_t)(TMO_PPP_GET_NET_BUF);
const unsigned_t TOPPERS_cfg_TMO_ARP_GET_NET_BUF = (unsigned_t)(TMO_ARP_GET_NET_BUF);
const unsigned_t TOPPERS_cfg_TMO_TCP_GET_NET_BUF = (unsigned_t)(TMO_TCP_GET_NET_BUF);
const unsigned_t TOPPERS_cfg_TMO_TCP_OUTPUT = (unsigned_t)(TMO_TCP_OUTPUT);
const unsigned_t TOPPERS_cfg_TMO_UDP_OUTPUT = (unsigned_t)(TMO_UDP_OUTPUT);
const unsigned_t TOPPERS_cfg_TMO_ICMP_OUTPUT = (unsigned_t)(TMO_ICMP_OUTPUT);
const unsigned_t TOPPERS_cfg_TMO_IGMP_OUTPUT = (unsigned_t)(TMO_IGMP_OUTPUT);
const unsigned_t TOPPERS_cfg_TMO_ND6_NS_OUTPUT = (unsigned_t)(TMO_ND6_NS_OUTPUT);
const unsigned_t TOPPERS_cfg_TMO_ND6_NA_OUTPUT = (unsigned_t)(TMO_ND6_NA_OUTPUT);
const unsigned_t TOPPERS_cfg_TMO_ND6_RS_OUTPUT = (unsigned_t)(TMO_ND6_RS_OUTPUT);
const unsigned_t TOPPERS_cfg_TMO_ARP_OUTPUT = (unsigned_t)(TMO_ARP_OUTPUT);
const unsigned_t TOPPERS_cfg_TMO_ND6_RTR_SOL_DELAY = (unsigned_t)(TMO_ND6_RTR_SOL_DELAY);
const unsigned_t TOPPERS_cfg_TMO_ND6_RTR_SOL_INTERVAL = (unsigned_t)(TMO_ND6_RTR_SOL_INTERVAL);
const unsigned_t TOPPERS_cfg_TMO_IN_REDIRECT = (unsigned_t)(TMO_IN_REDIRECT);
const unsigned_t TOPPERS_cfg_TCP_OUT_TASK_STACK_SIZE = (unsigned_t)(TCP_OUT_TASK_STACK_SIZE);
const unsigned_t TOPPERS_cfg_UDP_OUT_TASK_STACK_SIZE = (unsigned_t)(UDP_OUT_TASK_STACK_SIZE);
const unsigned_t TOPPERS_cfg_PPP_INPUT_STACK_SIZE = (unsigned_t)(PPP_INPUT_STACK_SIZE);
const unsigned_t TOPPERS_cfg_PPP_OUTPUT_STACK_SIZE = (unsigned_t)(PPP_OUTPUT_STACK_SIZE);
const unsigned_t TOPPERS_cfg_ETHER_INPUT_STACK_SIZE = (unsigned_t)(ETHER_INPUT_STACK_SIZE);
const unsigned_t TOPPERS_cfg_ETHER_OUTPUT_STACK_SIZE = (unsigned_t)(ETHER_OUTPUT_STACK_SIZE);
const unsigned_t TOPPERS_cfg_LOOP_INPUT_STACK_SIZE = (unsigned_t)(LOOP_INPUT_STACK_SIZE);
const unsigned_t TOPPERS_cfg_LOOP_OUTPUT_STACK_SIZE = (unsigned_t)(LOOP_OUTPUT_STACK_SIZE);
const unsigned_t TOPPERS_cfg_NET_TIMER_STACK_SIZE = (unsigned_t)(NET_TIMER_STACK_SIZE);
const unsigned_t TOPPERS_cfg_TCP_OUT_TASK_PRIORITY = (unsigned_t)(TCP_OUT_TASK_PRIORITY);
const unsigned_t TOPPERS_cfg_UDP_OUT_TASK_PRIORITY = (unsigned_t)(UDP_OUT_TASK_PRIORITY);
const unsigned_t TOPPERS_cfg_PPP_INPUT_PRIORITY = (unsigned_t)(PPP_INPUT_PRIORITY);
const unsigned_t TOPPERS_cfg_PPP_OUTPUT_PRIORITY = (unsigned_t)(PPP_OUTPUT_PRIORITY);
const unsigned_t TOPPERS_cfg_ETHER_INPUT_PRIORITY = (unsigned_t)(ETHER_INPUT_PRIORITY);
const unsigned_t TOPPERS_cfg_ETHER_OUTPUT_PRIORITY = (unsigned_t)(ETHER_OUTPUT_PRIORITY);
const unsigned_t TOPPERS_cfg_LOOP_INPUT_PRIORITY = (unsigned_t)(LOOP_INPUT_PRIORITY);
const unsigned_t TOPPERS_cfg_LOOP_OUTPUT_PRIORITY = (unsigned_t)(LOOP_OUTPUT_PRIORITY);
const unsigned_t TOPPERS_cfg_NET_TIMER_PRIORITY = (unsigned_t)(NET_TIMER_PRIORITY);
const unsigned_t TOPPERS_cfg_NUM_DTQ_UDP_RCVQ = (unsigned_t)(NUM_DTQ_UDP_RCVQ);
const unsigned_t TOPPERS_cfg_NUM_DTQ_UDP_OUTPUT = (unsigned_t)(NUM_DTQ_UDP_OUTPUT);
const unsigned_t TOPPERS_cfg_NUM_DTQ_PPP_OUTPUT = (unsigned_t)(NUM_DTQ_PPP_OUTPUT);
const unsigned_t TOPPERS_cfg_NUM_DTQ_ETHER_OUTPUT = (unsigned_t)(NUM_DTQ_ETHER_OUTPUT);
const unsigned_t TOPPERS_cfg_NUM_DTQ_LOOP_INPUT = (unsigned_t)(NUM_DTQ_LOOP_INPUT);
const unsigned_t TOPPERS_cfg_NUM_DTQ_LOOP_OUTPUT = (unsigned_t)(NUM_DTQ_LOOP_OUTPUT);
const unsigned_t TOPPERS_cfg_TCP_REP_FLG_DYNAMIC = (unsigned_t)(TCP_REP_FLG_DYNAMIC);
const unsigned_t TOPPERS_cfg_TCP_REP_FLG_VALID = (unsigned_t)(TCP_REP_FLG_VALID);
const unsigned_t TOPPERS_cfg_TCP_CEP_FLG_IPV4 = (unsigned_t)(TCP_CEP_FLG_IPV4);
const unsigned_t TOPPERS_cfg_TCP_CEP_FLG_ACK_NOW = (unsigned_t)(TCP_CEP_FLG_ACK_NOW);
const unsigned_t TOPPERS_cfg_TCP_CEP_FLG_DEL_ACK = (unsigned_t)(TCP_CEP_FLG_DEL_ACK);
const unsigned_t TOPPERS_cfg_TCP_CEP_FLG_SENT_FIN = (unsigned_t)(TCP_CEP_FLG_SENT_FIN);
const unsigned_t TOPPERS_cfg_TCP_CEP_FLG_NEED_SYN = (unsigned_t)(TCP_CEP_FLG_NEED_SYN);
const unsigned_t TOPPERS_cfg_TCP_CEP_FLG_NEED_FIN = (unsigned_t)(TCP_CEP_FLG_NEED_FIN);
const unsigned_t TOPPERS_cfg_TCP_CEP_FLG_FORCE = (unsigned_t)(TCP_CEP_FLG_FORCE);
const unsigned_t TOPPERS_cfg_TCP_CEP_FLG_NO_PUSH = (unsigned_t)(TCP_CEP_FLG_NO_PUSH);
const unsigned_t TOPPERS_cfg_TCP_CEP_FLG_NO_DELAY = (unsigned_t)(TCP_CEP_FLG_NO_DELAY);
const unsigned_t TOPPERS_cfg_TCP_CEP_FLG_FORCE_CLEAR = (unsigned_t)(TCP_CEP_FLG_FORCE_CLEAR);
const unsigned_t TOPPERS_cfg_TCP_CEP_FLG_POST_OUTPUT = (unsigned_t)(TCP_CEP_FLG_POST_OUTPUT);
const unsigned_t TOPPERS_cfg_TCP_CEP_FLG_RESERVE_OUTPUT = (unsigned_t)(TCP_CEP_FLG_RESERVE_OUTPUT);
const unsigned_t TOPPERS_cfg_TCP_CEP_FLG_DYNAMIC = (unsigned_t)(TCP_CEP_FLG_DYNAMIC);
const unsigned_t TOPPERS_cfg_TCP_CEP_FLG_VALID = (unsigned_t)(TCP_CEP_FLG_VALID);
const unsigned_t TOPPERS_cfg_TCP_CEP_FLG_CLOSE_AFTER_OUTPUT = (unsigned_t)(TCP_CEP_FLG_CLOSE_AFTER_OUTPUT);
const unsigned_t TOPPERS_cfg_TCP_CEP_FLG_RESTORE_NEXT_OUTPUT = (unsigned_t)(TCP_CEP_FLG_RESTORE_NEXT_OUTPUT);
const unsigned_t TOPPERS_cfg_TCP_CEP_FLG_WBCS_NBUF_REQ = (unsigned_t)(TCP_CEP_FLG_WBCS_NBUF_REQ);
const unsigned_t TOPPERS_cfg_TCP_CEP_FLG_WBCS_MASK = (unsigned_t)(TCP_CEP_FLG_WBCS_MASK);
const unsigned_t TOPPERS_cfg_TCP_CEP_FLG_WBCS_FREE = (unsigned_t)(TCP_CEP_FLG_WBCS_FREE);
const unsigned_t TOPPERS_cfg_TCP_CEP_FLG_WBCS_WOPEN_PEND = (unsigned_t)(TCP_CEP_FLG_WBCS_WOPEN_PEND);
const unsigned_t TOPPERS_cfg_TCP_CEP_FLG_WBCS_NBUF_PEND = (unsigned_t)(TCP_CEP_FLG_WBCS_NBUF_PEND);
const unsigned_t TOPPERS_cfg_TCP_CEP_FLG_WBCS_NBUF_RSVD = (unsigned_t)(TCP_CEP_FLG_WBCS_NBUF_RSVD);
const unsigned_t TOPPERS_cfg_TCP_CEP_FLG_WBCS_NBUF_READY = (unsigned_t)(TCP_CEP_FLG_WBCS_NBUF_READY);
const unsigned_t TOPPERS_cfg_TCP_CEP_FLG_WBCS_SEND_READY = (unsigned_t)(TCP_CEP_FLG_WBCS_SEND_READY);
const unsigned_t TOPPERS_cfg_TCP_CEP_FLG_WBCS_SENT = (unsigned_t)(TCP_CEP_FLG_WBCS_SENT);
const unsigned_t TOPPERS_cfg_TCP_CEP_FLG_WBCS_ACKED = (unsigned_t)(TCP_CEP_FLG_WBCS_ACKED);
const unsigned_t TOPPERS_cfg_TCP_CEP_FLG_NOT_CLEAR = (unsigned_t)(TCP_CEP_FLG_NOT_CLEAR);
const unsigned_t TOPPERS_cfg_TCP_CEP_EVT_ESTABLISHED = (unsigned_t)(TCP_CEP_EVT_ESTABLISHED);
const unsigned_t TOPPERS_cfg_TCP_CEP_EVT_CLOSED = (unsigned_t)(TCP_CEP_EVT_CLOSED);
const unsigned_t TOPPERS_cfg_TCP_CEP_EVT_SWBUF_READY = (unsigned_t)(TCP_CEP_EVT_SWBUF_READY);
const unsigned_t TOPPERS_cfg_TCP_CEP_EVT_RWBUF_READY = (unsigned_t)(TCP_CEP_EVT_RWBUF_READY);
const unsigned_t TOPPERS_cfg_TCP_CEP_EVT_ALL = (unsigned_t)(TCP_CEP_EVT_ALL);
const unsigned_t TOPPERS_cfg_EOBJ_NULL = (unsigned_t)(EOBJ_NULL);
const unsigned_t TOPPERS_cfg_EOBJ_LOCAL_NODE = (unsigned_t)(EOBJ_LOCAL_NODE);
const unsigned_t TOPPERS_cfg_EOBJ_SYNC_REMOTE_NODE = (unsigned_t)(EOBJ_SYNC_REMOTE_NODE);
const unsigned_t TOPPERS_cfg_EOBJ_ASYNC_REMOTE_NODE = (unsigned_t)(EOBJ_ASYNC_REMOTE_NODE);
const unsigned_t TOPPERS_cfg_EOBJ_DEVICE = (unsigned_t)(EOBJ_DEVICE);
const unsigned_t TOPPERS_cfg_EPC_NONE = (unsigned_t)(EPC_NONE);
const unsigned_t TOPPERS_cfg_EPC_RULE_SET = (unsigned_t)(EPC_RULE_SET);
const unsigned_t TOPPERS_cfg_EPC_RULE_GET = (unsigned_t)(EPC_RULE_GET);
const unsigned_t TOPPERS_cfg_EPC_RULE_ANNO = (unsigned_t)(EPC_RULE_ANNO);
const unsigned_t TOPPERS_cfg_EPC_ANNOUNCE = (unsigned_t)(EPC_ANNOUNCE);
const unsigned_t TOPPERS_cfg_EPC_VARIABLE = (unsigned_t)(EPC_VARIABLE);
const unsigned_t TOPPERS_cfg_EOJ_X1_SENSOR = (unsigned_t)(EOJ_X1_SENSOR);
const unsigned_t TOPPERS_cfg_EOJ_X1_AIR_CONDITIONER = (unsigned_t)(EOJ_X1_AIR_CONDITIONER);
const unsigned_t TOPPERS_cfg_EOJ_X1_AMENITY = (unsigned_t)(EOJ_X1_AMENITY);
const unsigned_t TOPPERS_cfg_EOJ_X1_HOUSEWORK = (unsigned_t)(EOJ_X1_HOUSEWORK);
const unsigned_t TOPPERS_cfg_EOJ_X1_WELLNESS = (unsigned_t)(EOJ_X1_WELLNESS);
const unsigned_t TOPPERS_cfg_EOJ_X1_CONTROLLER = (unsigned_t)(EOJ_X1_CONTROLLER);
const unsigned_t TOPPERS_cfg_EOJ_X1_AUDIO_VISUAL = (unsigned_t)(EOJ_X1_AUDIO_VISUAL);
const unsigned_t TOPPERS_cfg_EOJ_X1_PROFILE = (unsigned_t)(EOJ_X1_PROFILE);
const unsigned_t TOPPERS_cfg_EOJ_X1_USER_DEFINED = (unsigned_t)(EOJ_X1_USER_DEFINED);
const unsigned_t TOPPERS_cfg_EOJ_X2_NODE_PROFILE = (unsigned_t)(EOJ_X2_NODE_PROFILE);
#if defined(USE_EXTERNAL_ID)
const signed_t TOPPERS_cfg_USE_EXTERNAL_ID = (signed_t)(true);
#endif
#if defined(SIL_ENDIAN_BIG)
const signed_t TOPPERS_cfg_SIL_ENDIAN_BIG = (signed_t)(true);
#endif
#if defined(SIL_ENDIAN_LITTLE)
const signed_t TOPPERS_cfg_SIL_ENDIAN_LITTLE = (signed_t)(true);
#endif
const unsigned_t TOPPERS_cfg_TA_NULL = (unsigned_t)(TA_NULL);
const unsigned_t TOPPERS_cfg_TA_ACT = (unsigned_t)(TA_ACT);
const unsigned_t TOPPERS_cfg_TA_NOACTQUE = (unsigned_t)(TA_NOACTQUE);
const unsigned_t TOPPERS_cfg_TA_TPRI = (unsigned_t)(TA_TPRI);
const unsigned_t TOPPERS_cfg_TA_WMUL = (unsigned_t)(TA_WMUL);
const unsigned_t TOPPERS_cfg_TA_CLR = (unsigned_t)(TA_CLR);
const unsigned_t TOPPERS_cfg_TA_CEILING = (unsigned_t)(TA_CEILING);
const unsigned_t TOPPERS_cfg_TA_STA = (unsigned_t)(TA_STA);
const unsigned_t TOPPERS_cfg_TA_NONKERNEL = (unsigned_t)(TA_NONKERNEL);
const unsigned_t TOPPERS_cfg_TA_ENAINT = (unsigned_t)(TA_ENAINT);
const unsigned_t TOPPERS_cfg_TA_EDGE = (unsigned_t)(TA_EDGE);
const unsigned_t TOPPERS_cfg_TNFY_HANDLER = (unsigned_t)(TNFY_HANDLER);
const unsigned_t TOPPERS_cfg_TNFY_SETVAR = (unsigned_t)(TNFY_SETVAR);
const unsigned_t TOPPERS_cfg_TNFY_INCVAR = (unsigned_t)(TNFY_INCVAR);
const unsigned_t TOPPERS_cfg_TNFY_ACTTSK = (unsigned_t)(TNFY_ACTTSK);
const unsigned_t TOPPERS_cfg_TNFY_WUPTSK = (unsigned_t)(TNFY_WUPTSK);
const unsigned_t TOPPERS_cfg_TNFY_SIGSEM = (unsigned_t)(TNFY_SIGSEM);
const unsigned_t TOPPERS_cfg_TNFY_SETFLG = (unsigned_t)(TNFY_SETFLG);
const unsigned_t TOPPERS_cfg_TNFY_SNDDTQ = (unsigned_t)(TNFY_SNDDTQ);
const unsigned_t TOPPERS_cfg_TENFY_SETVAR = (unsigned_t)(TENFY_SETVAR);
const unsigned_t TOPPERS_cfg_TENFY_INCVAR = (unsigned_t)(TENFY_INCVAR);
const unsigned_t TOPPERS_cfg_TENFY_ACTTSK = (unsigned_t)(TENFY_ACTTSK);
const unsigned_t TOPPERS_cfg_TENFY_WUPTSK = (unsigned_t)(TENFY_WUPTSK);
const unsigned_t TOPPERS_cfg_TENFY_SIGSEM = (unsigned_t)(TENFY_SIGSEM);
const unsigned_t TOPPERS_cfg_TENFY_SETFLG = (unsigned_t)(TENFY_SETFLG);
const unsigned_t TOPPERS_cfg_TENFY_SNDDTQ = (unsigned_t)(TENFY_SNDDTQ);
const signed_t TOPPERS_cfg_TMIN_TPRI = (signed_t)(TMIN_TPRI);
const signed_t TOPPERS_cfg_TMAX_TPRI = (signed_t)(TMAX_TPRI);
const signed_t TOPPERS_cfg_TMIN_DPRI = (signed_t)(TMIN_DPRI);
const signed_t TOPPERS_cfg_TMAX_DPRI = (signed_t)(TMAX_DPRI);
const signed_t TOPPERS_cfg_TMIN_ISRPRI = (signed_t)(TMIN_ISRPRI);
const signed_t TOPPERS_cfg_TMAX_ISRPRI = (signed_t)(TMAX_ISRPRI);
const unsigned_t TOPPERS_cfg_TBIT_FLGPTN = (unsigned_t)(TBIT_FLGPTN);
const unsigned_t TOPPERS_cfg_TMAX_MAXSEM = (unsigned_t)(TMAX_MAXSEM);
const unsigned_t TOPPERS_cfg_TMAX_RELTIM = (unsigned_t)(TMAX_RELTIM);
const signed_t TOPPERS_cfg_TMIN_INTPRI = (signed_t)(TMIN_INTPRI);
const signed_t TOPPERS_cfg_TMAX_INTPRI = (signed_t)(TMAX_INTPRI);
const signed_t TOPPERS_cfg_TMIN_TSKID = (signed_t)(TMIN_TSKID);
const signed_t TOPPERS_cfg_TMIN_SEMID = (signed_t)(TMIN_SEMID);
const signed_t TOPPERS_cfg_TMIN_FLGID = (signed_t)(TMIN_FLGID);
const signed_t TOPPERS_cfg_TMIN_DTQID = (signed_t)(TMIN_DTQID);
const signed_t TOPPERS_cfg_TMIN_PDQID = (signed_t)(TMIN_PDQID);
const signed_t TOPPERS_cfg_TMIN_MTXID = (signed_t)(TMIN_MTXID);
const signed_t TOPPERS_cfg_TMIN_MPFID = (signed_t)(TMIN_MPFID);
const signed_t TOPPERS_cfg_TMIN_CYCID = (signed_t)(TMIN_CYCID);
const signed_t TOPPERS_cfg_TMIN_ALMID = (signed_t)(TMIN_ALMID);
#if defined(USE_TSKINICTXB)
const signed_t TOPPERS_cfg_USE_TSKINICTXB = (signed_t)(true);
#endif
#if defined(OMIT_INITIALIZE_INTERRUPT)
const signed_t TOPPERS_cfg_OMIT_INITIALIZE_INTERRUPT = (signed_t)(true);
#endif
#if defined(USE_INHINIB_TABLE)
const signed_t TOPPERS_cfg_USE_INHINIB_TABLE = (signed_t)(true);
#endif
#if defined(USE_INTINIB_TABLE)
const signed_t TOPPERS_cfg_USE_INTINIB_TABLE = (signed_t)(true);
#endif
#if defined(OMIT_INITIALIZE_EXCEPTION)
const signed_t TOPPERS_cfg_OMIT_INITIALIZE_EXCEPTION = (signed_t)(true);
#endif
#if defined(DEFAULT_ISTK)
const unsigned_t TOPPERS_cfg_DEFAULT_ISTK = (unsigned_t)(DEFAULT_ISTK);
#endif
#if defined(TARGET_TSKATR)
const unsigned_t TOPPERS_cfg_TARGET_TSKATR = (unsigned_t)(TARGET_TSKATR);
#else
const unsigned_t TOPPERS_cfg_TARGET_TSKATR = (unsigned_t)(0);
#endif
#if defined(TARGET_INTATR)
const unsigned_t TOPPERS_cfg_TARGET_INTATR = (unsigned_t)(TARGET_INTATR);
#else
const unsigned_t TOPPERS_cfg_TARGET_INTATR = (unsigned_t)(0);
#endif
#if defined(TARGET_INHATR)
const unsigned_t TOPPERS_cfg_TARGET_INHATR = (unsigned_t)(TARGET_INHATR);
#else
const unsigned_t TOPPERS_cfg_TARGET_INHATR = (unsigned_t)(0);
#endif
#if defined(TARGET_ISRATR)
const unsigned_t TOPPERS_cfg_TARGET_ISRATR = (unsigned_t)(TARGET_ISRATR);
#else
const unsigned_t TOPPERS_cfg_TARGET_ISRATR = (unsigned_t)(0);
#endif
#if defined(TARGET_EXCATR)
const unsigned_t TOPPERS_cfg_TARGET_EXCATR = (unsigned_t)(TARGET_EXCATR);
#else
const unsigned_t TOPPERS_cfg_TARGET_EXCATR = (unsigned_t)(0);
#endif
#if defined(TARGET_MIN_STKSZ)
const unsigned_t TOPPERS_cfg_TARGET_MIN_STKSZ = (unsigned_t)(TARGET_MIN_STKSZ);
#else
const unsigned_t TOPPERS_cfg_TARGET_MIN_STKSZ = (unsigned_t)(1);
#endif
#if defined(TARGET_MIN_ISTKSZ)
const unsigned_t TOPPERS_cfg_TARGET_MIN_ISTKSZ = (unsigned_t)(TARGET_MIN_ISTKSZ);
#else
const unsigned_t TOPPERS_cfg_TARGET_MIN_ISTKSZ = (unsigned_t)(1);
#endif
#if defined(CHECK_STKSZ_ALIGN)
const unsigned_t TOPPERS_cfg_CHECK_STKSZ_ALIGN = (unsigned_t)(CHECK_STKSZ_ALIGN);
#else
const unsigned_t TOPPERS_cfg_CHECK_STKSZ_ALIGN = (unsigned_t)(1);
#endif
#if defined(CHECK_INTPTR_ALIGN)
const unsigned_t TOPPERS_cfg_CHECK_INTPTR_ALIGN = (unsigned_t)(CHECK_INTPTR_ALIGN);
#else
const unsigned_t TOPPERS_cfg_CHECK_INTPTR_ALIGN = (unsigned_t)(1);
#endif
#if defined(CHECK_INTPTR_NONNULL)
const signed_t TOPPERS_cfg_CHECK_INTPTR_NONNULL = (signed_t)(true);
#endif
#if defined(CHECK_FUNC_ALIGN)
const unsigned_t TOPPERS_cfg_CHECK_FUNC_ALIGN = (unsigned_t)(CHECK_FUNC_ALIGN);
#else
const unsigned_t TOPPERS_cfg_CHECK_FUNC_ALIGN = (unsigned_t)(1);
#endif
#if defined(CHECK_FUNC_NONNULL)
const signed_t TOPPERS_cfg_CHECK_FUNC_NONNULL = (signed_t)(true);
#endif
#if defined(CHECK_STACK_ALIGN)
const unsigned_t TOPPERS_cfg_CHECK_STACK_ALIGN = (unsigned_t)(CHECK_STACK_ALIGN);
#else
const unsigned_t TOPPERS_cfg_CHECK_STACK_ALIGN = (unsigned_t)(1);
#endif
#if defined(CHECK_STACK_NONNULL)
const signed_t TOPPERS_cfg_CHECK_STACK_NONNULL = (signed_t)(true);
#endif
#if defined(CHECK_MPF_ALIGN)
const unsigned_t TOPPERS_cfg_CHECK_MPF_ALIGN = (unsigned_t)(CHECK_MPF_ALIGN);
#else
const unsigned_t TOPPERS_cfg_CHECK_MPF_ALIGN = (unsigned_t)(1);
#endif
#if defined(CHECK_MPF_NONNULL)
const signed_t TOPPERS_cfg_CHECK_MPF_NONNULL = (signed_t)(true);
#endif
#if defined(CHECK_MB_ALIGN)
const unsigned_t TOPPERS_cfg_CHECK_MB_ALIGN = (unsigned_t)(CHECK_MB_ALIGN);
#else
const unsigned_t TOPPERS_cfg_CHECK_MB_ALIGN = (unsigned_t)(1);
#endif
const unsigned_t TOPPERS_cfg_sizeof_void_ptr = (unsigned_t)(sizeof(void*));
const unsigned_t TOPPERS_cfg_sizeof_uint_t = (unsigned_t)(sizeof(uint_t));
const unsigned_t TOPPERS_cfg_sizeof_size_t = (unsigned_t)(sizeof(size_t));
const unsigned_t TOPPERS_cfg_sizeof_intptr_t = (unsigned_t)(sizeof(intptr_t));
const unsigned_t TOPPERS_cfg_sizeof_ID = (unsigned_t)(sizeof(ID));
const unsigned_t TOPPERS_cfg_sizeof_FP = (unsigned_t)(sizeof(FP));
const unsigned_t TOPPERS_cfg_sizeof_INTNO = (unsigned_t)(sizeof(INTNO));
const unsigned_t TOPPERS_cfg_sizeof_INHNO = (unsigned_t)(sizeof(INHNO));
const unsigned_t TOPPERS_cfg_sizeof_EXCNO = (unsigned_t)(sizeof(EXCNO));
const unsigned_t TOPPERS_cfg_sizeof_TASK = (unsigned_t)(sizeof(TASK));
const unsigned_t TOPPERS_cfg_sizeof_TMEHDR = (unsigned_t)(sizeof(TMEHDR));
const unsigned_t TOPPERS_cfg_sizeof_ISR = (unsigned_t)(sizeof(ISR));
const unsigned_t TOPPERS_cfg_sizeof_INTHDR = (unsigned_t)(sizeof(INTHDR));
const unsigned_t TOPPERS_cfg_sizeof_EXCHDR = (unsigned_t)(sizeof(EXCHDR));
const unsigned_t TOPPERS_cfg_sizeof_INIRTN = (unsigned_t)(sizeof(INIRTN));
const unsigned_t TOPPERS_cfg_sizeof_TERRTN = (unsigned_t)(sizeof(TERRTN));
const unsigned_t TOPPERS_cfg_sizeof_NFYHDR = (unsigned_t)(sizeof(NFYHDR));
const unsigned_t TOPPERS_cfg_sizeof_TINIB = (unsigned_t)(sizeof(TINIB));
const unsigned_t TOPPERS_cfg_offsetof_TINIB_tskatr = (unsigned_t)(offsetof(TINIB,tskatr));
const unsigned_t TOPPERS_cfg_offsetof_TINIB_exinf = (unsigned_t)(offsetof(TINIB,exinf));
const unsigned_t TOPPERS_cfg_offsetof_TINIB_task = (unsigned_t)(offsetof(TINIB,task));
const unsigned_t TOPPERS_cfg_offsetof_TINIB_ipriority = (unsigned_t)(offsetof(TINIB,ipriority));
#if !defined(USE_TSKINICTXB)
const unsigned_t TOPPERS_cfg_offsetof_TINIB_stksz = (unsigned_t)(offsetof(TINIB,stksz));
#endif
#if !defined(USE_TSKINICTXB)
const unsigned_t TOPPERS_cfg_offsetof_TINIB_stk = (unsigned_t)(offsetof(TINIB,stk));
#endif
const unsigned_t TOPPERS_cfg_sizeof_SEMINIB = (unsigned_t)(sizeof(SEMINIB));
const unsigned_t TOPPERS_cfg_offsetof_SEMINIB_sematr = (unsigned_t)(offsetof(SEMINIB,sematr));
const unsigned_t TOPPERS_cfg_offsetof_SEMINIB_isemcnt = (unsigned_t)(offsetof(SEMINIB,isemcnt));
const unsigned_t TOPPERS_cfg_offsetof_SEMINIB_maxsem = (unsigned_t)(offsetof(SEMINIB,maxsem));
const unsigned_t TOPPERS_cfg_sizeof_FLGPTN = (unsigned_t)(sizeof(FLGPTN));
const unsigned_t TOPPERS_cfg_sizeof_FLGINIB = (unsigned_t)(sizeof(FLGINIB));
const unsigned_t TOPPERS_cfg_offsetof_FLGINIB_flgatr = (unsigned_t)(offsetof(FLGINIB,flgatr));
const unsigned_t TOPPERS_cfg_offsetof_FLGINIB_iflgptn = (unsigned_t)(offsetof(FLGINIB,iflgptn));
const unsigned_t TOPPERS_cfg_sizeof_DTQINIB = (unsigned_t)(sizeof(DTQINIB));
const unsigned_t TOPPERS_cfg_offsetof_DTQINIB_dtqatr = (unsigned_t)(offsetof(DTQINIB,dtqatr));
const unsigned_t TOPPERS_cfg_offsetof_DTQINIB_dtqcnt = (unsigned_t)(offsetof(DTQINIB,dtqcnt));
const unsigned_t TOPPERS_cfg_offsetof_DTQINIB_p_dtqmb = (unsigned_t)(offsetof(DTQINIB,p_dtqmb));
const unsigned_t TOPPERS_cfg_sizeof_PDQINIB = (unsigned_t)(sizeof(PDQINIB));
const unsigned_t TOPPERS_cfg_offsetof_PDQINIB_pdqatr = (unsigned_t)(offsetof(PDQINIB,pdqatr));
const unsigned_t TOPPERS_cfg_offsetof_PDQINIB_pdqcnt = (unsigned_t)(offsetof(PDQINIB,pdqcnt));
const unsigned_t TOPPERS_cfg_offsetof_PDQINIB_maxdpri = (unsigned_t)(offsetof(PDQINIB,maxdpri));
const unsigned_t TOPPERS_cfg_offsetof_PDQINIB_p_pdqmb = (unsigned_t)(offsetof(PDQINIB,p_pdqmb));
const unsigned_t TOPPERS_cfg_sizeof_MTXINIB = (unsigned_t)(sizeof(MTXINIB));
const unsigned_t TOPPERS_cfg_offsetof_MTXINIB_mtxatr = (unsigned_t)(offsetof(MTXINIB,mtxatr));
const unsigned_t TOPPERS_cfg_offsetof_MTXINIB_ceilpri = (unsigned_t)(offsetof(MTXINIB,ceilpri));
const unsigned_t TOPPERS_cfg_sizeof_MPFINIB = (unsigned_t)(sizeof(MPFINIB));
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_mpfatr = (unsigned_t)(offsetof(MPFINIB,mpfatr));
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_blkcnt = (unsigned_t)(offsetof(MPFINIB,blkcnt));
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_blksz = (unsigned_t)(offsetof(MPFINIB,blksz));
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_mpf = (unsigned_t)(offsetof(MPFINIB,mpf));
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_p_mpfmb = (unsigned_t)(offsetof(MPFINIB,p_mpfmb));
const unsigned_t TOPPERS_cfg_sizeof_CYCINIB = (unsigned_t)(sizeof(CYCINIB));
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_cycatr = (unsigned_t)(offsetof(CYCINIB,cycatr));
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_exinf = (unsigned_t)(offsetof(CYCINIB,exinf));
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_nfyhdr = (unsigned_t)(offsetof(CYCINIB,nfyhdr));
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_cyctim = (unsigned_t)(offsetof(CYCINIB,cyctim));
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_cycphs = (unsigned_t)(offsetof(CYCINIB,cycphs));
const unsigned_t TOPPERS_cfg_sizeof_ALMINIB = (unsigned_t)(sizeof(ALMINIB));
const unsigned_t TOPPERS_cfg_offsetof_ALMINIB_almatr = (unsigned_t)(offsetof(ALMINIB,almatr));
const unsigned_t TOPPERS_cfg_offsetof_ALMINIB_exinf = (unsigned_t)(offsetof(ALMINIB,exinf));
const unsigned_t TOPPERS_cfg_offsetof_ALMINIB_nfyhdr = (unsigned_t)(offsetof(ALMINIB,nfyhdr));
const unsigned_t TOPPERS_cfg_sizeof_ISRINIB = (unsigned_t)(sizeof(ISRINIB));
const unsigned_t TOPPERS_cfg_offsetof_ISRINIB_isratr = (unsigned_t)(offsetof(ISRINIB,isratr));
const unsigned_t TOPPERS_cfg_offsetof_ISRINIB_exinf = (unsigned_t)(offsetof(ISRINIB,exinf));
const unsigned_t TOPPERS_cfg_offsetof_ISRINIB_p_isr_queue = (unsigned_t)(offsetof(ISRINIB,p_isr_queue));
const unsigned_t TOPPERS_cfg_offsetof_ISRINIB_isr = (unsigned_t)(offsetof(ISRINIB,isr));
const unsigned_t TOPPERS_cfg_offsetof_ISRINIB_isrpri = (unsigned_t)(offsetof(ISRINIB,isrpri));
#if !defined(OMIT_INITIALIZE_INTERRUPT)
const unsigned_t TOPPERS_cfg_sizeof_INHINIB = (unsigned_t)(sizeof(INHINIB));
#endif
#if !defined(OMIT_INITIALIZE_INTERRUPT)
const unsigned_t TOPPERS_cfg_offset_INHINIB_inhno = (unsigned_t)(offsetof(INHINIB,inhno));
#endif
#if !defined(OMIT_INITIALIZE_INTERRUPT)
const unsigned_t TOPPERS_cfg_offset_INHINIB_inhatr = (unsigned_t)(offsetof(INHINIB,inhatr));
#endif
#if !defined(OMIT_INITIALIZE_INTERRUPT)
const unsigned_t TOPPERS_cfg_offset_INHINIB_int_entry = (unsigned_t)(offsetof(INHINIB,int_entry));
#endif
#if !defined(OMIT_INITIALIZE_INTERRUPT)
const unsigned_t TOPPERS_cfg_sizeof_INTINIB = (unsigned_t)(sizeof(INTINIB));
#endif
#if !defined(OMIT_INITIALIZE_INTERRUPT)
const unsigned_t TOPPERS_cfg_offset_INTINIB_intno = (unsigned_t)(offsetof(INTINIB,intno));
#endif
#if !defined(OMIT_INITIALIZE_INTERRUPT)
const unsigned_t TOPPERS_cfg_offset_INTINIB_intatr = (unsigned_t)(offsetof(INTINIB,intatr));
#endif
#if !defined(OMIT_INITIALIZE_INTERRUPT)
const unsigned_t TOPPERS_cfg_offset_INTINIB_intpri = (unsigned_t)(offsetof(INTINIB,intpri));
#endif
#if !defined(OMIT_INITIALIZE_EXCEPTION)
const unsigned_t TOPPERS_cfg_sizeof_EXCINIB = (unsigned_t)(sizeof(EXCINIB));
#endif
#if !defined(OMIT_INITIALIZE_EXCEPTION)
const unsigned_t TOPPERS_cfg_offset_EXCINIB_excno = (unsigned_t)(offsetof(EXCINIB,excno));
#endif
#if !defined(OMIT_INITIALIZE_EXCEPTION)
const unsigned_t TOPPERS_cfg_offset_EXCINIB_excatr = (unsigned_t)(offsetof(EXCINIB,excatr));
#endif
#if !defined(OMIT_INITIALIZE_EXCEPTION)
const unsigned_t TOPPERS_cfg_offset_EXCINIB_exc_entry = (unsigned_t)(offsetof(EXCINIB,exc_entry));
#endif
#if defined(TARGET_RZA1H)
const signed_t TOPPERS_cfg_TARGET_RZA1H = (signed_t)(true);
#endif
#if defined(TARGET_RZA1L)
const signed_t TOPPERS_cfg_TARGET_RZA1L = (signed_t)(true);
#endif
const unsigned_t TOPPERS_cfg_TA_NEGEDGE = (unsigned_t)(TA_NEGEDGE);
const unsigned_t TOPPERS_cfg_TA_POSEDGE = (unsigned_t)(TA_POSEDGE);
const unsigned_t TOPPERS_cfg_TA_BOTHEDGE = (unsigned_t)(TA_BOTHEDGE);
const unsigned_t TOPPERS_cfg_INTNO_IRQ0 = (unsigned_t)(INTNO_IRQ0);
const unsigned_t TOPPERS_cfg_INTNO_IRQ7 = (unsigned_t)(INTNO_IRQ7);
const unsigned_t TOPPERS_cfg_TARGET_ARCH_ARM = (unsigned_t)(__TARGET_ARCH_ARM);
#if defined(USE_INTCFG_TABLE)
const signed_t TOPPERS_cfg_USE_INTCFG_TABLE = (signed_t)(true);
#endif
const unsigned_t TOPPERS_cfg_sizeof_TCB = (unsigned_t)(sizeof(TCB));
const unsigned_t TOPPERS_cfg_offsetof_TCB_p_tinib = (unsigned_t)(offsetof(TCB,p_tinib));
const unsigned_t TOPPERS_cfg_offsetof_TCB_sp = (unsigned_t)(offsetof(TCB,tskctxb.sp));
const unsigned_t TOPPERS_cfg_offsetof_TCB_pc = (unsigned_t)(offsetof(TCB,tskctxb.pc));
const unsigned_t TOPPERS_cfg_offsetof_T_EXCINF_cpsr = (unsigned_t)(offsetof(T_EXCINF,cpsr));


#line 10 "../../asp3_dcre/arch/arm_gcc/rza1/chip_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_1 = 1;
#line 10 "../../asp3_dcre/arch/arm_gcc/rza1/chip_timer.cfg"
const unsigned_t TOPPERS_cfg_valueof_iniatr_1 = (unsigned_t)(TA_NULL);

#line 11 "../../asp3_dcre/arch/arm_gcc/rza1/chip_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_2 = 2;
#line 11 "../../asp3_dcre/arch/arm_gcc/rza1/chip_timer.cfg"
const unsigned_t TOPPERS_cfg_valueof_teratr_2 = (unsigned_t)(TA_NULL);

#line 12 "../../asp3_dcre/arch/arm_gcc/rza1/chip_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_3 = 3;
#line 12 "../../asp3_dcre/arch/arm_gcc/rza1/chip_timer.cfg"
const unsigned_t TOPPERS_cfg_valueof_intno_3 = (unsigned_t)(INTNO_TIMER);
#line 12 "../../asp3_dcre/arch/arm_gcc/rza1/chip_timer.cfg"
const unsigned_t TOPPERS_cfg_valueof_intatr_3 = (unsigned_t)(TA_ENAINT|INTATR_TIMER);
#line 12 "../../asp3_dcre/arch/arm_gcc/rza1/chip_timer.cfg"
const signed_t TOPPERS_cfg_valueof_intpri_3 = (signed_t)(INTPRI_TIMER);

#line 13 "../../asp3_dcre/arch/arm_gcc/rza1/chip_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_4 = 4;
#line 13 "../../asp3_dcre/arch/arm_gcc/rza1/chip_timer.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhno_4 = (unsigned_t)(INHNO_TIMER);
#line 13 "../../asp3_dcre/arch/arm_gcc/rza1/chip_timer.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhatr_4 = (unsigned_t)(TA_NULL);

#ifdef TOPPERS_SUPPORT_OVRHDR

#line 19 "../../asp3_dcre/arch/arm_gcc/rza1/chip_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_5 = 5;
#line 19 "../../asp3_dcre/arch/arm_gcc/rza1/chip_timer.cfg"
const unsigned_t TOPPERS_cfg_valueof_iniatr_5 = (unsigned_t)(TA_NULL);

#line 20 "../../asp3_dcre/arch/arm_gcc/rza1/chip_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_6 = 6;
#line 20 "../../asp3_dcre/arch/arm_gcc/rza1/chip_timer.cfg"
const unsigned_t TOPPERS_cfg_valueof_teratr_6 = (unsigned_t)(TA_NULL);

#line 21 "../../asp3_dcre/arch/arm_gcc/rza1/chip_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_7 = 7;
#line 21 "../../asp3_dcre/arch/arm_gcc/rza1/chip_timer.cfg"
const unsigned_t TOPPERS_cfg_valueof_intno_7 = (unsigned_t)(INTNO_OVRTIMER);
#line 21 "../../asp3_dcre/arch/arm_gcc/rza1/chip_timer.cfg"
const unsigned_t TOPPERS_cfg_valueof_intatr_7 = (unsigned_t)(TA_ENAINT|INTATR_OVRTIMER);
#line 21 "../../asp3_dcre/arch/arm_gcc/rza1/chip_timer.cfg"
const signed_t TOPPERS_cfg_valueof_intpri_7 = (signed_t)(INTPRI_OVRTIMER);

#line 22 "../../asp3_dcre/arch/arm_gcc/rza1/chip_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_8 = 8;
#line 22 "../../asp3_dcre/arch/arm_gcc/rza1/chip_timer.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhno_8 = (unsigned_t)(INHNO_OVRTIMER);
#line 22 "../../asp3_dcre/arch/arm_gcc/rza1/chip_timer.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhatr_8 = (unsigned_t)(TA_NULL);

#endif

#line 2 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_static_api_9 = 9;
#define TSKID_tTask_Task	(<>)
#line 2 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_9 = (unsigned_t)(TA_ACT);
#line 2 "./gen/tecsgen.cfg"
const signed_t TOPPERS_cfg_valueof_itskpri_9 = (signed_t)(10);
#line 2 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_stksz_9 = (unsigned_t)(1024);

#line 3 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_static_api_10 = 10;
#define TSKID_tTask_LogTask_Task	(<>)
#line 3 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_10 = (unsigned_t)(TA_ACT);
#line 3 "./gen/tecsgen.cfg"
const signed_t TOPPERS_cfg_valueof_itskpri_10 = (signed_t)(3);
#line 3 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_stksz_10 = (unsigned_t)(1024);

#line 4 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_static_api_11 = 11;
#define SEMID_tSemaphore_SerialPort1_ReceiveSemaphore	(<>)
#line 4 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_11 = (unsigned_t)(TA_NULL);
#line 4 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_isemcnt_11 = (unsigned_t)(0);
#line 4 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_maxsem_11 = (unsigned_t)(1);

#line 5 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_static_api_12 = 12;
#define SEMID_tSemaphore_SerialPort1_SendSemaphore	(<>)
#line 5 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_12 = (unsigned_t)(TA_NULL);
#line 5 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_isemcnt_12 = (unsigned_t)(1);
#line 5 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_maxsem_12 = (unsigned_t)(1);

#line 7 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_static_api_13 = 13;
#line 7 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_iniatr_13 = (unsigned_t)(TA_NULL);

#line 9 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_static_api_14 = 14;
#line 9 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_teratr_14 = (unsigned_t)(TA_NULL);

#line 10 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_static_api_15 = 15;
#line 10 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_teratr_15 = (unsigned_t)(TA_NULL);

#line 7 "../../asp3_dcre/mbed/mbed_stub.cfg"
const unsigned_t TOPPERS_cfg_static_api_16 = 16;
#define SEM_MALLOC	(<>)
#line 7 "../../asp3_dcre/mbed/mbed_stub.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_16 = (unsigned_t)(TA_TPRI);
#line 7 "../../asp3_dcre/mbed/mbed_stub.cfg"
const unsigned_t TOPPERS_cfg_valueof_isemcnt_16 = (unsigned_t)(1);
#line 7 "../../asp3_dcre/mbed/mbed_stub.cfg"
const unsigned_t TOPPERS_cfg_valueof_maxsem_16 = (unsigned_t)(1);

#ifdef SUPPORT_ETHER

#line 50 "../../asp3_dcre/tinet/netdev/if_mbed/nic_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_17 = 17;
#define IF_MBED_PHY_TASK	(<>)
#line 50 "../../asp3_dcre/tinet/netdev/if_mbed/nic_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_17 = (unsigned_t)(TA_ACT);
#line 50 "../../asp3_dcre/tinet/netdev/if_mbed/nic_asp.cfg"
const signed_t TOPPERS_cfg_valueof_itskpri_17 = (signed_t)(IF_MBED_PHY_PRIORITY);
#line 50 "../../asp3_dcre/tinet/netdev/if_mbed/nic_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_stksz_17 = (unsigned_t)(IF_MBED_PHY_STACK_SIZE);

#line 54 "../../asp3_dcre/tinet/netdev/if_mbed/nic_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_18 = 18;
#line 54 "../../asp3_dcre/tinet/netdev/if_mbed/nic_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhno_18 = (unsigned_t)(INHNO_IF_MBED);
#line 54 "../../asp3_dcre/tinet/netdev/if_mbed/nic_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhatr_18 = (unsigned_t)(TA_NULL);

#line 55 "../../asp3_dcre/tinet/netdev/if_mbed/nic_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_19 = 19;
#line 55 "../../asp3_dcre/tinet/netdev/if_mbed/nic_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_intno_19 = (unsigned_t)(INTNO_IF_MBED);
#line 55 "../../asp3_dcre/tinet/netdev/if_mbed/nic_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_intatr_19 = (unsigned_t)(INTATR_IF_MBED);
#line 55 "../../asp3_dcre/tinet/netdev/if_mbed/nic_asp.cfg"
const signed_t TOPPERS_cfg_valueof_intpri_19 = (signed_t)(INTPRI_IF_MBED);

#line 59 "../../asp3_dcre/tinet/netdev/if_mbed/nic_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_20 = 20;
#define SEM_IF_MBED_SBUF_READY	(<>)
#line 59 "../../asp3_dcre/tinet/netdev/if_mbed/nic_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_20 = (unsigned_t)(TA_TPRI);
#line 59 "../../asp3_dcre/tinet/netdev/if_mbed/nic_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_isemcnt_20 = (unsigned_t)(NUM_IF_MBED_TXBUF);
#line 59 "../../asp3_dcre/tinet/netdev/if_mbed/nic_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_maxsem_20 = (unsigned_t)(NUM_IF_MBED_TXBUF);

#line 60 "../../asp3_dcre/tinet/netdev/if_mbed/nic_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_21 = 21;
#define SEM_IF_MBED_RBUF_READY	(<>)
#line 60 "../../asp3_dcre/tinet/netdev/if_mbed/nic_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_21 = (unsigned_t)(TA_TPRI);
#line 60 "../../asp3_dcre/tinet/netdev/if_mbed/nic_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_isemcnt_21 = (unsigned_t)(0);
#line 60 "../../asp3_dcre/tinet/netdev/if_mbed/nic_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_maxsem_21 = (unsigned_t)(NUM_IF_MBED_RXBUF);

#endif

#line 42 "../../asp3_dcre/tinet/net/net.cfg"
const unsigned_t TOPPERS_cfg_static_api_22 = 22;
#define NET_TIMER_TASK	(<>)
#line 42 "../../asp3_dcre/tinet/net/net.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_22 = (unsigned_t)(TA_HLNG);
#line 42 "../../asp3_dcre/tinet/net/net.cfg"
const signed_t TOPPERS_cfg_valueof_itskpri_22 = (signed_t)(NET_TIMER_PRIORITY);
#line 42 "../../asp3_dcre/tinet/net/net.cfg"
const unsigned_t TOPPERS_cfg_valueof_stksz_22 = (unsigned_t)(NET_TIMER_STACK_SIZE);

#line 51 "../../asp3_dcre/tinet/net/net.cfg"
const unsigned_t TOPPERS_cfg_static_api_23 = 23;
#define NET_TIMER_HANDLER	(<>)
#line 51 "../../asp3_dcre/tinet/net/net.cfg"
const unsigned_t TOPPERS_cfg_valueof_cycatr_23 = (unsigned_t)(TA_STA);
#line 51 "../../asp3_dcre/tinet/net/net.cfg"
const unsigned_t TOPPERS_cfg_valueof_nfymode_23 = (unsigned_t)(TNFY_HANDLER);
#line 51 "../../asp3_dcre/tinet/net/net.cfg"
const unsigned_t TOPPERS_cfg_valueof_cyctim_23 = (unsigned_t)(NET_TIMER_CYCLE);
#line 51 "../../asp3_dcre/tinet/net/net.cfg"
const unsigned_t TOPPERS_cfg_valueof_cycphs_23 = (unsigned_t)(1);

#line 60 "../../asp3_dcre/tinet/net/net.cfg"
const unsigned_t TOPPERS_cfg_static_api_24 = 24;
#define SEM_CALL_OUT_LOCK	(<>)
#line 60 "../../asp3_dcre/tinet/net/net.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_24 = (unsigned_t)(TA_TPRI);
#line 60 "../../asp3_dcre/tinet/net/net.cfg"
const unsigned_t TOPPERS_cfg_valueof_isemcnt_24 = (unsigned_t)(1);
#line 60 "../../asp3_dcre/tinet/net/net.cfg"
const unsigned_t TOPPERS_cfg_valueof_maxsem_24 = (unsigned_t)(1);

#line 61 "../../asp3_dcre/tinet/net/net.cfg"
const unsigned_t TOPPERS_cfg_static_api_25 = 25;
#define SEM_CALL_OUT_TIMEOUT	(<>)
#line 61 "../../asp3_dcre/tinet/net/net.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_25 = (unsigned_t)(TA_TPRI);
#line 61 "../../asp3_dcre/tinet/net/net.cfg"
const unsigned_t TOPPERS_cfg_valueof_isemcnt_25 = (unsigned_t)(0);
#line 61 "../../asp3_dcre/tinet/net/net.cfg"
const unsigned_t TOPPERS_cfg_valueof_maxsem_25 = (unsigned_t)(NUM_NET_CALLOUT);

#line 65 "../../asp3_dcre/tinet/net/net.cfg"
const unsigned_t TOPPERS_cfg_static_api_26 = 26;
#define SEM_IP2STR_BUFF_LOCK	(<>)
#line 65 "../../asp3_dcre/tinet/net/net.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_26 = (unsigned_t)(TA_TPRI);
#line 65 "../../asp3_dcre/tinet/net/net.cfg"
const unsigned_t TOPPERS_cfg_valueof_isemcnt_26 = (unsigned_t)(1);
#line 65 "../../asp3_dcre/tinet/net/net.cfg"
const unsigned_t TOPPERS_cfg_valueof_maxsem_26 = (unsigned_t)(1);

#ifndef NOUSE_MPF_NET_BUF

#if defined(NUM_MPF_NET_BUF_CSEG) && NUM_MPF_NET_BUF_CSEG > 0

#line 51 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_27 = 27;
#define MPF_NET_BUF_CSEG	(<>)
#line 51 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_mpfatr_27 = (unsigned_t)(TA_TFIFO);
#line 51 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_blkcnt_27 = (unsigned_t)(NUM_MPF_NET_BUF_CSEG);
#line 51 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_blksz_27 = (unsigned_t)(sizeof(T_NET_BUF_CSEG));

#endif

#if defined(NUM_MPF_NET_BUF_64) && NUM_MPF_NET_BUF_64 > 0

#line 61 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_28 = 28;
#define MPF_NET_BUF_64	(<>)
#line 61 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_mpfatr_28 = (unsigned_t)(TA_TFIFO);
#line 61 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_blkcnt_28 = (unsigned_t)(NUM_MPF_NET_BUF_64);
#line 61 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_blksz_28 = (unsigned_t)(sizeof(T_NET_BUF_64));

#endif

#if defined(NUM_MPF_NET_BUF_128) && NUM_MPF_NET_BUF_128 > 0

#line 70 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_29 = 29;
#define MPF_NET_BUF_128	(<>)
#line 70 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_mpfatr_29 = (unsigned_t)(TA_TFIFO);
#line 70 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_blkcnt_29 = (unsigned_t)(NUM_MPF_NET_BUF_128);
#line 70 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_blksz_29 = (unsigned_t)(sizeof(T_NET_BUF_128));

#endif

#if defined(NUM_MPF_NET_BUF_256) && NUM_MPF_NET_BUF_256 > 0

#line 80 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_30 = 30;
#define MPF_NET_BUF_256	(<>)
#line 80 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_mpfatr_30 = (unsigned_t)(TA_TFIFO);
#line 80 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_blkcnt_30 = (unsigned_t)(NUM_MPF_NET_BUF_256);
#line 80 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_blksz_30 = (unsigned_t)(sizeof(T_NET_BUF_256));

#endif

#if defined(NUM_MPF_NET_BUF_512) && NUM_MPF_NET_BUF_512 > 0

#line 90 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_31 = 31;
#define MPF_NET_BUF_512	(<>)
#line 90 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_mpfatr_31 = (unsigned_t)(TA_TFIFO);
#line 90 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_blkcnt_31 = (unsigned_t)(NUM_MPF_NET_BUF_512);
#line 90 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_blksz_31 = (unsigned_t)(sizeof(T_NET_BUF_512));

#endif

#if defined(NUM_MPF_NET_BUF_IP_MSS) && NUM_MPF_NET_BUF_IP_MSS > 0

#line 100 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_32 = 32;
#define MPF_NET_BUF_IP_MSS	(<>)
#line 100 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_mpfatr_32 = (unsigned_t)(TA_TFIFO);
#line 100 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_blkcnt_32 = (unsigned_t)(NUM_MPF_NET_BUF_IP_MSS);
#line 100 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_blksz_32 = (unsigned_t)(sizeof(T_NET_BUF_IP_MSS));

#endif

#if defined(NUM_MPF_NET_BUF_1024) && NUM_MPF_NET_BUF_1024 > 0

#line 110 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_33 = 33;
#define MPF_NET_BUF_1024	(<>)
#line 110 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_mpfatr_33 = (unsigned_t)(TA_TFIFO);
#line 110 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_blkcnt_33 = (unsigned_t)(NUM_MPF_NET_BUF_1024);
#line 110 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_blksz_33 = (unsigned_t)(sizeof(T_NET_BUF_1024));

#endif

#if defined(NUM_MPF_NET_BUF_IPV6_MMTU) && NUM_MPF_NET_BUF_IPV6_MMTU > 0

#line 120 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_34 = 34;
#define MPF_NET_BUF_IPV6_MMTU	(<>)
#line 120 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_mpfatr_34 = (unsigned_t)(TA_TFIFO);
#line 120 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_blkcnt_34 = (unsigned_t)(NUM_MPF_NET_BUF_IPV6_MMTU);
#line 120 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_blksz_34 = (unsigned_t)(sizeof(T_NET_BUF_IPV6_MMTU));

#endif

#if defined(NUM_MPF_NET_BUF_IF_PDU) && NUM_MPF_NET_BUF_IF_PDU > 0

#line 130 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_35 = 35;
#define MPF_NET_BUF_IF_PDU	(<>)
#line 130 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_mpfatr_35 = (unsigned_t)(TA_TFIFO);
#line 130 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_blkcnt_35 = (unsigned_t)(NUM_MPF_NET_BUF_IF_PDU);
#line 130 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_blksz_35 = (unsigned_t)(sizeof(T_NET_BUF_IF_PDU));

#endif

#if defined(NUM_MPF_NET_BUF6_REASSM) && NUM_MPF_NET_BUF6_REASSM > 0

#line 141 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_36 = 36;
#define MPF_NET_BUF_REASSM	(<>)
#line 141 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_mpfatr_36 = (unsigned_t)(TA_TFIFO);
#line 141 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_blkcnt_36 = (unsigned_t)(NUM_MPF_NET_BUF6_REASSM);
#line 141 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_blksz_36 = (unsigned_t)(sizeof(T_NET_BUF6_REASSM));

#else

#if defined(NUM_MPF_NET_BUF4_REASSM) && NUM_MPF_NET_BUF4_REASSM > 0

#line 153 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_37 = 37;
#define MPF_NET_BUF_REASSM	(<>)
#line 153 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_mpfatr_37 = (unsigned_t)(TA_TFIFO);
#line 153 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_blkcnt_37 = (unsigned_t)(NUM_MPF_NET_BUF4_REASSM);
#line 153 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_blksz_37 = (unsigned_t)(sizeof(T_NET_BUF4_REASSM));

#endif

#endif

#if defined(NUM_MPF_NET_BUF6_65536) && NUM_MPF_NET_BUF6_65536 > 0

#line 165 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_38 = 38;
#define MPF_NET_BUF6_65536	(<>)
#line 165 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_mpfatr_38 = (unsigned_t)(TA_TFIFO);
#line 165 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_blkcnt_38 = (unsigned_t)(NUM_MPF_NET_BUF6_65536);
#line 165 "../../asp3_dcre/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_blksz_38 = (unsigned_t)(sizeof(T_NET_BUF6_65536));

#endif

#endif

#ifdef SUPPORT_ETHER

#line 40 "../../asp3_dcre/tinet/net/ethernet.cfg"
const unsigned_t TOPPERS_cfg_static_api_39 = 39;
#define ETHER_OUTPUT_TASK	(<>)
#line 40 "../../asp3_dcre/tinet/net/ethernet.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_39 = (unsigned_t)(TA_HLNG);
#line 40 "../../asp3_dcre/tinet/net/ethernet.cfg"
const signed_t TOPPERS_cfg_valueof_itskpri_39 = (signed_t)(ETHER_OUTPUT_PRIORITY);
#line 40 "../../asp3_dcre/tinet/net/ethernet.cfg"
const unsigned_t TOPPERS_cfg_valueof_stksz_39 = (unsigned_t)(ETHER_OUTPUT_STACK_SIZE);

#line 41 "../../asp3_dcre/tinet/net/ethernet.cfg"
const unsigned_t TOPPERS_cfg_static_api_40 = 40;
#define ETHER_INPUT_TASK	(<>)
#line 41 "../../asp3_dcre/tinet/net/ethernet.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_40 = (unsigned_t)(TA_HLNG|TA_ACT);
#line 41 "../../asp3_dcre/tinet/net/ethernet.cfg"
const signed_t TOPPERS_cfg_valueof_itskpri_40 = (signed_t)(ETHER_INPUT_PRIORITY);
#line 41 "../../asp3_dcre/tinet/net/ethernet.cfg"
const unsigned_t TOPPERS_cfg_valueof_stksz_40 = (unsigned_t)(ETHER_INPUT_STACK_SIZE);

#line 43 "../../asp3_dcre/tinet/net/ethernet.cfg"
const unsigned_t TOPPERS_cfg_static_api_41 = 41;
#define DTQ_ETHER_OUTPUT	(<>)
#line 43 "../../asp3_dcre/tinet/net/ethernet.cfg"
const unsigned_t TOPPERS_cfg_valueof_dtqatr_41 = (unsigned_t)(TA_TFIFO);
#line 43 "../../asp3_dcre/tinet/net/ethernet.cfg"
const unsigned_t TOPPERS_cfg_valueof_dtqcnt_41 = (unsigned_t)(NUM_DTQ_ETHER_OUTPUT);

#line 47 "../../asp3_dcre/tinet/net/ethernet.cfg"
const unsigned_t TOPPERS_cfg_static_api_42 = 42;
#define SEM_MAC2STR_BUFF_LOCK	(<>)
#line 47 "../../asp3_dcre/tinet/net/ethernet.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_42 = (unsigned_t)(TA_TPRI);
#line 47 "../../asp3_dcre/tinet/net/ethernet.cfg"
const unsigned_t TOPPERS_cfg_valueof_isemcnt_42 = (unsigned_t)(1);
#line 47 "../../asp3_dcre/tinet/net/ethernet.cfg"
const unsigned_t TOPPERS_cfg_valueof_maxsem_42 = (unsigned_t)(1);

#endif

#if defined(_IP4_CFG) && defined(SUPPORT_ETHER)

#line 42 "../../asp3_dcre/tinet/netinet/if_ether.cfg"
const unsigned_t TOPPERS_cfg_static_api_43 = 43;
#define SEM_ARP_CACHE_LOCK	(<>)
#line 42 "../../asp3_dcre/tinet/netinet/if_ether.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_43 = (unsigned_t)(TA_TPRI);
#line 42 "../../asp3_dcre/tinet/netinet/if_ether.cfg"
const unsigned_t TOPPERS_cfg_valueof_isemcnt_43 = (unsigned_t)(1);
#line 42 "../../asp3_dcre/tinet/netinet/if_ether.cfg"
const unsigned_t TOPPERS_cfg_valueof_maxsem_43 = (unsigned_t)(1);

#endif

#if defined(_IP4_CFG)

#ifdef IP4_CFG_FRAGMENT

#line 44 "../../asp3_dcre/tinet/netinet/ip.cfg"
const unsigned_t TOPPERS_cfg_static_api_44 = 44;
#define SEM_IP4_FRAG_QUEUE	(<>)
#line 44 "../../asp3_dcre/tinet/netinet/ip.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_44 = (unsigned_t)(TA_TPRI);
#line 44 "../../asp3_dcre/tinet/netinet/ip.cfg"
const unsigned_t TOPPERS_cfg_valueof_isemcnt_44 = (unsigned_t)(1);
#line 44 "../../asp3_dcre/tinet/netinet/ip.cfg"
const unsigned_t TOPPERS_cfg_valueof_maxsem_44 = (unsigned_t)(1);

#endif

#if NUM_IN4_REDIRECT_ROUTE_ENTRY > 0

#line 52 "../../asp3_dcre/tinet/netinet/ip.cfg"
const unsigned_t TOPPERS_cfg_static_api_45 = 45;
#define SEM_IN4_ROUTING_TBL	(<>)
#line 52 "../../asp3_dcre/tinet/netinet/ip.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_45 = (unsigned_t)(TA_TPRI);
#line 52 "../../asp3_dcre/tinet/netinet/ip.cfg"
const unsigned_t TOPPERS_cfg_valueof_isemcnt_45 = (unsigned_t)(1);
#line 52 "../../asp3_dcre/tinet/netinet/ip.cfg"
const unsigned_t TOPPERS_cfg_valueof_maxsem_45 = (unsigned_t)(1);

#endif

#endif

#if defined(_IP4_CFG) && defined(SUPPORT_IGMP)

#line 42 "../../asp3_dcre/tinet/netinet/ip_igmp.cfg"
const unsigned_t TOPPERS_cfg_static_api_46 = 46;
#define SEM_IGMP_GROUP_LOCK	(<>)
#line 42 "../../asp3_dcre/tinet/netinet/ip_igmp.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_46 = (unsigned_t)(TA_TPRI);
#line 42 "../../asp3_dcre/tinet/netinet/ip_igmp.cfg"
const unsigned_t TOPPERS_cfg_valueof_isemcnt_46 = (unsigned_t)(1);
#line 42 "../../asp3_dcre/tinet/netinet/ip_igmp.cfg"
const unsigned_t TOPPERS_cfg_valueof_maxsem_46 = (unsigned_t)(1);

#endif

#ifdef SUPPORT_TCP

#line 42 "../../asp3_dcre/tinet/netinet/tcp.cfg"
const unsigned_t TOPPERS_cfg_static_api_47 = 47;
#define TCP_OUTPUT_TASK	(<>)
#line 42 "../../asp3_dcre/tinet/netinet/tcp.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_47 = (unsigned_t)(TA_HLNG);
#line 42 "../../asp3_dcre/tinet/netinet/tcp.cfg"
const signed_t TOPPERS_cfg_valueof_itskpri_47 = (signed_t)(TCP_OUT_TASK_PRIORITY);
#line 42 "../../asp3_dcre/tinet/netinet/tcp.cfg"
const unsigned_t TOPPERS_cfg_valueof_stksz_47 = (unsigned_t)(TCP_OUT_TASK_STACK_SIZE);

#line 53 "../../asp3_dcre/tinet/netinet/tcp.cfg"
const unsigned_t TOPPERS_cfg_static_api_48 = 48;
#define SEM_TCP_POST_OUTPUT	(<>)
#line 53 "../../asp3_dcre/tinet/netinet/tcp.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_48 = (unsigned_t)(TA_TPRI);
#line 53 "../../asp3_dcre/tinet/netinet/tcp.cfg"
const unsigned_t TOPPERS_cfg_valueof_isemcnt_48 = (unsigned_t)(0);
#line 53 "../../asp3_dcre/tinet/netinet/tcp.cfg"
const unsigned_t TOPPERS_cfg_valueof_maxsem_48 = (unsigned_t)(1);

#line 54 "../../asp3_dcre/tinet/netinet/tcp.cfg"
const unsigned_t TOPPERS_cfg_static_api_49 = 49;
#define SEM_TCP_CEP	(<>)
#line 54 "../../asp3_dcre/tinet/netinet/tcp.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_49 = (unsigned_t)(TA_TPRI);
#line 54 "../../asp3_dcre/tinet/netinet/tcp.cfg"
const unsigned_t TOPPERS_cfg_valueof_isemcnt_49 = (unsigned_t)(1);
#line 54 "../../asp3_dcre/tinet/netinet/tcp.cfg"
const unsigned_t TOPPERS_cfg_valueof_maxsem_49 = (unsigned_t)(1);

#ifdef TCP_CFG_TRACE

#line 57 "../../asp3_dcre/tinet/netinet/tcp.cfg"
const unsigned_t TOPPERS_cfg_static_api_50 = 50;
#define SEM_TCP_TRACE	(<>)
#line 57 "../../asp3_dcre/tinet/netinet/tcp.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_50 = (unsigned_t)(TA_TPRI);
#line 57 "../../asp3_dcre/tinet/netinet/tcp.cfg"
const unsigned_t TOPPERS_cfg_valueof_isemcnt_50 = (unsigned_t)(1);
#line 57 "../../asp3_dcre/tinet/netinet/tcp.cfg"
const unsigned_t TOPPERS_cfg_valueof_maxsem_50 = (unsigned_t)(1);

#endif

#endif

#ifdef SUPPORT_UDP

#ifdef UDP_CFG_NON_BLOCKING

#line 46 "../../asp3_dcre/tinet/netinet/udp.cfg"
const unsigned_t TOPPERS_cfg_static_api_51 = 51;
#define UDP_OUTPUT_TASK	(<>)
#line 46 "../../asp3_dcre/tinet/netinet/udp.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_51 = (unsigned_t)(TA_HLNG);
#line 46 "../../asp3_dcre/tinet/netinet/udp.cfg"
const signed_t TOPPERS_cfg_valueof_itskpri_51 = (signed_t)(UDP_OUT_TASK_PRIORITY);
#line 46 "../../asp3_dcre/tinet/netinet/udp.cfg"
const unsigned_t TOPPERS_cfg_valueof_stksz_51 = (unsigned_t)(UDP_OUT_TASK_STACK_SIZE);

#line 57 "../../asp3_dcre/tinet/netinet/udp.cfg"
const unsigned_t TOPPERS_cfg_static_api_52 = 52;
#define SEM_UDP_POST_OUTPUT	(<>)
#line 57 "../../asp3_dcre/tinet/netinet/udp.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_52 = (unsigned_t)(TA_TPRI);
#line 57 "../../asp3_dcre/tinet/netinet/udp.cfg"
const unsigned_t TOPPERS_cfg_valueof_isemcnt_52 = (unsigned_t)(0);
#line 57 "../../asp3_dcre/tinet/netinet/udp.cfg"
const unsigned_t TOPPERS_cfg_valueof_maxsem_52 = (unsigned_t)(1);

#endif

#line 61 "../../asp3_dcre/tinet/netinet/udp.cfg"
const unsigned_t TOPPERS_cfg_static_api_53 = 53;
#define SEM_UDP_CEP	(<>)
#line 61 "../../asp3_dcre/tinet/netinet/udp.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_53 = (unsigned_t)(TA_TPRI);
#line 61 "../../asp3_dcre/tinet/netinet/udp.cfg"
const unsigned_t TOPPERS_cfg_valueof_isemcnt_53 = (unsigned_t)(1);
#line 61 "../../asp3_dcre/tinet/netinet/udp.cfg"
const unsigned_t TOPPERS_cfg_valueof_maxsem_53 = (unsigned_t)(1);

#endif

#ifdef _IP6_CFG

#line 42 "../../asp3_dcre/tinet/netinet6/ip6.cfg"
const unsigned_t TOPPERS_cfg_static_api_54 = 54;
#define SEM_ND6_CACHE	(<>)
#line 42 "../../asp3_dcre/tinet/netinet6/ip6.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_54 = (unsigned_t)(TA_TPRI);
#line 42 "../../asp3_dcre/tinet/netinet6/ip6.cfg"
const unsigned_t TOPPERS_cfg_valueof_isemcnt_54 = (unsigned_t)(1);
#line 42 "../../asp3_dcre/tinet/netinet6/ip6.cfg"
const unsigned_t TOPPERS_cfg_valueof_maxsem_54 = (unsigned_t)(1);

#if NUM_ND6_DEF_RTR_ENTRY > 0

#line 48 "../../asp3_dcre/tinet/netinet6/ip6.cfg"
const unsigned_t TOPPERS_cfg_static_api_55 = 55;
#define SEM_ND6_DEFRTRLIST	(<>)
#line 48 "../../asp3_dcre/tinet/netinet6/ip6.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_55 = (unsigned_t)(TA_TPRI);
#line 48 "../../asp3_dcre/tinet/netinet6/ip6.cfg"
const unsigned_t TOPPERS_cfg_valueof_isemcnt_55 = (unsigned_t)(1);
#line 48 "../../asp3_dcre/tinet/netinet6/ip6.cfg"
const unsigned_t TOPPERS_cfg_valueof_maxsem_55 = (unsigned_t)(1);

#endif

#ifdef IP6_CFG_FRAGMENT

#line 56 "../../asp3_dcre/tinet/netinet6/ip6.cfg"
const unsigned_t TOPPERS_cfg_static_api_56 = 56;
#define SEM_IP6_FRAG_QUEUE	(<>)
#line 56 "../../asp3_dcre/tinet/netinet6/ip6.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_56 = (unsigned_t)(TA_TPRI);
#line 56 "../../asp3_dcre/tinet/netinet6/ip6.cfg"
const unsigned_t TOPPERS_cfg_valueof_isemcnt_56 = (unsigned_t)(1);
#line 56 "../../asp3_dcre/tinet/netinet6/ip6.cfg"
const unsigned_t TOPPERS_cfg_valueof_maxsem_56 = (unsigned_t)(1);

#endif

#if NUM_IN6_ROUTE_ENTRY > 0

#line 64 "../../asp3_dcre/tinet/netinet6/ip6.cfg"
const unsigned_t TOPPERS_cfg_static_api_57 = 57;
#define SEM_IN6_ROUTING_TBL	(<>)
#line 64 "../../asp3_dcre/tinet/netinet6/ip6.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_57 = (unsigned_t)(TA_TPRI);
#line 64 "../../asp3_dcre/tinet/netinet6/ip6.cfg"
const unsigned_t TOPPERS_cfg_valueof_isemcnt_57 = (unsigned_t)(1);
#line 64 "../../asp3_dcre/tinet/netinet6/ip6.cfg"
const unsigned_t TOPPERS_cfg_valueof_maxsem_57 = (unsigned_t)(1);

#endif

#endif

#ifdef SUPPORT_INET4

#line 48 "../../ntshell/src/tinet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_58 = 58;
#define USR_TCP_REP1	(<>)

#line 49 "../../ntshell/src/tinet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_59 = 59;
#define USR_TCP_REP2	(<>)

#line 50 "../../ntshell/src/tinet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_60 = 60;
#define USR_TCP_REP3	(<>)

#line 51 "../../ntshell/src/tinet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_61 = 61;
#define USR_TCP_REP4	(<>)

#line 53 "../../ntshell/src/tinet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_62 = 62;
#define USR_TCP_CEP1	(<>)

#line 54 "../../ntshell/src/tinet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_63 = 63;
#define USR_TCP_CEP2	(<>)

#line 55 "../../ntshell/src/tinet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_64 = 64;
#define USR_TCP_CEP3	(<>)

#line 56 "../../ntshell/src/tinet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_65 = 65;
#define USR_TCP_CEP4	(<>)

#ifndef TOPPERS_GRSAKURA

#line 58 "../../ntshell/src/tinet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_66 = 66;
#define USR_TCP_CEP5	(<>)

#line 59 "../../ntshell/src/tinet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_67 = 67;
#define USR_TCP_CEP6	(<>)

#line 60 "../../ntshell/src/tinet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_68 = 68;
#define USR_TCP_CEP7	(<>)

#line 61 "../../ntshell/src/tinet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_69 = 69;
#define USR_TCP_CEP8	(<>)

#endif

#line 64 "../../ntshell/src/tinet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_70 = 70;
#define USR_UDP_CEP1	(<>)

#line 65 "../../ntshell/src/tinet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_71 = 71;
#define USR_UDP_CEP2	(<>)

#line 66 "../../ntshell/src/tinet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_72 = 72;
#define USR_UDP_CEP3	(<>)

#line 67 "../../ntshell/src/tinet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_73 = 73;
#define USR_UDP_CEP4	(<>)

#endif

#ifdef SUPPORT_INET6

#line 73 "../../ntshell/src/tinet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_74 = 74;
#define USR_TCP6_REP1	(<>)

#line 74 "../../ntshell/src/tinet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_75 = 75;
#define USR_TCP6_REP2	(<>)

#line 75 "../../ntshell/src/tinet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_76 = 76;
#define USR_TCP6_REP3	(<>)

#line 76 "../../ntshell/src/tinet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_77 = 77;
#define USR_TCP6_REP4	(<>)

#line 78 "../../ntshell/src/tinet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_78 = 78;
#define USR_TCP6_CEP1	(<>)

#line 79 "../../ntshell/src/tinet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_79 = 79;
#define USR_TCP6_CEP2	(<>)

#line 80 "../../ntshell/src/tinet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_80 = 80;
#define USR_TCP6_CEP3	(<>)

#line 81 "../../ntshell/src/tinet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_81 = 81;
#define USR_TCP6_CEP4	(<>)

#ifndef TOPPERS_GRSAKURA

#line 83 "../../ntshell/src/tinet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_82 = 82;
#define USR_TCP6_CEP5	(<>)

#line 84 "../../ntshell/src/tinet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_83 = 83;
#define USR_TCP6_CEP6	(<>)

#line 85 "../../ntshell/src/tinet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_84 = 84;
#define USR_TCP6_CEP7	(<>)

#line 86 "../../ntshell/src/tinet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_85 = 85;
#define USR_TCP6_CEP8	(<>)

#endif

#line 89 "../../ntshell/src/tinet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_86 = 86;
#define USR_UDP6_CEP1	(<>)

#line 90 "../../ntshell/src/tinet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_87 = 87;
#define USR_UDP6_CEP2	(<>)

#line 91 "../../ntshell/src/tinet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_88 = 88;
#define USR_UDP6_CEP3	(<>)

#line 92 "../../ntshell/src/tinet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_89 = 89;
#define USR_UDP6_CEP4	(<>)

#endif

#ifdef DHCP4_CLI_CFG

#line 43 "../../asp3_dcre/tinet/netapp/tinet_dhcp4_cli.cfg"
const unsigned_t TOPPERS_cfg_static_api_90 = 90;
#define UDP4_DHCP_CLI_CEPID	(<>)
#line 43 "../../asp3_dcre/tinet/netapp/tinet_dhcp4_cli.cfg"
const unsigned_t TOPPERS_cfg_valueof_udp4_cepatr_90 = (unsigned_t)(0);

#endif

#ifdef USE_RESOLVER

#line 46 "../../asp3_dcre/tinet/netapp/resolver_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_91 = 91;
#define MPF_RSLV_SRBUF	(<>)
#line 46 "../../asp3_dcre/tinet/netapp/resolver_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_mpfatr_91 = (unsigned_t)(TA_TFIFO);
#line 46 "../../asp3_dcre/tinet/netapp/resolver_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_blkcnt_91 = (unsigned_t)(NUM_MPF_RSLV_SRBUF);
#line 46 "../../asp3_dcre/tinet/netapp/resolver_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_blksz_91 = (unsigned_t)(DNS_UDP_MSG_LENGTH);

#endif

#ifdef USE_RESOLVER

#ifdef SUPPORT_INET6

#line 45 "../../asp3_dcre/tinet/netapp/tinet_resolver.cfg"
const unsigned_t TOPPERS_cfg_static_api_92 = 92;
#define UDP6_RESOLVER_CEPID	(<>)
#line 45 "../../asp3_dcre/tinet/netapp/tinet_resolver.cfg"
const unsigned_t TOPPERS_cfg_valueof_udp6_cepatr_92 = (unsigned_t)(0);

#endif

#ifdef SUPPORT_INET4

#line 55 "../../asp3_dcre/tinet/netapp/tinet_resolver.cfg"
const unsigned_t TOPPERS_cfg_static_api_93 = 93;
#define UDP4_RESOLVER_CEPID	(<>)
#line 55 "../../asp3_dcre/tinet/netapp/tinet_resolver.cfg"
const unsigned_t TOPPERS_cfg_valueof_udp4_cepatr_93 = (unsigned_t)(0);

#endif

#endif

#line 41 "../../ntshell/src/tinet_ntp_cli.cfg"
const unsigned_t TOPPERS_cfg_static_api_94 = 94;
#define NTP_CLI_CEPID	(<>)
#line 41 "../../ntshell/src/tinet_ntp_cli.cfg"
const unsigned_t TOPPERS_cfg_valueof_udp4_cepatr_94 = (unsigned_t)(0);

#line 44 "../../ntshell/src/net_misc.cfg"
const unsigned_t TOPPERS_cfg_static_api_95 = 95;
#define SEM_DHCP4_CLI_LOCK	(<>)
#line 44 "../../ntshell/src/net_misc.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_95 = (unsigned_t)(TA_TPRI);
#line 44 "../../ntshell/src/net_misc.cfg"
const unsigned_t TOPPERS_cfg_valueof_isemcnt_95 = (unsigned_t)(1);
#line 44 "../../ntshell/src/net_misc.cfg"
const unsigned_t TOPPERS_cfg_valueof_maxsem_95 = (unsigned_t)(1);

#line 48 "../../ntshell/src/net_misc.cfg"
const unsigned_t TOPPERS_cfg_static_api_96 = 96;
#define MPF_DHCP4_CLI_MSG	(<>)
#line 48 "../../ntshell/src/net_misc.cfg"
const unsigned_t TOPPERS_cfg_valueof_mpfatr_96 = (unsigned_t)(TA_TFIFO);
#line 48 "../../ntshell/src/net_misc.cfg"
const unsigned_t TOPPERS_cfg_valueof_blkcnt_96 = (unsigned_t)(NUM_MPF_DHCP4_CLI_MSG);
#line 48 "../../ntshell/src/net_misc.cfg"
const unsigned_t TOPPERS_cfg_valueof_blksz_96 = (unsigned_t)(sizeof(T_DHCP4_CLI_MSG));

#line 58 "../../ntshell/src/net_misc.cfg"
const unsigned_t TOPPERS_cfg_static_api_97 = 97;
#define NET_MISC_TASK	(<>)
#line 58 "../../ntshell/src/net_misc.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_97 = (unsigned_t)(TA_HLNG|TA_ACT);
#line 58 "../../ntshell/src/net_misc.cfg"
const signed_t TOPPERS_cfg_valueof_itskpri_97 = (signed_t)(NET_MISC_MAIN_PRIORITY);
#line 58 "../../ntshell/src/net_misc.cfg"
const unsigned_t TOPPERS_cfg_valueof_stksz_97 = (unsigned_t)(NET_MISC_STACK_SIZE);

#line 40 "../../ntshell/fatfs/ffarch.cfg"
const unsigned_t TOPPERS_cfg_static_api_98 = 98;
#define FFARCH_TASK	(<>)
#line 40 "../../ntshell/fatfs/ffarch.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_98 = (unsigned_t)(TA_NULL);
#line 40 "../../ntshell/fatfs/ffarch.cfg"
const signed_t TOPPERS_cfg_valueof_itskpri_98 = (signed_t)(FFARCH_PRIORITY);
#line 40 "../../ntshell/fatfs/ffarch.cfg"
const unsigned_t TOPPERS_cfg_valueof_stksz_98 = (unsigned_t)(FFARCH_STACK_SIZE);

#line 41 "../../ntshell/fatfs/ffarch.cfg"
const unsigned_t TOPPERS_cfg_static_api_99 = 99;
#define SDFS_CYC	(<>)
#line 41 "../../ntshell/fatfs/ffarch.cfg"
const unsigned_t TOPPERS_cfg_valueof_cycatr_99 = (unsigned_t)(TA_NULL);
#line 41 "../../ntshell/fatfs/ffarch.cfg"
const unsigned_t TOPPERS_cfg_valueof_nfymode_99 = (unsigned_t)(TNFY_HANDLER);
#line 41 "../../ntshell/fatfs/ffarch.cfg"
const unsigned_t TOPPERS_cfg_valueof_cyctim_99 = (unsigned_t)(1000000);
#line 41 "../../ntshell/fatfs/ffarch.cfg"
const unsigned_t TOPPERS_cfg_valueof_cycphs_99 = (unsigned_t)(0);

#line 43 "../../ntshell/fatfs/ffarch.cfg"
const unsigned_t TOPPERS_cfg_static_api_100 = 100;
#define SEM_FILESYSTEM	(<>)
#line 43 "../../ntshell/fatfs/ffarch.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_100 = (unsigned_t)(TA_TPRI);
#line 43 "../../ntshell/fatfs/ffarch.cfg"
const unsigned_t TOPPERS_cfg_valueof_isemcnt_100 = (unsigned_t)(1);
#line 43 "../../ntshell/fatfs/ffarch.cfg"
const unsigned_t TOPPERS_cfg_valueof_maxsem_100 = (unsigned_t)(1);

#ifdef IF_ETHER_BTUSB

#line 9 "../../asp3_dcre/../usbhost/src/usb_hbth.cfg"
const unsigned_t TOPPERS_cfg_static_api_101 = 101;
#line 9 "../../asp3_dcre/../usbhost/src/usb_hbth.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhno_101 = (unsigned_t)(INHNO_USB);
#line 9 "../../asp3_dcre/../usbhost/src/usb_hbth.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhatr_101 = (unsigned_t)(TA_NULL);

#line 10 "../../asp3_dcre/../usbhost/src/usb_hbth.cfg"
const unsigned_t TOPPERS_cfg_static_api_102 = 102;
#line 10 "../../asp3_dcre/../usbhost/src/usb_hbth.cfg"
const unsigned_t TOPPERS_cfg_valueof_intno_102 = (unsigned_t)(INTNO_USB);
#line 10 "../../asp3_dcre/../usbhost/src/usb_hbth.cfg"
const unsigned_t TOPPERS_cfg_valueof_intatr_102 = (unsigned_t)(INTATR_USB);
#line 10 "../../asp3_dcre/../usbhost/src/usb_hbth.cfg"
const signed_t TOPPERS_cfg_valueof_intpri_102 = (signed_t)(INTPRI_USB);

#line 12 "../../asp3_dcre/../usbhost/src/usb_hbth.cfg"
const unsigned_t TOPPERS_cfg_static_api_103 = 103;
#define USBHOST_TASK	(<>)
#line 12 "../../asp3_dcre/../usbhost/src/usb_hbth.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_103 = (unsigned_t)(TA_FPU);
#line 12 "../../asp3_dcre/../usbhost/src/usb_hbth.cfg"
const signed_t TOPPERS_cfg_valueof_itskpri_103 = (signed_t)(USBHOST_PRIORITY);
#line 12 "../../asp3_dcre/../usbhost/src/usb_hbth.cfg"
const unsigned_t TOPPERS_cfg_valueof_stksz_103 = (unsigned_t)(USBHOST_STACK_SIZE);

#endif

#line 43 "../../ntshell/src/ntshell_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_104 = 104;
#line 43 "../../ntshell/src/ntshell_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_iniatr_104 = (unsigned_t)(TA_NULL);

#line 45 "../../ntshell/src/ntshell_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_105 = 105;
#define NTSHELL_TASK	(<>)
#line 45 "../../ntshell/src/ntshell_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_105 = (unsigned_t)(TA_FPU);
#line 45 "../../ntshell/src/ntshell_main.cfg"
const signed_t TOPPERS_cfg_valueof_itskpri_105 = (signed_t)(NTSHELL_PRIORITY);
#line 45 "../../ntshell/src/ntshell_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_stksz_105 = (unsigned_t)(NTSHELL_STACK_SIZE);

#line 46 "../../ntshell/src/ntshell_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_106 = 106;
#define FLG_SELECT_WAIT	(<>)
#line 46 "../../ntshell/src/ntshell_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_flgatr_106 = (unsigned_t)(TA_WMUL);
#line 46 "../../ntshell/src/ntshell_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_iflgptn_106 = (unsigned_t)(0x00);

#line 47 "../../ntshell/src/ntshell_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_107 = 107;
#define SEM_FILEDESC	(<>)
#line 47 "../../ntshell/src/ntshell_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_107 = (unsigned_t)(TA_TPRI);
#line 47 "../../ntshell/src/ntshell_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_isemcnt_107 = (unsigned_t)(1);
#line 47 "../../ntshell/src/ntshell_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_maxsem_107 = (unsigned_t)(1);

#ifndef ECHONET_USE_MALLOC

#line 49 "../../ntshell/echonet/echonet_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_108 = 108;
#define ECHONET_MEMPOOL	(<>)
#line 49 "../../ntshell/echonet/echonet_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_mpfatr_108 = (unsigned_t)(TA_TFIFO);
#line 49 "../../ntshell/echonet/echonet_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_blkcnt_108 = (unsigned_t)(NUM_ECHONET_MEMPOOL_BLOCK);
#line 49 "../../ntshell/echonet/echonet_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_blksz_108 = (unsigned_t)(256);

#endif

#line 55 "../../ntshell/echonet/echonet_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_109 = 109;
#define ECHONET_API_DATAQUEUE	(<>)
#line 55 "../../ntshell/echonet/echonet_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_dtqatr_109 = (unsigned_t)(TA_TFIFO);
#line 55 "../../ntshell/echonet/echonet_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_dtqcnt_109 = (unsigned_t)(ECHONET_API_DATAQUEUE_COUNT);

#line 60 "../../ntshell/echonet/echonet_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_110 = 110;
#define ECHONET_SVC_DATAQUEUE	(<>)
#line 60 "../../ntshell/echonet/echonet_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_dtqatr_110 = (unsigned_t)(TA_TFIFO);
#line 60 "../../ntshell/echonet/echonet_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_dtqcnt_110 = (unsigned_t)(ECHONET_SVC_DATAQUEUE_COUNT);

#line 65 "../../ntshell/echonet/echonet_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_111 = 111;
#define ECHONET_SVC_TASK	(<>)
#line 65 "../../ntshell/echonet/echonet_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_111 = (unsigned_t)(TA_HLNG);
#line 65 "../../ntshell/echonet/echonet_asp.cfg"
const signed_t TOPPERS_cfg_valueof_itskpri_111 = (signed_t)(ECHONET_TASK_PRIORITY);
#line 65 "../../ntshell/echonet/echonet_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_stksz_111 = (unsigned_t)(ECHONET_TASK_STACK_SIZE);

#line 70 "../../ntshell/echonet/echonet_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_112 = 112;
#define ECHONET_UDP_DATAQUEUE	(<>)
#line 70 "../../ntshell/echonet/echonet_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_dtqatr_112 = (unsigned_t)(TA_TFIFO);
#line 70 "../../ntshell/echonet/echonet_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_dtqcnt_112 = (unsigned_t)(ECHONET_UDP_DATAQUEUE_COUNT);

#line 75 "../../ntshell/echonet/echonet_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_113 = 113;
#define ECHONET_UDP_TASK	(<>)
#line 75 "../../ntshell/echonet/echonet_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_113 = (unsigned_t)(TA_HLNG);
#line 75 "../../ntshell/echonet/echonet_asp.cfg"
const signed_t TOPPERS_cfg_valueof_itskpri_113 = (signed_t)(ECHONET_UDP_TASK_PRIORITY);
#line 75 "../../ntshell/echonet/echonet_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_stksz_113 = (unsigned_t)(ECHONET_UDP_TASK_STACK_SIZE);

#ifdef SUPPORT_INET4

#line 48 "../../ntshell/echonet/echonet_udp.cfg"
const unsigned_t TOPPERS_cfg_static_api_114 = 114;
#define ECHONET_UDP_CEPID	(<>)
#line 48 "../../ntshell/echonet/echonet_udp.cfg"
const unsigned_t TOPPERS_cfg_valueof_udp4_cepatr_114 = (unsigned_t)(TA_ACT);

#endif

#ifdef SUPPORT_INET6

#line 54 "../../ntshell/echonet/echonet_udp.cfg"
const unsigned_t TOPPERS_cfg_static_api_115 = 115;
#define ECHONET_UDP6_CEPID	(<>)
#line 54 "../../ntshell/echonet/echonet_udp.cfg"
const unsigned_t TOPPERS_cfg_valueof_udp6_cepatr_115 = (unsigned_t)(TA_NULL);

#endif

#line 12 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_116 = 116;
#define LOCAL_NODE_EOBJ	(<>)
#line 12 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_eobjatr_116 = (unsigned_t)(EOBJ_LOCAL_NODE);
#line 12 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_eojx1_116 = (unsigned_t)(EOJ_X1_PROFILE);
#line 12 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_eojx2_116 = (unsigned_t)(EOJ_X2_NODE_PROFILE);
#line 12 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_eojx3_116 = (unsigned_t)(EOJ_X3_NODE_PROFILE);

#line 14 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_117 = 117;
#line 14 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_eprpcd_117 = (unsigned_t)(0x80);
#line 14 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_eprpatr_117 = (unsigned_t)(EPC_RULE_SET | EPC_RULE_GET);
#line 14 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_eprpsz_117 = (unsigned_t)(1);

#line 16 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_118 = 118;
#line 16 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_eprpcd_118 = (unsigned_t)(0x8A);
#line 16 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_eprpatr_118 = (unsigned_t)(EPC_RULE_GET);
#line 16 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_eprpsz_118 = (unsigned_t)(3);

#line 18 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_119 = 119;
#line 18 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_eprpcd_119 = (unsigned_t)(0x82);
#line 18 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_eprpatr_119 = (unsigned_t)(EPC_RULE_GET);
#line 18 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_eprpsz_119 = (unsigned_t)(4);

#line 20 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_120 = 120;
#line 20 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_eprpcd_120 = (unsigned_t)(0x83);
#line 20 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_eprpatr_120 = (unsigned_t)(EPC_RULE_GET);
#line 20 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_eprpsz_120 = (unsigned_t)(17);

#line 26 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_121 = 121;
#define GENERAL_LIGHTING_CLASS_EOBJ	(<>)
#line 26 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_eobjatr_121 = (unsigned_t)(EOBJ_DEVICE);
#line 26 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_eojx1_121 = (unsigned_t)(EOJ_X1_AMENITY);
#line 26 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_eojx2_121 = (unsigned_t)(EOJ_X2_GENERAL_LIGHTING_CLASS);
#line 26 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_eojx3_121 = (unsigned_t)(EOJ_X3_GENERAL_LIGHTING_CLASS);

#line 28 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_122 = 122;
#line 28 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_eprpcd_122 = (unsigned_t)(0x80);
#line 28 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_eprpatr_122 = (unsigned_t)(EPC_RULE_SET | EPC_RULE_GET | EPC_ANNOUNCE);
#line 28 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_eprpsz_122 = (unsigned_t)(1);

#line 30 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_123 = 123;
#line 30 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_eprpcd_123 = (unsigned_t)(0xB6);
#line 30 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_eprpatr_123 = (unsigned_t)(EPC_RULE_SET | EPC_RULE_GET);
#line 30 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_eprpsz_123 = (unsigned_t)(1);

#line 32 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_124 = 124;
#line 32 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_eprpcd_124 = (unsigned_t)(0x81);
#line 32 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_eprpatr_124 = (unsigned_t)(EPC_RULE_SET | EPC_RULE_GET | EPC_ANNOUNCE);
#line 32 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_eprpsz_124 = (unsigned_t)(1);

#line 34 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_125 = 125;
#line 34 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_eprpcd_125 = (unsigned_t)(0x82);
#line 34 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_eprpatr_125 = (unsigned_t)(EPC_RULE_GET);
#line 34 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_eprpsz_125 = (unsigned_t)(4);

#line 36 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_126 = 126;
#line 36 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_eprpcd_126 = (unsigned_t)(0x88);
#line 36 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_eprpatr_126 = (unsigned_t)(EPC_RULE_GET | EPC_ANNOUNCE);
#line 36 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_eprpsz_126 = (unsigned_t)(1);

#line 38 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_static_api_127 = 127;
#line 38 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_eprpcd_127 = (unsigned_t)(0x8A);
#line 38 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_eprpatr_127 = (unsigned_t)(EPC_RULE_GET);
#line 38 "../src/echonet_main.cfg"
const unsigned_t TOPPERS_cfg_valueof_eprpsz_127 = (unsigned_t)(3);

#line 86 "../src/main.cfg"
const unsigned_t TOPPERS_cfg_static_api_128 = 128;
#define MAIN_TASK	(<>)
#line 86 "../src/main.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_128 = (unsigned_t)(TA_NULL);
#line 86 "../src/main.cfg"
const signed_t TOPPERS_cfg_valueof_itskpri_128 = (signed_t)(MAIN_PRIORITY);
#line 86 "../src/main.cfg"
const unsigned_t TOPPERS_cfg_valueof_stksz_128 = (unsigned_t)(MAIN_STACK_SIZE);

#line 87 "../src/main.cfg"
const unsigned_t TOPPERS_cfg_static_api_129 = 129;
#define MAIN_DATAQUEUE	(<>)
#line 87 "../src/main.cfg"
const unsigned_t TOPPERS_cfg_valueof_dtqatr_129 = (unsigned_t)(TA_TFIFO);
#line 87 "../src/main.cfg"
const unsigned_t TOPPERS_cfg_valueof_dtqcnt_129 = (unsigned_t)(NUM_MAIN_DATAQUEUE);

