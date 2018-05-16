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

#include "utils.h"

/**
 * @brief explode explode a string by delim
 * @param s string to explode
 * @param delim char for explode
 * @return vector<string> string exploded
 */
std::vector<std::string> explode(const std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

/**
 * @brief readFile read file with filepath
 * @param filePath filepath of the file
 * @return vector<string> content of the file
 */
std::vector<std::string> readFile(std::string filePath)
{
    std::vector<std::string> res;

    try {
        std::ifstream file(filePath.c_str(), std::ios::in);
        if (file)
        {
            std::string ligne;

            while (getline(file, ligne))
            {
                res.emplace_back(ligne);
            }

            file.close();
        }

    }
    catch (const std::exception& e) {
        throw e;
    }

    return res;
}

/**
 * @brief readFile read file with filepath
 * @param filePath filepath of the file
 * @return content of the file
 */
QStringList readFile(const QString &filePath)
{
    QStringList res;
    try {
        std::ifstream file(filePath.toUtf8(), std::ios::in);
        if (file)
        {
            std::string ligne;

            while (getline(file, ligne))
            {
                res << QString::fromStdString(ligne);
            }

            file.close();
        }

    }
    catch (const std::exception& e) {
        throw e;
    }

    return res;
}

/**
 * @brief writeFile write file
 * @param filePath filepath of the file
 * @param content content to write in the file
 * @return true|false success
 */
bool writeFile(std::string filePath, std::vector<std::string> content)
{

    try {
        std::ofstream file(filePath.c_str(), std::ios::out | std::ios::trunc);

        if (file)
        {
            for (int i = 0; i < (int)(content.size()); i++)
            {
                file << content[i] << std::endl;
            }

            file.close();
        }

    }
    catch (const std::exception& e) {
        throw e;
        return false;
    }
    return true;
}

/**
 * @brief writeFile add content to a file
 * @param filePath filepath of the file
 * @param content content to write in the file
 * @return true|false success
 */
bool writeEndFile(std::string filePath, std::vector<std::string> content)
{
    try {
        std::ofstream file(filePath.c_str(), std::ios::app);

        if (file)
        {
            for (int i = 0; i < (int)(content.size()); i++)
            {
                file << content[i] << std::endl;
            }

            file.close();
        }

    }
    catch (const std::exception& e) {
        throw e;
        return false;
    }
    return true;
}

/**
 * @brief writeFile add content to a file
 * @param filePath filepath of the file
 * @param content content to write in the file
 * @return true|false success
 */
bool writeEndFile(const QString &filePath, const QStringList &content)
{
    try {
        std::ofstream file(filePath.toUtf8(), std::ios::app);

        if (file)
        {
            for (int i = 0; i < content.size(); i++)
            {
                file << content.at(i).toUtf8().constData() << std::endl;
            }

            file.close();
        }

    }
    catch (const std::exception& e) {
        throw e;
        return false;
    }
    return true;
}


/**
 * @brief deleteFile delete file
 * @param filePath filepath of the file
 * @return status
 */
int deleteFile(std::string filePath)
{
    return remove(filePath.c_str());
}

/**
 * @brief createFile create file
 * @param filePath filepath of the file
 * @return true|false success
 */
bool createFile(std::string filePath)
{
    std::ofstream file;

    file.open(filePath.c_str(), std::ios::out);

    return file.bad();
}

/**
 * @brief getFileSize get file's size
 * @param fileName filepath of the file
 * @return -1 if the file could not be opened
 */
int getFileSize(const std::string &fileName)
{
    std::streampos begin, end;
    std::ifstream file(fileName, std::ios::binary);
    begin = file.tellg();
    file.seekg(0, std::ios::end);
    end = file.tellg();
    file.close();
    return (int)(end - begin);
}

/**
 * @brief ExePath get path where program is execute
 * @return path where program is execute
 */
QString ExePath() {
    TCHAR buffer[MAX_PATH];
    GetModuleFileName(NULL, buffer, MAX_PATH);
    std::wstring arr_w( buffer );
    std::string::size_type pos = std::string(arr_w.begin(), arr_w.end()).find_last_of("\\/");
    return QString::fromStdString(std::string(arr_w.begin(), arr_w.end()).substr(0, pos) + '\\' );
}
