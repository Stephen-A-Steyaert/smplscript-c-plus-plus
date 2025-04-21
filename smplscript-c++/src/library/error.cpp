#include "include/error/error.h"
 
 #include <string>
 
 // Constructor
 // Initializes the error name and details
std::Error::Error(std::string errorName, std::string details) {
 	mErrorName = errorName;
 	mDetails = details;
 }
 // toString function
 // Returns the error name and details as a string
 std::string std::Error::toString() {
 	return mErrorName + ": " + mDetails;
 }