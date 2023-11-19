/**
 * @file protocolCom.h
 * @author Raynner Schnneider Carvalho
 * @brief Header file for the communication protocol.
 * @version 1.0.0
 * @date 2023-11-19
 */

#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <string>
#include <sstream>
#include <vector>
#include "managerObject.h"

extern std::string endLine;

/**
 * @brief Function to process a protocol request.
 *
 * This function takes a protocol request, parses it, and performs the corresponding action using the ManagerObject.
 *
 * @param request The protocol request string.
 * @param managerObject The ManagerObject used to perform actions.
 * @return A string containing the result or an error message.
 */
std::string protocol(std::string request, ManagerObject &managerObject);

#endif // PROTOCOL_H