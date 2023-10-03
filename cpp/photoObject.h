#ifndef PHOTOOBJECT_H
#define PHOTOOBJECT_H

#include "mediaObject.h"

class PhotoObject : public MediaObject
{
private:
    float latitude;
    float longitude;
public:
    PhotoObject();
    PhotoObject(std::string nameFile, std::string pathFile, float latitude, float longitude);
    ~PhotoObject();
    void setLatitude(float latitude);
    void setLongitude(float longitude);
    const float getLatitude();
    const float getLongitude();
    const void displayVariables(std::ostream &log) override;
    const void reproduceMedia() override;
};

#endif // PHOTOOBJECT_H
