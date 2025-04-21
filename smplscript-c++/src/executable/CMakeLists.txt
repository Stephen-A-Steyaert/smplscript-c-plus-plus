add_executable(smpl)

target_sources(
    smpl
    PRIVATE
    main.cpp
)

target_link_libraries(
    smpl
    PRIVATE 
    smplscript::library
)
