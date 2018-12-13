/**
 *  @file: monkey-comment.cpp
 *
 * This utility makes it easy to generate a take a text file
 * and turn it into a character array so it can be embedded
 * into an compiled executable.
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
#include <iostream>
#include <string>
#include <fstream>
#include <boost/program_options.hpp>
#include <boost/progress.hpp>
#include <boost/algorithm/string.hpp>

#include <monkeylib/core/formatters/comment_formatter.h>

using namespace std;
namespace po = boost::program_options;
using namespace Monkey::Formatters;

const char *CPREFIX="comment-prefix";
const char *CPOSTFIX="comment-postfix";
const char *CPRE="comment-pre";
const char *INPUT="input";
const char *OUTPUT="output";
const char *HELP="help";
const char *LANGUAGE="language";
const char *SHOW_LANG="show-languages";

//! Program Entry Point
int main(int ac, char **av) {

    CommentFormatter gComment;
    // Declare the supported options.
    po::options_description generic("Generic options");
    generic.add_options()
    (HELP, "produce help message")
    (INPUT, po::value< string >(), "specifies input file name to comment-ize.")
    (OUTPUT, po::value< string >(), "specifies output file name.")
    ;

    po::options_description langcfg("Language options");
    langcfg.add_options()
    (CPREFIX, po::value< string >(), "Comment characters to prefix comment stanza.")
    (CPRE, po::value< string >(), "comment characters to prefix each line.")
    (CPOSTFIX, po::value< string >(), "Comment characters to postfix comment stanza.")
//    (LANGUAGE, po::value< string >(), "sets language options")
//    (SHOW_LANG, "display supported computer languages")
    ;

    po::options_description cmdline_options;
    cmdline_options.add(generic).add(langcfg);

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

//        if (vm.count(SHOW_LANG))
//        {
//            cout << "Supported languages:\n\n";
//            SupportedLanguage::instance().dump_supported_languages();
//            return 0;
//        }
//
//        if (vm.count(LANGUAGE))
//        {
//            string tmp =  vm[LANGUAGE].as< string >();
//            boost::to_upper(tmp);
//            bool valid_language = false;
//
//            int id = SupportedLanguage::instance().getLanguageID(tmp);
//            if (id != -1) {
//                gComment.setLanguage(id);
//            }
//            else {
//                cerr << "Error: undefined language.\n";
//                return 2;
//            }
//        }
//
       // override switches.  These switches will override
       // the --language switch:

       if (vm.count(CPREFIX)) {
           string tmp = vm[CPREFIX].as< string >();
           gComment.setMultiLinePrefix(tmp);
       }

       if (vm.count(CPRE)) {
           string tmp = vm[CPRE].as< string >();
           gComment.setLinePrefix(tmp);
       }

       if (vm.count(CPOSTFIX)) {
           string tmp = vm[CPOSTFIX].as< string >();
           gComment.setMultiLinePostfix(tmp);
       }

       if (vm.count(INPUT)) {
           string tmp = vm[INPUT].as< string >();
           ifstream infile;
           infile.open(tmp.c_str(), ofstream::in);

           if (!infile.good())
           {
               cerr << "Could not open input file " << tmp << endl;
           }

           gComment.format(infile);
       }
       else
       {
           // no template specified, we simply use standard in.
           gComment.format(cin);
       }

       if (vm.count(OUTPUT)) {
           string tmp = vm[OUTPUT].as< string >();
           ofstream file;
           file.open(tmp.c_str(), ofstream::out);

           if (!file.good())
           {
               cerr << "Could not open output file " << tmp << endl;
           }

           file << gComment.getResults();
           file.close();
       }
       else
       {
           // if no files specified, we dump to std::cout, and
           // we only do it once.
           std::cout << gComment.getResults();
       }
    }
    catch(...) {
        cout << "Invalid arguments.  See --help for proper options.\n\n";
    }


    return 0;
}


