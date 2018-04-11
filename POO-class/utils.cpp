#include "utils.hpp"

/** 
 * @brief  function use to explode a string in sub-string
 * @retval None
 */
std::vector<std::string> explode(std::string const & s, char delim)
{
    std::vector<std::string> result;
    std::istringstream iss(s);

    for (std::string token; std::getline(iss, token, delim); )
    {
        result.push_back(std::move(token));
    }

    return result;
}

/** 
 * @brief  function use to read a file
 * @retval vector<string>: content
 */
std::vector<std::string>> readFile( std::string filePath )
{
    std::vector<std::string>> res;

    try {
        ifstream file(filePath.c_str(), ios::in);

        if(file)
        {
            std::string ligne;

            while(getline(fichier, ligne))
            {
                res.emplace_back(ligne);
            }

            file.close();
        }

    } catch(const std::exception& e) {
        throw;
    }

    return res;
}

/** 
 * @brief  function use to write in a file
 * @retval None
 */
bool writeFile( std::string filePath , std::vector<std::string>> content )
{

    try {
        ofstream file(filePath.c_str(), ios::out | ios::trunc );

        if(file)
        {
            for( int i = 0 ; i < content.size() ; i++)
            {
                file << content[i] << std::endl;
            }

            file.close();
        }

    } catch(const std::exception& e) {
        throw;
        return false;
    }
    return true;
}

/** 
 * @brief  function use to write at the end of a file
 * @retval None
 */
bool writeEndFile( std::string filePath , std::vector<std::string>> content )
{

    try {
        ofstream file(filePath.c_str(), ios::app );

        if(file)
        {
            for( int i = 0 ; i < content.size() ; i++)
            {
                file << content[i] << std::endl;
            }

            file.close();
        }

    } catch(const std::exception& e) {
        throw;
        return false;
    }
    return true;
}

/** 
 * @brief  function use to delete a file
 * @retval None
 */
void deleteFile( std::string filePath )
{
    return remove(filePath.c_str());
}

/** 
 * @brief  function use to create file
 * @retval bool: success or false (true or false)
 */
bool createFile( std::string filePath)
{
    ofstream file;

    file.open(filePath.c_str(), ios::out);

    return file.bad();
}