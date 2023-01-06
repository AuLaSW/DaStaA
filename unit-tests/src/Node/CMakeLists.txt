# add library pointing to the source Node.cpp file
add_library(clnode_src_node STATIC ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/CLNode.cpp)

# add library pointing to the source Node.Test.cpp file
add_library(CLNode_tests OBJECT ${CMAKE_CURRENT_SOURCE_DIR}/CLNode.Test.cpp)

# target the Catch2 files, point them to the test file
target_link_libraries(CLNode_tests PRIVATE Catch2::Catch2)

# target the source library to the test library
target_link_libraries(CLNode_tests PRIVATE clnode_src_node)
