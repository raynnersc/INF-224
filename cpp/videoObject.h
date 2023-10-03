#ifndef VIDEOOBJECT_H
#define VIDEOOBJECT_H

#include "mediaObject.h"

class VideoObject : public MediaObject
{
private:
    unsigned int duration;
public:
    VideoObject();
    VideoObject(std::string nameFile, std::string pathFile, unsigned int duration);
    ~VideoObject();
    void setDuration(unsigned int duration);
    const unsigned int getDuration();
    const void displayVariables(std::ostream &log) override;
    const void reproduceMedia() override;
};

#endif // VIDEOOBJECT_H
