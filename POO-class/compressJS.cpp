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
    char result[this->fileSize];
    for (size_t i = 0; i < this->content.size(); i++)
    {
        char ** str = & this->content[i];

        // Cmt let's know us if we have a '/*' open and we wait to close it
        bool cmt = false;
        bool lcmt = false;

        for ( char *p = *str ; *p != '\n' ; p++ )
        {
            if( get(*p) == '/' && !cmt )
            {
                switch( get(*(p+1)) )
                {
                    case '/':
                        lcmt = true;
                        p++;
                        break;
                    case '*':
                        cmt = true;
                        p++;
                        break;
                    default:
                        break;
                }

            } else if(cmt)
            {
                // If we have the end of the cmt
                if(*p == '*'  && *(p+1) == "/")
                {
                    p += 2;
                }
            }else if(!lcmt)
            {
                *result = *p;
                result++;
            }
        }
    }
    writeCompressFile(this->getOutputFile() , result);
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
{ return ( ( c >= 'a' && c <= 'z') || ( c >= 'A' && c <= 'Z') || ( c >=  0  && c <=  9 ) || c == ' ' || c == '$' || c == '\\' || c > 126)  ; }