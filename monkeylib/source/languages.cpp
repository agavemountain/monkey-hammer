/**
 *  @file: languages.cpp
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
#include <monkeylib/core/languages.h>
#include <stdio.h>

struct language_definition
{
    const char *language_name;
    const char **file_extensions;
    const char *script;
    const char *file;
};

const char *known_binary_archives[] =
{
    ".tar",
    ".tar.Z",
    ".tar.gz",
    ".tar.bz2",
    ".zip",
    ".Zip",
    ".ear",     // Java
    ".war",     // Contained within .ear
    ".xz",
    NULL
};

