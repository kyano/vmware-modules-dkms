/*********************************************************
 * Copyright (C) 1998-2015 VMware, Inc. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation version 2 and no later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 *
 *********************************************************/

/* 
 * x86msr.h --
 *
 *      MSR number definitions.
 */

#ifndef _X86MSR_H_
#define _X86MSR_H_
#define INCLUDE_ALLOW_USERLEVEL
#define INCLUDE_ALLOW_VMX

#define INCLUDE_ALLOW_VMKERNEL
#define INCLUDE_ALLOW_MODULE
#define INCLUDE_ALLOW_DISTRIBUTE
#define INCLUDE_ALLOW_VMK_MODULE
#define INCLUDE_ALLOW_VMCORE
#define INCLUDE_ALLOW_VMMON
#include "includeCheck.h"

#include "vm_basic_types.h"
#include "community_source.h"

/*
 * Results of calling rdmsr(msrNum) on all logical processors.
 */
#ifdef _MSC_VER
#pragma warning (disable :4200) // non-std extension: zero-sized array in struct
#endif

typedef
#include "vmware_pack_begin.h"
struct MSRReply {
   /*
    * Unique host logical CPU identifier. It does not change across queries, so
    * we use it to correlate the replies of multiple queries.
    */
   uint64 tag;              // OUT

   uint64 msrVal;           // OUT

   uint8  implemented;      // OUT

   uint8  _pad[7];
}
#include "vmware_pack_end.h"
MSRReply;

typedef
#include "vmware_pack_begin.h"
struct MSRQuery {
   uint32 msrNum;           // IN
   uint32 numLogicalCPUs;   // IN/OUT
   MSRReply logicalCPUs[0]; // OUT
}
#include "vmware_pack_end.h"
MSRQuery;

#define MSR_TSC               0x00000010
#define MSR_PLATFORM_ID       0x00000017
#define MSR_APIC_BASE         0x0000001b
#define MSR_SMI_COUNT         0x00000034 // Intel Nehalem Family
#define MSR_FEATCTL           0x0000003a
#define MSR_TSC_ADJUST        0x0000003b
#define MSR_BIOS_UPDT_TRIG    0x00000079
#define MSR_BIOS_SIGN_ID      0x0000008b
#define MSR_PERFCTR0          0x000000c1
#define MSR_PERFCTR1          0x000000c2
#define MSR_PLATFORM_INFO     0x000000ce // Intel Nehalem Family
#define MSR_MTRR_CAP          0x000000fe
#define MSR_L2CFG             0x0000011e
#define MSR_SYSENTER_CS       0x00000174
#define MSR_SYSENTER_ESP      0x00000175
#define MSR_SYSENTER_EIP      0x00000176
#define MSR_MCG_CAP           0x00000179
#define MSR_MCG_STATUS        0x0000017a
#define MSR_MCG_CTL           0x0000017b
#define MSR_EVNTSEL0          0x00000186
#define MSR_EVNTSEL1          0x00000187
#define MSR_FLEX_RATIO        0x00000194 // Intel Nehalem Family
#define MSR_CLOCK_MODULATION  0x0000019a
#define MSR_MISC_ENABLE       0x000001a0
#define MSR_DEBUGCTL          0x000001d9
#define MSR_TSC_DEADLINE      0x000006e0
#define MSR_EFER              0xc0000080
#define MSR_FSBASE            0xc0000100
#define MSR_GSBASE            0xc0000101
#define MSR_KERNELGSBASE      0xc0000102
#define MSR_TSC_AUX           0xc0000103
#define MSR_BD_TSC_RATIO      0xc0000104

#define MSR_MISC_FEATURES_ENABLES            0x140

