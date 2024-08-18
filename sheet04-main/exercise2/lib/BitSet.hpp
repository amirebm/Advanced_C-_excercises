// Prevent multiple inclusion of the header file
#ifndef H_lib_BitSet
#define H_lib_BitSet

// Include necessary libraries
#include <algorithm>
#include <cstddef>
#include <iterator>
#include <vector>

// Declare the namespace for the bitset implementation
namespace bitset {

// Declare the BitSet class
class BitSet {
    public:
    // Constructors
    BitSet(); // Default constructor
    explicit BitSet(size_t size); // Constructor with a specified size

    // Member functions

    // Return the total number of elements in the bitset.
    size_t size() const;

    // Return the number of true elements in the bitset.
    size_t cardinality() const;

    // Insert an element at the end of the bitset.
    void push_back(bool value);

    // Const overloads

    // Access the first element.
    bool front() const;

    // Access the last element.
    bool back() const;

    // Subscript: Access a specific element.
    bool operator[](size_t index) const;

    // Non-const overloads

    // Declare the BitReference class for non-const operations
    class BitReference {
        public:
        // Constructor for BitReference class
        BitReference(std::vector<bool>::reference bitRef);

        // Conversion to bool for BitReference
        operator bool() const;

        // Assignment operator for BitReference
        BitReference& operator=(bool value);

        // Assignment operator for BitReference
        BitReference& operator=(const BitReference& other);

        private:
        std::vector<bool>::reference bitReference;
    };

    // Access the first element with write permission.
    BitReference front();

    // Access the last element with write permission.
    BitReference back();

    // Subscript: Access a specific element with write permission.
    BitReference operator[](size_t index);

    // Iterator for BitSet
    using BitIterator = typename std::vector<bool>::iterator;

    // Const Iterator for BitSet
    using ConstBitIterator = typename std::vector<bool>::const_iterator;

    // Functions to get iterators
    BitIterator begin();
    BitIterator end();
    ConstBitIterator begin() const;
    ConstBitIterator end() const;

    private:
    std::vector<bool> data; // Vector to store bits
};

} // namespace bitset

#endif // H_lib_BitSet
