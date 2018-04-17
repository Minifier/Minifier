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

#include "profil.hpp"

Profil::Profil( std::string folderJS , std::string folderCSS )
{
    this->jsFolder = folderJS;
    this->cssFolder = folderCSS;
}

Profil::~Profil()
{
}

/** 
 * @brief  function use to add profil into profil.txt
 * @retval None
 */
void Profil::save()
{
    return writeEndFile( PROFIL_PATH , this->fileName());
}

/** 
 * @brief  function use to convert jsFolder and cssFolder into profil
 * @retval encode string "jsFolder+cssFolder"
 */
std::string Profil::fileName()
{
    return this->jsFolder + "+" + this->cssFolder;
}


/*******************************************/
/************* Accesseur *******************/
/*******************************************/

std::string Profil::getJsFolder()
{
    return this->jsFolder;
}
std::string Profil::getCssFolder()
{
    return this->cssFolder;
}


/*******************************************/
/************* Mutateur ********************/
/*******************************************/

void Profil::setJsFolder( std::string jsFolder)
{
    this->jsFolder = jsFolder;
}

void Profil::setCssFolder( std::string cssFolder)
{
    this->cssFolder = cssFolder;
}
