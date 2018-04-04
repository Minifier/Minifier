#ifndef compress_code_manager_hpp
#define compress_code_manager_hpp 1

#include <string>
#include <vector>

#include "profil.hpp"
#include "compressFile.hpp"

namespace code_compressor {

class CodesCompresor
{
public:
    CodesCompresor(std::vector<std::string> folders);
    CodesCompresor(CodesCompresor &&) = default;
    CodesCompresor(const CodesCompresor &) = default;
    CodesCompresor &operator=(CodesCompresor &&) = default;
    CodesCompresor &operator=(const CodesCompresor &) = default;
    ~CodesCompresor();

    // Gestions des compresseurs
    void loadFiles();
    void compress();
    void stop();

    // Gestion des profils
    void loadProfils();
    void getProfil( std::string filePath);
    void saveProfil();

    int getFilesCount();
    int getFilesProcessed();
    int getIndex();
    std::string getCurrentFile();
    std::vector<std::string> getFolder();
    std::string getJsFolder();
    std::string getCssFolder();

    void setFilesCount(int count);
    void setFilesProcessed(int processed);
    void setIndex( int index);
    void setCurrentFile( std::string cf);
    void setFolder(std::string jsFolder, std::string cssFolder);
    void setJsFolder(std::string jsFolder);
    void setCssFolder(strign cssFolder);

private:
    int filesCount, filesProcessed, index;
    std::string currentFile;
    std::vector<std::string> folder;

    std::vector<std::string> files;
    std::vector< std::unique_ptr<Profil> > profils;
    std::unique_ptr<Profil> profil;
};

} //end code_compressor

#endif