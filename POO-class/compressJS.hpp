/*******************************************************************
Copyright (C) 2018 Oscar MARIE--TAILLEFER   <o5mariet@enib.fr>
Copyright (C) 2018 Nils JEGOU-GERGAUD       <n5jegoug@enib.fr>
Copyright (C) 2018 Nicols FRANCIS           <n4franci@enib.fr>
Copyright (C) 2018 Corentin LAMBERT         <c4lamber@enib.fr>

This file is part of Minifier.

Minifier is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Minifier is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Minifier.  If not, see <http://www.gnu.org/licenses/>.
*******************************************************************/

#ifndef compress_js_hpp
#define compress_js_hpp 1

#include <string>
#include <stdlib>
#include <stdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "CompressFile.hpp"
#include "utils.hpp"

namespace code_compressor {

class CompressJS : public CompressFile
{
public:
    CompressJS( std::string filePath );
    CompressJS(CompressJS &&) = default;
    CompressJS(const CompressJS &) = default;
    CompressJS &operator=(CompressJS &&) = default;
    CompressJS &operator=(const CompressJS &) = default;
    ~CompressJS();

    void compress() override;
    void stop() override;

    // Function use to print an error during compression
    static void error();

    // Function use to test if a char is alphanum
    // An alphanum char is  a letter, digit, underscore, dollar sign, or non-ASCII character.
    static int isAlphanum(int c);

    // Function use to get the next char from stdin
    static int get();

    // Function use to look at the next char without getting it
    static void peek();

    // Function use to get the next char, excluding comments
    static int next();
    
    /* action
            1   Output A. Copy B to A. Get the next B.
            2   Copy B to A. Get the next B. (Delete A).
            3   Get the next B. (Delete B).
    */

    // Function use to do some action.
    static int action();

private:
    static int   A,B,X,Y,nextChar;
    int fileSize;
    std::vector<char *> content  ;
    std::vector<char *> compress ;
};

} //end code_compressor

#endif
