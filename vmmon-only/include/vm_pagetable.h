/*********************************************************
 * Copyright (C) 2014,2016 VMware, Inc. All rights reserved.
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
 * vm_pagetable.h --
 *
 *      Virtual memory page table definitions
 */

#ifndef _VM_PAGETABLE_H_
#define _VM_PAGETABLE_H_

#define INCLUDE_ALLOW_MODULE
#define INCLUDE_ALLOW_VMK_MODULE
#define INCLUDE_ALLOW_VMKERNEL
#define INCLUDE_ALLOW_DISTRIBUTE
#define INCLUDE_ALLOW_VMCORE
#define INCLUDE_ALLOW_VMMON
#define INCLUDE_ALLOW_USERLEVEL
#include "includeCheck.h"

#include "vm_basic_types.h"
#include "vm_basic_defs.h"

/*
 * These definitions suit both the x64 and arm64 architectures. In particular
 * - At all levels, a page table is a 4KB page containing 512 8-byte entries.
 * - Each entry maps 39, 30, 21 and 12 bits at the respective page table
 *   levels (with standard page sizes).
 */

typedef uint64 PT_L4E;
typedef uint64 PT_L3E;
typedef uint64 PT_L2E;
typedef uint64 PT_L1E;

typedef enum {
   PT_LEVEL_1 = 1,
   PT_LEVEL_2,
   PT_LEVEL_3,
   PT_LEVEL_4,
   PT_MAX_LEVELS = PT_LEVEL_4
} PT_Level;

#define PT_PTE_SIZE           8
#define PT_LEVEL_SHIFT        9

#define PT_PTE_PFN_SHIFT      PAGE_SHIFT
#define PT_ENTRIES_PER_PT     (1 << PT_LEVEL_SHIFT)
#define PT_OFF_MASK           (PT_ENTRIES_PER_PT - 1)

/*
 * log2 of the
 * address space size (in 4KB pages) covered by a level-_l page table entry.
 */
#define PT_LE_PG_SHIFT(_l)    (PT_LEVEL_SHIFT * ((_l) - PT_LEVEL_1))

/* Address space size (in 4KB pages) covered by a level-_l page table entry. */
#define PT_PAGES_PER_LE(_l)   ((uint64)1 << PT_LE_PG_SHIFT(_l))
#define PT_PAGES_PER_L4E      PT_PAGES_PER_LE(PT_LEVEL_4)
#define PT_PAGES_PER_L3E      PT_PAGES_PER_LE(PT_LEVEL_3)
#define PT_PAGES_PER_L2E      PT_PAGES_PER_LE(PT_LEVEL_2)
#define PT_PAGES_PER_L1E      PT_PAGES_PER_LE(PT_LEVEL_1)

/*
 * log2 of the
 * address space size (in bytes) covered by a level-_l page table entry.
 */
#define PT_LE_SHIFT(_l)       (PAGE_SHIFT + PT_LE_PG_SHIFT(_l))
#define PT_L4E_SHIFT          PT_LE_SHIFT(PT_LEVEL_4)
#define PT_L3E_SHIFT          PT_LE_SHIFT(PT_LEVEL_3)
#define PT_L2E_SHIFT          PT_LE_SHIFT(PT_LEVEL_2)
#define PT_L1E_SHIFT          PT_LE_SHIFT(PT_LEVEL_1)

/* Address space size (in bytes) covered by a level-_l page table entry. */
#define PT_LE_SIZE(_l)        ((uint64)1 << PT_LE_SHIFT(_l))
#define PT_L4E_SIZE           PT_LE_SIZE(PT_LEVEL_4)
#define PT_L3E_SIZE           PT_LE_SIZE(PT_LEVEL_3)
#define PT_L2E_SIZE           PT_LE_SIZE(PT_LEVEL_2)
#define PT_L1E_SIZE           PT_LE_SIZE(PT_LEVEL_1)

/*
 * For a given LA,
 * determine the offset (== index) of the level-_l page table entry.
 */
#define PT_LA_2_LOFF(_a, _l)  (((_a) >> PT_LE_SHIFT(_l)) & PT_OFF_MASK)
#define PT_LA_2_L4OFF(_a)     PT_LA_2_LOFF(_a, PT_LEVEL_4)
#define PT_LA_2_L3OFF(_a)     PT_LA_2_LOFF(_a, PT_LEVEL_3)
#define PT_LA_2_L2OFF(_a)     PT_LA_2_LOFF(_a, PT_LEVEL_2)
#define PT_LA_2_L1OFF(_a)     PT_LA_2_LOFF(_a, PT_LEVEL_1)

/*
 * For a given LPN,
 * determine the offset (== index) of the level-_l page table entry.
 */
#define PT_LPN_2_LOFF(_a, _l) (((_a) >> PT_LE_PG_SHIFT(_l)) & PT_OFF_MASK)
#define PT_LPN_2_L4OFF(_a)    PT_LPN_2_LOFF(_a, PT_LEVEL_4)
#define PT_LPN_2_L3OFF(_a)    PT_LPN_2_LOFF(_a, PT_LEVEL_3)
#define PT_LPN_2_L2OFF(_a)    PT_LPN_2_LOFF(_a, PT_LEVEL_2)
#define PT_LPN_2_L1OFF(_a)    PT_LPN_2_LOFF(_a, PT_LEVEL_1)

/* Size (in bytes) of a 1GB page. */
#define PT_1G_PAGE_SIZE       PT_L3E_SIZE
#define PT_1G_PAGE_MASK       (PT_L3E_SIZE - 1)

/* Size (in bytes) of a 2MB page. */
#define PT_2M_PAGE_SIZE       PT_L2E_SIZE
#define PT_2M_PAGE_MASK       (PT_L2E_SIZE - 1)

#define PT_LE_NXT_PG(_a, _l)  ((((_a) >> PT_LE_PG_SHIFT(_l)) + 1) \
                               << PT_LE_PG_SHIFT(_l))

#endif
