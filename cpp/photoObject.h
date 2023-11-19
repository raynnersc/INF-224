/**
 * @file photoObject.h
 * @author Raynner Schnneider Carvalho
 * @brief Header file for the PhotoObject class.
 * @version 1.0.0
 * @date 2023-11-19
 */

#ifndef PHOTOOBJECT_H
#define PHOTOOBJECT_H

#include "mediaObject.h"

extern std::string endLine;

class PhotoObject : public MediaObject
{
private:
    float latitude{};
    float longitude{};

public:
    /**
     * @brief Default constructor for PhotoObject.
     */
    PhotoObject();

    /**
     * @brief Parameterized constructor for PhotoObject.
     *
     * @param nameFile The name of the photo file.
     * @param pathFile The path to the photo file.
     * @param latitude The latitude information for the photo.
     * @param longitude The longitude information for the photo.
     */
    PhotoObject(std::string nameFile, std::string pathFile, float latitude, float longitude);

    /**
     * @brief Destructor for PhotoObject.
     */
    ~PhotoObject();

    /**
     * @brief Set the latitude information of the photo.
     *
     * @param latitude The latitude information for the photo.
     */
    void setLatitude(float latitude);

    /**
     * @brief Set the longitude information of the photo.
     *
     * @param longitude The longitude information for the photo.
     */
    void setLongitude(float longitude);

    /**
     * @brief Get the latitude information of the photo.
     *
     * @return The latitude information for the photo.
     */
    float getLatitude() const;

    /**
     * @brief Get the longitude information of the photo.
     *
     * @return The longitude information for the photo.
     */
    float getLongitude() const;

    /**
     * @brief Display the variables of the photo object.
     *
     * @param log The output stream to which the variables will be displayed.
     */
    void displayVariables(std::ostream &log) const override;

    /**
     * @brief Display the variables of the photo object as a string.
     *
     * @return A string representation of the photo object variables.
     */
    std::string displayVariables() const override;

    /**
     * @brief Reproduce the photo media.
     */
    void reproduceMedia() const override;
};

#endif // PHOTOOBJECT_H
