/**
 *  @file: command.h
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

namespace Monkey
{
namespace Patterns
{

//! \brief Command pattern interface class
//!
//! The command pattern is a behavioral design pattern in which
//! an object is used to encapsulate all the information needed to
//! perform an action, now or later.
//!
//! Command decouples the object that invokes the operation from
//! the code that wishes to perform the action(s).
//!
//! To use, create one or more derived classes that encapsulate some
//! parameters and actions.
//!
//! Common usages:
//! - undo and redo actions
//! - asynchronous method invocations
//! - and more
class Command {
public:
    virtual void execute() = 0;

};

class UndoableCommand : public Command
{
public:

    virtual void execute() = 0;

    virtual void redo() = 0;

    virtual void undo() = 0;
};
}
}


