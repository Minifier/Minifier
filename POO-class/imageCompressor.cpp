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

#include "imageCompressor.hpp"

ImageCompressor::ImageCompressor(std::string n, int h, int w, std::string ext, int q, int d, std::string f)
    : name_{n}, height_{h}, width_{w}, extension_{ext}, quality_{q}, dimension_{d}, file_{f} 
{

}

ImageCompressor::~ImageCompressor()
{

}

void ImageCompressor::loadPicture()
{

}

void ImageCompressor::YCrCb()
{

}

void ImageCompressor::Echant422()
{

}

void ImageCompressor::Decoup8x8()
{

}

void ImageCompressor::Quantify()
{

}

void ImageCompressor::ZigZag()
{

}

void ImageCompressor::DCT()
{

}

void ImageCompressor::Huffman()
{

}

void ImageCompressor::resize()
{

}

void ImageCompressor::createImageSource()
{

}

void ImageCompressor::createImageCible()
{

}

void ImageCompressor::toCible()
{

}

void ImageCompressor::HuffmanInverse()
{

}

void ImageCompressor::unquantify()
{

}

void ImageCompressor::DCTInverse()
{

}

void ImageCompressor::convertPNG()
{

}


// Accesseur

inline int ImageCompressor::getHeight()
{

}

inline int ImageCompressor::getWidth()
{

}

inline int ImageCompressor::getQuality()
{

}

inline int ImageCompressor::getDim()
{

}

inline std::string ImageCompressor::getName()
{

}

inline std::string ImageCompressor::getExtension()
{

}

inline std::string ImageCompressor::getFile()
{

}


// Mutateur

inline void ImageCompressor::setHeight( int h)
{

}

inline void ImageCompressor::setWidth( int w)
{

}

inline void ImageCompressor::setQuality( int q)
{

}

inline void ImageCompressor::setDim( int d)
{

}

inline void ImageCompressor::setName( std::string n)
{

}

inline void ImageCompressor::setExtension( std::string e)
{

}

inline void ImageCompressor::setFile( std::string f )
{

}
