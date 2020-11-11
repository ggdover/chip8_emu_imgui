
add_library(glad)

target_sources(glad
    PRIVATE
        src/glad.c
)

target_include_directories(glad
    PUBLIC
        include
)

target_link_libraries(glad
    PUBLIC
        ${CMAKE_DL_LIBS} # Adds functions 'dlopen' and 'dlclose' needed by glad
)