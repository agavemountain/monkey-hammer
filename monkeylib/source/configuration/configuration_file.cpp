/**
 *  @file: configuration_file.h
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
#include <monkeylib/core/configuration/configuration_file.h>

namespace Monkey
{
namespace Configuration
{

std::string ConfigurationFile::get_file_location() const
{
	return _location;
}

void ConfigurationFile::set_file_location(const char *location)
{
    _location = location;
}

void ConfigurationFile::set_file_location(const std::string &location)
{
	_location = location;
}

}
}
