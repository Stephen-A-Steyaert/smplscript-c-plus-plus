#pragma once
 #ifndef ERROR_H
 #define ERROR_H
 
 #include <string>
 
 /*
 * Error object is the base class for future errors
 */
 
namespace std
{


    class Error
    {
    public:
        Error(std::string errorName, std::string details);
        std::string toString();
    private:
        std::string mErrorName;
        std::string mDetails;
    };

 } // namespace std
 
 #endif
