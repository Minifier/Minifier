#include "compressFile.hpp"

CompressFile::CompressFile( string filePath)
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

}