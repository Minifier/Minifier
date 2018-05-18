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
#include <Qfilesystemwatcher>
#include <QProcess>

#include "utils.h"
#include "config.h"

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
        ~CompressFile();

        void compress();
        void stop();

        // Accesseur
        inline QString getFilePath();
        inline QString getOutputFile();

        // Mutateur
        inline void setFilePath(const QString &filePath);
        inline void setOutputFile(const QString &output);
        
        QFileSystemWatcher* fileWatch;

    public slots:
        UINT CompressCallback();

    protected:
        QString _filePath, _outputFile, _cmd;
    };

    /*******************************************/
    /************* Acesseur ********************/
    /*******************************************/

    inline QString CompressFile::getFilePath()
    {
        return this->_filePath;
    }
    inline QString CompressFile::getOutputFile()
    {
        return this->_outputFile;
    }

    /*******************************************/
    /************* Mutateur ********************/
    /*******************************************/

    inline void CompressFile::setFilePath(const QString &filePath)
    {
        this->_filePath = filePath;
    }

    inline void CompressFile::setOutputFile(const QString &output)
    {
        this->_outputFile = output;
    }

} //end code_compressor

#endif
