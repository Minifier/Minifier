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

#ifndef IMAGECOMPRESS_IMAGECOMPRESSOR_HPP
#define IMAGECOMPRESS_IMAGECOMPRESSOR_HPP 1

#include <QString>
#include <QStringList>

#include "utils.cpp"
#include <cmath>

namespace imageCompress{

class ImageCompressor{

public :

    ImageCompressor(const QString &n, const unsigned int &q, const QString &f);

    ImageCompressor(ImageCompressor &&) = delete;
    ImageCompressor(const ImageCompressor &) = default;
    ImageCompressor &operator=(ImageCompressor &&) = delete;
    ImageCompressor &operator=(const ImageCompressor &) = default;
    ~ImageCompressor();

    // Load the picture
    void loadPicture();

    void RGBToYCrCb();
    void YCbCrToRGB();
    void Echant422();
    void Decoup8x8();
    void Quantify();
    void ZigZag();
    void DCT();
    void Huffman();
    void resize();
    void HuffmanInverse();
    void unquantify();
    void DCTInverse();

    // Converte function
    void convertPNG(const QString &fileName);

    // Accesseur

    inline unsigned int getHeight();
    inline unsigned int getWidth();
    inline unsigned int getQuality();
    inline QString getFile();
    inline QString getOutputFilePath();

    // Mutateur

    inline void setHeight( const unsigned int &h);
    inline void setWidth( const unsigned int &w);
    inline void setQuality( const unsigned int &q);
    inline void setFilePath( const QString &filePath);
    inline void setOutputFilePath( const QString &output);

private:

    QString _filePath, _outputFilePath;
    unsigned int _height, _width, _quality, _subMatCount; 
    
    // Picture's matrix
    rgb* _content;
    
    // Picture's 8*8 matrix
    rgb ** _subContent;
};

} // End imageCompress

#endif