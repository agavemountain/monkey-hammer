/**
 *  @file: error.cpp
 *
 *  Copyright (C) 2019  Joe Turner <joe@agavemountain.com>
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
#include <iostream>
#include <monkeylib/core/error.h>

using namespace std;

const char *abortMessage[] = {
    NULL,
    "Invalid command line arguments",
    "Failed to open source file",

    "Unimplemented feature",
};

void AbortTranslation(eAbortCode a_code)
{
    if ( (a_code < eAbortUnimplementedFeature) || 
        ( a_code > eAbortInvalidCommandLineArgs) )
    {
        cerr << "Fatal Error: Error out of range." << endl;
    }
    else
    {
        cerr << "Fatal error: " << abortMessage[-a_code] << endl;     
    }
}