#include "codesCompressor.hpp"

CodesCompressor::CodesCompressor(std::vector<std::string> folders)
{
    this->folder.push_back(folders[0]);
    this->folder.push_back(folders[1]);

    this->index = 0;
    this->filesCount = 0;
    this->filesProcessed = 0;

    this->loadFiles();

    this->compress();
}

CodesCompressor::~CodesCompressor()
{
}

void CodesCompressor::loadFiles()
{

}

void CodesCompressor::compress()
{
    for(int i = 0; i < this->count; i++){
        this->folder[i]->compress();
    }
}

void CodesCompressor::stop()
{
    for(int i = 0; i < this->count; i++){
        this->folder[i]->stop();
    }
}

void CodesCompressor::loadProfils()
{

}

void CodesCompressor::getProfil( std::string filePath)
{

}

void CodesCompressor::saveProfil()
{
    this->profil->save();
}

inline int CodesCompressor::getFilesCount()
{
    return this->filesCount;
}

inline int CodesCompressor::getFilesProcessed()
{
    return this->filesProcessed;
}

inline int CodesCompressor::getIndex()
{
    return this->index;
}

inline std::string CodesCompressor::getCurrentFile()
{
    return this->currentFile;
}

inline std::vector<std::string> CodesCompressor::getFolder()
{
    return this->folder;
}

inline std::string getJsFolder()
{
    return this->folder[0];
}
inline std::string getCssFolder()
{
    return this->folder[1];
}

inline void CodesCompressor::setFilesCount(int count)
{
    this->filesCount = count;
}

inline void CodesCompressor::setFilesProcessed(int processed)
{
    this->filesProcessed = processed;
}

inline void CodesCompressor::setIndex( int index)
{
    this->index = index;
}

inline void CodesCompressor::setCurrentFile( std::string cf)
{
    this->currentFile = cf;
}

inline void CodesCompressor::setFolder(std::string jsFolder, std::string cssFolder)
{
    this->folder[0] = jsFolder;
    this->folder[1] = cssFolder;
}

inline void CodesCompressor::setJsFolder(std::string jsFolder)
{
    this->folder[0] = jsFolder;
}

inline void CodesCompressor::setCssFolder(std::string cssFolder)
{
    this->folder[1] = cssFolder;
}