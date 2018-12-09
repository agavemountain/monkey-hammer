/**
 *  @file: file_utilities.h
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

//! \brief checks to see if a file exists
//!
//! \param filename     path and filename of the file to look for
//! \returns
//!     true if the file exists, else false.
bool does_file_exist (const std::string& filename) ;

//! \brief An implementation of the unix touch command
//!
//! \param  pathname    file to create or touch
//!
int touch(const std::string& pathname);

//! \brief Take a string and push it to a file
//!
//! \param  pathname    file to create or touch
//! \param  data        text to push into the file.
//!
bool string_to_file(const std::string& pathname, const std::string &data);

//! \brief Checks to see if a directory exists
//!
//! \param pathname     directory path
//!
//! \returns true if exists, else false.
bool does_directory_exist( const char* pzPath );

}
