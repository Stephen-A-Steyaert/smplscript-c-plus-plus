add_library(library)

target_sources(library 
PRIVATE
    entryPoint.cpp
    error.cpp
    illegalCharError.cpp
    lexer.cpp
    token.cpp
PUBLIC
    include/constants/constants.h
    include/constants/license.h
    include/entrypoint/entrypoint.h
    include/error/error.h
    include/error/illegalCharError.h
    include/lexer/lexer.h
    include/token/token.h
)

target_include_directories(library PUBLIC include)

add_library(smplscript::library ALIAS library)
