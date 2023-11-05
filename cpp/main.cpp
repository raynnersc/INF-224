//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include <string.h>
#include "mediaObject.h"
#include "photoObject.h"
#include "videoObject.h"
#include "filmObject.h"

int main(int argc, const char *argv[])
{
    const unsigned int duration = 20;
    const unsigned int numChapters = 4;
    // const unsigned int newNumChapters = 4;
    const unsigned int chapters[numChapters] = {5, 4, 7, 3};
    unsigned int *newChapters = new unsigned int[numChapters];
    // const unsigned int newNewChapters[newNumChapters] = {10,90,80,20};
    const unsigned int nbMedia = 6;
    MediaObject *media[nbMedia];

    // Create media
    for (unsigned int i = 0; i < nbMedia - 1; i++)
    {
        if (i % 2 == 0)
            media[i] = new PhotoObject("Photo_" + std::to_string(i), "~/gallery/Photo_" + std::to_string(i) + ".png", i * 1.758, i * 3.964);
        else
            media[i] = new VideoObject("Video_" + std::to_string(i), "~/gallery/Video_" + std::to_string(i) + ".mp4", i);
    }

    media[nbMedia - 1] = new FilmObject("Film_" + std::to_string(nbMedia - 1),
                                        "~/gallery/Film_" + std::to_string(nbMedia - 1) + ".mp4",
                                        duration, chapters, numChapters);

    // Display media
    for (unsigned int i = 0; i < nbMedia; i++)
    {
        std::cout << "media[" << std::to_string(i) << "]:" << std::endl;
        media[i]->displayVariables(std::cout);
        // media[i] -> reproduceMedia();
    }
    media[nbMedia - 1]->displayVariables(std::cout);

    for (uint8_t i = 0; i < 4; i++)
        newChapters[i] = i;

    FilmObject *filme = new FilmObject();
    FilmObject *filme2 = new FilmObject();
    filme->setNameFile("Film 6");
    filme->setPathFile("~/gallery/Film_6.mp4");
    filme->setDuration(duration);
    filme->setChapters(newChapters, 4);
    filme->displayVariables(std::cout);

    for (uint8_t i = 0; i < 4; i++)
        newChapters[i] = i * 10 + 3;

    *filme2 = *filme;
    filme->displayVariables(std::cout);
    filme2->setNameFile("Film 6_novo");
    filme2->displayVariables(std::cout);
    delete[] newChapters;
    filme->setNameFile("Film 7");
    filme->displayVariables(std::cout);

    // Free memory
    for (unsigned int i = 0; i < nbMedia; i++)
        delete media[i];


    delete filme;
    filme2->displayVariables(std::cout);
    
    FilmObject *filme3 = new FilmObject(*filme2);
    filme3->displayVariables(std::cout);
    delete filme2;
    filme3->displayVariables(std::cout);
    delete filme3;

    return 0;
}
