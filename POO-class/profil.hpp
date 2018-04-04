#ifndef profil_hpp
#define profil_hpp 1

namespace code_compressor {

#include <string>

class Profil
{
public:
    Profil( string folderCSS , string folderJS );
    Profil(Profil &&) = default;
    Profil(const Profil &) = default;
    Profil &operator=(Profil &&) = default;
    Profil &operator=(const Profil &) = default;
    ~Profil();

    void save();
    string FileName();

    string getJsFolder();
    string getCssFolder();

    void setJsFolder( string jsFolder);
    void setCssFolder( string cssFolder);

private:
    string jsFolder, cssFolder;
};

} //end code_compressor

#endif