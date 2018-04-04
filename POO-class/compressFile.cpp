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

void CompressFile::compress()
{
    throw "Not implemented";
}

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