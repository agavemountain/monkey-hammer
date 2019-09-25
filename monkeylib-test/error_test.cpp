/**
 *  @file: error_test.cpp
 *
 *  Copyright (C) 2019 Joe Turner <joe@agavemountain.com>
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
#include <iostream>
#include <monkeylib/core/error.h>

class error_test : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE( error_test );
    CPPUNIT_TEST( test_range );
    CPPUNIT_TEST_SUITE_END();
public:

    void test_range()
    {
        AbortTranslation((enum eAbortCode)100);
        AbortTranslation(eAbortInvalidCommandLineArgs);
        AbortTranslation(eAbortUnimplementedFeature);
    }
 
};

CPPUNIT_TEST_SUITE_REGISTRATION( error_test );
