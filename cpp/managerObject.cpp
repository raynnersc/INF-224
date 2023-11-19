#include "managerObject.h"

ManagerObject::ManagerObject() : mediaMap{}, groupMap{} {}

ManagerObject::~ManagerObject() {}

PhotoPtr ManagerObject::createPhoto(std::string nameFile, std::string pathFile, float latitude, float longitude)
{
    auto media = std::make_shared<PhotoObject>(nameFile, pathFile, latitude, longitude);
    this->mediaMap[nameFile] = media;
    return media;
}

VideoPtr ManagerObject::createVideo(std::string nameFile, std::string pathFile, int duration)
{
    auto media = std::make_shared<VideoObject>(nameFile, pathFile, duration);
    this->mediaMap[nameFile] = media;
    return media;
}

FilmPtr ManagerObject::createFilm(std::string nameFile, std::string pathFile, int duration, unsigned int *chapters, unsigned int numChapters)
{
    auto media = std::make_shared<FilmObject>(nameFile, pathFile, duration, chapters, numChapters);
    this->mediaMap[nameFile] = media;
    return media;
}

GroupPtr ManagerObject::createGroup(std::string nameGroup)
{
    this->groupMap[nameGroup] = std::make_shared<GroupObject>(nameGroup);
    return this->groupMap[nameGroup];
}

MediaPtr ManagerObject::findMedia(std::string nameFile)
{
    auto it = this->mediaMap.find(nameFile);
    if (it != this->mediaMap.end())
        return it->second;
    else
        return nullptr;
}

GroupPtr ManagerObject::findGroup(std::string nameGroup)
{
    auto it = this->groupMap.find(nameGroup);
    if (it != this->groupMap.end())
        return it->second;
    else
        return nullptr;
}

std::string ManagerObject::find(std::string nameFile)
{
    return (this->displayGroup(nameFile) + this->displayMedia(nameFile));
}

void ManagerObject::displayMedia(std::string nameFile, std::ostream &log)
{
    auto it = this->findMedia(nameFile);
    if(!it)
        log << "Media " << nameFile << " not found" << std::endl;
    else
        it->displayVariables(log);
}

void ManagerObject::displayGroup(std::string nameGroup, std::ostream &log)
{
    auto it = this->findGroup(nameGroup);
    if(!it)
        log << "Group " << nameGroup << " not found" << std::endl;
    else
        it->displayVariables(log);
}

std::string ManagerObject::displayMedia(std::string nameFile)
{
    auto it = this->findMedia(nameFile);
    if(!it)
        return ("Media " + nameFile + " not found" + endLine);
    else
        return it->displayVariables();
}

std::string ManagerObject::displayGroup(std::string nameFile)
{
    auto it = this->findGroup(nameFile);
    if(!it)
        return ("Group " + nameFile + " not found" + endLine);
    else
        return it->displayVariables();
}

template <>
VoidType ManagerObject::reproduceMedia<VoidType>(std::string nameFile)
{
    auto it = this->findMedia(nameFile);
    if(!it)
        std::cout << "Media " << nameFile << " not found" << std::endl;
    else
        it->reproduceMedia();
    
    return VoidType();
}

template <>
std::string ManagerObject::reproduceMedia<std::string>(std::string nameFile)
{
    auto it = this->findMedia(nameFile);
    if(!it)
        return ("Media " + nameFile + " not found" + endLine);
    else
    {
        it->reproduceMedia();
        return ("Media " + nameFile + " is being reproduced" + endLine);
    }
}

void ManagerObject::deleteMedia(std::string nameFile)
{
    auto it = this->findMedia(nameFile);
    if(!it)
        std::cout << "Media " << nameFile << " not found" << std::endl;
    else
        this->mediaMap.erase(nameFile);
}

void ManagerObject::deleteGroup(std::string nameGroup)
{
    auto it = this->findGroup(nameGroup);
    if(!it)
        std::cout << "Group " << nameGroup << " not found" << std::endl;
    else
        this->groupMap.erase(nameGroup);
}