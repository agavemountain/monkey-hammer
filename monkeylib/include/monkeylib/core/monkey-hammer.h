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
#pragma once

/*! \mainpage

    <table>
        <tr><th>Project     <td>Monkey Hammer code tools
        <tr><th>File        <td>SimpleIni.h
        <tr><th>Author      <td>Joe Turner
        <tr><th>Source      <td>https://github.com/agavemountain/monkey-hammer
        <tr><th>Version     <td>0.0.0
    </table>


 \section intro Introduction

 Welcome to the Monkey Hammer suite of code tools.

 Over the years, I have written hackish-quick-and-dirty utilities to generate
 code and automate various development tasks.  This project is a collection
 of those tools, in an combined and re-factored form.

 \tableofcontents

 \section Requirements

 - Doxygen 1.8.0+ (for markdown support) and GraphViz.
 - GNU GCC toolchain
 - Git (obviously)
 - CPPUNIT (for unit tests)

\section make Building and Installing

 \code
 $ mkdir build
 $ cmake ..
 $ make;
 $ sudo make install
 \endcode

\section uninstall Uninstalling

\code
$ sudo make uninstall
\endcode

 \section Generating Documentation

 This project uses doxygen to generate the documentation.  To generate
 this documentation, you must have doxygen installed.  Simple execute doxygen:
 \code
 $ make doc
 \endcode


 \section Running Unit Tests

 You can run unit tests (if cppunit is installed on your development workstation):

 \code
 $ ctest -VV
 \endcode


*/

//! \brief Monkey Hammer namespace
//!
//! Namespaces allow us to group named entities that otherwise would
//! have global scope into narrower scopes, giving them namespace scope.
//! This allows organizing the elements of programs into different logical
//! scopes referred to by names.
//!
//! Per good standards, all of the Monkey Hammer code is contained within a
//! namespace.
namespace Monkey
{

//! \brief Re-usable design patterns and idioms
//!
//! This namespace contains reusable idioms and design patterns.
namespace Patterns
{
}

//! \brief Config files
//!
//! This namespace contains code dealing with loading, parsing, 
//! generating, and saving configuration files for various change control
//! systems, and code generation tools.
namespace Configuration
{
}

//! \brief Text formatters
//!
//! This namespace contains code dealing with transforming text.
namespace Formatters
{
}

}

/**
 \page commenting Commenting Utility

 As a technical mercenary (consultant), I've had the pleasure of working in
 a variety of industries and with a myriad of clients.  While I generally follow
 the style of the code I'm editing, I do run into developers with unusually
 strong opinions about code comment formatting, especially where copyright
 headers and class documentation are concerned.

 I gave up and wrote this handy-dandy utility for generating properly formatted
 copyright headers and code comments.  This is the remnants of those scripts,
 rewritten and refactored in C++.

 This application does not strip or alter code.  It will simply prepend and
 format the stream of text that is passed through it, via standard I/O

 \section Examples

 For the following examples, we assume we are using the following imaginary example file (named myfile),
 with the following content:
 \code
 This is a test
 This is a comment
 \endcode

 \subsection Redirection
 ---------
 Without specifying an input file and output file:
 - If no input file is specified, standard input is used
 - If no output file is specified, standard output is used

 Therefore, you can take a file and pipe it to the monkeyhammer utility
 which will take the input and format it which can be dumped into a
 file (named myoutputfile in the following example):
 \code
 $ cat myfile | mhcomment > myoutputfile
 \endcode

 Additionally, you can append it to an existing file:
 \code
 $ cat myfile | mhcomment  >> myoutputfile
 \endcode

 \subsection singleline Single Line Comments

 You can choose to prefix each line with a string.  For bash files, or Perl
 headers you'd want to use the # symbol.  For C++, // would rule the day.

 \code
 $ mhcomment --input myfile  --comment-pre "# "
 # This is a test
 # This is only a test
 \endcode

 \subsection multiline Multi-Line Comments
 ------
 More importantly, you can specify how multi-line comments are formatted.
 \code
 $ mhcomment --input myfile --comment-prefix "//!" --comment-pre " #" --comment-postfix "//!"
//!
 # This is a test
 # This is only a test
//!
 \endcode

Language specifier.  To list the
 \code
 $ mhcomment --input myfile --language javascript
/*
 * This is a test
 * This is only a test
 */
\endcode
*/
