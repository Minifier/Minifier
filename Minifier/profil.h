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

#include <QString>
#include <QInputDialog>
#include <QDir>
#include <QLineEdit>

#include <string>
#include <iostream>
#include <vector>

#include "utils.h"
#include "config.h"

namespace code_compressor {

    class Profil
    {
    public:
        Profil( const QString &folderCSS, const QString &folderJS, const QString &cfgName);
        Profil( const QString &folderCSS, const QString &folderJS);
        Profil( const QStringList &folders, const QString &profilName);
        Profil( const QStringList &folders);
        Profil(Profil &&) = delete;
        Profil(const Profil &) = default;
        Profil &operator=(Profil &&) = delete;
        Profil &operator=(const Profil &) = default;
        ~Profil();

        // Sauvegarder le fichier de configuration
        bool save(const QString &cfgName);

        // Obtenir le chemin vers le fichier de configuration
        QStringList fileName();

        // Accesseur
        QString getJsFolder();
        QString getCssFolder();

        // Mutateur
        void setJsFolder( const QString &jsFolder);
        void setCssFolder( const QString &cssFolder);

    private:
        QString configName, jsFolder, cssFolder;
    };

} //end code_compressor

#endif
