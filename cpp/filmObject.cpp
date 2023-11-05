#include "filmObject.h"

FilmObject::FilmObject() : VideoObject(), chapters{}, numChapters{} {}

FilmObject::FilmObject(std::string nameFile, std::string pathFile, const unsigned int duration, const unsigned int *chapters, const unsigned int numChapters) : VideoObject(nameFile, pathFile, duration)
{
    this->numChapters = numChapters;
    this->chapters = new unsigned int[numChapters];

    for (unsigned int i = 0; i < numChapters; i++)
        this->chapters[i] = chapters[i];
}

FilmObject::~FilmObject()
{
    delete[] this->chapters;
}

void FilmObject::setChapters(const unsigned int *chapters, const unsigned int numChapters)
{
    delete[] this->chapters;

    this->numChapters = numChapters;
    this->chapters = new unsigned int[numChapters];

    for (unsigned int i = 0; i < numChapters; i++)
        this->chapters[i] = chapters[i];
}

const unsigned int *FilmObject::getChapters() const
{
    return this->chapters;
}

const unsigned int FilmObject::getNumChapters() const
{
    return this->numChapters;
}

const void FilmObject::displayVariables(std::ostream &log)
{
    VideoObject::displayVariables(log);

    for (unsigned int i = 0; i < this->getNumChapters(); i++)
        log << "Chapter " << i << ": " << this->getChapters()[i] << std::endl;
}

// Deep copy
FilmObject::FilmObject(const FilmObject &from) : VideoObject(from)
{
    this->numChapters = from.numChapters;
    if (from.chapters)
    {
        this->chapters = new unsigned int[from.numChapters];
        for (unsigned int i = 0; i < from.numChapters; i++)
        {
            this->chapters[i] = from.chapters[i];
        }
    }
    else
    {
        this->chapters = nullptr;
    }
}

FilmObject &FilmObject::operator=(const FilmObject &from)
{
    VideoObject::operator=(from);
    this->numChapters = from.numChapters;

    delete[] this->chapters;

    if (from.chapters)
    {
        this->chapters = new unsigned int[from.numChapters];
        for (unsigned int i = 0; i < from.numChapters; i++)
        {
            this->chapters[i] = from.chapters[i];
        }
    }
    else
    {
        this->chapters = nullptr;
    }
    return *this;
}