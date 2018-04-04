#ifndef compress_js_hpp
#define compress_js_hpp 1

#include <string>
#include "CompressFile.hpp"

namespace code_compressor {

class CompressJS : public CompressFile
{
public:
    CompressJS( std::string filePath );
    CompressJS(CompressJS &&) = default;
    CompressJS(const CompressJS &) = default;
    CompressJS &operator=(CompressJS &&) = default;
    CompressJS &operator=(const CompressJS &) = default;
    ~CompressJS();

    void compress() override;

private:
    
};

} //end code_compressor

#endif