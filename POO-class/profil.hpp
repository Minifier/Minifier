#ifndef profil_hpp
#define profil_hpp 1

namespace code_compressor {

#include <string>

class Profil
{
public:
    Profil( std::string folderCSS , std::string folderJS );
    Profil(Profil &&) = default;
    Profil(const Profil &) = default;
    Profil &operator=(Profil &&) = default;
    Profil &operator=(const Profil &) = default;
    ~Profil();

    void save();
    std::string FileName();

    std::string getJsFolder();
    std::string getCssFolder();

    void setJsFolder( std::string jsFolder);
    void setCssFolder( std::string cssFolder);

private:
    std::string jsFolder, cssFolder;
};

} //end code_compressor

#endif