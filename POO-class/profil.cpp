#include "profil.hpp"

Profil::Profil( string folderCSS , string folderJS )
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

string Profil::FileName()
{
}

string Profil::getJsFolder()
{
    return this->jsFolder;
}
string Profil::getCssFolder()
{
    return this->cssFolder;
}

void Profil::setJsFolder( string jsFolder)
{
    this->jsFolder = jsFolder;
}

void Profil::setCssFolder( string cssFolder)
{
    this->cssFolder = cssFolder;
}