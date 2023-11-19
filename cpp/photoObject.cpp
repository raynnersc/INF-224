#include "photoObject.h"

PhotoObject::PhotoObject() : MediaObject(), latitude{}, longitude{} {}

PhotoObject::PhotoObject(std::string nameFile, std::string pathFile, float latitude, float longitude) : MediaObject(nameFile, pathFile)
{
    this->latitude = latitude;
    this->longitude = longitude;
}

PhotoObject::~PhotoObject() {
    std::cout << "PhotoObject destructor called" << std::endl;
}

void PhotoObject::setLatitude(float latitude)
{
    this->latitude = latitude;
}

void PhotoObject::setLongitude(float longitude)
{
    this->longitude = longitude;
}

float PhotoObject::getLatitude() const
{
    return this->latitude;
}

float PhotoObject::getLongitude() const
{
    return this->latitude;
}

void PhotoObject::displayVariables(std::ostream &log) const
{
    MediaObject::displayVariables(log);
    log << "Photo Latitude: " << this->getLatitude() << std::endl
        << "Photo Longitude: " << this->getLongitude() << std::endl;
}

std::string PhotoObject::displayVariables() const
{
    std::string str = MediaObject::displayVariables();
    str += "Photo Latitude: " + std::to_string(this->getLatitude()) + endLine;
    str += "Photo Longitude: " + std::to_string(this->getLongitude()) + endLine;
    return str;
}

void PhotoObject::reproduceMedia() const
{
    std::string command = "imagej " + getPathFile() + " &";
    std::system(command.data());
}
