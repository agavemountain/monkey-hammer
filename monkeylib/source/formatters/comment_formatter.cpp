/**
 *  @file: CommentFormatter.cpp
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
#include <monkeylib/core/formatters/comment_formatter.h>

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>


namespace Monkey
{
namespace Formatters
{

CommentFormatter::CommentFormatter()
{
}

CommentFormatter::~CommentFormatter()
{
}

void CommentFormatter::setMultiLinePrefix(std::string prefix)
{
    mPrefix = prefix;
}

void CommentFormatter::setMultiLinePostfix(std::string postfix)
{
    mPostfix = postfix;
}

void CommentFormatter::setLinePrefix(std::string prefix)
{
    mLinePrefix = prefix;
}

std::string CommentFormatter::getResults()
{
    return mOutput;
}

void CommentFormatter::applyMultiLinePrefix()
{
    // multi-line postfix (on it's own line)
    if (mPrefix.length())
    {
        mOutput += mPrefix + "\n";
    }
}

void CommentFormatter::applyMultiLinePostfix()
{
    // multi-line postfix (on it's own line)
    if (mPostfix.length())
    {
        mOutput += mPostfix + "\n";
    }
}

void CommentFormatter::processLine(std::string &str)
{
    // @TODO word wrap.
    if (mLinePrefix.length())
    {
        mOutput += mLinePrefix ;
    }

    mOutput += str + "\n";
}

std::string CommentFormatter::format(std::string text)
{
    applyMultiLinePrefix();
    processLine(text);
    applyMultiLinePostfix();

    return mOutput;
}

std::string CommentFormatter::format(const char *array[])
{
    applyMultiLinePrefix();
    for (int i=0; *array[i]; i++)
    {
        std::string tmp = array[i];
        processLine(tmp);
    }

    applyMultiLinePostfix();

    return mOutput;
}

/*
 * This function will read from the input
 * string and place the results in the output
 * string (above).  This builds the properly
 * formatted stanza and then returns.
 *
 * %PREFIX
 * %PRE my comment
 * %PRE my comment too
 * %POSTFIX
 */
std::string CommentFormatter::format(std::istream &in)
{
    applyMultiLinePrefix();

    std::string line="";
    while (std::getline(in, line))
    {
        processLine(line);
    }

    applyMultiLinePostfix();

    return mOutput;
}

std::string CommentFormatter::format(const char *strchar)
{
    std::string tmp = strchar;
    std::stringstream ss(tmp);
    std::string line;

    applyMultiLinePrefix();
    if (strchar != NULL)
    {

        while(std::getline(ss,line,'\n')) {
            processLine(line);
        }
    }
    applyMultiLinePostfix();

    return mOutput;
}

/**
 * Most language adhere to C comments.  Setup the
 *
 * PHP, MYSQL, Objective C, C, C++, and JavaScript
 */
void CommentFormatter::setCLanguage()
{
    setMultiLinePrefix("/*");
    setLinePrefix(" * ");
    setMultiLinePostfix(" */");
}

/**
 * Set RUBY
 */
void CommentFormatter::setRubyLanguage()
{
    setMultiLinePrefix("begin==");
    setLinePrefix("");
    setMultiLinePostfix("end==");
}

/**
 * Set PYTHON
 */
void CommentFormatter::setPythonLanguage()
{
    setMultiLinePrefix("\'\'\'");
    setLinePrefix("");
    setMultiLinePostfix("\'\'\'");
}

void CommentFormatter::setXMLLanguage()
{
    setMultiLinePrefix("<!--");
    setLinePrefix("");
    setMultiLinePostfix("-->");
}

void CommentFormatter::setBashLanguage()
{
    setMultiLinePrefix("#");
    setLinePrefix("# ");
    setMultiLinePostfix("#");
}

//void CommentFormatter::setLanguage(int language)
//{
//    switch (language)
//    {
//    case BASH:
//        setBashLanguage();
//        break;
//
//    case CPP:
//    case JAVASCRIPT:
//    case PERL:
//        setCLanguage();
//        break;
//
//    case RUBY:
//        setRubyLanguage();
//        break;
//    case XML:
//        setXMLLanguage();
//        break;
//
//    case PYTHON:
//        setPythonLanguage();
//        break;
//
//    case HTML:
//        setXMLLanguage();
//        break;
//
//    default:
//        break;
//    }
//}

void CommentFormatter::execute(std::istream &in)
{
    format(in);
}

void CommentFormatter::execute(std::string &in)
{
    format(in);
}

}
}

