/**
 *  @file: monkey_hammer_config_test.cpp
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
#include <stdio.h>

using namespace Monkey;
using namespace Monkey::Configuration;

class monkey_config_test : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE( monkey_config_test );
    CPPUNIT_TEST( test_load_does_not_exit );
    CPPUNIT_TEST( test_create_new_and_load );
    CPPUNIT_TEST_SUITE_END();
public:

    void test_load_does_not_exit()
    {
    	MonkeyHammerConfigurationFile cfg;
    	int rc = cfg.load();

        CPPUNIT_ASSERT( rc == M_CONFIG_LOAD_ERROR );
    }

    void test_create_new_and_load()
    {
        const char *GLOBAL="global";
        const char *fn = "xyz";
        std::string u = "Max Powers";
        std::string c = "Mega Inc.";
        std::string em = "spam@spam.com";

        remove(fn);
        CSimpleIni ini;
        SI_Error rc = ini.SetValue(GLOBAL, NULL, NULL);
        CPPUNIT_ASSERT(rc >= 0);

        rc = ini.SetValue(GLOBAL, "username", u.c_str());
        CPPUNIT_ASSERT(rc >= 0);

        rc = ini.SetValue(GLOBAL, "company", c.c_str());
        CPPUNIT_ASSERT(rc >= 0);

        rc = ini.SetValue(GLOBAL, "email", em.c_str());
        CPPUNIT_ASSERT(rc >= 0);

        rc = ini.SaveFile(fn);
        CPPUNIT_ASSERT(rc >= 0);

        MonkeyHammerConfigurationFile cfg;
        cfg.set_file_location(fn);
        int e = cfg.load();
        CPPUNIT_ASSERT (e == M_OK);

        CPPUNIT_ASSERT( cfg.get_username().compare(u) == 0);
        CPPUNIT_ASSERT( cfg.get_email_address().compare(em) == 0);
        CPPUNIT_ASSERT( cfg.get_company().compare(c) == 0);
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( monkey_config_test );


