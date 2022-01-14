cmake_minimum_required(VERSION 3.15)
project(
    WorkdayCalender-Libray
    VERSION 1.0
    DESCRIPTION "Library that increments date and time in working days for a given date and time."
    LANGUAGES CXX)

### Get dependencies ###
include(FetchContent)

# Unit test lib
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

include(CTest)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(examples)