/* Intel Core Architecture and later: use only architected counters. */
#define IA32_MSR_PERF_CAPABILITIES                0x345
#define MSR_PERF_CAPABILITIES_LBRFMT_SHIFT        0
#define MSR_PERF_CAPABILITIES_LBRFMT_MASK         0x3f
#define MSR_PERF_CAPABILITIES_PEBSTRAP            (1u << 6)
#define MSR_PERF_CAPABILITIES_PEBSSAVEARCHREGS    (1u << 7)
#define MSR_PERF_CAPABILITIES_PEBSRECORDFMT_SHIFT 8
#define MSR_PERF_CAPABILITIES_PEBSRECORDFMT_MASK  0xf
#define MSR_PERF_CAPABILITIES_FREEZE_WHILE_SMM    (1u << 12)
#define MSR_PERF_CAPABILITIES_FULL_WIDTH_WRITES   (1u << 13)

#define IA32_MSR_PEBS_ENABLE                      0x3f1

typedef enum {
   SL_PMC_FLAGS_NONE             = 0x00, /* No flags.                      */
   SL_PMC_FLAGS_LBR_VA32         = 0x01, /* LBR format: 32-bit VA.         */
   SL_PMC_FLAGS_LBR_LA64         = 0x02, /* LBR format: 64-bit LA.         */
   SL_PMC_FLAGS_LBR_VA64         = 0x04, /* LBR format: 64-bit VA.         */
   SL_PMC_FLAGS_LBR_PACKED_VA32  = 0x08, /* LBR format: 2x32-bit VAs.      */
} StateLoggerPMCFlags;

#define MSR_MTRR_BASE0        0x00000200
#define MSR_MTRR_MASK0        0x00000201
#define MSR_MTRR_BASE1        0x00000202
#define MSR_MTRR_MASK1        0x00000203
#define MSR_MTRR_BASE2        0x00000204
#define MSR_MTRR_MASK2        0x00000205
#define MSR_MTRR_BASE3        0x00000206
#define MSR_MTRR_MASK3        0x00000207
#define MSR_MTRR_BASE4        0x00000208
#define MSR_MTRR_MASK4        0x00000209
#define MSR_MTRR_BASE5        0x0000020a
#define MSR_MTRR_MASK5        0x0000020b
#define MSR_MTRR_BASE6        0x0000020c
#define MSR_MTRR_MASK6        0x0000020d
#define MSR_MTRR_BASE7        0x0000020e
#define MSR_MTRR_MASK7        0x0000020f
#define MSR_MTRR_FIX64K_00000 0x00000250
#define MSR_MTRR_FIX16K_80000 0x00000258
#define MSR_MTRR_FIX16K_A0000 0x00000259
#define MSR_MTRR_FIX4K_C0000  0x00000268
#define MSR_MTRR_FIX4K_C8000  0x00000269
#define MSR_MTRR_FIX4K_D0000  0x0000026a
#define MSR_MTRR_FIX4K_D8000  0x0000026b
#define MSR_MTRR_FIX4K_E0000  0x0000026c
#define MSR_MTRR_FIX4K_E8000  0x0000026d
#define MSR_MTRR_FIX4K_F0000  0x0000026e
#define MSR_MTRR_FIX4K_F8000  0x0000026f
#define MSR_MTRR_DEF_TYPE     0x000002ff

#define MSR_CR_PAT           0x00000277

#define MSR_MC0_CTL          0x00000400
#define MSR_MC0_STATUS       0x00000401
#define MSR_MC0_ADDR         0x00000402
#define MSR_MC0_MISC         0x00000403
#define MSR_MC0_CTL2         0x00000280

#define MSR_DS_AREA          0x00000600

#define MSR_LASTBRANCHFROMIP 0x000001db // Intel P6 Family
#define MSR_LASTBRANCHTOIP   0x000001dc // Intel P6 Family
#define MSR_LASTINTFROMIP    0x000001dd // Intel P6 Family
#define MSR_LASTINTTOIP      0x000001de // Intel P6 Family

