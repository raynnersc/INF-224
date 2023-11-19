/**
 * @file videoObject.h
 * @author Raynner Schnneider Carvalho
 * @brief Header file for the VideoObject class.
 * @version 1.0.0
 * @date 2023-11-19
 */

#ifndef VIDEOOBJECT_H
#define VIDEOOBJECT_H

#include "mediaObject.h"

extern std::string endLine;

class VideoObject : public MediaObject
{
protected:
    unsigned int duration{};

public:
    /**
     * @brief Default constructor for VideoObject.
     */
    VideoObject();

    /**
     * @brief Parameterized constructor for VideoObject.
     *
     * @param nameFile The name of the video file.
     * @param pathFile The path to the video file.
     * @param duration The duration of the video in seconds.
     */
    VideoObject(std::string nameFile, std::string pathFile, unsigned int duration);

    /**
     * @brief Destructor for VideoObject.
     */
    ~VideoObject();

    /**
     * @brief Set the duration of the video.
     *
     * @param duration The duration of the video in seconds.
     */
    void setDuration(unsigned int duration);

    /**
     * @brief Get the duration of the video.
     *
     * @return The duration of the video in seconds.
     */
    unsigned int getDuration() const;

    /**
     * @brief Reproduce the video media.
     */
    void reproduceMedia() const override;

    /**
     * @brief Display the variables of the video object.
     *
     * @param log The output stream to which the variables will be displayed.
     */
    void displayVariables(std::ostream &log) const override;

    /**
     * @brief Display the variables of the video object as a string.
     *
     * @return A string representation of the video object variables.
     */
    std::string displayVariables() const override;
};

#endif // VIDEOOBJECT_H
