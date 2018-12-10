/**
 *  @file: monkey_hammer_config.cpp
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
#include <cppunit/extensions/HelperMacros.h>
#include <monkeylib/core/configuration/monkey_hammer_config.h>
#include <monkeylib/core/configuration/simpleini/SimpleIni.h>
#include <monkeylib/core/monkey_errors.h>

namespace Monkey
{
namespace Configuration
{


MonkeyHammerConfigurationFile::MonkeyHammerConfigurationFile()
{

}

std::string MonkeyHammerConfigurationFile::get_username() const
{
	return _username;
}

std::string MonkeyHammerConfigurationFile::get_company() const
{
	return _company;
}

std::string MonkeyHammerConfigurationFile::get_email_address() const
{
	return _email_address;
}

void MonkeyHammerConfigurationFile::set_username(std::string & username)
{
	_username = username;
}

void MonkeyHammerConfigurationFile::set_company(std::string & company)
{
	_company = company;
}

void MonkeyHammerConfigurationFile::set_email_address(std::string & email_address)
{
	_email_address=email_address;
}

int MonkeyHammerConfigurationFile::load()
{
    CSimpleIni ini;
    SI_Error rc = ini.LoadFile(_location.c_str());
	if (rc < 0)
    {
	    return M_CONFIG_LOAD_ERROR;
    }

	_username = ini.GetValue("global", "username", "");
	_company = ini.GetValue("global", "company", "");
	_email_address = ini.GetValue("global", "email", "");

	return M_OK;
}

int MonkeyHammerConfigurationFile::save()
{
	return M_OK;
}


}
}
