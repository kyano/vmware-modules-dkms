/*********************************************************
 * Copyright (C) 2010-2017 VMware, Inc. All rights reserved.
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

#ifndef _MONITORACTION_EXPORTED_H_
#define _MONITORACTION_EXPORTED_H_

#define INCLUDE_ALLOW_VMX
#define INCLUDE_ALLOW_VMCORE
#define INCLUDE_ALLOW_USERLEVEL
#define INCLUDE_ALLOW_VMKERNEL
#define INCLUDE_ALLOW_DISTRIBUTE
#include "includeCheck.h"

#include "vm_basic_types.h"

#if defined __cplusplus
extern "C" {
#endif

#define MONACTION_INVALID  MAX_UINT32

typedef uint32 MonitorIdemAction;

#if defined __cplusplus
} // extern "C"
#endif

#endif // _MONITORACTION_EXPORTED_H_
