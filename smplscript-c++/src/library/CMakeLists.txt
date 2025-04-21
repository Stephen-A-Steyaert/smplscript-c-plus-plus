add_library(library)

target_sources(library 
PUBLIC
    include/constants/constants.h
    include/constants/license.h
)

target_include_directories(library PUBLIC include)

add_library(smplscript::library ALIAS library)
