cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

# Set options for this project
set (PROJECT_NAME "tests" CXX)
project(${PROJECT_NAME})

message(STATUS "============================")
message(STATUS "Project: ${PROJECT_NAME}")
message(STATUS "============================")

set (PROJECT_SOURCE_DECLARATION_DIRECTORY ${PROJECT_SOURCE_DIR})
set (PROJECT_SOURCE_DEFINITION_DIRECTORY ${PROJECT_SOURCE_DIR})

add_definitions(-std=c++11)

find_package( UnitTest++ REQUIRED )
if(UNITTEST++_FOUND)
    add_library(UnitTest++ STATIC IMPORTED)
    include_directories (SYSTEM ${UNITTEST++_INCLUDE_DIR})
    link_directories (${UNITTEST++_LIBRARY})
endif()

#add_test(ParseFile faxparser)


#include_directories(${PROJECT_SOURCE_DECLARATION_DIRECTORY} /usr/include/unittest++)
#set(LIBS ${LIBS} ${UNITTEST++_LIBRARIES})

aux_source_directory(. SRC_TEST_FILES)

add_executable(${PROJECT_NAME} ${SRC_TEST_FILES}) # find all source files in ./
message(STATUS "Source files: ${SRC_TEST_FILES}")



#target_link_libraries(${PROJECT_NAME} UnitTest++)

#install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
