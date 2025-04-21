#[[    smplscript, A Simple Scripting Language for Beginners
       Copyright (C) 2025  Stephen Steyaert

       This program is free software: you can redistribute it and/or modify
       it under the terms of the GNU General Public License as published by
       the Free Software Foundation, either version 3 of the License, or
       (at your option) any later version.

       This program is distributed in the hope that it will be useful,
       but WITHOUT ANY WARRANTY; without even the implied warranty of
       MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
       GNU General Public License for more details.

       You should have received a copy of the GNU General Public License
       along with this program.  If not, see <https://www.gnu.org/licenses/>.
]]

add_library(library)

target_sources(library 
PRIVATE
    entrypoint.cpp
    error.cpp
    illegalCharacterError.cpp
    lexer.cpp
    token.cpp
    position.cpp
PUBLIC
    include/constants/constants.h
    include/constants/license.h
    include/entrypoint/entrypoint.h
    include/error/error.h
    include/error/illegalCharacterError.h
    include/lexer/lexer.h
    include/position/position.h
    include/token/token.h
)

target_include_directories(library PUBLIC include)

add_library(smplscript::library ALIAS library)
