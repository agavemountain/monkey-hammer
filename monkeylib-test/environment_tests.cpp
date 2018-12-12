/**
 *  @file: environment_tests.cpp
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
#include <monkeylib/core/environment.h>

using namespace Monkey;

class environment_test : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE( environment_test );
    CPPUNIT_TEST( test_get );
    CPPUNIT_TEST( test_exists );
    CPPUNIT_TEST( test_home );
    CPPUNIT_TEST( test_set_and_erase );
    CPPUNIT_TEST_SUITE_END();
public:

    void test_get()
    {
        Environment env;
        const char *HOME= "HOME";
        char const *home = getenv("HOME");

        std::string strhome = env.get(HOME);
        CPPUNIT_ASSERT( strhome == home );

        strhome = HOME;
        CPPUNIT_ASSERT( env.get(strhome) == home);

        CPPUNIT_ASSERT( env[strhome] == home);
        CPPUNIT_ASSERT( env[HOME] == home);
    }

    void test_exists()
    {
        Environment env;
        const char *xyz="XZVSS123";
        const char *home="HOME";

        CPPUNIT_ASSERT( !env.isExists(xyz) );
        CPPUNIT_ASSERT( env.isExists(home) );

        std::string tmp = xyz;
        CPPUNIT_ASSERT( !env.isExists( tmp ) );
        tmp = home;
        CPPUNIT_ASSERT( env.isExists(  tmp ) );
    }

    void test_home()
    {
        Environment env;
        char const *home = getenv("HOME");
        CPPUNIT_ASSERT( env.home_path() == home);
    }

        void test_set_and_erase()
    {
        Environment env;
        const char *xyz="XZVSS123";
        CPPUNIT_ASSERT( !env.isExists(xyz) );
        CPPUNIT_ASSERT( !env.set(xyz, xyz));
        CPPUNIT_ASSERT( env.get(xyz) == xyz);
        CPPUNIT_ASSERT( env.isExists(xyz) );
        CPPUNIT_ASSERT( !env.erase(xyz));
        CPPUNIT_ASSERT( !env.isExists(xyz) );
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( environment_test );

