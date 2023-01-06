cmake_minimum_required(VERSION 3.5)
# name of project
project(DaStaA)

# folder whose libraries should be included
include_directories(include)

# files to include to create the executable
#file(GLOB SOURCES "src/*.cpp")

# files to include to make the library
add_library(DaStaA SHARED
    # src/file.cpp
)

# optional but good practice
set_target_properties(DaStaA PROPERTIES VERSION ${PROJECT_VERSION})

# create the API for using the library
set_target_properties(DaStaA PROPERTIES PUBLIC_HEADER 
    # include/header.h
)

# create executable
add_executable(DaStaA ${SOURCES})
