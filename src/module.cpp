/** 
 * Simple arithmetic operations implemented in C++ and exposed to Python using pybind11.
 * This module includes functions for addition, subtraction, multiplication, and division.
 * It also handles division by zero by throwing an exception.
 */
#include <pybind11/pybind11.h>

/**
 * Addition operation
 */
template <typename T>
T add(T a, T b) {
    return a + b;
}
/**
 * Subtraction operation
 */
template <typename T>
T subtract(T a, T b) {
    return a - b;
}
/**
 * Multiplication operation
 */
template <typename T>
T multiply(T a, T b) {
    return a * b;
}   
/**
 * Divide operation
 */
template <typename T>
T divide(T a, T b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return a / b;
}

/**
 * Module definition to use in Python
 */
PYBIND11_MODULE(module, m) {
    m.doc() = "A module that provides basic arithmetic operations";
    m.def("add", &add<int>, "A function that adds two integers");
    m.def("add", &add<double>, "A function that adds two doubles");
    m.def("subtract", &subtract<int>, "A function that subtracts two integers");
    m.def("subtract", &subtract<double>, "A function that subtracts two doubles");
    m.def("multiply", &multiply<int>, "A function that multiplies two integers");
    m.def("multiply", &multiply<double>, "A function that multiplies two doubles");
    m.def("divide", &divide<int>, "A function that divides two integers");
    m.def("divide", &divide<double>, "A function that divides two doubles");            
}