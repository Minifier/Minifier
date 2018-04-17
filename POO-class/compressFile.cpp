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
    this->setExist(false);
    this->setChange(false);
    this->setType("none");
    this->setFilePath(filePath);
    this->setOutputFile("");
}

CompressFile::~CompressFile()
{
    this->stop();
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


/** 
 * @brief  void function
 * @note   
 * @retval None
 */
inline void CompressFile::stop()
{
    throw "Not implemented";
}

/*******************************************/
/************* Acesseur ********************/
/*******************************************/

inline bool CompressFile::getChange()
{
    return this->_change;
}
inline bool CompressFile::getExist()
{
    return this->_exist;
}
inline std::string CompressFile::getFilePath()
{
    return this->_filePath;
}
inline std::string CompressFile::getOutputFile()
{
    return this->_outputFile;
}
inline std::string CompressFile::getType()
{
    return this->_type;
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
}

inline void CompressFile::setType(std::string type)
{
    this->_type = type;
}

inline void CompressFile::setOutputFile( std::string output)
{
    this->_outputFile = output;
}
