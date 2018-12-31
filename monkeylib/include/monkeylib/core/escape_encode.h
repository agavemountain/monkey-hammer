/**
 *  @file: escape_encode.h
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
#pragma once
#include <string>

namespace Monkey
{

//! Detect is the specified character is a control character.  This is a
//! a faster version of the regex [:cntrl:].
//!
//! @param a_ch character to test
//!
//! @returns
//!     true    this is an ASCII control character (0x00 -1xF)
//!     false   this is not an ASCII control character
//!
bool isControl(char a_ch);

//! Detect if the specified character is a printable ASCII character.
//!
//! @param a_ch character to test
//!
//! @returns
//!     true    this is an ASCII printable latin character
//!     false   this is not an ASCII printable latin character
//!
bool isPrintableASCII(char a_ch);

//! Translate any characters that require escaping when encoding into
//! a string literal.
//!
//! @param r_data   reference to string data.
std::string  encode_cpp(const std::string& r_data);


}
