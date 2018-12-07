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
#include <iostream>
#include <monkeylib/core/patterns/command.h>
#include <monkeylib/core/patterns/observer.h>

using namespace std;   // so sue me, I'm lazy tonight.
using namespace Monkey::Patterns;

class ConcreteCommand : public Command
{
public:
	int value;

	ConcreteCommand() : value( 0 ) {}
	void execute() { value++; }
};


class design_patterns_test : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE( design_patterns_test );
    CPPUNIT_TEST( test_command );
    CPPUNIT_TEST_SUITE_END();
public:

    void test_command()
    {
    	ConcreteCommand c;
    	CPPUNIT_ASSERT_EQUAL(c.value, 0);
    	c.execute();
    	CPPUNIT_ASSERT_EQUAL(c.value, 1);

    }


};

CPPUNIT_TEST_SUITE_REGISTRATION( design_patterns_test );


