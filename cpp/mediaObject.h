#ifndef MEDIAOBJECT_H
#define MEDIAOBJECT_H

#include <iostream>
#include <string.h>

class MediaObject
{
protected:
    std::string nameFile;
    std::string pathFile;
public:
    MediaObject();
    MediaObject(std::string nameFile, std::string pathFile);
    virtual ~MediaObject();
    void setNameFile(std::string nameFile);
    void setPathFile(std::string pathFile);
    const std::string getNameFile();
    const std::string getPathFile();
    virtual const void displayVariables(std::ostream &log);
    virtual const void reproduceMedia();
};

#endif // MEDIAOBJECT_H
