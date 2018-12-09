/**
 *  @file: environment.h
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
#include <string>

namespace Monkey
{

//! @brief Environment variables
//!
//! Environment Variables
//!
//! This class wraps the code necessary to get and set environment
//! variables in a cross-platform friendly way, taking into consideration
//! CERT's Secure Programming best practices.  The design of the
//! class interface borrows from Python, and leverages
//! operator overloading to make it easier to use.
//!
//! CERT NOTES:
//! - Don't trust environment variables
//! - The only standard C99 function is getenv()
//! - Make sure you have created a safe environment before calling exec*()or
//!   system()
//!
//! \todo ENV03-C Sanitize the environment when invoking external programs
//! \todo set IFS environment variable.
//!
//! \code
//!   Environment env;
//!   cout << env.home_path();
//!   env.set("HELLO", "WORLD");
//!   cout << env["HELLO"] << " should equal: " << env.get("HELLO") << endl;
//! \endcode
//!
class Environment
{
public:
    //! Get environment variable
    //!
    //! The value returned by getenv() is wrapped in a string object.  This
    //! automatically copies the data, avoiding a potential dangling pointer, and
    //! eliminates the potential for a buffer overrun.
    //!
    //! \param a_key	name of the environment variable to lookup
    //!
    //! \returns
    //!  	Returns empty string if no environment variable is defined,
    //!		or the environment variable as a string.
    static std::string get(std::string const& a_key) ;

    //! Get environment variable
    //!
    //! The value returned by getenv() is wrapped in a string object.  This
    //! automatically copies the data, avoiding a potential dangling pointer, and
    //! eliminates the potential for a buffer overrun.
    //!
    //! \param a_key	name of the environment variable to lookup
    //!
    //! \returns
    //!  	Returns empty string if no environment variable is defined,
    //!		or the environment variable as a string.
    static std::string get(const char * a_key) ;

    //! Add or modify an environment variable
    //!
    //! \param a_key	name of the environment variable to lookup
    //! \param a_value	value of the environment
    //!
    //! \returns
    //!		This function returns the result from the setenv call.  A 0
    //! 	is returned if the operation was successful, else -1 if
    //!		there was insufficient space.
    static int set(std::string const& a_key, std::string const& a_value);

    //! Add or modify an environment variable
    //!
    //! \param a_key	name of the environment variable to lookup
    //! \param a_value	value of the environment
    //!
    //! \returns
    //!		This function returns the result from the setenv call.  A 0
    //! 	is returned if the operation was successful, else -1 if
    //!		there was insufficient space.
    static int set(const char *a_key, const char *a_value);

    //! Check to see if an environment variable exists.
    //!
    //! \param a_key	name of the environment variable to lookup
    //!
    //! \returns
    //! 	If the environment variable exists, it returns true.
    //!		If it does not, this function returns false.
    bool isExists(const char *a_key);

    //! Check to see if an environment variable exists.
    //!
    //! \param a_key	name of the environment variable to lookup
    //!
    //! \returns
    //! 	If the environment variable exists, it returns true.
    //!		If it does not, this function returns false.
    bool isExists(std::string &a_key);

    //! Erase (unset) a specific environment variable.
    //!
    //! \param a_key	name of the environment variable to lookup
    //!
    //! \returns
    //!		This function returns the result from the setenv call.  A 0
    //! 	is returned if the operation was successful, else -1 if
    //!		there was an error.
    int erase(std::string const& a_key);

    //! Erase (unset) a specific environment variable.
    //!
    //! \param a_key	name of the environment variable to lookup
    //!
    //! \returns
    //!		This function returns the result from the setenv call.  A 0
    //! 	is returned if the operation was successful, else -1 if
    //!		there was an error.
    int erase(const char *a_key);

    //! Clear the environment
    //!
    //! This function will remove all name-value pairs, and should be used
    //! in security-conscious applications.
    bool clearAll();

    //! returns a vector of all environment variables.
    //std::vector<std::string> getAll();

    const std::string operator[](const char *a_name) const;
    const std::string operator[](const std::string &a_name) const;

    //! Retrieve users's home path
    //!
    //! This function is a cross-platform method for retrieving the user's
    //! home path.
    //!
    //! - If this is Linux, getenv("HOME") contains the home path.
    //! - If this is Windows, env USERPROFILE, followed by getenv("HOMEDRIVE")
    //!   and getenv("HOMEPATH") are concatinated.
    //! - OS X getpwuid for GIU applications.
    //!
    static std::string home_path();

};

}; // namespace Monkey