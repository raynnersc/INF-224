#ifndef MEDIAOBJECT_H
#define MEDIAOBJECT_H

#include <iostream>
#include <string.h>

class MediaObject
{
protected:
    std::string nameFile{};
    std::string pathFile{};

public:
    MediaObject();
    MediaObject(std::string nameFile, std::string pathFile);
    virtual ~MediaObject();
    void setNameFile(std::string nameFile);
    void setPathFile(std::string pathFile);
    std::string getNameFile() const;
    std::string getPathFile() const;
    virtual void displayVariables(std::ostream &log) const;
    virtual void reproduceMedia() const;
};

#endif // MEDIAOBJECT_H