#define MSR_LER_FROM_LIP     0x000001d7 // Intel Pentium4 Family
#define MSR_LER_TO_LIP       0x000001d8 // Intel Pentium4 Family
#define MSR_LASTBRANCH_TOS   0x000001da // Intel Pentium4 Family
#define MSR_LASTBRANCH_0     0x000001db // Intel Pentium4 Family
#define MSR_LASTBRANCH_1     0x000001dc // Intel Pentium4 Family
#define MSR_LASTBRANCH_2     0x000001dd // Intel Pentium4 Family
#define MSR_LASTBRANCH_3     0x000001de // Intel Pentium4 Family

#define CORE_LBR_SIZE        8
#define CORE2_LBR_SIZE       4

/* Power Management MSRs */
#define MSR_PERF_STATUS      0x00000198 // Current Performance State (ro)
#define MSR_PERF_CTL         0x00000199 // Target Performance State (rw)
#define MSR_POWER_CTL        0x000001fc // Power Control Register
#define MSR_CST_CONFIG_CTL   0x000000e2 // C-state Configuration (CORE)
#define MSR_MISC_PWR_MGMT    0x000001aa // Misc Power Management (NHM)
#define MSR_ENERGY_PERF_BIAS 0x000001b0 // Performance Energy Bias Hint
#define MSR_PKG_C2_RESIDENCY 0x0000060d
#define MSR_PKG_C3_RESIDENCY 0x000003f8
#define MSR_PKG_C6_RESIDENCY 0x000003f9
#define MSR_PKG_C7_RESIDENCY 0x000003fa
#define MSR_CORE_C3_RESIDENCY 0x000003fc
#define MSR_CORE_C6_RESIDENCY 0x000003fd
#define MSR_CORE_C7_RESIDENCY 0x000003fe

/* MSR_POWER_CTL bits (Intel) */
#define MSR_POWER_CTL_C1E    0x00000002 // C1E enable (NHM)

/* P-State Hardware Coordination Feedback Capability (Intel) */
#define MSR_MPERF            0x000000e7 // Maximum Performance (rw)
#define MSR_APERF            0x000000e8 // Actual Performance (rw)

/* Software Controlled Clock Modulation and Thermal Monitors (Intel) */
#define MSR_CLOCK_MODULATION 0x0000019a // Thermal Monitor Control (rw)
#define MSR_THERM_INTERRUPT  0x0000019b // Thermal Interrupt Control (rw)
#define MSR_THERM_STATUS     0x0000019c // Thermal Monitor Status (rw)
#define MSR_THERM2_CTL       0x0000019d // Thermal Monitor 2 Control (ro)

/* x2APIC MSRs */
#define MSR_X2APIC_BASE      0x00000800
#define MSR_X2APIC_MAX       0x0000083f
#define MSR_X2APIC_LIMIT     0x00000bff
#define MSR_X2APIC_ID        0x00000802
#define MSR_X2APIC_VERSION   0x00000803
#define MSR_X2APIC_TPR       0x00000808
#define MSR_X2APIC_PPR       0x0000080a
#define MSR_X2APIC_EOI       0x0000080b
#define MSR_X2APIC_LDR       0x0000080d
#define MSR_X2APIC_SVR       0x0000080f
#define MSR_X2APIC_ISR       0x00000810
#define MSR_X2APIC_TMR       0x00000818
#define MSR_X2APIC_IRR       0x00000820
#define MSR_X2APIC_ESR       0x00000828
#define MSR_X2APIC_CMCILVT   0x0000082f
#define MSR_X2APIC_ICRLO     0x00000830
#define MSR_X2APIC_TIMERLVT  0x00000832
#define MSR_X2APIC_THERMLVT  0x00000833
#define MSR_X2APIC_PCLVT     0x00000834
#define MSR_X2APIC_LVT0      0x00000835
#define MSR_X2APIC_LVT1      0x00000836
#define MSR_X2APIC_ERRLVT    0x00000837
#define MSR_X2APIC_INITCNT   0x00000838
#define MSR_X2APIC_CURCNT    0x00000839
#define MSR_X2APIC_DIVIDER   0x0000083e
#define MSR_X2APIC_SELFIPI   0x0000083f


