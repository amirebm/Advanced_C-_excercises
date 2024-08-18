// Include the header file for the our Rational class
#include "lib/Rational.hpp"
#include <compare>
#include <numeric>

namespace arithmetic {

// constructors used for our rational class
Rational::Rational() : numerator_numbers(0), denominator_numbers(1) {}

Rational::Rational(long long value) : numerator_numbers(value), denominator_numbers(1) {}

Rational::Rational(long long numerator, long long denominator)
    : numerator_numbers(numerator), denominator_numbers(denominator) {
    // this function reduces the rational number to its smplest form
    reduce();
}

// Member functions
long long Rational::num() const {
    //// this function returns the numerator of the rational number
    return numerator_numbers;
}

long long Rational::den() const {
    //// this function returns the denominator of the rational number
    return denominator_numbers;
}

Rational Rational::inv() const {
    //// this function returns the inverse of the rational number
    return Rational(denominator_numbers, numerator_numbers);
}

// Operators
Rational Rational::operator-() const {
    // Unary negation operator
    return Rational(-numerator_numbers, denominator_numbers);
}

Rational Rational::operator+(const Rational& other_value) const {
    // Addition operator
    return Rational(numerator_numbers * other_value.denominator_numbers + other_value.numerator_numbers * denominator_numbers,
                    denominator_numbers * other_value.denominator_numbers);
}

Rational Rational::operator+() const {
    // Unary plus operator (identity)
    return *this;
}

Rational Rational::operator-(const Rational& other_value) const {
    // Subtraction operator
    return Rational(numerator_numbers * other_value.denominator_numbers - other_value.numerator_numbers * denominator_numbers,
                    denominator_numbers * other_value.denominator_numbers);
}

Rational Rational::operator*(const Rational& other_value) const {
    // Multiplication operator
    return Rational(numerator_numbers * other_value.numerator_numbers, denominator_numbers * other_value.denominator_numbers);
}

Rational Rational::operator/(const Rational& other_value) const {
    // Division operator
    return Rational(numerator_numbers * other_value.denominator_numbers, denominator_numbers * other_value.numerator_numbers);
}

bool Rational::operator!=(const Rational& other_value) const {
    // Inequality operator
    return !(*this == other_value);
}

bool Rational::operator>=(const Rational& other_value) const {
    // Greater than or equal to operator
    return numerator_numbers * other_value.denominator_numbers >= other_value.numerator_numbers * denominator_numbers;
}

bool Rational::operator<=(const Rational& other_value) const {
    // Less than or equal to operator
    return numerator_numbers * other_value.denominator_numbers <= other_value.numerator_numbers * denominator_numbers;
}

bool Rational::operator>(const Rational& other_value) const {
    // Greater than operator
    return numerator_numbers * other_value.denominator_numbers > other_value.numerator_numbers * denominator_numbers;
}

bool Rational::operator==(const Rational& other_value) const {
    // Equality operator
    return numerator_numbers == other_value.numerator_numbers && denominator_numbers == other_value.denominator_numbers;
}

bool Rational::operator<(const Rational& other_value) const {
    // Less than operator
    return numerator_numbers * other_value.denominator_numbers < other_value.numerator_numbers * denominator_numbers;
}

std::strong_ordering Rational::operator<=>(const Rational& other_value) const {
    // Three-way comparison operator
    if (*this < other_value) return std::strong_ordering::less;
    if (*this > other_value) return std::strong_ordering::greater;
    return std::strong_ordering::equal;
}

Rational::operator double() const {
    // Conversion to double operator
    return static_cast<double>(numerator_numbers) / static_cast<double>(denominator_numbers);
}

// Private functions
long long Rational::gcd(long long a, long long b) {
    // this function calculates the greatest common divisor using Euclid's algorithm
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void Rational::reduce() {
    // this function reduces the rational number to its simplest form
    long long common = gcd(numerator_numbers, denominator_numbers);
    numerator_numbers /= common;
    denominator_numbers /= common;
}

} // namespace arithmetic
