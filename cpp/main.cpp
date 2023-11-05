//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include <string.h>
#include <memory>
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

    std::shared_ptr<FilmObject> film(new FilmObject("Film 1", "Gallery", 1, tab, 3));
    std::shared_ptr<PhotoObject> photo(new PhotoObject("Photo 2", "Drive", 19.7859, 23.774));

    GroupObject group("Group 1");
    group.push_back(film);
    group.push_back(photo);
    group.displayVariables(std::cout);
    
    film.reset();
    photo.reset();

    return 0;
}
