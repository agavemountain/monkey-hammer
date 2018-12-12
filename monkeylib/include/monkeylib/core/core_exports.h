/**
 *  @file: core_exports.h
 *
 *  Copyright (C) 2018  Joe Turner <joe@agavemountain.com>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *     This program is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.
 *
 *     You should have received a copy of the GNU General Public License
 *     along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#pragma once

#if defined (USE_WINDOWS_DLL_SEMANTICS) || defined (WIN32)
    #ifdef _MSC_VER
        #pragma warning(disable : 4251)
    #endif // _MSC_VER

    #ifdef USE_IMPORT_EXPORT
        #ifdef MONKEY_CORE_EXPORTS
            #define  MKY_CORE_API __declspec(dllexport)
        #else // MONKEY_CORE_EXPORTS
            #define  MKY_CORE_API __declspec(dllimport)
        #endif // MONKEY_CORE_EXPORTS
    #else // USE_IMPORT_EXPORT
        #define MKY_CORE_API
    #endif // USE_IMPORT_EXPORT
#else // defined (USE_WINDOWS_DLL_SEMANTICS) || defined (WIN32)
    #define MKY_CORE_API
#endif // defined (USE_WINDOWS_DLL_SEMANTICS) || defined (WIN32)

