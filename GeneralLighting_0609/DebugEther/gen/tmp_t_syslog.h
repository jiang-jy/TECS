/*  1 "./gen/tmp_C_src.c" */
/*  1 "<built-in>" */
/*  1 "<command-line>" */
/*  1 "./gen/tmp_C_src.c" */
/*  34 "./gen/tmp_C_src.c" */
typedef struct { int dummy; } va_list;

/*  1 "../../asp3_dcre/include/t_syslog.h" 1 */
/*  69 "../../asp3_dcre/include/t_syslog.h" */
/*  1 "../../asp3_dcre/include/t_stddef.h" 1 */
/*  65 "../../asp3_dcre/include/t_stddef.h" */
/*  1 "../../asp3_dcre/target/gr_peach_gcc/target_stddef.h" 1 */
/*  61 "../../asp3_dcre/target/gr_peach_gcc/target_stddef.h" */
/*  1 "../../musl-1.1.18/include/stdint.h" 1 */
/*  20 "../../musl-1.1.18/include/stdint.h" */
/*  1 "../../musl-1.1.18/include/bits/alltypes.h" 1 */
/*  93 "../../musl-1.1.18/include/bits/alltypes.h" */
typedef unsigned int uintptr_t;
/*  108 "../../musl-1.1.18/include/bits/alltypes.h" */
typedef int intptr_t;
/*  124 "../../musl-1.1.18/include/bits/alltypes.h" */
typedef signed char int8_t;




typedef short int16_t;




typedef int int32_t;




typedef long long int64_t;




typedef long long intmax_t;




typedef unsigned char uint8_t;




typedef unsigned short uint16_t;




typedef unsigned int uint32_t;




typedef unsigned long long uint64_t;
/*  174 "../../musl-1.1.18/include/bits/alltypes.h" */
typedef unsigned long long uintmax_t;
/*  21 "../../musl-1.1.18/include/stdint.h" 2 */

typedef int8_t int_fast8_t;
typedef int64_t int_fast64_t;

typedef int8_t int_least8_t;
typedef int16_t int_least16_t;
typedef int32_t int_least32_t;
typedef int64_t int_least64_t;

typedef uint8_t uint_fast8_t;
typedef uint64_t uint_fast64_t;

typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;
typedef uint32_t uint_least32_t;
typedef uint64_t uint_least64_t;
/*  95 "../../musl-1.1.18/include/stdint.h" */
/*  1 "../../musl-1.1.18/include/bits/stdint.h" 1 */
typedef int32_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint32_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
/*  96 "../../musl-1.1.18/include/stdint.h" 2 */
/*  62 "../../asp3_dcre/target/gr_peach_gcc/target_stddef.h" 2 */



/*  1 "../../asp3_dcre/arch/gcc/tool_stddef.h" 1 */
/*  81 "../../asp3_dcre/arch/gcc/tool_stddef.h" */
/*  1 "../../musl-1.1.18/include/stddef.h" 1 */
/*  17 "../../musl-1.1.18/include/stddef.h" */
/*  1 "../../musl-1.1.18/include/bits/alltypes.h" 1 */
/*  18 "../../musl-1.1.18/include/bits/alltypes.h" */
typedef unsigned wchar_t;
/*  36 "../../musl-1.1.18/include/bits/alltypes.h" */
typedef struct { long long __ll; long double __ld; } max_align_t;
/*  88 "../../musl-1.1.18/include/bits/alltypes.h" */
typedef unsigned int size_t;
/*  98 "../../musl-1.1.18/include/bits/alltypes.h" */
typedef int ptrdiff_t;
/*  18 "../../musl-1.1.18/include/stddef.h" 2 */
/*  82 "../../asp3_dcre/arch/gcc/tool_stddef.h" 2 */
/*  1 "../../musl-1.1.18/include/limits.h" 1 */



/*  1 "../../musl-1.1.18/include/features.h" 1 */
/*  5 "../../musl-1.1.18/include/limits.h" 2 */



/*  1 "../../musl-1.1.18/include/bits/limits.h" 1 */
/*  9 "../../musl-1.1.18/include/limits.h" 2 */
/*  83 "../../asp3_dcre/arch/gcc/tool_stddef.h" 2 */
/*  191 "../../asp3_dcre/arch/gcc/tool_stddef.h" */
typedef float float32_t;
typedef double double64_t;
/*  66 "../../asp3_dcre/target/gr_peach_gcc/target_stddef.h" 2 */




/*  1 "../../asp3_dcre/arch/arm_gcc/rza1/chip_stddef.h" 1 */
/*  68 "../../asp3_dcre/arch/arm_gcc/rza1/chip_stddef.h" */
/*  1 "../../asp3_dcre/arch/arm_gcc/common/core_stddef.h" 1 */
/*  69 "../../asp3_dcre/arch/arm_gcc/rza1/chip_stddef.h" 2 */
/*  71 "../../asp3_dcre/target/gr_peach_gcc/target_stddef.h" 2 */






