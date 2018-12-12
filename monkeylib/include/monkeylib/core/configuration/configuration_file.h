/**
 *  @file: configuration_file.h
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
namespace Configuration
{

//! \brief Configuration File Interface
//!
//! This class defines a generic interface for configuration file(s).  A 
//! configuration file contains settings for various applications.  It
//! may be an INI file, a text configuration file, YAML file, JSON file,
//! or even an XML file.
//!
//! The commonality with configuration files is
class ConfigurationFile
{
public:

    //! \brief Load and parse the configuration file
    virtual int load() = 0;

    //! \brief Save the configuration file.
    virtual int save() = 0;
    
    //! \brief Get the configuration file's location
    //!
    //! \returns
    //!		path and filename of the configuration file.
    virtual std::string get_file_location() const;

    virtual void set_file_location(const char *location);
    virtual void set_file_location(const std::string &location);

protected:

    //! absolute or relative path and filename of where the configuration
    //! file is stored.
    std::string _location;
};

}
}
