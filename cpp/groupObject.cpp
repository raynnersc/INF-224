#include "groupObject.h"

GroupObject::GroupObject() : nameGroup{} {}

GroupObject::GroupObject(std::string nameGroup)
{
    this->nameGroup = nameGroup;
}

std::string GroupObject::getNameGroup() const
{
    return this->nameGroup;
}

void GroupObject::displayVariables(std::ostream &log) const
{
    log << "Group Name: " << this->getNameGroup() << std::endl;
    for (auto it = this->begin(); it != this->end(); ++it) //for(auto &it : *this)
    {
        (*it)->displayVariables(log);
    }
}

std::string GroupObject::displayVariables() const
{
    std::string str = "Group Name: " + this->getNameGroup() + this->endLine;
    for (auto it = this->begin(); it != this->end(); ++it) //for(auto &it : *this)
    {
        str += (*it)->displayVariables();
    }
    return str;
}