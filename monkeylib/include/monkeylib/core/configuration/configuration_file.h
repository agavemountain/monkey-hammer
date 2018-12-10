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
    virtual int load();

    //! \brief Save the configuration file.
    virtual int save();
    
protected:

    //! absolute or relavite path and filename of where the configuration
    //! file is stored.
    std::string _location;
};

}
}