static inline void
TOPPERS_assert_abort(void)
{



 __asm__ volatile("bkpt #0");
}
/*  66 "../../asp3_dcre/include/t_stddef.h" 2 */
/*  84 "../../asp3_dcre/include/t_stddef.h" */
struct TOPPERS_dummy_t { int TOPPERS_dummy_field; };
typedef void (*TOPPERS_fp_t)(struct TOPPERS_dummy_t);






typedef int bool_t;

typedef signed int int_t;
typedef unsigned int uint_t;

typedef signed long long_t;
typedef unsigned long ulong_t;

typedef int_t FN;
typedef int_t ER;
typedef int_t ID;
typedef uint_t ATR;
typedef uint_t STAT;
typedef uint_t MODE;
typedef int_t PRI;
typedef uint32_t TMO;
typedef uint32_t RELTIM;

typedef uint64_t SYSTIM;



typedef uint32_t PRCTIM;
typedef uint32_t HRTCNT;

typedef TOPPERS_fp_t FP;

typedef int_t ER_BOOL;
typedef int_t ER_ID;
typedef int_t ER_UINT;

typedef uintptr_t MB_T;

typedef uint32_t ACPTN;
typedef struct acvct {
 ACPTN acptn1;
 ACPTN acptn2;
 ACPTN acptn3;
 ACPTN acptn4;
} ACVCT;
/*  70 "../../asp3_dcre/include/t_syslog.h" 2 */
/*  119 "../../asp3_dcre/include/t_syslog.h" */
typedef struct {
 uint_t logtype;
 HRTCNT logtim;
 intptr_t logpar[6];
} SYSLOG;
/*  134 "../../asp3_dcre/include/t_syslog.h" */
typedef struct t_syslog_rlog {
 uint_t count;
 uint_t lost;
 uint_t logmask;
 uint_t lowmask;
} T_SYSLOG_RLOG;
/*  152 "../../asp3_dcre/include/t_syslog.h" */
extern ER tSysLog_eSysLog_write(uint_t prio, const SYSLOG *p_syslog) ;

static inline void
_syslog_0(uint_t prio, uint_t type)
{
 SYSLOG logbuf;

 logbuf.logtype = type;
 (void) tSysLog_eSysLog_write(prio, &logbuf);
}

static inline void
_syslog_1(uint_t prio, uint_t type, intptr_t arg1)
{
 SYSLOG logbuf;

 logbuf.logtype = type;
 logbuf.logpar[0] = arg1;
 (void) tSysLog_eSysLog_write(prio, &logbuf);
}

static inline void
_syslog_2(uint_t prio, uint_t type, intptr_t arg1, intptr_t arg2)
{
 SYSLOG logbuf;

 logbuf.logtype = type;
 logbuf.logpar[0] = arg1;
 logbuf.logpar[1] = arg2;
 (void) tSysLog_eSysLog_write(prio, &logbuf);
}

static inline void
_syslog_3(uint_t prio, uint_t type, intptr_t arg1, intptr_t arg2, intptr_t arg3)
{
 SYSLOG logbuf;

 logbuf.logtype = type;
 logbuf.logpar[0] = arg1;
 logbuf.logpar[1] = arg2;
 logbuf.logpar[2] = arg3;
 (void) tSysLog_eSysLog_write(prio, &logbuf);
}

static inline void
_syslog_4(uint_t prio, uint_t type, intptr_t arg1, intptr_t arg2,
           intptr_t arg3, intptr_t arg4)
{
 SYSLOG logbuf;

 logbuf.logtype = type;
 logbuf.logpar[0] = arg1;
 logbuf.logpar[1] = arg2;
 logbuf.logpar[2] = arg3;
 logbuf.logpar[3] = arg4;
 (void) tSysLog_eSysLog_write(prio, &logbuf);
}

static inline void
_syslog_5(uint_t prio, uint_t type, intptr_t arg1, intptr_t arg2,
        intptr_t arg3, intptr_t arg4, intptr_t arg5)
{
 SYSLOG logbuf;

 logbuf.logtype = type;
 logbuf.logpar[0] = arg1;
 logbuf.logpar[1] = arg2;
 logbuf.logpar[2] = arg3;
 logbuf.logpar[3] = arg4;
 logbuf.logpar[4] = arg5;
 (void) tSysLog_eSysLog_write(prio, &logbuf);
}

static inline void
_syslog_6(uint_t prio, uint_t type, intptr_t arg1, intptr_t arg2,
     intptr_t arg3, intptr_t arg4, intptr_t arg5, intptr_t arg6)
{
 SYSLOG logbuf;

 logbuf.logtype = type;
 logbuf.logpar[0] = arg1;
 logbuf.logpar[1] = arg2;
 logbuf.logpar[2] = arg3;
 logbuf.logpar[3] = arg4;
 logbuf.logpar[4] = arg5;
 logbuf.logpar[5] = arg6;
 (void) tSysLog_eSysLog_write(prio, &logbuf);
}




extern void syslog(uint_t prio, const char *format, ...) ;
/*  36 "./gen/tmp_C_src.c" 2 */
