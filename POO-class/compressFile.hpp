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

#ifndef compress_file_hpp
#define compress_file_hpp 1

#include <string>
#include "utils.hpp"

namespace code_compressor {

class CompressFile
{
public:
    CompressFile( std::string filePath );
    CompressFile(CompressFile &&) = default;
    CompressFile(const CompressFile &) = default;
    CompressFile &operator=(CompressFile &&) = default;
    CompressFile &operator=(const CompressFile &) = default;
    virtual ~CompressFile();

    virtual void compress();
    virtual void stop();

    // Accesseur
    inline bool getChange();
    inline bool getExist();
    inline std::string getFilePath();
    inline std::string getOutputFile();
    inline std::string getType();

    // Mutateur
    inline void setChange(bool change);
    inline void setExist(bool exist);
    inline void setFilePath(std::string filePath);
    inline void setOutputFile(std::string output);
    inline void setType(std::string type);

private:
    bool _change, _exist;
    std::string _filePath , _outputFile, _type;
};

} //end code_compressor

#endif
