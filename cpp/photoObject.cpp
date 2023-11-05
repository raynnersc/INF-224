#include "photoObject.h"

PhotoObject::PhotoObject() : MediaObject(), latitude{}, longitude{} {}

PhotoObject::PhotoObject(std::string nameFile, std::string pathFile, float latitude, float longitude) :
    MediaObject(nameFile, pathFile) {
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
    MediaObject::displayVariables(log);
    log << "Photo Latitude: " << this->getLatitude() << std::endl
        << "Photo Longitude: " << this->getLongitude() << std::endl;
}

const void PhotoObject::reproduceMedia(){
    std::string command = "imagej " + getPathFile() + " &";
    std::system(command.data());
}