/* MSR_CR_PAT power-on value */
#define MSR_CR_PAT_DEFAULT   0x0007040600070406ULL

/* MSR_MISC_ENABLE bits (Intel) */
#define MSR_MISC_ENABLE_FAST_STRINGS     (1LL<<0)  // Enable Fast string ops
#define MSR_MISC_ENABLE_FOPCODE_COMPAT   (1LL<<2)
#define MSR_MISC_ENABLE_TM1              (1LL<<3)  // Enable Thermal Monitor 1
#define MSR_MISC_ENABLE_EMON_AVAILABLE   (1LL<<7)  // Perf Monitoring Available
#define MSR_MISC_ENABLE_BTS_UNAVAILABLE  (1LL<<11)
#define MSR_MISC_ENABLE_PEBS_UNAVAILABLE (1LL<<12)
#define MSR_MISC_ENABLE_TM2              (1LL<<13) // Enable Thermal Monitor 2
#define MSR_MISC_ENABLE_ESS              (1LL<<16) // Enable Enhanced SpeedStep
#define MSR_MISC_ENABLE_LIMIT_CPUID      (1LL<<22) // Enable CPUID maxval
#define MSR_MISC_ENABLE_C1E              (1LL<<25) // C1E enable (Merom/Penryn)
#define MSR_MISC_ENABLE_ACNT2            (1LL<<27) // ACNT2 (Nehalem only, deprecated)
#define MSR_MISC_ENABLE_TURBO_DISABLE    (1LL<<38) // Turbo Mode Disabled

/* DebugCtlMSR bits */
#define MSR_DEBUGCTL_LBR                   0x00000001
#define MSR_DEBUGCTL_BTF                   0x00000002
#define MSR_DEBUGCTL_TR                    0x00000040
#define MSR_DEBUGCTL_BTS                   0x00000080
#define MSR_DEBUGCTL_BTINT                 0x00000100
#define MSR_DEBUGCTL_BTS_OFF_OS            0x00000200
#define MSR_DEBUGCTL_BTS_OFF_USR           0x00000400
#define MSR_DEBUGCTL_FREEZE_LBRS_ON_PMI    0x00000800
#define MSR_DEBUGCTL_FREEZE_PERFMON_ON_PMI 0x00001000
#define MSR_DEBUGCTL_ENABLE_UNCORE_PMI     0x00002000
#define MSR_DEBUGCTL_FREEZE_WHILE_SMM      0x00004000
#define MSR_DEBUGCTL_RTM                   0x00008000
#define MSR_DEBUGCTL_RSVD          0xffffffffffff003cULL

/* Feature control bits */
#define MSR_FEATCTL_LOCK     0x00000001
#define MSR_FEATCTL_SMXE     0x00000002
#define MSR_FEATCTL_VMXE     0x00000004
#define MSR_FEATCTL_SGXE     0x00040000

/* MSR_EFER bits. */
#define MSR_EFER_SCE         0x0000000000000001ULL  /* Sys call ext'ns:  r/w */
#define MSR_EFER_RAZ         0x00000000000000feULL  /* Read as zero          */
#define MSR_EFER_LME         0x0000000000000100ULL  /* Long mode enable: r/w */
#define MSR_EFER_LMA         0x0000000000000400ULL  /* Long mode active: r/o */
#define MSR_EFER_NXE         0x0000000000000800ULL  /* No-exec enable:   r/w */
#define MSR_EFER_SVME        0x0000000000001000ULL  /* SVM(AMD) enabled? r/w */
#define MSR_EFER_LMSLE       0x0000000000002000ULL  /* LM seg lim enable:r/w */
#define MSR_EFER_FFXSR       0x0000000000004000ULL  /* Fast FXSAVE:      r/w */
#define MSR_EFER_TCE         0x0000000000008000ULL  /* Trans. cache ext. r/w */
#define MSR_EFER_MBZ         0xffffffffffff0200ULL  /* Must be zero (resrvd) */

