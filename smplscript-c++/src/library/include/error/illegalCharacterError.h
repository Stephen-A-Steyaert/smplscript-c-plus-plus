#pragma once
 #ifndef ILLEGALCHARACTERERROR_H
 #define ILLEGALCHARACTERERROR_H
 
 #include "error.h"
 #include <string>
 
 /*
 * Error object for all illegal characters
 */

 namespace std
 {
    
    class IllegalCharacterError : public Error
    {
    public:
        IllegalCharacterError(std::string details);
    };

 } // namespace std
 
 #endif