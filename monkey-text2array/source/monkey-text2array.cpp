/**
 *  @file: monkey-text2array.cpp
 *
 * This utility makes it easy to generate a take a text file
 * and turn it into a character array so it can be embedded
 * into an compiled executable.
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
#include <string>
#include <fstream>
#include <boost/program_options.hpp>
#include <boost/algorithm/string.hpp>

#include <monkeylib/core/formatters/string_array_formatter.h>

using namespace std;
namespace po = boost::program_options;
using namespace Monkey::Formatters;

const char *INPUT="input";
const char *OUTPUT="output";
const char *HELP="help";
const char *VARNAME="variable-name";

std::string gVarName;

//
//! Program Entry Point
int main(int ac, char **av) {
    po::options_description generic("Generic options");
    generic.add_options()
    (HELP, "produce help message")
    (INPUT, po::value< string >(), "specifies input file name to read.")
    (OUTPUT, po::value< string >(), "specifies output file name.")
    (VARNAME, po::value< string >(), "specifies the variable name.")
    ;

    std::string line;
    std::vector<std::string> myLines;

    po::options_description cmdline_options;
    cmdline_options.add(generic);

    try {
        // parse command line arguments.
        po::variables_map vm;
        po::store(po::parse_command_line(ac, av, cmdline_options), vm);
        po::notify(vm);

        // if user wants help or doesn't specify arguments, dump help and exit.
        if (vm.count(HELP) || ac == 1 ) {   //
            cout << cmdline_options << "\n";
            return 1;
        }

        if (vm.count(INPUT)) {
           string tmp = vm[INPUT].as< string >();
           ifstream infile;
           infile.open(tmp.c_str(), ofstream::in);

           if (!infile.good())
           {
               cerr << "Could not open input file " << tmp << endl;
           }

           while (std::getline(infile, line))
           {
              myLines.push_back(line);
           }
       }
       else
       {
           // no template specified, we simply use standard in.
           while (std::getline(cin, line))
           {
              myLines.push_back(line);
           }
       }

       if (vm.count(VARNAME))
       {
           gVarName = vm[VARNAME].as< string >();
       }
       else
       {
           cout << "You must specify a variable name.\n\n";
           return -1;
       }

       if (vm.count(OUTPUT)) {
           string tmp = vm[OUTPUT].as< string >();
           ofstream file;
           file.open(tmp.c_str(), ofstream::out);

           if (!file.good())
           {
               cerr << "Could not open output file " << tmp << endl;
           }

           file << format_literal_array_cpp(gVarName, myLines, true);
           file.close();
       }
       else
       {
           // if no files specified, we dump to std::cout, and
           // we only do it once.
           std::cout << format_literal_array_cpp(gVarName, myLines, true);
       }
    }
    catch(...) {
        cout << "Invalid arguments.  See --help for proper options.\n\n";
    }


    return 0;
    return 0;
}
