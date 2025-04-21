#pragma once
#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

#include "../token/token.h"
#include <string>
#include <vector>

// run function for console input
std::vector<std::Token> run(std::string text);

#endif