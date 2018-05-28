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

        /* Gestions des compresseurs */

        /**
         * @brief loadFiles load file after directory definition
         */
        void loadFiles();

        /**
         * @brief compress launch function compress on each files
         */
        void compress();

        /**
         * @brief stop launch function stop on each files
         */
        void stop();

        /* Gestion des profils */

        /**
         * @brief loadProfils load all profil from profil.txt
         * @return true|false one or more files has been loaded ?
         */
        bool loadProfils();

        /**
         * @brief setProfil set profil using folder list
         * @param filePath list (cssFolder,jsFolder)
         */
        void setProfil(const QStringList & filePath);

        /**
         * @brief setProfil set profil using jsFolder and cssFolder params
         * @param jsFolder path to JS folder
         * @param cssFolder path to CSS folder
         */
        void setProfil(const QString &cssFolder, const QString &jsFolder);

        /**
         * @brief saveProfil launch profil's save function
         * @param cfgName name for saving cfg
         */
        void saveProfil(const QString &cfgName);

        /**
         * @brief deleteProfilByIndex
         * @param index
         */
        void deleteProfilByIndex(const int &index);

        /**
         * @brief renameProfilByIndex
         * @param index
         * @param newName
         */
        void renameProfilByIndex(const int &index, const QString &newName);

        /**
         * @brief checkExist
         * @param cfgName
         * @return true|false name exist
         */
        bool checkExist(const QString& cfgName);
        
        /* Function to launch compressor */

        /**
         * @brief launchCompressor launch compressor and set profil
         * @param filePath list (cssFolder,jsFolder)
         */
        void launchCompressor(const QStringList& filePath);

        /**
         * @brief setProfilByIndex
         * @param i index of profil in profils'list
         */
        void launchCompressorByIndex(const int &i);

        QStringList getProfilInfoByIndex(const int &i);

        /**
         * @brief running use to know if compressors are running
         * @return true|false running state
         */
        bool running();

        /* public var */

        bool availableProfil;

        ::std::unique_ptr<code_compressor::Profil> _profil;
        QStringList _profilsName;

    private:
        // functions use to add file's compressor

        /**
         * @brief addCompressorFile use to add CompressFile to files
         * @param filePath way to access to the file
         */
        void addCompressorFile(const QString &filePath);


        /* private var */
        ::std::vector<code_compressor::CompressFile *> _files;
        ::std::vector<::std::unique_ptr<code_compressor::Profil>> _profils;

        bool _state;
    };

} //end code_compressor

#endif
