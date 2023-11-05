#ifndef GROUPOBJECT_H
#define GROUPOBJECT_H

#include <list>
#include "mediaObject.h"

class GroupObject : public std::list<MediaObject *>
{
private:
    std::string nameGroup{};
public:
    GroupObject();
    GroupObject(std::string nameGroup);
    std::string getNameGroup() const;
    void displayVariables(std::ostream &log) const;
};

#endif // GROUPOBJECT_H