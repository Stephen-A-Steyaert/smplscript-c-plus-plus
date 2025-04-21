#include <string>
#include "include/error/error.h"
#include "include/error/illegalCharacterError.h"
 
// Constructor
// Calls the Error constructor with the "Illegal Character" error name and details
std::IllegalCharacterError::IllegalCharacterError(std::string details) : std::Error("Illegal Character", details) {}