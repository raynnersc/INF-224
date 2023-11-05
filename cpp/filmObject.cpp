#include "filmObject.h"

FilmObject::FilmObject() : VideoObject(), chapters{}, numChapters{} {}

FilmObject::FilmObject(std::string nameFile, std::string pathFile, const unsigned int duration, const unsigned int *chapters, const unsigned int numChapters) :
    VideoObject(nameFile, pathFile, duration) {
    this->numChapters = numChapters;
    this->chapters = new unsigned int[numChapters];
    for(unsigned int i = 0; i < numChapters; i++)
        this->chapters[i] = chapters[i];
}

FilmObject::~FilmObject() {
    delete[] this->chapters;
}

void FilmObject::setChapters(const unsigned int *chapters, const unsigned int numChapters){
    // delete[] this->chapters;
    this->numChapters = numChapters;
    for(unsigned int i = 0; i < numChapters; i++)
        this->chapters[i] = chapters[i];
}

const unsigned int *FilmObject::getChapters(){
    return this->chapters;
}

const unsigned int FilmObject::getNumChapters(){
    return this->numChapters;
}

const void FilmObject::displayVariables(std::ostream &log){
    VideoObject::displayVariables(log);
    for(unsigned int i = 0; i < this->getNumChapters(); i++)
        log << "Chapter " << i << ": " << this->getChapters()[i] << std::endl;
}