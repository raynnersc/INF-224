#include "protocolCom.h"

std::string protocol(std::string request, ManagerObject &managerObject)
{
    std::stringstream iss(request);
    std::string command;
    std::vector<std::string> args;

    iss >> command;
    std::string arg;
    while (iss >> arg) {
        if (arg == endLine) {
            break;
        }
        args.push_back(arg);
    }
    
    if (command == "find")
        return managerObject.find(args[0]);
    else if (command == "displayGroup")
        return managerObject.displayGroup(args[0]);
    else if (command == "displayMedia")
        return managerObject.displayMedia(args[0]);
    else if (command == "reproduce")
        return managerObject.reproduceMedia<std::string>(args[0]);
    else
        return "Command not found";
}