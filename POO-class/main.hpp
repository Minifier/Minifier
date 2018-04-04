#ifndef main_hpp
#define main_hpp 1

namespace minifier {

#include "codesCompressor.hpp"
#include "imagecompressor.hpp"

class Main
{
public:
    Main();
    Main(Main &&) = default;
    Main(const Main &) = default;
    Main &operator=(Main &&) = default;
    Main &operator=(const Main &) = default;
    ~Main();

    // Launch an image compressor
    void launchImg();

    // ShutDown Minifier
    void shutDown();

    // Operation on mais window
    void openMainW();
    void closeMainW();

    void setStateMW(bool state);
    bool getStateMW();

    std::unique_ptr<CodesCompressor> getCodesCompressor();
    std::unique_ptr<ImageCompressor> getImageCompressor();

private:
    bool state_main_window = False;
    std::unique_ptr<CodesCompressor> code;
    std::unique_ptr<ImageCompressor> image;
};

} //end code_compressor

#endif