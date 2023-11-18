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
#include "managerObject.h"  

int main(int argc, const char *argv[])
{
    ManagerObject *manager = new ManagerObject();
    PhotoPtr photo(new PhotoObject("Photo 4 of Group", "Drive", 19.7859, 23.774));

    manager->createPhoto("Photo 0", "~/gallery/Photo_0.png", 19.7859, 23.774);
    manager->createGroup("Group 1");

    manager->findGroup("Group 1")->push_back(photo);
    manager->displayGroup("Group 1", std::cout);
    manager->deleteGroup("Group 1");
    manager->displayGroup("Group 1", std::cout);
    
    manager->displayMedia("Photo 1", std::cout);
    manager->displayMedia("Photo 2", std::cout);
    
    manager->reproduceMedia("Photo 1");    
    manager->deleteMedia("Photo 1");

    delete manager;

    return 0;
}
