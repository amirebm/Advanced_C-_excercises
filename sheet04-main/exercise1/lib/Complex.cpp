// Include the header file for our Complex class
#include "Complex.hpp"

namespace arithmetic {

// Constructors used for complex class
Complex::Complex() : real_numbers(0.0), imag_numbers(0.0) {}
Complex::Complex(double real) : real_numbers(real), imag_numbers(0.0) {}
Complex::Complex(double real, double imag) : real_numbers(real), imag_numbers(imag) {}

// Member functions of our complex class
double Complex::real() const {
    return real_numbers;
}

double Complex::imag() const {
    return imag_numbers;
}

double Complex::abs() const {
    // this function calculates the absolute value of the complex number
    return std::sqrt(real_numbers * real_numbers + imag_numbers * imag_numbers);
}

double Complex::norm() const {
    // this function calculates the squared norm of the complex number
    return real_numbers * real_numbers + imag_numbers * imag_numbers;
}

double Complex::arg() const {
    // this function calculates the phase angle (argument) of the complex number
    return std::atan2(imag_numbers, real_numbers);
}

Complex Complex::conj() const {
    // // this function calculates the conjugate of the complex number
    return Complex(real_numbers, -imag_numbers);
}

// Operators
Complex Complex::operator-() const {
    // Unary negation operator
    return Complex(-real_numbers, -imag_numbers);
}

Complex Complex::operator+() const {
    // Unary plus operator (identity)
    return Complex(real_numbers, imag_numbers);
}

Complex Complex::operator-(const Complex& other_value) const {
    // this function subtracts two complex numbers
    return Complex(real_numbers - other_value.real_numbers, imag_numbers - other_value.imag_numbers);
}

Complex Complex::operator+(const Complex& other_value) const {
    // this function adds two complex numbers
    return Complex(real_numbers + other_value.real_numbers, imag_numbers + other_value.imag_numbers);
}

Complex Complex::operator*(const Complex& other_value) const {
    // this function multiplies two complex numbers
    return Complex(real_numbers * other_value.real_numbers - imag_numbers * other_value.imag_numbers,
                   real_numbers * other_value.imag_numbers + imag_numbers * other_value.real_numbers);
}

Complex Complex::operator/(const Complex& other_value) const {
    // this function calculates divides two complex numbers
    double denominator = other_value.real_numbers * other_value.real_numbers + other_value.imag_numbers * other_value.imag_numbers;
    return Complex((real_numbers * other_value.real_numbers + imag_numbers * other_value.imag_numbers) / denominator,
                   (imag_numbers * other_value.real_numbers - real_numbers * other_value.imag_numbers) / denominator);
}

bool Complex::operator==(const Complex& other_value) const {
    // this function checks if two complex numbers are equal
    return real_numbers == other_value.real_numbers && imag_numbers == other_value.imag_numbers;
}

bool Complex::operator!=(const Complex& other_value) const {
    //// this function checks if two complex numbers are not equal
    return !(*this == other_value);
}

} // namespace arithmetic
