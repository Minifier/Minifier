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

#include "compressFile.hpp"

CompressFile::CompressFile( std::string filePath)
{
    this->exist = false;
    this->change = false;
    this->type = "none";
    this->filePath = filePath;
    this->outputFile = "" ; // Faire le bon traitement ici
}

CompressFile::~CompressFile()
{
}

/** 
 * @brief  void function
 * @note   
 * @retval None
 */
inline void CompressFile::compress()
{
    throw "Not implemented";
}


/*******************************************/
/************* Acesseur ********************/
/*******************************************/

inline bool CompressFile::getChange()
{

}
inline bool CompressFile::getExist()
{

}
inline std::string CompressFile::getFilePath()
{

}
inline std::string CompressFile::getOutputFile()
{

}
inline std::string CompressFile::getType()
{

}


/*******************************************/
/************* Mutateur ********************/
/*******************************************/

inline void CompressFile::setChange(bool change)
{
    this->_change = change;
}
inline void CompressFile::setExist(bool exist)
{
    this->_exist = exist;
}
inline void CompressFile::setFilePath(std::string filePath)
{
    this->_filePath = filePath;
    //TODO Mettre en place l'output filepath en meme temps
    
}