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

#ifndef compress_code_manager_hpp
#define compress_code_manager_hpp 1

#include <QDir>
#include <QFileInfoList>
#include <QString>

#include <memory>
#include <vector>

#include "utils.h"
#include "profil.h"
#include "compressfile.h"

namespace code_compressor {

    class CodesCompressor
    {
    public:
        CodesCompressor();
        CodesCompressor(CodesCompressor &&) = delete;
        CodesCompressor(const CodesCompressor &) = default;
        CodesCompressor &operator=(CodesCompressor &&) = delete;
        CodesCompressor &operator=(const CodesCompressor &) = default;
        ~CodesCompressor();

        // Gestions des compresseurs
        void loadFiles();
        void compress();
        void stop();

        // Gestion des profils
        bool loadProfils();

        void setProfil(const QStringList & filePath);
        void setProfil(const QString &cssFolder, const QString &jsFolder);

        void saveProfil(const QString &cfgName);

        bool checkExist(const QString& cfgName);
        
        // Function to launch compressor
        void launchCompressor(const QStringList& filePath);        
        void launchCompressorByIndex(const int &i);

        QStringList getProfilInfoByIndex(const int &i);

        bool availableProfil;

        ::std::unique_ptr<code_compressor::Profil> _profil;
        QStringList _profilsName;

    private:
        // functions use to add file's compressor
        void addCompressorFile(const QString &filePath);

        ::std::vector<code_compressor::CompressFile *> _files;
        ::std::vector<::std::unique_ptr<code_compressor::Profil>> _profils;
    };

} //end code_compressor

#endif
