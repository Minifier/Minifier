#include "main.hpp"

Main::Main()
{
    this->sate_main_window = false;
}

Main::~Main()
{
}

void Main::setStateMW(bool state){
    state_main_window = state;
};

bool Main::getStateMW(){
    return state_main_window;
}

void Main::launchImg()
{

}

void Main::shutDown()
{

}

void Main::openMainW()
{

}

void Main::closeMainW()
{

}

std::unique_ptr<CodesCompressor> Main::getCodesCompressor()
{
    return this->code;
}

std::unique_ptr<ImageCompressor> Main::getImageCompressor()
{
    return this->image;
}
