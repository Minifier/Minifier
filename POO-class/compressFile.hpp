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

    inline bool getChange();
    inline bool getExist();
    inline std::string getFilePath();
    inline std::string getOutputFile();
    inline std::string getType();

    inline void setChange(bool change);
    inline void setExist(bool exist);
    inline void setFilePath(std::string filePath);

private:
    bool _change, _exist;
    std::string _filePath , _outputFile, _type;
};

} //end code_compressor

#endif