// Header guard to prevent multiple inclusion
#ifndef H_lib_Rational
#define H_lib_Rational

// Include necessary libraries
#include <compare>

// Use the arithmetic namespace
namespace arithmetic {

// Declaration of the Rational class
class Rational {
    public:
    // Constructors
    Rational();
    Rational(long long value);
    Rational(long long numerator, long long denominator);

    // Member functions
    long long num() const;
    long long den() const;
    Rational inv() const;

    // Operators
    Rational operator-() const;
    Rational operator+() const;
    Rational operator-(const Rational& other_value) const;
    Rational operator+(const Rational& other_value) const;
    Rational operator*(const Rational& other_value) const;
    Rational operator/(const Rational& other_value) const;
    bool operator==(const Rational& other_value) const;
    bool operator!=(const Rational& other_value) const;
    bool operator<(const Rational& other_value) const;
    bool operator<=(const Rational& other_value) const;
    bool operator>(const Rational& other_value) const;
    bool operator>=(const Rational& other_value) const;
    std::strong_ordering operator<=>(const Rational& other_value) const;
    explicit operator double() const;

    private:
    // Private data members
    long long gcd(long long a, long long b);
    void reduce();

    long long numerator_numbers;
    long long denominator_numbers;
};

} // namespace arithmetic

// End of the header guard
#endif
