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

#include <string>
#include <vector>
#include <iostream>
#include <limits>
#include <sstream>

#include "profil.hpp"
#include "compressFile.hpp"
#include "utils.hpp"

namespace code_compressor {

class CodesCompresor
{
public:
    CodesCompresor(std::vector<std::string> folders);
    CodesCompresor(CodesCompresor &&) = default;
    CodesCompresor(const CodesCompresor &) = default;
    CodesCompresor &operator=(CodesCompresor &&) = default;
    CodesCompresor &operator=(const CodesCompresor &) = default;
    ~CodesCompresor();

    // Gestions des compresseurs
    void loadFiles();
    void compress();
    void stop();

    // Gestion des profils
    void loadProfils();
    void getProfil( std::string filePath);
    void saveProfil();

    // Accesseur
    inline int getFilesCount();
    inline int getFilesProcessed();
    inline int getIndex();
    inline std::string getCurrentFile();
    inline std::vector<std::string> getFolder();
    inline std::string getJsFolder();
    inline std::string getCssFolder();

    // Mutateur
    inline void setFilesCount(int count);
    inline void setFilesProcessed(int processed);
    inline void setIndex( int index);
    inline void setCurrentFile( std::string cf);
    inline void setFolder(std::string jsFolder, std::string cssFolder);
    inline void setJsFolder(std::string jsFolder);
    inline void setCssFolder(strign cssFolder);

private:
    int _filesCount, _filesProcessed, _index;
    std::string _currentFile;
    std::vector<std::string> _folder;

    std::vector<std::unique_ptr<CompressFile>> _files;
    
    std::vector< std::unique_ptr<Profil> > _profils;
    std::unique_ptr<Profil> _profil;
};

} //end code_compressor

#endif
