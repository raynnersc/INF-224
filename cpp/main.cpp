//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include <string.h>
#include "mediaObject.h"
#include "photoObject.h"
#include "videoObject.h"

int main(int argc, const char* argv[])
{
    const u_int8_t nbMedia = 6;
    MediaObject* media[nbMedia];

    // Create media
    for (u_int8_t i = 0; i < nbMedia; i++)
    {
        if (i % 2 == 0)
            media[i] = new PhotoObject("Photo_" + std::to_string(i), "~/gallery/Photo_" + std::to_string(i) + ".png", i*1.758, i*3.964);
        else
            media[i] = new VideoObject("Video_" + std::to_string(i), "~/gallery/Video_" + std::to_string(i) + ".mp4", i);
    }
    
    // Display media
    for (u_int8_t i = 0; i < nbMedia; i++)
    {
        std::cout << "media[" << std::to_string(i) << "]:" << std::endl;
        media[i] -> displayVariables(std::cout);
        media[i] -> reproduceMedia();
    }

    // Free memory
    for (u_int8_t i = 0; i < nbMedia; i++)
        delete media[i];

    return 0;
}
