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
#include <monkeylib/core/file_utilities.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <fcntl.h>
#include <unistd.h>
#include <utime.h>
#include <dirent.h>

#include <iostream>
#include <string>

#include <fstream>
#include <cstdlib>

namespace Monkey {

bool does_file_exist (const std::string& filename) {
    struct stat buffer;
    return (stat (filename.c_str(), &buffer) == 0);
}

bool does_directory_exist( const char* pzPath )
{
    if ( pzPath == NULL) return false;

    DIR *pDir;
    bool bExists = false;

    pDir = opendir (pzPath);

    if (pDir != NULL)
    {
        bExists = true;
        (void) closedir (pDir);
    }

    return bExists;
}

int touch(const std::string& pathname)
{
    int fd = open(pathname.c_str(),
                  O_WRONLY|O_CREAT|O_NOCTTY|O_NONBLOCK,
                  0666);
    if (fd<0) // Couldn't open that path.
    {
        // Couldn't open() path 
        return -1;
    }
    int rc = utimensat(AT_FDCWD,
                       pathname.c_str(),
                       nullptr,
                       0);
    if (rc)
    {
        return -1;  // Couldn't utimensat() path 
    }

    return 0;
}

bool string_to_file(const std::string& pathname, const std::string &data, bool create = false)
{

    if (does_file_exist(pathname))
    {
        // if the file exists, but we aren't allowed to create it.. return error.
        if (create == false)
        {
            return false;
        }
        else
        {
            remove(pathname.c_str());
        }
    }

    std::ofstream out(pathname);
    out << data;
    out.close();

    return true;
}


}