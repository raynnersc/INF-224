/**
 * @file filmObject.h
 * @author Raynner Schnneider Carvalho
 * @brief Header file for the FilmObject class.
 * @version 1.0.0
 * @date 2023-11-19
 */

#ifndef FILMOBJECT_H
#define FILMOBJECT_H

#include "videoObject.h"

extern std::string endLine;

class FilmObject : public VideoObject
{
private:
    unsigned int *chapters{};
    unsigned int numChapters{};

public:
    /**
     * @brief Default constructor for the FilmObject class.
     *
     * This constructor creates an instance of FilmObject using the default constructor
     * of the base class VideoObject. It initializes the chapters array as an empty array
     * and sets the number of chapters (numChapters) to zero.
     */
    FilmObject();

    /**
     * @brief Parameterized constructor for the FilmObject class.
     *
     * This constructor creates an instance of FilmObject with specified parameters.
     * It initializes the FilmObject using the constructor of the base class VideoObject,
     * setting the name, path, and duration. Additionally, it sets the number of chapters
     * and allocates memory for the chapters array, copying the values from the input array.
     *
     * @param nameFile   The name of the film file.
     * @param pathFile   The path to the film file.
     * @param duration   The duration of the film in seconds.
     * @param chapters   An array representing the chapters of the film.
     * @param numChapters The number of chapters in the film.
     */
    FilmObject(std::string nameFile, std::string pathFile, const unsigned int duration, const unsigned int *chapters, const unsigned int numChapters);

    /**
     * @brief Destructor for the FilmObject class.
     *
     * This destructor is responsible for deallocating resources associated with a FilmObject
     * instance. It prints a message to the console indicating that the FilmObject destructor
     * is being called, and then frees the memory allocated for the chapters array.
     */
    ~FilmObject();

    /**
     * @brief Set chapters for the FilmObject.
     *
     * This function sets the chapters for the FilmObject instance. It first deallocates
     * any existing chapters array to avoid memory leaks. Then, it allocates a new array
     * and copies the values from the input array. Finally, it updates the number of chapters.
     *
     * @param chapters     An array representing the chapters of the film.
     * @param numChapters  The number of chapters in the film.
     */
    void setChapters(const unsigned int *chapters, const unsigned int numChapters);

    /**
     * @brief Get the chapters array for the FilmObject.
     *
     * This function returns a pointer to the chapters array of the FilmObject.
     *
     * @return A pointer to the chapters array.
     */
    unsigned int *getChapters() const;

    /**
     * @brief Get the number of chapters for the FilmObject.
     *
     * This function returns the number of chapters in the FilmObject.
     *
     * @return The number of chapters.
     */
    unsigned int getNumChapters() const;

    /**
     * @brief Display the variables of the FilmObject.
     *
     * This function displays the variables of the FilmObject, including the base class
     * VideoObject's variables and the chapters of the film.
     *
     * @param log The output stream to which the variables will be displayed.
     */
    void displayVariables(std::ostream &log) const override;

    /**
     * @brief Display the variables of the FilmObject as a string.
     *
     * This function returns a string containing the variables of the FilmObject, including
     * the base class VideoObject's variables and the chapters of the film.
     *
     * @return A string representation of the FilmObject variables.
     */
    std::string displayVariables() const override;

    /**
     * @brief Copy constructor for the FilmObject class.
     *
     * This constructor creates a new FilmObject instance by copying the contents of another
     * FilmObject instance (from). It utilizes the copy constructor of the base class VideoObject
     * and then copies the number of chapters and allocates memory for the chapters array if needed.
     *
     * @param from The FilmObject instance to be copied.
     */
    FilmObject(const FilmObject &from);

    /**
     * @brief Assignment operator for the FilmObject class.
     *
     * This assignment operator overloads the assignment operator to copy the contents
     * of another FilmObject instance (from) into the current instance. It utilizes the
     * assignment operator of the base class VideoObject and then copies the number of
     * chapters and allocates memory for the chapters array if needed.
     *
     * @param from The FilmObject instance to be assigned.
     * @return A reference to the current FilmObject instance after the assignment.
     */
    FilmObject &operator=(const FilmObject &from);
};

#endif // FILMOBJECT_H