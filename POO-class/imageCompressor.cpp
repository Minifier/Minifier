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
#define _N 8

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

//Permet de traduire l'image reçu en paramètre sous la forme d'une matrice de valeurs de pixels avec trois valeurs R G et B.
std::vector<int, int, int> imageToRGB()
{
	std::vector<int, int,int> pixel[this-width_][this->height_]; 
	int r,g,b;
	for (int x=0; x<(this->width_*this->height_)/3; x+=3){
		r=file[x+0];
		g=file[x+1];
		b=file[x+2];
		std::make_tuple(r,g,b) p;
		std::vector.emplace_back(p) pixel[][];
	}
	return pixel;
}

//Transforme la matrice RGB en matrice YCbCr grâce à une matrice de coefficients à appliquer sur chaque triplet d'un pixel . 
void ImageCompressor::RGBToYCrCb()
{
	int Y,Cb,Cr;
	std::vector<int, int, int> YCbCr[this->width][this->height];
		for(int i =0; i<=imageCompressor.getDimension()/3; i++){	
			Y = 0,299*pixel[i][0] + 0,587*pixel[i][1] + 0,114*pixel[i][2];
			Cb = 0,1687*pixel[i][0] - 0,3313*pixel[i][1] + 0,5*pixel[i][2] + 128;
			Cr = 0,5*pixel[i][0] - 0,4187*pixel[i][1] - 0,0813*pixel[i][2] + 128;
			YCbCr.emplace_back(Y,Cb,Cr);
		}
}

//Transforme la matrice YCbCr en matrice RGB grâce à une matrice de coefficients à appliquer sur chaque triplet d'un pixel . 
void ImageCompressor::YCrCbToRGB()
{
	int R,G,B;
	std::vector<int, int, int> RGB[this->width][this->height];
		for(int i =0; i<=imageCompressor.getDimension()/3; i++){	
			R = 1*YCbCr[i][0] + 1.402*YCbCr[i][2];
			G = YCbCr[x][0] - 0,344136*YCbCr[x][1] - 0.714136*YCbCr[i][2];
			B = YCbCr[i][0] + 1.772*YCbCr[i][1];
			RGB.emplace_back(R,G,B);
		}
}

//Sous échantillonage de la matrice YCbCr pour mettre à 0 les CbCr trois fois sur quatre car la chrominance est une donnée de l'image peut visible à l'oeil nue. 
void ImageCompressor::Echant422()
{
	for (int i =0;i<YCbCr.size();i++){
	}
}


//Découpage de la matrice Initiale YCbCr en bloc de 8x8 pour le sous échantillonage pour permettre de gagner en temps de calcul.
void ImageCompressor::Decoup8x8()
{
	//std::vector<int, int, int> sousMat[8][8];
	//for (int i=0; i<this->length_;i++){
	//	for (int j=0; j<this->height_;j++){
	//			
	//	}
	//}
}


void ImageCompressor::Quantify()
{
	float Quantify[_N][_N];
	for (int i=0; i<_N; i++){
		for (int j=0; j<_N; j++){
			Quantify[i][j]=1+(i+j+1)*this->quality_;
		}
	}
}

void ImageCompressor::ZigZag()
{

}

void ImageCompressor::DCT()
{
	std::vector<int, int> DCT[_N][_N];
	for (int i=0;i<_N;i++){
		for(int j=0; j<_N; j++){
			DCT[i][j]=(1/sqrt(2));
			for (int x=0; x<_N; x++){
				for (int y=0; y<_N; y++){
					DCT[i][j]+=pixel[x][y]*cos((2*x+1)*i*3,14159/(2*_N))*cos((2*y+1)*j*3,14159/(2*_N));
				}
			}
		}
	}
	
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
	std::vector<int, int> pixel[_N][_N];
	for (int x=0;x<_N;x++){
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

void ImageCompressor::convertPNG()
{

}


// Accesseur

inline int ImageCompressor::getHeight()
{
	return this->height_;
}

inline int ImageCompressor::getWidth()
{
	return this->width_;
}

inline int ImageCompressor::getQuality()
{
	return this->quality_;
}

inline int ImageCompressor::getDim()
{
	return this->dimension_;
}

inline std::string ImageCompressor::getName()
{
	return this->name_;
	/* this->type = "jpg";
	auto c = explode(filePath, '.');
	if(c.size() == 2){
		this->name_ = "" + c[0];
		return this->name_;
	}else{
		std::string path = "";
		for( int i = 0; i < c.size()-1 ; i++){
			path += c[i].c_str();
		}
		this->name_ = "" + path;
		return this->name_;
	} */
}

inline std::string ImageCompressor::getExtension()
{
	return this->extension_;
	/* this->type = "jpg";
	auto c = explode(filePath, '.');
	if(c.size() == 2){
		this->extension_ = "" + c[1];
		return this->extension_;
	}else{
		this->extension_ = "" + c[c.size()-1];
		return this->extension_;
	} */
}

inline std::string ImageCompressor::getFile()
{
	return this->file_;
}


// Mutateur

inline void ImageCompressor::setHeight( int h)
{
	this->height_ = h;
}

inline void ImageCompressor::setWidth( int w)
{
	this->width_ = w;
}
}

inline void ImageCompressor::setQuality( int q)
{
	this->quality_ = q;
}

inline void ImageCompressor::setDim()
{
	this->dimension_ = std::make_tuple(this->width_,this->height_);

}

//inline void ImageCompressor::setName( std::string n)
//{
//	
//}

//inline void ImageCompressor::setExtension( std::string e)
//{
//
//}

inline void ImageCompressor::setFile( std::string f )
{
	this->file = utils.getFile(Filepath)
}
