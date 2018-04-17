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

#include "codesCompressor.hpp"

/** 
 * @brief  Constructor of CodesCompressor class
 * @param  folders: vector of string indiquate folder where search for file to compress
 * @note   ex folder = { "" , "css" }
 * @retval None
 */
CodesCompressor::CodesCompressor(std::vector<std::string> folders)
{
    this->setFolder(folders[0] , folder[1]);
    this->setIndex(0);
    this->setFilesCount(0);
    this->setFilesProcessed(0);

    this->loadFiles();

    this->compress();
}

CodesCompressor::~CodesCompressor()
{
	this->stop();
}

/** 
 * @brief  function use to load files in folder selected by user
 * @retval None
 */
void CodesCompressor::loadFiles()
{
    /*
    Parcourir les dossiers indiqué par l'utilisateur et les stockers dans le vecteur files
    */
}

/** 
 * @brief  function use to launch compressor on files
 * @retval None
 */
void CodesCompressor::compress()
{
    for(int i = 0; i < this->count; i++){
        this->files[i]->compress();
    }
}

/** 
 * @brief  function use to stop compressor on files
 * @retval None
 */
void CodesCompressor::stop()
{
    for(int i = 0; i < this->count; i++){
        this->files[i]->stop();
    }
}

/** 
 * @brief  function use to load profils from profils'file
 * @retval None
 */
void CodesCompressor::loadProfils()
{

}

/** 
 * @brief  function use to translate a profil
 * @param  filePath: string to translate
 * @retval None
 */
void CodesCompressor::setProfil( std::string filePath)
{
    auto c = explode(filePath, '+');
    this->_profil( std::make_unique( new Profil( c[0] , c[1] ) ) );
}

void CodesCompressor::saveProfil()
{
    this->profil->save();
}

/*******************************************/
/************* Accesseur *******************/
/*******************************************/

inline int CodesCompressor::getFilesCount()
{
    return this->_filesCount;
}

inline int CodesCompressor::getFilesProcessed()
{
    return this->_filesProcessed;
}

inline int CodesCompressor::getIndex()
{
    return this->_index;
}

inline std::vector<std::string> CodesCompressor::getFolder()
{
    return this->_folder;
}

inline std::string CodesCompressor::getJsFolder()
{
    return this->_folder[0];
}

inline std::string CodesCompressor::getCssFolder()
{
    return this->_folder[1];
}

/*******************************************/
/************* Mutateur ********************/
/*******************************************/

inline void CodesCompressor::setFilesCount(int count)
{
    this->_filesCount = count;
}

inline void CodesCompressor::setFilesProcessed(int processed)
{
    this->_filesProcessed = processed;
}

inline void CodesCompressor::setIndex( int index)
{
    this->_index = index;
}

inline void CodesCompressor::setFolder(std::string jsFolder, std::string cssFolder)
{
    this->_folder[0] = jsFolder;
    this->_folder[1] = cssFolder;
}

inline void CodesCompressor::setJsFolder(std::string jsFolder)
{
    this->_folder[0] = jsFolder;
}

inline void CodesCompressor::setCssFolder(std::string cssFolder)
{
    this->_folder[1] = cssFolder;
}
