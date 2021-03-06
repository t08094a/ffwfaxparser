cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_LIST_DIR}/CMakeModules/")

# Set options for this project
set(PROJECT_NAME "faxparser" CXX)
project(${PROJECT_NAME})

message(STATUS "============================")
message(STATUS "Project: ${PROJECT_NAME}")
message(STATUS "============================")

# set the installation prefix to a custom one for testing purpose
if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set (CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/installed" CACHE PATH "default install path" FORCE )
    message(STATUS "Install prefix (overriden): ${CMAKE_INSTALL_PREFIX}")
endif()

set(PROJECT_SOURCE_DECLARATION_DIRECTORY ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_SOURCE_DEFINITION_DIRECTORY ${PROJECT_SOURCE_DIR}/src)

set(CMAKE_BUILD_TYPE Debug)
message( STATUS "CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE}" )

# Note: http://unlogic.co.uk/2012/08/13/cmake-and-gcov/
# lcov and gcovr must be installed
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Wall -W -Wunused-variable -Wunused-parameter -Wunused-function -Wunused -Wno-system-headers -Wno-deprecated -Woverloaded-virtual -Wwrite-strings -fprofile-arcs -ftest-coverage") # -Wshadow 
SET(CMAKE_C_FLAGS "-g -O0 -Wall -W -fprofile-arcs -ftest-coverage")
SET(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")

add_definitions(-std=c++11)

enable_testing()

# Load settings for the external project "Boost".
# The components "system" and "filesystem" from "Boost" version 1.55.0 or
# greater are required.
find_package( Boost 1.55.0 REQUIRED COMPONENTS log regex date_time )
if (Boost_FOUND)
    # From the offical documentation:
    # Add include directories to the build. [...] If the SYSTEM option is given,
    # the compiler will be told the directories are meant as system include
    # directories on some platforms (signalling this setting might achieve effects
    # such as the compiler skipping warnings [...])."
    include_directories (SYSTEM ${Boost_INCLUDE_DIR})

    message(STATUS "Boost libs: ${Boost_LIBRARIES}")
    
    # From the offical documentation:
    # "Specify directories in which the linker will look for libraries. [...] Note
    # that this command is rarely necessary. Library locations returned by
    # find_package() and find_library() are absolute paths. Pass these absolute
    # library file paths directly to the target_link_libraries() command. CMake
    # will ensure the linker finds them."
    link_directories (${Boost_LIBRARY_DIRS})
endif ()

include_directories (${PROJECT_SOURCE_DECLARATION_DIRECTORY})
include_directories(tests)

aux_source_directory(src SRC_FILES)
aux_source_directory(include HEADER_FILES)

#exe add_executable(${PROJECT_NAME} ${SRC_FILES}) # find all source files in ./src/
add_library(${PROJECT_NAME} SHARED ${SRC_FILES}) # find all source files in ./src/
message(STATUS "Source files: ${SRC_FILES}")

#exe install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(FILES ${HEADER_FILES} DESTINATION include)

add_subdirectory(tests)

target_link_libraries (${PROJECT_NAME} ${Boost_LIBRARIES})