#define MSR_AMD_PATCH_LOADER 0xc0010020

/* This ifndef is necessary because this is defined by some kernel headers. */
#ifndef MSR_K7_HWCR
#define MSR_K7_HWCR                0xc0010015    // Available on AMD processors
#endif
#define MSR_K7_HWCR_SSEDIS         0x00008000ULL // Disable SSE bit
#define MSR_K7_HWCR_MONMWAITUSEREN 0x00000400ULL // Enable MONITOR/MWAIT CPL>0
#define MSR_K7_HWCR_TLBFFDIS       0x00000040ULL // Disable TLB Flush Filter
#define MSR_K7_HWCR_SMMLOCK        0x00000001ULL // Lock SMM environment

#ifndef MSR_K8_SYSCFG
#define MSR_K8_SYSCFG        0xc0010010
#endif
#define MSR_K8_SYSCFG_MTRRTOM2EN         (1ULL<<21)
#define MSR_K8_SYSCFG_TOM2FORCEMEMTYPEWB (1ULL<<22)
#define MSR_K8_TOPMEM2       0xc001001d

/* AMD "Greyhound" MSRs */
#define MSR_GH_CMPHLT            0xc0010055  // Interrupt Pending & CMP Halt
#define MSR_GH_CMPHLT_C1E        (1ULL<<27)  // C1E on CMP Halt is enabled
#define MSR_GH_CMPHLT_SMI        (1ULL<<28)  // SMI on CMP Halt is enabled

#define MSR_GH_OSVW_LENGTH       0xc0010140  // OS visible workaround length
#define MSR_GH_OSVW_STATUS       0xc0010141  // OS visible workaround bits
#define MSR_GH_OSVW_C1E          (1ULL<<1)   // Workaround for C1E not needed

#define MSR_GH_PSTATE_LIMIT      0xc0010061  // P-state Limit Register
#define MSR_GH_PSTATE_CONTROL    0xc0010062  // P-state Control Register [2:0]
#define MSR_GH_PSTATE_STATUS     0xc0010063  // P-state Status Register [2:0]
#define MSR_GH_PSTATE0           0xc0010064  // P-state 0
#define MSR_GH_PSTATE1           0xc0010065  // P-state 1
#define MSR_GH_PSTATE2           0xc0010066  // P-state 2
#define MSR_GH_PSTATE3           0xc0010067  // P-state 3
#define MSR_GH_PSTATE4           0xc0010068  // P-state 4
#define MSR_GH_COFVID_CONTROL    0xc0010070  // COFVID Control Register
#define MSR_GH_COFVID_STATUS     0xc0010071  // COFVID Status Register

/* SVM related MSRs */
#define MSR_VM_CR                  0xc0010114
#define MSR_IGNNE                  0xc0010115
#define MSR_SMM_CTL                0xc0010116
#define MSR_VM_HSAVE_PA            0xc0010117

#define MSR_VM_CR_DPD              0x0000000000000001ULL // Disable HDT
#define MSR_VM_CR_R_INIT           0x0000000000000002ULL
#define MSR_VM_CR_DIS_A20M         0x0000000000000004ULL
#define MSR_VM_CR_SVM_LOCK         0x0000000000000008ULL
#define MSR_VM_CR_SVME_DISABLE     0x0000000000000010ULL
#define MSR_VM_CR_RESERVED         0xffffffffffffffe0ULL


/* Syscall/Sysret related MSRs (x86_64) */
#define MSR_STAR             0xc0000081 // Also present on Athlons.
#define MSR_LSTAR            0xc0000082
#define MSR_CSTAR            0xc0000083
#define MSR_SFMASK           0xc0000084


