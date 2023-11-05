#ifndef FILMOBJECT_H
#define FILMOBJECT_H

#include "videoObject.h"

class FilmObject : public VideoObject
{
private:
    unsigned int *chapters{};
    unsigned int numChapters{};

public:
    FilmObject();
    FilmObject(std::string nameFile, std::string pathFile, const unsigned int duration, const unsigned int *chapters, const unsigned int numChapters);
    ~FilmObject();
    void setChapters(const unsigned int *chapters, const unsigned int numChapters);
    const unsigned int *getChapters() const;
    const unsigned int getNumChapters() const;
    const void displayVariables(std::ostream &log) final;
    
    // Deep copy
    FilmObject(const FilmObject &from);
    FilmObject &operator=(const FilmObject &from);
};

#endif // FILMOBJECT_H