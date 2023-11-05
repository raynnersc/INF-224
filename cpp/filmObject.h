#ifndef FILMOBJECT_H
#define FILMOBJECT_H

#include "videoObject.h"

class FilmObject : public VideoObject
{
private:
    unsigned int *chapters;
    unsigned int numChapters;

public:
    FilmObject();
    FilmObject(std::string nameFile, std::string pathFile, const unsigned int duration, const unsigned int *chapters, const unsigned int numChapters);
    ~FilmObject();
    void setChapters(const unsigned int *chapters, const unsigned int numChapters);
    const unsigned int *getChapters();
    const unsigned int getNumChapters();
    const void displayVariables(std::ostream &log) override;
};

#endif // FILMOBJECT_H