/*
 * Hyper-V synthetic MSRs.
 */

#define MSR_HYPERV_GUEST_OS_ID                   0x40000000
#define MSR_HYPERV_HYPERCALL                     0x40000001
#define MSR_HYPERV_VP_INDEX                      0x40000002
#define MSR_HYPERV_RESET                         0x40000003
#define MSR_HYPERV_VP_RUNTIME                    0x40000010
#define MSR_HYPERV_TIME_REF_COUNT                0x40000020
#define MSR_HYPERV_REFERENCE_TSC                 0x40000021
#define MSR_HYPERV_TIME_TSC_FREQUENCY            0x40000022
#define MSR_HYPERV_TIME_APIC_FREQUENCY           0x40000023
#define MSR_HYPERV_EOI                           0x40000070
#define MSR_HYPERV_ICR                           0x40000071
#define MSR_HYPERV_TPR                           0x40000072
#define MSR_HYPERV_APIC_ASSIST_PAGE              0x40000073
#define MSR_HYPERV_SCONTROL                      0x40000080
#define MSR_HYPERV_SVERSION                      0x40000081
#define MSR_HYPERV_SIEFP                         0x40000082
#define MSR_HYPERV_SIMP                          0x40000083
#define MSR_HYPERV_EOM                           0x40000084
#define MSR_HYPERV_SINT0                         0x40000090
#define MSR_HYPERV_SINT1                         0x40000091
#define MSR_HYPERV_SINT2                         0x40000092
#define MSR_HYPERV_SINT3                         0x40000093
#define MSR_HYPERV_SINT4                         0x40000094
#define MSR_HYPERV_SINT5                         0x40000095
#define MSR_HYPERV_SINT6                         0x40000096
#define MSR_HYPERV_SINT7                         0x40000097
#define MSR_HYPERV_SINT8                         0x40000098
#define MSR_HYPERV_SINT9                         0x40000099
#define MSR_HYPERV_SINT10                        0x4000009A
#define MSR_HYPERV_SINT11                        0x4000009B
#define MSR_HYPERV_SINT12                        0x4000009C
#define MSR_HYPERV_SINT13                        0x4000009D
#define MSR_HYPERV_SINT14                        0x4000009E
#define MSR_HYPERV_SINT15                        0x4000009F
#define MSR_HYPERV_STIMER0_CONFIG                0x400000B0
#define MSR_HYPERV_STIMER0_COUNT                 0x400000B1
#define MSR_HYPERV_STIMER1_CONFIG                0x400000B2
#define MSR_HYPERV_STIMER1_COUNT                 0x400000B3
#define MSR_HYPERV_STIMER2_CONFIG                0x400000B4
#define MSR_HYPERV_STIMER2_COUNT                 0x400000B5
#define MSR_HYPERV_STIMER3_CONFIG                0x400000B6
#define MSR_HYPERV_STIMER3_COUNT                 0x400000B7
#define MSR_HYPERV_POWER_STATE_TRIGGER_C1        0x400000C1
#define MSR_HYPERV_POWER_STATE_TRIGGER_C2        0x400000C2
#define MSR_HYPERV_POWER_STATE_TRIGGER_C3        0x400000C3
#define MSR_HYPERV_POWER_STATE_CONFIG_C1         0x400000D1
#define MSR_HYPERV_POWER_STATE_CONFIG_C2         0x400000D2
#define MSR_HYPERV_POWER_STATE_CONFIG_C3         0x400000D3
#define MSR_HYPERV_STATS_PARTITION_RETAIL_PAGE   0x400000E0
#define MSR_HYPERV_STATS_PARTITION_INTERNAL_PAGE 0x400000E1
#define MSR_HYPERV_STATS_VP_RETAIL_PAGE          0x400000E2
#define MSR_HYPERV_STATS_VP_INTERNAL_PAGE        0x400000E3
#define MSR_HYPERV_GUEST_IDLE                    0x400000F0
#define MSR_HYPERV_SYNTH_DEBUG_CONTROL           0x400000F1
#define MSR_HYPERV_SYNTH_DEBUG_STATUS            0x400000F2
#define MSR_HYPERV_SYNTH_DEBUG_SEND_BUFFER       0x400000F3
#define MSR_HYPERV_SYNTH_DEBUG_RECEIVE_BUFFER    0x400000F4
#define MSR_HYPERV_SYNTH_DEBUG_PENDING_BUFFER    0x400000F5

