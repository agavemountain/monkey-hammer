/**
 *  @file: version.cpp
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
#include <monkeylib/core/Version.h>
#include <monkeylib/core/VersionConfig.h>
#include <cstdio>
#include <cassert>

namespace Monkey
{
namespace Version
{
  const char* GetVersionString()
  {
    return MONKEY_VERSION_STRING;
  }

  unsigned GetVersionMajor()
  {
    return MONKEY_VERSION_MAJOR;
  }

  unsigned GetVersionMinor()
  {
    return MONKEY_VERSION_MINOR;
  }

  unsigned GetVersionPatch()
  {
    return MONKEY_VERSION_PATCH;
  }

  const char* GetCompilerVersionString()
  {
#define xstr(s) str(s)
#define str(s) #s
#if defined(__GNUC__)
      return "GCC/" xstr(__GNUC__) "."  xstr(__GNUC_MINOR__) "." xstr(__GNUC_PATCHLEVEL__);
#elif defined(__clang__)
      return "Clang/" xstr(__clang_major__) "."  xstr(__clang_minor__) "." xstr(__clang_patchlevel__);
#elif defined(_MSC_VER)
      return "MSVC/" xstr(_MSC_VER);
#else
      return "UnknownCompiler";
#endif
#undef str
#undef xstr
  }
} //namespace Version
} //namespace Monkey
