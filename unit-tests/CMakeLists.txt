cmake_minimum_required(VERSION 3.5)
project(c_make_test LANGUAGES CXX)

add_subdirectory(lib/Catch2)
# add the subdirectory for the tests
#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/CLList CLList_tests)
#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/Shooter Shooter_tests)
#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/CLNode CLNode_tests)
#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/CLQueue CLQueue_tests)

add_executable(unit_tests)

# link the above subdirectory tests to the executable
target_link_libraries(unit_tests
    Catch2::Catch2WithMain
    #CLList_tests
    #Shooter_tests
    #CLNode_tests
    #CLQueue_tests
)

