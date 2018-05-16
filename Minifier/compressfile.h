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

#include <QObject>
#include <QString>

#include "utils.h"

namespace code_compressor{

    class CompressFile: public QObject
    {
        Q_OBJECT
    public:
        CompressFile(const QString &filePath);
        CompressFile(CompressFile &&) = delete;
        CompressFile(const CompressFile &) = delete;
        CompressFile &operator=(CompressFile &&) = delete;
        CompressFile &operator=(const CompressFile &) = default;
        virtual ~CompressFile() {};

        virtual void compress();
        virtual void stop();

        // Accesseur
        inline bool getChange();
        inline bool getExist();
        inline QString getFilePath();
        inline QString getOutputFile();
        inline QString getExePath();

        // Mutateur
        inline void setChange(bool change);
        inline void setExist(bool exist);
        inline void setFilePath(const QString &filePath);
        inline void setOutputFile(const QString &output);
        inline void setExePath(const QString &exePath);

    protected:
        QString _exePath, _filePath, _outputFile;
        bool _change, _exist;
    };

    /**
    * @brief  void function
    * @note
    * @retval None
    */
    inline void CompressFile::compress()
    {
        throw "Not implemented";
    }


    /**
    * @brief  void function
    * @note
    * @retval None
    */
    inline void CompressFile::stop()
    {
        throw "Not implemented";
    }

    /*******************************************/
    /************* Acesseur ********************/
    /*******************************************/

    inline bool CompressFile::getChange()
    {
        return this->_change;
    }
    inline bool CompressFile::getExist()
    {
        return this->_exist;
    }
    inline QString CompressFile::getFilePath()
    {
        return this->_filePath;
    }
    inline QString CompressFile::getOutputFile()
    {
        return this->_outputFile;
    }

    inline QString CompressFile::getExePath()
    {
        return this->_exePath;
    }

    /*******************************************/
    /************* Mutateur ********************/
    /*******************************************/

    inline void CompressFile::setChange(bool change)
    {
        this->_change = change;
    }
    inline void CompressFile::setExist(bool exist)
    {
        this->_exist = exist;
    }
    inline void CompressFile::setFilePath(const QString &filePath)
    {
        this->_filePath = filePath;
    }

    inline void CompressFile::setOutputFile(const QString &output)
    {
        this->_outputFile = output;
    }

    inline void CompressFile::setExePath(const QString &exePath)
    {
        this->_exePath = exePath;
    }

} //end code_compressor

#endif
