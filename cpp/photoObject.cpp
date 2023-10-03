#include "photoObject.h"

PhotoObject::PhotoObject(){}

PhotoObject::PhotoObject(std::string nameFile, std::string pathFile, float latitude, float longitude){
    this->nameFile = nameFile;
    this->pathFile = pathFile;
    this->latitude = latitude;
    this->longitude = longitude;
}

PhotoObject::~PhotoObject(){}

void PhotoObject::setLatitude(float latitude){
    this->latitude = latitude;
}

void PhotoObject::setLongitude(float longitude){
    this->longitude = longitude;
}

const float PhotoObject::getLatitude(){
    return this->latitude;
}

const float PhotoObject::getLongitude(){
    return this->latitude;
}

const void PhotoObject::displayVariables(std::ostream &log){
    log << "File Name: " << this->getNameFile() << std::endl
        << "File path: " << this->getPathFile() << std::endl
        << "Photo Latitude: " << this->getLatitude() << std::endl
        << "Photo Longitude: " << this->getLongitude() << std::endl;
}

const void PhotoObject::reproduceMedia(){
    std::string command = "imagej " + getPathFile() + " &";
    std::system(command.data());
}
