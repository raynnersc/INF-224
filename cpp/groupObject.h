#ifndef GROUPOBJECT_H
#define GROUPOBJECT_H

#include <list>
#include <memory>
#include "mediaObject.h"

using MediaPtr = std::shared_ptr<MediaObject>;

class GroupObject : public std::list<MediaPtr>
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