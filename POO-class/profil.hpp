/*******************************************************************
Copyright (C) 2018 Oscar MARIE--TAILLEFER   <o5mariet@enib.fr>
Copyright (C) 2018 Nils JEGOU-GERGAUD       <n5jegoug@enib.fr>
Copyright (C) 2018 Nicols FRANCIS           <n4franci@enib.fr>
Copyright (C) 2018 Corentin LAMBERT         <c4lamber@enib.fr>

This file is part of Minifier.

Minifier is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Minifier is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Minifier.  If not, see <http://www.gnu.org/licenses/>.
*******************************************************************/

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