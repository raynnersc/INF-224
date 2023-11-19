#ifndef VIDEOOBJECT_H
#define VIDEOOBJECT_H

#include "mediaObject.h"

extern std::string endLine;

class VideoObject : public MediaObject
{
protected:
    unsigned int duration{};

public:
    VideoObject();
    VideoObject(std::string nameFile, std::string pathFile, unsigned int duration);
    ~VideoObject();
    void setDuration(unsigned int duration);
    unsigned int getDuration() const;
    void reproduceMedia() const override;
    void displayVariables(std::ostream &log) const override;
    std::string displayVariables() const override;
};

#endif // VIDEOOBJECT_H
