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

#define _N 8

/*
int Quantify[_N][_N];
for (int i=0; i<_N; i++){ // Création de la matrice de quantification 8x8 avec un pas de quality_
    for (int j=0; j<_N; j++){
        Quantify[i][j]=1+(i+j+1)*this->quality_;
    }
}
*/

ImageCompressor::ImageCompressor(const QString &n, const unsigned int &q, const QString &f)
{
    this->setFilePath(f);
    
    QStringList path = f.split('\\');
    QString fn = path.at(path.size()-1);
    QString fp;
    for(int i = 0; i < f.size()-1; i++)
    {
        fp += path.at(i);
    }
    this-->setOutputFilePath(fp + "\\" + n);
      
    QRegExp re_png("*.png", Qt::CaseInsensitive);
    QRegExp re_jpg("*.jpg", Qt::CaseInsensitive);
    QRegExp re_jpeg("*.jpeg", Qt::CaseInsensitive);
    re_png.setPatternSyntax(QRegExp::Wildcard);
    re_jpg.setPatternSyntax(QRegExp::Wildcard);
    re_jpeg.setPatternSyntax(QRegExp::Wildcard);
    
    if(re_png.exactMatch(fn))
    {
        this->setFilePath(fp + convertPNG(fn));
    }
    if(re_jpg.exactMatch(fn) || re_jpeg.exactMatch(fn)){
        this->loadPicture();
        this->RGBToYCrCB();
        this->Echant422();
        this->Decoup8x8();
        this->Quantify();
        //TODO ....
    }
}

ImageCompressor::~ImageCompressor()
{

}

/**
 * @brief ImageCompressor::loadPicture function use to load picture with CImg
 */
void ImageCompressor::loadPicture()
{
    readJPEG(this->_filePath, &this->_content , &this->_width, &this->_height);
}

/**
 * @brief ImageCompressor::RGBToYCrCb Transforme la matrice RGB en matrice YCbCr grâce à une matrice de coefficients à appliquer sur chaque triplet d'un pixel
 */
void ImageCompressor::RGBToYCrCb()
{
    unsigned char R,G,B;
    unsigned int count = 0;
    for(unsigned int i =0; i<=this->getWidth(); i++){
        count += this->getWidth();
        for(unsigned int j =0; j<=this->getHeight(); j++){
            R = this->_content[count + j][0];
            G = this->_content[count + j][1];
            B = this->_content[count + j][2];
            this->_content[count + j][0] = 0,299 * R + 0,587 * G + 0,114 * B;
            this->_content[count + j][1] = 0,1687 * R - 0,3313 * G + 0,5 * B + 128;
            this->_content[count + j][2] = 0,5 * R - 0,4187 * G - 0,0813 * B + 128;
        }
    }
}


/**
 * @brief ImageCompressor::Echant422 Sous échantillonage de la matrice YCbCr pour mettre à 0 les CbCr trois fois sur quatre car la chrominance est une donnée de l'image peut visible à l'oeil nue.
 */
void ImageCompressor::Echant422()
{
    unsigned int count = 0;
    for(unsigned int i =0; i<=this->getWidth(); i++){
        count += this->getWidth();
        for(unsigned int j =0; j<=this->getHeight(); j++){
            if (i%2==1 && j%2==0){
                this->_content[count + j][1] = 0;
            }
            else if(j%2==1 && i%2==0){
                this->_content[count + j][2] = 0;
            }
            else if(j%2==1 && i%2==1){
                this->_content[count + j][1] = 0;
                this->_content[count + j][2] = 0;
            }
        }
    }
}


void ImageCompressor::DCT() /// OK
{
    rgb DCT[_N][_N];
    for (int i=0;i<_N;i++){ // Création de la matrice DCT, Valeurs fixes dans la première colonne et la première ligne.
        for(int j=0; j<_N; j++){
            if(j==0 && i==0){
                Cj=1/sqrt(2);
                Ci=1/sqrt(2);
            }
            else if(j==0 && i>=0){
                Cj=1/sqrt(2);
                Ci=1;
            }
            else if(j>=0 && i==0){
                Cj=1;
                Ci=1/sqrt(2);
            }
            else if(j>=0 && i>=0){
                Cj=1;
                Ci=1;
            }
            DCT[i][j]=(1/sqrt(2));
            for (int x=0; x<_N; x++){
                for (int y=0; y<_N; y++){
                    DCT[i][j]+=YCbCr[x][y]*cos((2*x+1)*i*3,14159/(2*_N))*cos((2*y+1)*j*3,14159/(2*_N));
                }
            }
        }
    }

}


//Découpage de la matrice Initiale YCbCr en bloc de 8x8 pour le sous échantillonage pour permettre de gagner en temps de calcul.
void ImageCompressor::Decoup8x8()
{
    unsigned int nW = this->getWidth() / 8 ;
    unsigned int nh = this->getHeight() / 8;
    this->_subMatCount = nw * nh ;
    
    this->_subContent = new rgb[this->_subMatCount][64];
    
    unsigned int cursor = 0;
    
    unsigned int x1 = 0;
    unsigned int y1 = 0;
            
    for(unsigned int i = 0; i < nW; i++)
    {
        x1 = i * 8;
        for(unsigned int j = 0; j < nH; j++)
        {
            cursor ++;
            for(unsigned int k = 0; k < 8; k++)
            {
                x1++;
                y1 = j * 8;
                for(unsigned int l = 0; l < 8; l++)
                {
                    y1++;
                    this->_subContent[cursor][x1 + y1] = this->_content[x1 + y1];
                }
            }
        }
    }
}

