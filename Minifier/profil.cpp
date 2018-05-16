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

#include "profil.h"

/**
 * @brief Profil constructor of profil class
 * @param folderJS path to js folder
 * @param folderCSS path to css folder
 * @param profilName profil's name
 */
code_compressor::Profil::Profil(const QString &folderJS, const QString &folderCSS, const QString &cfgName)
{
    this->setCssFolder(folderCSS);
    this->setJsFolder(folderJS);
    this->configName = cfgName;
}

/**
 * @brief Profil constructor of profil class
 * @param folderJS path to js folder
 * @param folderCSS path to css folder
 */
code_compressor::Profil::Profil( const QString &folderJS, const QString &folderCSS)
{
    this->setJsFolder(folderJS);
    this->setCssFolder(folderCSS);
}

/**
 * @brief Profil constructor of profil class
 * @param folders list(cssFolder,jsFolder)
 * @param profilName profil's name
 */
code_compressor::Profil::Profil(const QStringList &folders, const QString &profilName)
{
    this->setCssFolder(folders.at(0));
    this->setJsFolder(folders.at(1));
    this->configName = profilName;
}

/**
 * @brief Profil constructor of profil class
 * @param folders list(cssFolder,jsFolder)
 */
code_compressor::Profil::Profil(const QStringList &folders)
{
    this->setCssFolder(folders.at(0));
    this->setJsFolder(folders.at(1));
}

code_compressor::Profil::~Profil()
{
}

/**
 * @brief save write profil's data in profil.txt
 * @param cfgName profil's name
 * @return true|false state
 */
bool code_compressor::Profil::save(const QString &cfgName)
{
    QStringList ctn;
    ctn << cfgName << this->fileName();
    return writeEndFile((ExePath() + PROFIL_FILE ), ctn);
}

/**
 * @brief fileName get file's info
 * @return QString(cssFolder,jsFolder)
 */
QStringList code_compressor::Profil::fileName()
{
    QStringList retval;
    retval << this->cssFolder << this->jsFolder;
    return retval;
}

/*******************************************/
/************* Accesseur *******************/
/*******************************************/

QString code_compressor::Profil::getJsFolder()
{
    return this->jsFolder;
}

QString code_compressor::Profil::getCssFolder()
{
    return this->cssFolder;
}

QString code_compressor::Profil::getCfgName()
{
    return this->configName;
}

/*******************************************/
/************* Mutateur ********************/
/*******************************************/

void code_compressor::Profil::setJsFolder( const QString &jsFolder)
{
    this->jsFolder = jsFolder;
}

void code_compressor::Profil::setCssFolder( const QString &cssFolder)
{
    this->cssFolder = cssFolder;
}

void code_compressor::Profil::setCfgName(const QString &cfgName)
{
    this->configName = cfgName;
}
