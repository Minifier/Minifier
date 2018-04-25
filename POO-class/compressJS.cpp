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

#include "compressJS.hpp"

CompressJS::CompressJS(std::string filePath) : CompressFile{filePath}
{
    this->setType("js");
    auto c = explode(filePath, '.');
    if(c.size() == 2){
        this->setOutputFile("" + c[0] + ".min.js");
    }else{
        std::string path = "";
        for( int i = 0; i < c.size()-1 ; i++){
            path += c[i].c_str();
        }
        this->setOutputFile("" + path + ".min.js");
    }
    this->filesize = getFileSize(this->filePath);
    if(this->fileSize != -1){
        this->content = sToc(readFile(this->filePath ));
    }else{
        throw;
    }
}

CompressJS::~CompressJS()
{
    this->stop();
}

/** 
 * @brief  function use to compress a js file
 * @retval None
 */
void CompressJS::compress()
{
    if (peek() == 0xEF) {
        this->get();
        this->get();
        this->get();
    }
    this->A = '\n';
    this->action(3);
    while (this->A != EOF) {
        switch (this->A) {
        case ' ':
            this->action(this->isAlphanum(this->B) ? 1 : 2);
            break;
        case '\n':
            switch (this->B) {
            case '{':
            case '[':
            case '(':
            case '+':
            case '-':
            case '!':
            case '~':
                this->action(1);
                break;
            case ' ':
                this->action(3);
                break;
            default:
                this->action(this->isAlphanum(this->B) ? 1 : 2);
            }
            break;
        default:
            switch (this->B) {
            case ' ':
                this->action(this->isAlphanum(this->A) ? 1 : 3);
                break;
            case '\n':
                switch (this->A) {
                case '}':
                case ']':
                case ')':
                case '+':
                case '-':
                case '"':
                case '\'':
                case '`':
                    this->action(1);
                    break;
                default:
                    this->action(this->isAlphanum(this->A) ? 1 : 3);
                }
                break;
            default:
                this->action(1);
                break;
            }
        }
    }
}

/** 
 * @brief  function use to stop compressor
 * @retval None
 */
void CompressJS::stop()
{

}

static void CompressJS::error()
{

}

static int CompressJs::isAlphanum(int c) 
{ return ( ( c >= 'a' && c <= 'z') || ( c >= 'A' && c <= 'Z') || ( c >=  0  && c <=  9 ) || c == ' ' || c == '$' || c == '\\' || c > 126) ) ; }

static int CompressJs::get()
{
    int c = this->nextChar;
    this->nextChar = EOF;
    if (c == EOF) {
        c = getc(stdin);
    }
    if (c >= ' ' || c == '\n' || c == EOF) {
        return c;
    }
    if (c == '\r') {
        return '\n';
    }
    return ' ';
}

static int CompressJs::next()
{
    int c = this->get();
    if  (c == '/') {
        this->peek();
        switch (this->nextChar) {
        case '/':
            for (;;) {
                c = this->get();
                if (c <= '\n') {
                    break;
                }
            }
            break;
        case '*':
            this->get();
            while (c != ' ') {
                switch (this->get()) {
                case '*':
                    this->peek();
                    if (this->nextChar == '/') {
                        this->get();
                        c = ' ';
                    }
                    break;
                case EOF:
                    this->error("Unterminated comment.");
                }
            }
            break;
        }
    }
    this->Y = this->X;
    this->X = c;
    return c;
}

static int CompressJs::action()
{
    switch (d) {
    case 1:
        putc(this->A, stdout);
        if (
            (this->Y == '\n' || this->Y == ' ') &&
            (this->A == '+' || this->A == '-' || this->A == '*' || this->A == '/') &&
            (this->B == '+' || this->B == '-' || this->B == '*' || this->B == '/')
        ) {
            putc(this->Y, stdout);
        }
    case 2:
        this->A = this->B;
        if (this->A == '\'' || this->A == '"' || this->A == '`') {
            for (;;) {
                putc(this->A, stdout);
                this->A = get();
                if (this->A == this->B) {
                    break;
                }
                if (this->A == '\\') {
                    putc(this->A, stdout);
                    this->A = get();
                }
                if (this->A == EOF) {
                    error("Unterminated string literal.");
                }
            }
        }
    case 3:
        this->B = next();
        if (this->B == '/' && (
            this->A == '(' || this->A == ',' || this->A == '=' || this->A == ':' ||
            this->A == '[' || this->A == '!' || this->A == '&' || this->A == '|' ||
            this->A == '?' || this->A == '+' || this->A == '-' || this->A == '~' ||
            this->A == '*' || this->A == '/' || this->A == '{' || this->A == '\n'
        )) {
            putc(this->A, stdout);
            if (this->A == '/' || this->A == '*') {
                putc(' ', stdout);
            }
            putc(this->B, stdout);
            for (;;) {
                this->A = get();
                if (this->A == '[') {
                    for (;;) {
                        putc(this->A, stdout);
                        this->A = get();
                        if (this->A == ']') {
                            break;
                        }
                        if (this->A == '\\') {
                            putc(this->A, stdout);
                            this->A = get();
                        }
                        if (this->A == EOF) {
                            error("Unterminated set in Regular Expression literal.");
                        }
                    }
                } else if (this->A == '/') {
                    switch (peek()) {
                    case '/':
                    case '*':
                        error("Unterminated set in Regular Expression literal.");
                    }
                    break;
                } else if (this->A =='\\') {
                    putc(this->A, stdout);
                    this->A = get();
                }
                if (this->A == EOF) {
                    error("Unterminated Regular Expression literal.");
                }
                putc(this->A, stdout);
            }
            this->B = next();
        }
    }
}