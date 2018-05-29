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

#include "imagecompressor.h"

image_compressor::ImageCompressor::ImageCompressor()
{
    // List of extension available
    this->_rawList << "*.3fr" << "*.ari" << "*.arw" << "*.srf" << "*.sr2" << "*.bay" << "*.crw" << "*.cr2" << "*.cap" << "*.iiq" << "*.eip" << "*.dcs" << "*.dcr" << "*.drf" << "*.k25" << "*.kdc" << "*.dng" << "*.erf" << "*.fff" << "*.mef" << "*.mos" << "*.mrw" << "*.nef" << "*.nrw" << "*.orf" << "*.ptx" << "*.pef" << "*.pxn" << "*.r3d" << "*.raf" << "*.raw" << "*.rw2" << "*.rwl" << "*.rwz" << "*.x3f";
    this->_pngList << "*.png";
    this->_tifList << "*.tif" << "*.tiff";
    this->_psdList << "*.psd";
    this->_bmpList << "*.bmp" << "*.rle" << "*.dib";
    this->_gifList << "*.gif";
    this->_icoList << "*.ico";

    this->_extList = this->_rawList + this->_pngList + this->_tifList + this->_psdList + this->_bmpList + this->_gifList + this->_icoList;
}

image_compressor::ImageCompressor::~ImageCompressor()
{

}

/**
 * @brief ImageCompressor::canConvert
 * @param extension
 * @return True|False if extension is available to convert
 */
bool image_compressor::ImageCompressor::canConvert(const QString &extension)
{
    return !(this->_extList.filter(extension, Qt::CaseInsensitive).isEmpty());
}

/**
 * @brief inList test if a file get his extension in a list
 * @param filePath filepath
 * @param list list of extension to test
 * @return true|false if file's extension is in list
 */
bool static inList(const QString &filePath, const QStringList &list)
{
    QString ext = filePath.split('.').last();
    return !(list.filter(ext).isEmpty());
}

/**
 * @brief makeCmd Build a cmd
 * @param exe extension for launch .exe ( for exemple jpg => jpg2png.exe)
 * @param filePath filepath
 * @param fileName output fileName
 * @param quality quality level
 * @return cmd built
 */
static inline QString makeCmd(const QString &exe, const QString &filePath, const QString &fileName, const int &quality)
{
    QString cmd = "cmd /c \"\"" + ExePath() + "convert\\" + exe +"2jpg.exe -i " + filePath + " -q --filename-mask=\"" + fileName + ".%ext%\" --jpg-quality=" + QString::number(quality) + "\"\"";
    return cmd;
}

/**
 * @brief convert algo to create and launch convertissor and compressor
 * @param filePath input filePath
 * @param fileName output File's Name
 * @param quality [0-100] % quality for compression (default 70)
 */
void image_compressor::ImageCompressor::convert(const QString &filePath , QString &fileName, int quality)
{
    bool no_name = false;
    if(fileName.isEmpty())
    {
        fileName = "%filename%";
        no_name = true;
    }

    if(quality == 0)
    {
        quality = 100;
    }
    QRegExp re_jpg("*.jpg", Qt::CaseInsensitive);
    re_jpg.setPatternSyntax(QRegExp::Wildcard);
    if(re_jpg.exactMatch(filePath) == true)
    {
        if(!no_name)
        {
            QStringList path = filePath.split('\\');
            QString fp;
            for(int i = 0; i < filePath.size()-1; i++)
            {
                fp += path.at(i);
                std::cout << fp.toUtf8().constData() << std::endl;
            }
            fileName = fp + fileName + ".jpg";
        }
        else{
            fileName = filePath;
        }

        this->_cmd = "cmd /c \"\"" + ExePath() + "convert -strip -interlace Plane -quality " + QString::number(quality) + "% "+ filePath +" " + fileName +"\"\"";

    } else if( inList(filePath, this->_rawList )) {
        this->_cmd = makeCmd("raw", filePath, fileName, quality);
    } else if( inList(filePath , this->_pngList )) {
        this->_cmd = makeCmd("png", filePath, fileName, quality);
    } else if( inList(filePath , this->_tifList )) {
        this->_cmd = makeCmd("tiff", filePath, fileName, quality);
    } else if( inList(filePath , this->_psdList )) {
        this->_cmd = makeCmd("psd", filePath, fileName, quality);
    } else if( inList(filePath , this->_bmpList )) {
        this->_cmd = makeCmd("bmp", filePath, fileName, quality);
    } else if( inList(filePath , this->_gifList )) {
        this->_cmd = makeCmd("gif", filePath, fileName, quality);
    } else if( inList(filePath , this->_icoList )) {
        this->_cmd = makeCmd("ico", filePath, fileName, quality);
    }

    QProcess::startDetached(this->_cmd);
    std::cout << this->_cmd.toUtf8().constData() << std::endl;
    this->_cmd = "";
}
