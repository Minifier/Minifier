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

#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

/** 
 * @brief  function use to explode a string in sub-string
 * @retval None
 */
std::vector<std::string> explode(std::string const & s, char delim);

/** 
 * @brief  function use to read a file
 * @retval vector<string>: content
 */
std::vector<std::string> readFile( std::string filePath);

/** 
 * @brief  function use to write in a file
 * @retval None
 */
bool writeFile( std::string filePath , std::vector<std::string>> content );

/** 
 * @brief  function use to write at the end of a file
 * @retval None
 */
bool writeEndFile( std::string filePath , std::vector<std::string>> content );

/**
 * @brief function use to write a compress content in a file
 * @retval success
 */
bool writeCompressFile(std::string filePath , char * content );

/** 
 * @brief  function use to delete a file
 * @retval None
 */
void deleteFile( std::string filePath );

/** 
 * @brief  function use to create file
 * @retval bool: success or false (true or false)
 */
bool createFile( std::string filePath);

/**
 * @brief function use to converte std::vector<std::string> into std::vector<char *>
 * @param content : std::vector<std::string>
 */
std::vector<char *> sToc( std::vector<std::string> content);

/**
 * @brief function use to get File size
 * @retval -1 if the file could not be opened
 */
int getFileSize(const std::string &fileName);