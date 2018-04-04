#ifndef compress_file_hpp
#define compress_file_hpp 1

#include <string>

namespace code_compressor {

class CompressFile
{
public:
    CompressFile( std::string filePath );
    CompressFile(CompressFile &&) = default;
    CompressFile(const CompressFile &) = default;
    CompressFile &operator=(CompressFile &&) = default;
    CompressFile &operator=(const CompressFile &) = default;
    virtual ~CompressFile();

    virtual void compress();

private:
    bool _change, _exist;
    std::string _filePath , _outputFile, _type;
};

} //end code_compressor

#endif