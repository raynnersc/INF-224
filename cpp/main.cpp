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
#include "protocolCom.h"
#include "tcpserver.h"

#define QUESTION_11

const int PORT = 3331;

int main(int argc, const char *argv[])
{

#ifdef QUESTION_6
    const unsigned int duration = 20;
    const unsigned int numChapters = 4;
    const unsigned int newNumChapters = 4;
    const unsigned int chapters[numChapters] = {5, 4, 7, 3};
    const unsigned int newChapters[newNumChapters] = {1, 9, 8, 2};
    const unsigned int newNewChapters[newNumChapters] = {10, 90, 80, 20};
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

    FilmObject *filme = new FilmObject();
    filme->setNameFile("Film 6");
    filme->setPathFile("~/gallery/Film_6->mp4");
    filme->setDuration(duration);
    // filme->setChapters(newChapters, newNumChapters);
    filme->displayVariables(std::cout);
    // film->setChapters(newNewChapters, newNumChapters);
    // film->displayVariables(std::cout);

    // Free memory
    for (unsigned int i = 0; i < nbMedia; i++)
        delete media[i];

    delete filme;
#endif

#ifdef QUESTION_7
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
#endif

#ifdef QUESTION_8
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
#endif

#ifdef QUESTION_9
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
#endif

#ifdef QUESTION_10

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

    manager->reproduceMedia<VoidType>("Photo 1");
    manager->deleteMedia("Photo 1");

    delete manager;

#endif

#ifdef QUESTION_11

    ManagerObject manager = ManagerObject();
    manager.createPhoto("Photo_0", "../files/Photo_0.png", 19.7859, 23.774);
    manager.createVideo("Video_1", "../files/Video_1.mp4", 120);

    // cree le TCPServer
    auto *server =
        new TCPServer([&](std::string const &request, std::string &response)
                      {

    // the request sent by the client to the server
    std::cout << "request: " << request << std::endl;

    // the response that the server sends back to the client
    response = protocol(request, manager);
    std::cout << "response: " << response << std::endl;

    // return false would close the connecytion with the client
    return true; });

    // lance la boucle infinie du serveur
    std::cout << "Starting Server on port " << PORT << std::endl;

    int status = server->run(PORT);

    // en cas d'erreur
    if (status < 0)
    {
        std::cerr << "Could not start Server on port " << PORT << std::endl;
        return 1;
    }

#endif

    return 0;
}
