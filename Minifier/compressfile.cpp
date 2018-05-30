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

#include "compressfile.h"

/**
 * @brief CompressCallback callback to launch (cssmin|jsmin).exe each time file change
 * @return 0
 */
UINT code_compressor::CompressFile::CompressCallback()
{
    /* Copyright (c) 2010  (www.ryanday.org) cssmin.c */
    /* Copyright (c) 2002 Douglas Crockford  (www.crockford.com) jsmin.c */
    QProcess::startDetached(bat_name);
    return 0;
}

/**
 * @brief CompressFile Constructor of CompressFile class
 * @param filePath path for file's access
 */
code_compressor::CompressFile::CompressFile(const QString &filePath)
{
    this->setFilePath(filePath);

    // Define filePath and outPutFilePath
    QStringList c = filePath.split('.');
    int sl = c.size();
    if (sl == 2) {
        this->setOutputFile(c.at(0) + ".min."+ c.at(sl-1));
        QString tmp = (c.at(0));
        this->bat_name = tmp.split('/').last() + ".bat";
    }
    else {
        QString path = "";
        for (int i = 0; i < sl - 1; i++) {
            path += c.at(i);
        }
        this->setOutputFile(path + ".min." + c.at(sl-1));
        this->bat_name = path.split('/').last() + ".bat";
    }
    if(this->bat_name.contains(' ')) this->bat_name.replace(' ', '_');
    this->bat_name = ExePath() + "tmp/" + this->bat_name;
    // Struct : default_app_path/ + %extension% + min.exe
    this->_cmd =ExePath()  + c.at(sl-1) + "min.exe";

    // Need to detect whitespace in filePath
    QStringList cmd_to_check;
    cmd_to_check << this->_cmd;
    cmdCheck(&cmd_to_check);
    this->_cmd = cmd_to_check.at(0) + " <\"" + this->_filePath + "\"> \"" + this->_outputFile + "\"";

    // Set bat's name
    this->bat.setFileName(this->bat_name);

    // Write cmd to compress (js|css) in bat file
    if(!this->bat.open(QIODevice::WriteOnly) )
       return;

    this->bat.write(this->_cmd.toUtf8().constData());
    this->bat.close();

    // Create file watcher
    fileWatch = new QFileSystemWatcher(this);

    // Connect fileChanged signal and Compress callback
    QObject::connect(fileWatch, SIGNAL(fileChanged(const QString &)),
                         this, SLOT(CompressCallback()));
    this->compress();
}

code_compressor::CompressFile::~CompressFile()
{
    this->stop();

    // Remove bat file create for compression
    this->bat.remove();
}

/**
 * @brief compress add file path to file watcher and launch compress callback
 */
void code_compressor::CompressFile::compress()
{
    this->CompressCallback();
    fileWatch->addPath(this->_filePath);
}

/**
 * @brief stop remove file path from file watcher
 */
void code_compressor::CompressFile::stop()
{
    this->CompressCallback();
    fileWatch->removePath(this->_filePath);
}
