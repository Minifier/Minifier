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

ImageCompressor::ImageCompressor(std::string n, int h, int w, std::string ext, int q, int d, std::string f) // Constructeur de la classe ImageCompressor
    : name_{n}, height_{h}, width_{w}, extension_{ext}, quality_{q}, dimension_{d}, file_{f} ///OK
{

}

ImageCompressor::~ImageCompressor()
{

}

void ImageCompressor::loadPicture()
{

}

//Permet de traduire l'image reçu en paramètre sous la forme d'une matrice de valeurs de pixels avec trois valeurs R G et B.
std::vector<std::vector<std::vector<int, int, int>>> imageToRGB() //OK
{
	std::vector<std::vector<std::vector<int, int,int>>> RGB[this->width_][this->height_][3]; 
	int r,g,b;
	for (int x=0; x<this->width_; x++){ // Création de la matrice RGB
		for (int y=0; y<this->height_; y++){
			r=file[x][y][0];
			g=file[x][y][1];
			b=file[x][y][2];
			RGB[x][y].emplace_back(std::vector<r,g,b>);
		}
	}
	return RGB;
}

//Transforme la matrice RGB en matrice YCbCr grâce à une matrice de coefficients à appliquer sur chaque triplet d'un pixel . 
void ImageCompressor::RGBToYCrCb() ///OK
{
	int Y,Cb,Cr;
	std::vector<std::vector<std::vector<int, int,int>>> YCbCr[this->width][this->height][3];
	for(int i =0; i<=this->width_; i++){ // Conversion de la matrice RGB en YCbCr
		for(int j =0; j<=this->height_; j++){			
			Y = 0,299*RGB[i][j][0] + 0,587*RGB[i][j][1] + 0,114*RGB[i][j][2];
			Cb = 0,1687*RGB[i][j][0] - 0,3313*RGB[i][j][1] + 0,5*RGB[i][j][2] + 128;
			Cr = 0,5*RGB[i][j][0] - 0,4187*RGB[i][j][1] - 0,0813*RGB[i][j][2] + 128;
			YCbCr[i][j].emplace_back(std::vector<Y,Cb,Cr>);
		}
	}
}

//Transforme la matrice YCbCr en matrice RGB grâce à une matrice de coefficients à appliquer sur chaque triplet d'un pixel . 
void ImageCompressor::YCrCbToRGB() /// OK
{
	int R,G,B;
	std::vector<std::vector<std::vector<int, int,int>>> RGBNew[this->width][this->height];
	for(int i =0; i<=imageCompressor.getDimension()/3; i++){ // Conversion de la matrice YCbCr en matrice RGBNew
		for(int j=0; i<this->height_;j++){
			R = YCbCr[i][j][0] + 1.402*YCbCr[i][j][2];
			G = YCbCr[i][j][0] - 0,344136*YCbCr[i][j][1] - 0.714136*YCbCr[i][j][2];
			B = YCbCr[i][j][0] + 1.772*YCbCr[i][j][1];
			RGBNew[i][j].emplace_back(std::vector<R,G,B>);
		}
	}
}

//Sous échantillonage de la matrice YCbCr pour mettre à 0 les CbCr trois fois sur quatre car la chrominance est une donnée de l'image peut visible à l'oeil nue. 
void ImageCompressor::Echant422()
{
	for (int i =0;i<(YCbCr.getSize()/2);i++){ 
		for(int j=0 ; j<(YCbCr.getSize()/2);j++){ 
		      if (i%2==1 && j%2==0){ 
			YCbCr[i][j][1]=0; 
		      }
		      else if(j%2==1 && i%2==0){ 
			YCbCr[i][j][2]=0; 
		      }
		      else if(j%2==1 && i%2==1){ 
			YCbCr[i][j][1]=0; 
			YCbCr[i][j][2]=0; 
		      }
		      else if(j%2==0 && i%2==0){ 
			continue; 
		      }
		}
	} 
}


//Découpage de la matrice Initiale YCbCr en bloc de 8x8 pour le sous échantillonage pour permettre de gagner en temps de calcul.
void ImageCompressor::Decoup8x8()
{
	//std::vector<int, int, int> sousMat[8][8];
	
	sousMat = mat2cell(Echant,8,8);
	//for (int i=0; i<this->length_;i++){
	//	for (int j=0; j<this->height_;j++){
	//			
	//	}
	//}
}

/// Quantification des sous matrices 8x8 en fonction du coeffcient de qualité souhaité, on divide chaque composante par la valeur associée de quantification.
void ImageCompressor::Quantify() /// OK
{
	int Quantify[_N][_N];
	for (int i=0; i<_N; i++){ // Création de la matrice de quantification 8x8 avec un pas de quality_ 
		for (int j=0; j<_N; j++){
			Quantify[i][j]=1+(i+j+1)*this->quality_;
		}
	}
	
	for (int i =0; i < _N; i++){ // Modification des matrices 8x8 DCT en divisant chaque composante par son coefficient de qualité dans la matrice Quatify.
		for (int j=0; j< _N; j++){
			int DCTQ[i][j]=DCT[i][j]/Quantify[i][j];
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
	}
}

void ImageCompressor::DCT() /// OK
{
	std::vector<std::vector<int>> DCT[_N][_N];
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


void ImageCompressor::Huffman()
{

}

void ImageCompressor::resize() //Optionnel
{

}

void ImageCompressor::createImageSource()//PNG to JPEG
{

}

void ImageCompressor::createImageCible()//PNG to JPEG
{

}

void ImageCompressor::toCible() //PNG to JPEG
{

}

void ImageCompressor::HuffmanInverse()
{

}

void ImageCompressor::unquantify()
{

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

void ImageCompressor::convertPNG()//PNG to JPEG
{

}


// Accesseur

inline int ImageCompressor::getHeight() /// OK
{
	return this->height_;
}

inline int ImageCompressor::getWidth() /// OK
{
	return this->width_;
}

inline int ImageCompressor::getQuality() /// OK
{
	return this->quality_;
}

inline int ImageCompressor::getDim() /// OK
{
	return this->dimension_;
}

inline std::string ImageCompressor::getName() /// OK
{
	return this->name_;
}

inline std::string ImageCompressor::getExtension()/// OK
{
	return this->extension_;
}

inline std::string ImageCompressor::getFile()/// OK
{
	return this->file_;
}


// Mutateur

inline void ImageCompressor::setHeight( int h) /// OK
{
	this->height_ = h;
}

inline void ImageCompressor::setWidth( int w)/// OK
{
	this->width_ = w;
}
}

inline void ImageCompressor::setQuality( int q)/// OK
{
	this->quality_ = q;
}

inline void ImageCompressor::setDim() /// OK
{
	this->dimension_ = std::make_tuple(this->width_,this->height_);

}

inline void ImageCompressor::setFile( std::string f ) /// OK
{
	this->file = utils.getFile(Filepath)
}
