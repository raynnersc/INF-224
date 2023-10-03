#include "videoObject.h"

VideoObject::VideoObject(){}

VideoObject::VideoObject(std::string nameFile, std::string pathFile, unsigned int duration){
    this->nameFile = nameFile;
    this->pathFile = pathFile;
    this->duration = duration;
}

VideoObject::~VideoObject(){}

void VideoObject::setDuration(unsigned int duration){
    this->duration = duration;
}

const unsigned int VideoObject::getDuration(){
    return this->duration;
}

const void VideoObject::displayVariables(std::ostream &log){
    log << "File Name: " << this->getNameFile() << std::endl
        << "File path: " << this->getPathFile() << std::endl
        << "Video Duration: " << this->getDuration() << std::endl;
}

const void VideoObject::reproduceMedia(){
    std::string command = "vlc " + getPathFile() + " &";
    std::system(command.data());
}
