/**
 *  @file: CommentFormatter.h
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
#include <monkeylib/core/patterns/command.h>

namespace Monkey
{
namespace Formatters
{

//! \brief Code comment block formatter
//!
//! Formatter for a block of comments.  This formatter will transform
//! a block of text for a variety of languages (simply set the proper
//! comment delimiters and execute.
//!
class CommentFormatter //: public Command
{
public:
    CommentFormatter();
    virtual ~CommentFormatter();

    virtual void execute(std::istream &in);
    virtual void execute(std::string &in);

    //! set the multi-line postfix (prepended to the beginning the multiple line
    //! block of text.
    void setMultiLinePrefix(std::string prefix);

    //! set the multi-line postfix (appended to after the multiple line
    //! block of text.
    void setMultiLinePostfix(std::string postfix);

    //! set the line prefix, which is prepended to each line.
    void setLinePrefix(std::string prefix);

    //! format one or more lines of text into a comment.
    std::string format(std::string text);

    //! take an array of C-style, null terminated strings and
    //! turn it into a properly formatted comment.
    std::string format(const char *array[]);

    std::string format(const char *strchar);

    //! given an istream, turn it into comments.
    std::string format(std::istream &in);

    //! returns the results of the format operation.
    std::string getResults();

private:
    void setRubyLanguage();
    void setCLanguage();
    void setXMLLanguage();
    void setPythonLanguage();
    void setBashLanguage();


    void applyMultiLinePrefix();
    void applyMultiLinePostfix();
    void processLine(std::string &str);

    std::string mPrefix;				//!< multi-line prefix
    std::string mPostfix;				//!< multi-line postfix
    std::string mLinePrefix;			//!< prefix for each comment line
    std::string mOutput; 				//!< temporary output buffer.
};
}
}
