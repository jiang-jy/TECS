/*  1 "./gen/tmp_C_src.c" */
/*  1 "<built-in>" */
/*  1 "<command-line>" */
/*  1 "./gen/tmp_C_src.c" */
/*  34 "./gen/tmp_C_src.c" */
typedef struct { int dummy; } va_list;

/*  1 "../../asp3_dcre/target/gr_peach_gcc/target_syssvc.h" 1 */
/*  54 "../../asp3_dcre/target/gr_peach_gcc/target_syssvc.h" */
/*  1 "../../asp3_dcre/target/gr_peach_gcc/gr_peach.h" 1 */
/*  47 "../../asp3_dcre/target/gr_peach_gcc/gr_peach.h" */
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
/*  48 "../../asp3_dcre/target/gr_peach_gcc/gr_peach.h" 2 */
/*  73 "../../asp3_dcre/target/gr_peach_gcc/gr_peach.h" */
extern void gr_peach_set_led(uint_t led, uint_t set);
/*  55 "../../asp3_dcre/target/gr_peach_gcc/target_syssvc.h" 2 */
/*  66 "../../asp3_dcre/target/gr_peach_gcc/target_syssvc.h" */
/*  1 "../../asp3_dcre/arch/arm_gcc/common/core_syssvc.h" 1 */
/*  53 "../../asp3_dcre/arch/arm_gcc/common/core_syssvc.h" */
/*  1 "../../asp3_dcre/arch/arm_gcc/common/arm.h" 1 */
/*  278 "../../asp3_dcre/arch/arm_gcc/common/arm.h" */
static inline void
arm_set_high_vectors(void)
{
 uint32_t reg;

 CP15_READ_SCTLR(reg);
 reg |= (0x00002000U);
 CP15_WRITE_SCTLR(reg);
}




static inline void
arm_set_low_vectors(void)
{
 uint32_t reg;

 CP15_READ_SCTLR(reg);
 reg &= ~(0x00002000U);
 CP15_WRITE_SCTLR(reg);
}




static inline void
arm_enable_bp(void)
{
 uint32_t reg;

 CP15_READ_SCTLR(reg);
 reg |= (0x00000800U);
 CP15_WRITE_SCTLR(reg);
}




static inline void
arm_disable_bp(void)
{
 uint32_t reg;

 CP15_READ_SCTLR(reg);
 reg &= ~(0x00000800U);
 CP15_WRITE_SCTLR(reg);
}
/*  335 "../../asp3_dcre/arch/arm_gcc/common/arm.h" */
static inline uint32_t
arm_prc_index(void)
{
 uint32_t reg;

 CP15_READ_MPIDR(reg);
 return(reg & 0xffU);
}
/*  353 "../../asp3_dcre/arch/arm_gcc/common/arm.h" */
extern void arm_enable_icache(void);
extern void arm_disable_icache(void);
extern void arm_enable_dcache(void);
extern void arm_disable_dcache(void);




static inline void
arm_enable_cache(void)
{
 arm_enable_icache();
 arm_enable_dcache();
}




static inline void
arm_disable_cache(void)
{
 arm_disable_icache();
 arm_disable_dcache();
}
/*  389 "../../asp3_dcre/arch/arm_gcc/common/arm.h" */
extern void armv7_invalidate_dcache(void);
extern void armv7_clean_and_invalidate_dcache(void);





static inline void
arm_invalidate_dcache(void)
{




 armv7_invalidate_dcache();

}




static inline void
arm_clean_and_invalidate_dcache(void)
{






 armv7_clean_and_invalidate_dcache();

}




static inline void
arm_invalidate_icache(void)
{
 CP15_INVALIDATE_ICACHE();
}




static inline void
arm_invalidate_bp(void)
{
 CP15_INVALIDATE_BP();
 data_sync_barrier();
 inst_sync_barrier();
}




static inline void
arm_invalidate_tlb(void)
{
 CP15_INVALIDATE_TLB();
 data_sync_barrier();
}
/*  54 "../../asp3_dcre/arch/arm_gcc/common/core_syssvc.h" 2 */
/*  67 "../../asp3_dcre/target/gr_peach_gcc/target_syssvc.h" 2 */
/*  36 "./gen/tmp_C_src.c" 2 */
