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

    // Accesseur
    bool getStateMW();
    std::unique_ptr<CodesCompressor> getCodesCompressor();
    std::unique_ptr<ImageCompressor> getImageCompressor();

    // Mutateur
    void setStateMW(bool state);
    
private:
    bool state_main_window = False;
    std::unique_ptr<CodesCompressor> code;
    std::unique_ptr<ImageCompressor> image;
};

} //end code_compressor

#endif