#ifndef profil_hpp
#define profil_hpp 1

namespace code_compressor {

#include <string>
#include <iostream>

#include "config.hpp"

class Profil
{
public:
    Profil( std::string folderCSS , std::string folderJS );
    Profil(Profil &&) = default;
    Profil(const Profil &) = default;
    Profil &operator=(Profil &&) = default;
    Profil &operator=(const Profil &) = default;
    ~Profil();

    // Sauvegarder le fichier de configuration
    void save();

    // Obtenir le chemin vers le fichier de configuration
    std::string fileName();

    // Accesseur
    std::string getJsFolder();
    std::string getCssFolder();

    // Mutateur
    void setJsFolder( std::string jsFolder);
    void setCssFolder( std::string cssFolder);

private:
    std::string jsFolder, cssFolder;
};

} //end code_compressor

#endif