#include "mediaObject.h"

MediaObject::MediaObject(){}

MediaObject::MediaObject(std::string nameFile, std::string pathFile){
    this->nameFile = nameFile;
    this->pathFile = pathFile;
}

MediaObject::~MediaObject(){}

void MediaObject::setNameFile(std::string nameFile){
    this->nameFile = nameFile;
}

void MediaObject::setPathFile(std::string pathFile){
    this->pathFile = pathFile;
}

const std::string MediaObject::getNameFile(){
    return this->nameFile;
}

const std::string MediaObject::getPathFile(){
    return this->pathFile;
}

const void MediaObject::displayVariables(std::ostream &log){
    log << "File Name: " << this->getNameFile() << std::endl
        << "File path: " << this->getPathFile() << std::endl;
}

const void MediaObject::reproduceMedia(){}