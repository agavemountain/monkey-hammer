/**
 *  @file: monkey_hammer_config.h
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
#include <monkeylib/core/configuration/simpleini/SimpleIni.h>
#include <monkeylib/core/configuration/configuration_file.h>

namespace Monkey
{
namespace Configuration
{
    //! \brief Monkey Hammer Configuration File
    //!
    //! The monkey hammer applications will load a configuration file
    //! stored in the user's home directory with the various configuration
    //! options.
    //!
    class MonkeyHammerConfigurationFile : public ConfigurationFile
    {
    public:
        MonkeyHammerConfigurationFile();

        //! \brief Load and parse the configuration file
        virtual int load();

        //! \brief Save the configuration file.
        virtual int save();
        
        std::string get_username() const;
        std::string get_company() const;
        std::string get_email_address() const;

        void set_username(std::string & username);
        void set_company(std::string & company);
        void set_email_address(std::string & email_address);

    private:
        std::string _username;
        std::string _email_address;
        std::string _company;
    };
}
}
