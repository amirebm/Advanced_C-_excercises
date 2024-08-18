// Header guard to prevent multiple inclusion
#ifndef H_lib_Complex
#define H_lib_Complex

// Include necessary libraries
#include <cmath>

// Use the arithmetic namespace
namespace arithmetic {

// Declaration of the Complex class
class Complex {
    public:
    // Constructors
    Complex();
    Complex(double real);
    Complex(double real, double imag);

    // Member functions
    double real() const;
    double imag() const;
    double abs() const;
    double norm() const;
    double arg() const;
    Complex conj() const;

    // Operators
    Complex operator-() const;
    Complex operator+() const;
    Complex operator-(const Complex& other_value) const;
    Complex operator+(const Complex& other_value) const;
    Complex operator*(const Complex& other_value) const;
    Complex operator/(const Complex& other_value) const;
    bool operator==(const Complex& other_value) const;
    bool operator!=(const Complex& other_value) const;

    private:
    // Private data members
    double real_numbers;
    double imag_numbers;
};

} // namespace arithmetic

// End of the header guard
#endif
