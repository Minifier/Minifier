#include "codesCompressor.hpp"


CodesCompresor::CodesCompresor(std::vector<std::string> folders)
{
}

CodesCompresor::~CodesCompresor()
{
}

int CodesCompressor::getFilesCount()
{
    return this->filesCount;
}

int CodesCompressor::getFilesProcessed()
{
    return this->filesProcessed;
}

int CodesCompressor::getIndex()
{
    return this->index;
}

string CodesCompressor::getCurrentFile()
{
    return this->currentFile;
}

std::vector<String> CodesCompressor::getFolder()
{
    return this->folder;
}

string getJsFolder()
{
    return this->folder[0];
}
string getCssFolder()
{
    return this->folder[1];
}

void CodesCompressor::setFilesCount(int count)
{
    this->filesCount = count;
}

void CodesCompressor::setFilesProcessed(int processed)
{
    this->filesProcessed = processed;
}

void CodesCompressor::setIndex( int index)
{
    this->index = index;
}

void CodesCompressor::setCurrentFile( string cf)
{
    this->currentFile = cf;
}

void CodesCompressor::setFolder(string jsFolder, string cssFolder)
{
    this->folder[0] = jsFolder;
    this->folder[1] = cssFolder;
}

void CodesCompressor::setJsFolder(string jsFolder)
{
    this->folder[0] = jsFolder;
}

void CodesCompressor::setCssFolder(strign cssFolder)
{
    this->folder[1] = cssFolder;
}