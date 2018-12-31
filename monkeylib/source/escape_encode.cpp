/**
 *  @file: escape_encode.cpp
 *
 *  Copyright (C) 2019  Joe Turner <joe@agavemountain.com>
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
#include <monkeylib/core/escape_encode.h>

#define LT             '<'
#define QUOTE          '\"'
#define GT             '>'
#define AMP            '&'
#define APOS           '\''
#define BACKSLASH      '\\'
#define TAB            '\t'
#define BACKSPACE      '\b'
#define SPACE          ' '
#define PERCENT        '%'
#define DOLLAR         '$'
#define QUESTION       '?'
#define DOUBLE_APOS    "\'\'"
#define ESC_DOLLAR     "\\$"
#define ESC_BACKSLASH  "\\\\"

namespace Monkey
{

bool isControl(char a_ch)
{
    return (a_ch < 0x20 ? true : false );
}

bool isPrintableASCII(char a_ch)
{
    if ( a_ch < 0x20 || a_ch >0x7E )
    {
        return false;
    }

    return true;
}

std::string encode_cpp(const std::string& r_data) {
    std::string buffer;
    buffer.reserve(r_data.size());
    for(size_t pos = 0; pos != r_data.size(); ++pos) {
        switch(r_data[pos]) {
        case '\'':
            buffer.append("\\\'");
            break;
        case '\"':
            buffer.append("\\\"");
            break;
        case '\?':
            buffer.append("\\\?");
            break;
        case '\r':  // eat MSDOS carriage return.
            break;
        default:
            buffer.append(1, r_data[pos]);
            break;
        }
    }
    return buffer;
}


}
