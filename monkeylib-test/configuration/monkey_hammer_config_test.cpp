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

using namespace Monkey;

class monkey_config_test : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE( monkey_config_test );
    CPPUNIT_TEST( test_something );
    CPPUNIT_TEST_SUITE_END();
public:

    void test_something()
    {
        CPPUNIT_ASSERT( true );
    }

};

CPPUNIT_TEST_SUITE_REGISTRATION( monkey_config_test );


