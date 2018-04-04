#include "profil.hpp"

Profil::Profil( std::string folderCSS , std::string folderJS )
{
    this->jsFolder = folderJS;
    this->cssFolder = folderCSS;
}

Profil::~Profil()
{
}

void Profil::save()
{
    // Fonction pour écrire dans un fichier la config et la sauvegarder
    // Traitement à déterminer
}

std::string Profil::fileName()
{
    return "/" + PROFIL_PATH + "/" + this->jsFolder + "+" + this->cssFolder + "." + EXTENSION_CONFIG;
}

// Accesseur

std::string Profil::getJsFolder()
{
    return this->jsFolder;
}
std::string Profil::getCssFolder()
{
    return this->cssFolder;
}

// Mutateur

void Profil::setJsFolder( std::string jsFolder)
{
    this->jsFolder = jsFolder;
}

void Profil::setCssFolder( std::string cssFolder)
{
    this->cssFolder = cssFolder;
}