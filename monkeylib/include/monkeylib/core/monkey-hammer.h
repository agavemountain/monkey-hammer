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


