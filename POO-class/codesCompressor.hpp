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

    inline int getFilesCount();
    inline int getFilesProcessed();
    inline int getIndex();
    inline std::string getCurrentFile();
    inline std::vector<std::string> getFolder();
    inline std::string getJsFolder();
    inline std::string getCssFolder();

    inline void setFilesCount(int count);
    inline void setFilesProcessed(int processed);
    inline void setIndex( int index);
    inline void setCurrentFile( std::string cf);
    inline void setFolder(std::string jsFolder, std::string cssFolder);
    inline void setJsFolder(std::string jsFolder);
    inline void setCssFolder(strign cssFolder);

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