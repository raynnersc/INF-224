#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <string>
#include <sstream>
#include <vector>
#include "managerObject.h"

extern std::string endLine;

std::string protocol(std::string request, ManagerObject &managerObject);

#endif // PROTOCOL_H