#ifndef FILMOBJECT_H
#define FILMOBJECT_H

#include "videoObject.h"

extern std::string endLine;

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
    unsigned int *getChapters() const;
    unsigned int getNumChapters() const;
    void displayVariables(std::ostream &log) const override;
    std::string displayVariables() const override;
    // Deep copy
    FilmObject(const FilmObject &from);
    FilmObject& operator=(const FilmObject &from);
};

#endif // FILMOBJECT_H