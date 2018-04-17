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

#include "compressCSS.hpp"

CompressCSS::CompressCSS(std::string filePath) : CompressFile{filePath}
{
    this->setType("css");
    auto c = explode(filePath, '.');
    if(c.size() == 2){
        this->setOutputFile( "" + c[0] + ".min.css");
    }else{
        std::string path = "";
        for( int i = 0; i < c.size()-1 ; i++){
            path += c[i].c_str();
        }
        this->setOutputFile("" + path + ".min.css");
    }
}

CompressCSS::~CompressCSS()
{
    this->stop();
}

/** 
 * @brief  function use to compress a css file
 * @retval None
 */
void CompressCss::compress()
{
    
}

/**
 * @brief function use to stop compressor
 * @retval None
 */
void CompressCss::stop()
{
    
}
