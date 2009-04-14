// This file is part of BlueSky
// 
// BlueSky is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation; either version 3
// of the License, or (at your option) any later version.
// 
// BlueSky is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with BlueSky; if not, see <http://www.gnu.org/licenses/>.

//guardian
#ifndef _SETUP_COMMON_API_H
#define _SETUP_COMMON_API_H

//setup API macro depending on compiler
#if defined(_MSC_VER)		//M$ compiler
	//disable warning about stdext namespace
	#pragma warning(disable:4996)
	//disable xxx needs to have dll-interface blah-blah
	#pragma warning(disable:4251)
	//compiler bug (?) - no suitable definition provided for explicit template instantiation request
	#pragma warning(disable:4661)
	//c++ exception specification throw(type)
	#pragma warning(disable:4290)
	//python Py_ssize_t to unsigned int warnings
	#pragma warning(disable:4244)

	//API export/import macro
	#define _BS_API_EXPORT __declspec(dllexport)
	#define _BS_C_API_EXPORT extern "C" __declspec(dllexport)
	#define _BS_HIDDEN_API_EXPORT

	#define _BS_API_IMPORT __declspec(dllimport)
	#define _BS_C_API_IMPORT extern "C" __declspec(dllimport)
	#define _BS_HIDDEN_API_IMPORT

#elif defined(__GNUC__)		//GCC
	//API export/import macro

	#define _BS_API_EXPORT __attribute__ ((visibility("default")))
	#define _BS_C_API_EXPORT extern "C" __attribute__ ((visibility("default")))
	#define _BS_HIDDEN_API_EXPORT __attribute__ ((visibility("hidden")))

	#define _BS_API_IMPORT
	#define _BS_C_API_IMPORT
	#define _BS_HIDDEN_API_IMPORT
#endif

//setup kernel API macro
#ifdef BS_EXPORTING
	#define BS_API _BS_API_EXPORT
	#define BS_C_API _BS_C_API_EXPORT
	#define BS_HIDDEN_API _BS_HIDDEN_API_EXPORT
#else
	#define BS_API _BS_API_IMPORT
	#define BS_C_API _BS_C_API_IMPORT
	#define BS_HIDDEN_API _BS_HIDDEN_API_IMPORT
#endif

//macro for plugin's API setup
#define BS_SETUP_PLUGIN_API() "setup_plugin_api.h"
#define BS_FORCE_PLUGIN_IMPORT() "force_plugin_import.h"
#define BS_STOP_PLUGIN_IMPORT() "stop_plugin_import.h"

#endif	//_SETUP_COMMON_API_H
