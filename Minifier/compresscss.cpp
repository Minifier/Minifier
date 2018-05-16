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

#include "compresscss.h"

/**
 * @brief CompressCallback callback to launch cssmin.exe each time file change
 * @return 0
 */
UINT code_compressor::CompressCSS::CompressCallback()
{
    /* Copyright (c) 2010  (www.ryanday.org) */
    QProcess::startDetached("cmd /c \"" + this->_exePath + CSSMIN_PATH + "cssmin.exe" + " <" + this->_filePath + "> " + this->_outputFile + "\"" );
    return 0;
}

/**
 * @brief CompressCSS Constructor of class CompressCSS
 * @param filePath path to ".css" file
 */
code_compressor::CompressCSS::CompressCSS(const QString &filePath) : CompressFile{ filePath }
{
    // Define filePath and outPutFilePath
    QStringList c = filePath.split('.');
    if (c.size() == 2) {
        this->setOutputFile(c.at(0) + ".min.css");
    }
    else {
        QString path = "";
        for (int i = 0; i < c.size() - 1; i++) {
            path += c.at(i);
        }
        this->setOutputFile(path + ".min.css");
    }

    // Create file watcher
    fileWatch = new QFileSystemWatcher(this);

    // Connect fileChanged signal and Compress callback
    QObject::connect(fileWatch, SIGNAL(fileChanged(const QString &)),
                         this, SLOT(CompressCallback()));
    this->compress();
}

code_compressor::CompressCSS::~CompressCSS()
{
    this->stop();
}

/**
 * @brief compress add file path to file watcher and launch compress callback
 */
void code_compressor::CompressCSS::compress()
{
    fileWatch->addPath(this->_filePath);
    this->CompressCallback();
}

/**
 * @brief stop remove file path from file watcher
 */
void code_compressor::CompressCSS::stop()
{
    this->CompressCallback();
    fileWatch->removePath(this->_filePath);
}