/**
 * @brief  Quantification des sous matrices 8x8 en fonction du coeffcient de qualité souhaité, on divide chaque composante par la valeur associée de quantification.
 */
void ImageCompressor::Quantify()
{    
    for(unsigned int k = 0; k < this->_subMatCount; k++ )
    {
        for (int i =0; i < _N; i++){
            for (int j=0; j< _N; j++){
                this->_subContent[k][i*_N +j][0]=this->_subContent[k][i*_N +j][0]/(1+(i+j+1)*this->getQuality());
                this->_subContent[k][i*_N +j][1]=this->_subContent[k][i*_N +j][1]/(1+(i+j+1)*this->getQuality());
                this->_subContent[k][i*_N +j][2]=this->_subContent[k][i*_N +j][2]/(1+(i+j+1)*this->getQuality());
            }
        }
    }
}


///Pacours des la matrice 8x8 selon la méthode "Zig-Zag" pour obtenir des chaines de nombre pour pouvoir ensuite réduire cette chaine en fonction du nombre de nombre identique qui se suivent ///
void ImageCompressor::ZigZag()
{
    int i =0;
    int j =0;
    int maxI =_N-1;
    int maxJ =_N-1;
    int croiss = 0;

    std::vector<std::vector<int>> liste[nbBlock][64];

    for (int b=0; b<nbBlock; b++){
        while (i <= maxI && j <= maxJ){ // Parcours de la matrice 8x8 en Zig-Zag
            if (i == 0 || i == maxI){
                if (j == maxJ){
                    j -= 1;
                    i += 1;
                }
                j += 1;
            }
            else{
                if (j == 0 || j == maxJ){
                    if (i == maxI){
                        i -= 1;
                        j += 1;
                    }
                    i += 1;
                }
            }
            if (i == 0 || j == maxJ) { croiss = 0;}
            if (j == 0 || i == maxI)  { croiss = 1;}
            if (croiss==1) {
                i -= 1;
                j += 1;
            }
            else{
                i += 1;
                j -= 1;
            }

            liste[b].emplace_back(listeDecoup8x8[i][j]);
        }
    }
}


void ImageCompressor::Huffman()
{

}

void ImageCompressor::HuffmanInverse()
{

}

/// Déquantification des sous matrices 8x8 après compression en fonction du coeffcient de qualité souhaité, on multiplie chaque composante par la valeur associée de quantification.
void ImageCompressor::unquantify() /// OK
{
    for (int i =0; i < _N; i++){ // Modification des matrices 8x8 HuffmanInverse en multipliant chaque composante par son coefficient de qualité dans la matrice Quantify.
        for (int j=0; j< _N; j++){
            int DCTQI[i][j]=this->_subContent[*(1+(i+j+1)*this->quality_);
        }
    }
}

void ImageCompressor::DCTInverse() /// OK
{
    std::vector<int, int> pixel[_N][_N];
    for (int x=0;x<_N;x++){ // Création de la matrice DCT inverse en prenant la matrice DCT qui a été quantifiée puis déquantifiée.
        for(int y=0; y<_N; y++){
            pixel[x][y]=(1/sqrt(2*_N));
            for (int i=0; i<_N; i++){
                for (int j=0; j<_N; j++){
                    pixel[x][x]+=DCT[i][j]*cos((2*x+1)*i*3,14159/(2*_N))*cos((2*y+1)*j*3,14159/(2*_N));
                }
            }
        }
    }
}

/**
 * @brief ImageCompressor::YCrCbToRGB Transforme la matrice YCbCr en matrice RGB grâce à une matrice de coefficients à appliquer sur chaque triplet d'un pixel
 */
void ImageCompressor::YCrCbToRGB()
{
    unsigned char Y,Cb,Cr;
    unsigned int count = 0;
    for(unsigned int i =0; i<=this->getWidth(); i++){
        count += this->getWidth();
        for(unsigned int j =0; j<=this->getHeight(); j++){
            Y = this->_content[count + j][0];
            Cb = this->_content[count + j][1];
            Cr = this->_content[count + j][2];
            this->_content[count + j][0] = Y + 1.402 * Cr;
            this->_content[count + j][1] = Y - 0.344136 * Cb - 0.714136 * Cr;
            this->_content[count + j][2] = Y + 1.772 * Yb;
        }
    }
}


void ImageCompressor::convertPNG(const QString &fileName)//PNG to JPEG
{

}


// Accesseur

inline unsigned int ImageCompressor::getHeight()
{
    return this->_height;
}

inline unsigned int ImageCompressor::getWidth()
{
    return this->_width;
}

inline unsigned int ImageCompressor::getQuality()
{
    return this->_quality;
}
                                              
inline QString ImageCompressor::fetFilePath()
{
    return this->_filePath;
}
                                              
inline QString ImageCompressor::fetFilePath()
{
    return this->_outputFilePath;
}

// Mutateur

inline void ImageCompressor::setHeight( const unsigned int &h)
{
    this->_height = h;
}

inline void ImageCompressor::setWidth( const unsigned int &w)
{
    this->_width = w;
}
}

inline void ImageCompressor::setQuality(const unsigned int &q)
{
    this->_quality = q;
}

inline void ImageCompressor::setFilePath( const QString &filePath)
{
    this->_filePath = filePath;
}
                                              
inline void ImageCompressor::setFilePath( const QString &output)
{
    this->_outputFilePath = output;
}