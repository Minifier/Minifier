///////classe ImageCompressor//////

#ifndef IMAGECOMPRESS_IMAGECOMPRESSOR_HPP
#define IMAGECOMPRESS_IMAGECOMPRESSOR_HPP 1

#include "cstdio.hpp"

namespace imageCompress{
	
class ImageCompressor: 

public :
	
	ImageCompressor(std::string n, int h, int w, std::string ext, int q, int d, std::string f): name_{n}, height_{h}, width_{w}, extension_{ext}, quality_{q}, dimension_{d}, file_{f} {}
	
	
	
	private:
	
	std::string name_,extension_,file_;
	int height_,width_,quality_,dimension_
	
		
};

}

#endif