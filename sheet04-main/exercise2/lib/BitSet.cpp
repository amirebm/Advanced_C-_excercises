// Include the corresponding header file
#include "lib/BitSet.hpp"

// Include necessary libraries
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstddef>

// Define the namespace for the bitset implementation
namespace bitset {

// Default constructor of bitset without any value
BitSet::BitSet() = default;

// BitSet Constructor with a specified size
BitSet::BitSet(size_t size) : data(size, false) {}

// this function returns the total number of elements in the bitset
size_t BitSet::size() const {
    return data.size();
}

//this function returns the number of true elements in the bitset
size_t BitSet::cardinality() const {
    return std::count(data.begin(), data.end(), true);
}

//this function inserts an element at the end of the bitset
void BitSet::push_back(bool value) {
    data.push_back(value);
}

//this function gives access the first element
bool BitSet::front() const {
    assert(!data.empty());
    return data.front();
}

// this function gives access the last element
bool BitSet::back() const {
    assert(!data.empty());
    return data.back();
}

// Subscript: this function gives access a specific element
bool BitSet::operator[](size_t index) const {
    assert(index < size());
    return data[index];
}

// this is a constructor for BitReference class
BitSet::BitReference::BitReference(std::vector<bool>::reference bitRef)
    : bitReference(bitRef) {}

// this function gives access the first element with write permission
BitSet::BitReference BitSet::front() {
    assert(!data.empty());
    return BitReference(data.front());
}

// this function gives access the last element with write permission
BitSet::BitReference BitSet::back() {
    assert(!data.empty());
    return BitReference(data.back());
}

// Subscript: this function gives access a specific element with write permission
BitSet::BitReference BitSet::operator[](size_t index) {
    assert(index < size());
    return BitReference(data[index]);
}

// by this functions we can have a conversion to bool for BitReference
BitSet::BitReference::operator bool() const {
    return bitReference;
}

// Assignment operator for BitReference
BitSet::BitReference& BitSet::BitReference::operator=(bool value) {
    bitReference = value;
    return *this;
}

// Assignment operator for BitReference
BitSet::BitReference& BitSet::BitReference::operator=(const BitReference& other) {
    return *this = static_cast<bool>(other);
}

// Functions to get iterators

//Returns an iterator pointing to the beginning of the bitset.
BitSet::BitIterator BitSet::begin() {
    return data.begin();
}

// Returns an iterator pointing one past the last element of the bitset.
BitSet::BitIterator BitSet::end() {
    return data.end();
}

//Returns a constant iterator pointing to the beginning of the bitset.
BitSet::ConstBitIterator BitSet::begin() const {
    return data.begin();
}
//Returns a constant iterator pointing one past the last element of the bitset.
BitSet::ConstBitIterator BitSet::end() const {
    return data.end();
}

} // namespace bitset
