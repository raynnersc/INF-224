#include "mediaObject.h"

std::string endLine = "/end/";

MediaObject::MediaObject() : nameFile{}, pathFile{} {}

MediaObject::MediaObject(std::string nameFile, std::string pathFile)
{
    this->nameFile = nameFile;
    this->pathFile = pathFile;
}

MediaObject::~MediaObject() {
    std::cout << "MediaObject destructor called" << std::endl;
}

void MediaObject::setNameFile(std::string nameFile)
{
    this->nameFile = nameFile;
}

void MediaObject::setPathFile(std::string pathFile)
{
    this->pathFile = pathFile;
}

std::string MediaObject::getNameFile() const
{
    return this->nameFile;
}

std::string MediaObject::getPathFile() const
{
    return this->pathFile;
}

void MediaObject::displayVariables(std::ostream &log) const
{
    log << "File Name: " << this->getNameFile() << std::endl
        << "File path: " << this->getPathFile() << std::endl;
}

std::string MediaObject::displayVariables() const
{
    std::string str = "File Name: " + this->getNameFile() + endLine;
    str += "File path: " + this->getPathFile() + endLine;
    return str;
}

void MediaObject::reproduceMedia() const {}