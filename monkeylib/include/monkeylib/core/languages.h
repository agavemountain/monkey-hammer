/**
 *  @file: languages.h
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
#include <string>

namespace Monkey
{

//! \brief Source code annotation delimiters
//!
//! A comment is an programmer-readable explanation or annotation in the
//! source of a computer program.  The syntax of comments varies
//! considerably in various programming languages.
struct _source_annotation
{
    std::string prefix;	                //!< multi-line prefix
    std::string postfix;                //!< multi-line postfix
    std::string line_prefix;            //!< prefix for each comment line
};

}
