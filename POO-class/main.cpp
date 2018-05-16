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

#include "main.hpp"

Main::Main()
{
    this.sate_main_window = false;
}

Main::~Main()
{
}

/** 
 * @brief  function use to launch an image compressor
 * @retval None
 */
void Main::launchImg()
{

}

/** 
 * @brief  function use to shutdown logiciel
 * @retval None
 */
void Main::shutDown()
{

}

/** 
 * @brief  function use to open the main window
 * @retval None
 */
void Main::openMainW()
{
    if(!this.getStateMW()){

    }
}

/** 
 * @brief  function use to close the main window
 * @retval None
 */
void Main::closeMainW()
{
    if(this.getStateMW()){

    }
}

/*******************************************/
/************* Accesseur *******************/
/*******************************************/

bool Main::getStateMW(){
    return this.state_main_window;
}

std::unique_ptr<CodesCompressor> Main::getCodesCompressor()
{
    return this.code;
}

std::unique_ptr<ImageCompressor> Main::getImageCompressor()
{
    return this.image;
}

/*******************************************/
/************* Mutateur ********************/
/*******************************************/

void Main::setStateMW(bool state){
    this->state_main_window = state;
};
