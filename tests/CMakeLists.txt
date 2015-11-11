cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_LIST_DIR}/CMakeModules")

# Set options for this project
set (PROJECT_NAME "faxparser_tests" CXX)
project(${PROJECT_NAME})

message(STATUS "============================")
message(STATUS "Project: ${PROJECT_NAME}")
message(STATUS "============================")

set (PROJECT_SOURCE_DECLARATION_DIRECTORY ${PROJECT_SOURCE_DIR})
set (PROJECT_SOURCE_DEFINITION_DIRECTORY ${PROJECT_SOURCE_DIR})

add_definitions(-std=c++11)

enable_testing()

set(Boost_USE_STATIC_LIBS ON)

# Load settings for the external project "Boost".
# The components "system" and "filesystem" from "Boost" version 1.55.0 or
# greater are required.
find_package( Boost 1.55.0 REQUIRED COMPONENTS regex date_time unit_test_framework )
if (Boost_FOUND)
    # From the offical documentation:
    # Add include directories to the build. [...] If the SYSTEM option is given,
    # the compiler will be told the directories are meant as system include
    # directories on some platforms (signalling this setting might achieve effects
    # such as the compiler skipping warnings [...])."
    include_directories (SYSTEM ${Boost_INCLUDE_DIR})
    
    # From the offical documentation:
    # "Specify directories in which the linker will look for libraries. [...] Note
    # that this command is rarely necessary. Library locations returned by
    # find_package() and find_library() are absolute paths. Pass these absolute
    # library file paths directly to the target_link_libraries() command. CMake
    # will ensure the linker finds them."
    link_directories (${Boost_LIBRARY_DIRS})

    message(STATUS "Boost libs: ${Boost_LIBRARIES}")
endif ()

#include(BoostTestHelpers)
#add_boost_test(ParserUtilityTest.cpp ${PROJECT_NAME})

add_test(unit_1 ${PROJECT_NAME})

#aux_source_directory(${CMAKE_CURRENT_LIST_DIR} SRC_TEST_FILES) # find all source files in ./
#message(STATUS "Source files: ${SRC_TEST_FILES}")

#add_executable(${PROJECT_NAME} ${SRC_TEST_FILES}) 
add_executable(${PROJECT_NAME} TestRunner.cpp ParserUtilityTest.cpp PropertyLocationTest.cpp OperationKeywordsTest.cpp IlsAnsbachTest.cpp) 

target_link_libraries(${PROJECT_NAME} faxparser ${Boost_LIBRARIES})

#install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
