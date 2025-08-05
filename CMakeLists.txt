cmake_minimum_required(VERSION 3.12)

project(pyCPP)

set(CMAKE_CXX_STANDARD 14)

execute_process(
    COMMAND python -m pybind11 --includes
    OUTPUT_VARIABLE PYBIND11_INCLUDES
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
string(REPLACE "-I" "" PYBIND11_INCLUDES ${PYBIND11_INCLUDES})
separate_arguments(PYBIND11_INCLUDES)

execute_process(
    COMMAND python -c "import sys; print(sys.base_prefix)"
    OUTPUT_VARIABLE PYTHON_BASE_PREFIX
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
set(PYTHON_LIB_DIR "${PYTHON_BASE_PREFIX}/libs")
message(STATUS "PYTHON_LIB_DIR: ${PYTHON_LIB_DIR}")
link_directories(${PYTHON_LIB_DIR})

add_library(module MODULE src/module.cpp)
target_include_directories(module PRIVATE ${PYBIND11_INCLUDES})
target_link_libraries(module PRIVATE python312)
set_target_properties(module PROPERTIES PREFIX "" SUFFIX ".pyd")