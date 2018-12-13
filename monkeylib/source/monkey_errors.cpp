/**
 *  @file: monkey_errors.cpp
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
#include <monkeylib/core/monkey_errors.h>

namespace Monkey
{

const char *error_msg[] =
{
    "OK", // M_OK = 0x00,
    "Configuration file load error",    // M_CONFIG_LOAD_ERROR,
    "Invalid error code",               // M_INVALID_ERROR_CODE
};

const char *error_to_string(int error_code)
{
    // range check
    if ( (error_code < M_OK) || (error_code > M_INVALID_ERROR_CODE))
    {
        return error_msg[M_INVALID_ERROR_CODE];
    }
    return error_msg[error_code];
}

}
