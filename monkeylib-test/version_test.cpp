/**
 *  @file: monkey-hammer.h
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
#include <string>
#include <iostream>
#include <monkeylib/core/Version.h>

using namespace std;   // so sue me, I'm lazy tonight.
using namespace Monkey::Version;

class version_test : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE( version_test );
    CPPUNIT_TEST( TestMajorMinorPatch );
    CPPUNIT_TEST( TestCompilerVersionString );
    CPPUNIT_TEST_SUITE_END();
public:

    void TestMajorMinorPatch()
    {
    	char buff[10];
        auto major = GetVersionMajor();
        auto minor = GetVersionMinor();
        auto patch = GetVersionPatch();
        std::string version;
        sprintf(buff, "%d.%d.%d", major, minor, patch);
        version = buff;
        std::string versionString = GetVersionString();
        CPPUNIT_ASSERT(versionString == version);
    }

    void TestCompilerVersionString()
    {
        std::string compiler = GetCompilerVersionString();
    #if defined(_MSC_VER)
        const auto expected = "MSVC";
    #elif defined(__GNUC__)
        const auto expected = "GCC";
    #elif defined(__clang__)
        const auto expected = "Clang";
    #else
        const auto expected = "Unknown";
    #endif

        CPPUNIT_ASSERT( compiler.find(expected) != std::string::npos ) ;
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( version_test );


