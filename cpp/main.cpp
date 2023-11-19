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
    manager.createPhoto("Photo_0", "~/gallery/Photo_0.png", 19.7859, 23.774);
    manager.createVideo("Video_1", "~/gallery/Video_1.mp4", 120);

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

    // en cas d'erreur
    if (status < 0)
    {
        std::cerr << "Could not start Server on port " << PORT << std::endl;
        return 1;
    }

#endif

    return 0;
}
