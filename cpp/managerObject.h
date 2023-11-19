/**
 * @file managerObject.h
 * @author Raynner Schnneider Carvalho
 * @brief Header file for the ManagerObject class.
 * @version 1.0.0
 * @date 2023-11-19
 */

#ifndef MANAGEROBJECT_H
#define MANAGEROBJECT_H

#include <memory>
#include <map>
#include <string>
#include "mediaObject.h"
#include "groupObject.h"
#include "photoObject.h"
#include "videoObject.h"
#include "filmObject.h"

using PhotoPtr = std::shared_ptr<PhotoObject>;
using VideoPtr = std::shared_ptr<VideoObject>;
using FilmPtr = std::shared_ptr<FilmObject>;
using MediaPtr = std::shared_ptr<MediaObject>;
using GroupPtr = std::shared_ptr<GroupObject>;

using MediaMap = std::map<std::string, MediaPtr>;
using GroupMap = std::map<std::string, GroupPtr>;

struct VoidType
{
};

class ManagerObject
{
private:
    MediaMap mediaMap{};
    GroupMap groupMap{};

public:
    /**
     * @brief Default constructor for ManagerObject.
     */
    ManagerObject();

    /**
     * @brief Destructor for ManagerObject.
     */
    ~ManagerObject();

    // Creation of a photo, video, film or group

    /**
     * @brief Create a PhotoObject and add it to the manager.
     *
     * @param nameFile The name of the photo file.
     * @param pathFile The path to the photo file.
     * @param latitude The latitude information for the photo.
     * @param longitude The longitude information for the photo.
     * @return A shared pointer to the created PhotoObject.
     */
    PhotoPtr createPhoto(std::string nameFile, std::string pathFile, float latitude, float longitude);

    /**
     * @brief Create a VideoObject and add it to the manager.
     *
     * @param nameFile The name of the video file.
     * @param pathFile The path to the video file.
     * @param duration The duration of the video in seconds.
     * @return A shared pointer to the created VideoObject.
     */
    VideoPtr createVideo(std::string nameFile, std::string pathFile, int duration);

    /**
     * @brief Create a FilmObject and add it to the manager.
     *
     * @param nameFile The name of the film file.
     * @param pathFile The path to the film file.
     * @param duration The duration of the film in seconds.
     * @param chapters An array representing the chapters of the film.
     * @param numChapters The number of chapters in the film.
     * @return A shared pointer to the created FilmObject.
     */
    FilmPtr createFilm(std::string nameFile, std::string pathFile, int duration, unsigned int *tab, unsigned int size);

    /**
     * @brief Create a GroupObject and add it to the manager.
     *
     * @param nameGroup The name of the group.
     * @return A shared pointer to the created GroupObject.
     */
    GroupPtr createGroup(std::string nameGroup);

    // Find a media or a group

    /**
     * @brief Find a media object by its name.
     *
     * @param nameFile The name of the media object.
     * @return A shared pointer to the found media object, or nullptr if not found.
     */
    MediaPtr findMedia(std::string nameFile);

    /**
     * @brief Find a group by its name.
     *
     * @param nameGroup The name of the group.
     * @return A shared pointer to the found group, or nullptr if not found.
     */
    GroupPtr findGroup(std::string nameGroup);

    /**
     * @brief Find and display the variables of a media object and/or group.
     *
     * @param nameFile The name of the media object or group.
     * @return A string containing the displayed variables.
     */
    std::string find(std::string nameFile);

    // Display the media or the group

    /**
     * @brief Display the variables of a media object.
     *
     * @param nameFile The name of the media object.
     * @param log The output stream to which the variables will be displayed.
     */
    void displayMedia(std::string nameFile, std::ostream &log);

    /**
     * @brief Display the variables of a group.
     *
     * @param nameGroup The name of the group.
     * @param log The output stream to which the variables will be displayed.
     */
    void displayGroup(std::string nameGroup, std::ostream &log);

    /**
     * @brief Display the variables of a media object as a string.
     *
     * @param nameFile The name of the media object.
     * @return A string representation of the media object variables.
     */
    std::string displayMedia(std::string nameFile);

    /**
     * @brief Display the variables of a group as a string.
     *
     * @param nameGroup The name of the group.
     * @return A string representation of the group variables.
     */
    std::string displayGroup(std::string nameGroup);

    // Reproduce a media

    /**
     * @brief Reproduce a media object.
     *
     * @tparam T The return type of the reproduction (VoidType or std::string).
     * @param nameFile The name of the media object.
     * @return A message informing the status of the reproduction.
     */
    template <typename T>
    T reproduceMedia(std::string nameFile);

    // Delete a media or a group

    /**
     * @brief Delete a media object from the manager.
     *
     * @param nameFile The name of the media object.
     */
    void deleteMedia(std::string nameFile);

    /**
     * @brief Delete a group from the manager.
     *
     * @param nameGroup The name of the group.
     */
    void deleteGroup(std::string nameGroup);
};

#endif // MANAGEROBJECT_H
