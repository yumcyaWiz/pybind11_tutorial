cmake_minimum_required(VERSION 3.12)
project(pybind11_tutorial LANGUAGES C CXX)

# default build type
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to Release as none was specified.")
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build." FORCE)
endif()

# ext
add_subdirectory(ext/pybind11)

# MyLib
add_library(MyLib)
# needed for pybind11 binding
set_target_properties(MyLib PROPERTIES POSITION_INDEPENDENT_CODE ON)

# compile settings
target_compile_features(MyLib PUBLIC cxx_std_17)
set_target_properties(MyLib PROPERTIES CXX_STANDARD_REQUIRED ON)
set_target_properties(MyLib PROPERTIES CXX_EXTENSIONS OFF)

# src
target_include_directories(MyLib PUBLIC src)
target_sources(MyLib PRIVATE src/mylib.cpp)

# pybind11
pybind11_add_module(binding python/binding.cpp)
set_target_properties(binding PROPERTIES OUTPUT_NAME "MyLib")
target_include_directories(binding PRIVATE MyLib)
target_link_libraries(binding PRIVATE MyLib)
