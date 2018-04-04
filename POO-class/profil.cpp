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

}

std::string Profil::FileName()
{
}

std::string Profil::getJsFolder()
{
    return this->jsFolder;
}
std::string Profil::getCssFolder()
{
    return this->cssFolder;
}

void Profil::setJsFolder( std::string jsFolder)
{
    this->jsFolder = jsFolder;
}

void Profil::setCssFolder( std::string cssFolder)
{
    this->cssFolder = cssFolder;
}