/* Guest Crash Enlightenment MSRs */
#define MSR_HYPERV_CRASH_P0                      0x40000100
#define MSR_HYPERV_CRASH_P1                      0x40000101
#define MSR_HYPERV_CRASH_P2                      0x40000102
#define MSR_HYPERV_CRASH_P3                      0x40000103
#define MSR_HYPERV_CRASH_P4                      0x40000104
#define MSR_HYPERV_CRASH_CTL                     0x40000105

#define MSR_HYPERV_HYPERCALL_EN                  1ULL
#define MSR_HYPERV_REFERENCE_TSC_EN              1ULL

#define MSR_HYPERV_GUESTOSID_VENDOR_SHIFT        48
#define MSR_HYPERV_GUESTOSID_VENDOR_MASK         0xfULL
#define MSR_HYPERV_GUESTOSID_VENDOR_MICROSOFT    1ULL

#define MSR_HYPERV_GUESTOSID_OS_SHIFT            40
#define MSR_HYPERV_GUESTOSID_OS_MASK             0xfULL
#define MSR_HYPERV_GUESTOSID_OS_WINNT_DERIVATIVE 4ULL


/*
 * MTRR bit description
 */
#define MTRR_CAP_WC           0x400
#define MTRR_CAP_FIX          0x100
#define MTRR_CAP_VCNT_MASK    0xff

#define MTRR_DEF_ENABLE       0x800
#define MTRR_DEF_FIXED_ENABLE 0x400
#define MTRR_DEF_TYPE_MASK    0xff

#define MTRR_BASE_TYPE_MASK   0xff

#define MTRR_MASK_VALID       0x800

#define MTRR_TYPE_UC          0
#define MTRR_TYPE_WC          1
#define MTRR_TYPE_WT          4
#define MTRR_TYPE_WP          5
#define MTRR_TYPE_WB          6
/* PAT Memory Type Only */
/* UC- is equivalent to UC, except that the MTRR values take precedence */
#define MTRR_TYPE_UCM         7

/*
 * PERF_STATUS bits
 */
#define MSR_PERF_STATUS_MAX_BUS_RATIO_SHIFT 40
#define MSR_PERF_STATUS_MAX_BUS_RATIO_MASK  0x1f

/*
 * PLATFORM_INFO bits
 */
#define MSR_PLATFORM_INFO_CPUID_FAULTING (1UL << 31)  // Faulting is supported
#define MSR_PLATFORM_INFO_MIN_RATIO_SHIFT 40
#define MSR_PLATFORM_INFO_MIN_RATIO_MASK 0xff
#define MSR_PLATFORM_INFO_MAX_NONTURBO_RATIO_SHIFT 8
#define MSR_PLATFORM_INFO_MAX_NONTURBO_RATIO_MASK 0xff

/*
 * MISC_FEATURES_ENABLES bits
 */
#define MSR_MISC_FEATURES_ENABLES_CPUID_FAULTING 1





static INLINE uint32
X86MSR_SysCallEIP(uint64 star)
{
   return (uint32)star;
}


static INLINE uint16
X86MSR_SysCallCS(uint64 star)
{
   return (uint16)(star >> 32);
}


static INLINE uint16
X86MSR_SysRetCS(uint64 star)
{
   return (uint16)(star >> 48);
}


#endif /* _X86MSR_H_ */
