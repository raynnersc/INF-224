/**
 * @file groupObject.h
 * @author Raynner Schnneider Carvalho
 * @brief Header file for the GroupObject class.
 * @version 1.0.0
 * @date 2023-11-19
 */

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
    std::string endLine = "/end/";

public:
    /**
     * @brief Default constructor for the GroupObject class.
     *
     * Initializes the GroupObject with an empty group name.
     */
    GroupObject();

    /**
     * @brief Parameterized constructor for the GroupObject class.
     *
     * Initializes the GroupObject with the specified group name.
     *
     * @param nameGroup The name of the group.
     */
    GroupObject(std::string nameGroup);

    /**
     * @brief Get the name of the group.
     *
     * @return The name of the group.
     */
    std::string getNameGroup() const;

    /**
     * @brief Display the variables of the GroupObject.
     *
     * Displays the name of the group and the variables of each object in the group.
     *
     * @param log The output stream to which the variables will be displayed.
     */
    void displayVariables(std::ostream &log) const;

    /**
     * @brief Display the variables of the GroupObject as a string.
     *
     * Returns a string containing the name of the group and the variables of each object in the group.
     *
     * @return A string representation of the GroupObject variables.
     */
    std::string displayVariables() const;
};

#endif // GROUPOBJECT_H