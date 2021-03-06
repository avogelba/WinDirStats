// stdafx.h - include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently
//
// WinDirStat - Directory Statistics
// Copyright (C) 2003-2005 Bernhard Seifert
// Copyright (C) 2004-2016 WinDirStat team (windirstat.info)
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#ifndef __WDS_STDAFX_H__
#define __WDS_STDAFX_H__
#pragma once

#if (defined(HAVE_WIN7_SDK) && HAVE_WIN7_SDK) || (_MSC_VER >= 1600)
#   define SUPPORT_W7_TASKBAR 1
#   define SUPPORT_ELEVATION  1
#endif // HAVE_WIN7_SDK

#define _WIN32_WINNT _WIN32_WINNT_WINXP

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN        // Exclude rarely-used stuff from Windows headers
#endif

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS  // some CString constructors will be explicit

// turns off MFC's hiding of some common and often safely ignored warning messages
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC Core
#include <afxext.h>         // MFC Extensions

#include <afxdtctl.h>       // MFC IE 4
#include <afxcmn.h>         // MFC Common Controls
#include <afxtempl.h>       // MFC Container classes
#include <afxmt.h>          // MFC Multi-threading
#include <afxinet.h>        // For CInternet* classes

#include <io.h>             // _access()
#include <math.h>           // floor(), fmod(), sqrt() etc.
#include <psapi.h>          // PROCESS_MEMORY_INFO
#include <lmcons.h>         // UNLEN
#include <float.h>          // DBL_MAX

#include <atlbase.h>        // USES_CONVERSION, ComPtr<>

#include <common/mdexceptions.h>
#include <common/cotaskmem.h>
#include <common/commonhelpers.h>
#include <common/tracer.h>
#include <common/wds_constants.h>

#define RGB_GET_RVALUE(rgb) (rgb & 0xFF)
#define RGB_GET_GVALUE(rgb) ((rgb & 0xFF00) >> 8)
#define RGB_GET_BVALUE(rgb) ((rgb & 0xFF0000) >> 16)

// General purpose headers
#include "selectobject.h"
#include "set.h"

#define countof(arr) (sizeof(arr)/sizeof((arr)[0]))

template<class T> int signum(T x) { return (x) < 0 ? -1 : (x) == 0 ? 0 : 1; }

/// signum function for unsigned numbers.
template<class T> int usignum(T x, T y) { return (x) < (y) ? -1 : (x) == (y) ? 0 : 1; }

#define WEAK_ASSERT /##/ ASSERT

#endif // __WDS_STDAFX_H__
