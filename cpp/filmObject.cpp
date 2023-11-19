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
    std::cout << "FilmObject destructor called" << std::endl;
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

unsigned int *FilmObject::getChapters() const
{
    return this->chapters;
}

unsigned int FilmObject::getNumChapters() const
{
    return this->numChapters;
}

void FilmObject::displayVariables(std::ostream &log) const
{
    VideoObject::displayVariables(log);

    for (unsigned int i = 0; i < this->getNumChapters(); i++)
        log << "Chapter " << i << ": " << this->getChapters()[i] << std::endl;
}

std::string FilmObject::displayVariables() const
{
    std::string str = VideoObject::displayVariables();

    for (unsigned int i = 0; i < this->getNumChapters(); i++)
        str += "Chapter " + std::to_string(i) + ": " + std::to_string(this->getChapters()[i]) + endLine;

    return str;
}

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