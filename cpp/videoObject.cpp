#include "videoObject.h"

VideoObject::VideoObject() : MediaObject(), duration{} {}

VideoObject::VideoObject(std::string nameFile, std::string pathFile, unsigned int duration) : MediaObject(nameFile, pathFile)
{
    this->duration = duration;
}

VideoObject::~VideoObject() {}

void VideoObject::setDuration(unsigned int duration)
{
    this->duration = duration;
}

unsigned int VideoObject::getDuration() const
{
    return this->duration;
}

void VideoObject::displayVariables(std::ostream &log) const
{
    MediaObject::displayVariables(log);
    log << "Video Duration: " << this->getDuration() << std::endl;
}

void VideoObject::reproduceMedia() const
{
    std::string command = "vlc " + this->getPathFile() + " &";
    std::system(command.data());
}
