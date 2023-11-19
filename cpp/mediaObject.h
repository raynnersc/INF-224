/**
 * @file mediaObject.h
 * @author Raynner Schnneider Carvalho
 * @brief Header file for the MediaObject class.
 * @version 1.0.0
 * @date 2023-11-19
 */

#ifndef MEDIAOBJECT_H
#define MEDIAOBJECT_H

#include <iostream>
#include <string.h>

extern std::string endLine;

class MediaObject
{
protected:
    std::string nameFile{};
    std::string pathFile{};
public:
    /**
     * @brief Default constructor for MediaObject.
     */
    MediaObject();

    /**
     * @brief Parameterized constructor for MediaObject.
     *
     * @param nameFile The name of the media file.
     * @param pathFile The path to the media file.
     */
    MediaObject(std::string nameFile, std::string pathFile);

    /**
     * @brief Virtual destructor for MediaObject.
     */
    virtual ~MediaObject();

    /**
     * @brief Set the name of the media file.
     *
     * @param nameFile The name of the media file.
     */
    void setNameFile(std::string nameFile);

    /**
     * @brief Set the path to the media file.
     *
     * @param pathFile The path to the media file.
     */
    void setPathFile(std::string pathFile);

    /**
     * @brief Get the name of the media file.
     *
     * @return The name of the media file.
     */
    std::string getNameFile() const;

    /**
     * @brief Get the path to the media file.
     *
     * @return The path to the media file.
     */
    std::string getPathFile() const;

    /**
     * @brief Display the variables of the media object.
     *
     * @param log The output stream to which the variables will be displayed.
     */
    virtual void displayVariables(std::ostream &log) const;

    /**
     * @brief Display the variables of the media object as a string.
     *
     * @return A string representation of the media object variables.
     */
    virtual std::string displayVariables() const;

    /**
     * @brief Virtual function to reproduce the media.
     */
    virtual void reproduceMedia() const;
};

#endif // MEDIAOBJECT_H
