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

class ManagerObject
{
private:
    MediaMap mediaMap{};
    GroupMap groupMap{};
public:
    ManagerObject();
    ~ManagerObject();
    // Creation of a photo, video, film or group
    PhotoPtr createPhoto(std::string nameFile, std::string pathFile, float latitude, float longitude);
    VideoPtr createVideo(std::string nameFile, std::string pathFile, int duration);
    FilmPtr createFilm(std::string nameFile, std::string pathFile, int duration, unsigned int *tab, unsigned int size);
    GroupPtr createGroup(std::string nameGroup);
    // Find a media or a group
    MediaPtr findMedia(std::string nameFile);
    GroupPtr findGroup(std::string nameGroup);
    // Display the media or the group
    void displayMedia(std::string nameFile, std::ostream &log);
    void displayGroup(std::string nameGroup, std::ostream &log);
    // Replace a media
    void reproduceMedia(std::string nameFile);
    // Delete a media or a group
    void deleteMedia(std::string nameFile);
    void deleteGroup(std::string nameGroup);
};

#endif // MANAGEROBJECT_H
