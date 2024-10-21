cmake_minimum_required(VERSION 3.5.0)
project(conicFiltring VERSION 0.1.0 LANGUAGES C CXX)


# include Eigen
find_package(Eigen3 REQUIRED)
if(${EIGEN3_FOUND})
    message(STATUS "lib EIGEN3 found")
    message(STATUS "  version " ${EIGEN3_VERSION_STRING})
    message(STATUS "  include " ${EIGEN3_INCLUDE_DIR})
else()
    message(FATAL_ERROR "lib EIGEN3 not found")
endif()

add_executable(conicFiltring src/main.cpp)


# lib include path
target_include_directories(conicFiltring PRIVATE "${EIGEN3_INCLUDE_DIR}")
