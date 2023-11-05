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
#include "groupObject.h"

int main(int argc, const char *argv[])
{
    unsigned int *tab = new unsigned int[3];
    tab[0] = 1;
    tab[1] = 2;
    tab[2] = 3;

    MediaObject *mediaObject = new MediaObject("mediaObject", "mediaObjectPath");
    PhotoObject *photoObject = new PhotoObject("photoObject", "photoObjectPath", 1, 1);
    VideoObject *videoObject = new VideoObject("videoObject", "videoObjectPath", 1);
    FilmObject *filmObject = new FilmObject("filmObject", "filmObjectPath", 1, tab, 3);
    GroupObject *groupObject = new GroupObject("groupObject");
    GroupObject *groupObject2 = new GroupObject("groupObject2");

    groupObject->push_back(mediaObject);
    groupObject->push_back(photoObject);
    groupObject->push_back(videoObject);
    groupObject->push_back(filmObject);
    
    groupObject2->push_back(mediaObject);
    groupObject2->push_back(photoObject);
    groupObject2->push_back(videoObject);
    groupObject2->push_back(filmObject);

    groupObject->displayVariables(std::cout);
    groupObject2->displayVariables(std::cout);

    return 0;
}
