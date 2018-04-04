#ifndef compress_css_hpp
#define compress_css_hpp 1

#include <string>
#include "CompressFile.hpp"

namespace code_compressor {

class CompressCSS : public CompressFile
{
public:
    CompressCSS(string filePath);
    CompressCSS(CompressCSS &&) = default;
    CompressCSS(const CompressCSS &) = default;
    CompressCSS &operator=(CompressCSS &&) = default;
    CompressCSS &operator=(const CompressCSS &) = default;
    ~CompressCSS();

    void compress() override;

private:
    
};

} //end code_compressor

#endif