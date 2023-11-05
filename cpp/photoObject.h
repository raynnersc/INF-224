#ifndef PHOTOOBJECT_H
#define PHOTOOBJECT_H

#include "mediaObject.h"

class PhotoObject : public MediaObject
{
private:
    float latitude{};
    float longitude{};

public:
    PhotoObject();
    PhotoObject(std::string nameFile, std::string pathFile, float latitude, float longitude);
    ~PhotoObject();
    void setLatitude(float latitude);
    void setLongitude(float longitude);
    float getLatitude() const;
    float getLongitude() const;
    void displayVariables(std::ostream &log) const override;
    void reproduceMedia() const override;
};

#endif // PHOTOOBJECT_H
