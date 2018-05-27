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
#ifndef utils_hpp
#define utils_hpp 1

#include <QString>
#include <QStringList>

#include <windows.h>
#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include <iostream>
#include <fstream>
#include <stdio.h>

#include "CImg.h"

struct rgb{
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

inline void to_rgb(const unsigned char &r, const unsigned char &g, const unsigned char &b, rgb * dist)
{
    (*dist).r = r;
    (*dist).g = g;
    (*dist).b = b;
}
/**
 *@brief readJPEG function use to read a jpeg file
 *@param filePath file file's path
 *@param res list of rgb
 *@param w weight of picture
 *@param h height of picture
 */
void readJPEG(const char* &filePath, rgb *& res , unsigned int * w, unsigned int * h);

/**
 * @brief explode explode a string by delim
 * @param s string to explode
 * @param delim char for explode
 * @return vector<string> string exploded
 */
std::vector<std::string> explode(std::string const & s, char delim);

/**
 * @brief readFile read file with filepath
 * @param filePath filepath of the file
 * @return vector<string> content of the file
 */
std::vector<std::string> readFile(std::string filePath);

/**
 * @brief readFile read file with filepath
 * @param filePath filepath of the file
 * @return content of the file
 */
QStringList readFile(const QString &filePath);

/**
 * @brief writeFile write file
 * @param filePath filepath of the file
 * @param content content to write in the file
 * @return true|false success
 */
bool writeFile(std::string filePath, std::vector<std::string> content);

/**
 * @brief writeFile write file
 * @param filePath filepath of the file
 * @param content content to write in the file
 * @return true|false success
 */
bool writeFile(QString filePath, QStringList content);

/**
 * @brief writeFile add content to a file
 * @param filePath filepath of the file
 * @param content content to write in the file
 * @return true|false success
 */
bool writeEndFile(std::string filePath, std::vector<std::string> content);

/**
 * @brief writeFile add content to a file
 * @param filePath filepath of the file
 * @param content content to write in the file
 * @return true|false success
 */
bool writeEndFile(const QString &filePath, const QStringList &content);

/**
 * @brief deleteFile delete file
 * @param filePath filepath of the file
 * @return status
 */
int deleteFile(std::string filePath);

/**
 * @brief createFile create file
 * @param filePath filepath of the file
 * @return true|false success
 */
bool createFile(std::string filePath);

/**
 * @brief getFileSize get file's size
 * @param fileName filepath of the file
 * @return -1 if the file could not be opened
 */
int getFileSize(const std::string &fileName);

/**
 * @brief ExePath get path where program is execute
 * @return path where program is execute
 */
QString ExePath();

#endif
