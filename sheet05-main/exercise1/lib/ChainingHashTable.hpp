
#ifndef H_lib_ChainingHashTable
#define H_lib_ChainingHashTable

//---------------------------------------------------------------------------
#include "lib/GenericValue.hpp"
#include <iterator>
#include <list>
#include <vector>
//---------------------------------------------------------------------------

namespace hashtable {

//---------------------------------------------------------------------------
// Class representing a Chaining Hash Table
class ChainingHashTable {
public:
    // Structure to represent an entry in the hash table
    struct Entry {
        const int64_t key;        // Key of the entry
        GenericValue value;       // Value associated with the key

        // Custom comparison function for Entry
        bool operator==(const Entry& other) const {
            return key == other.key && value.getData() == other.value.getData();
        }

        // Custom not-equal-to function for Entry
        bool operator!=(const Entry& other) const {
            return !(*this == other);
        }
    };

    // Iterator class for ChainingHashTable
    class iterator {
    public:
        using value_type = Entry;
        using difference_type = std::ptrdiff_t;
        using reference = Entry&;
        using pointer = Entry*;
        using iterator_category = std::forward_iterator_tag;

        // Default constructor for iterator
        iterator() = default;

        // Pre-increment operator
        iterator& operator++() {
            ++entryIter;
            return *this;
        }

        // Post-increment operator
        iterator operator++(int) {
            iterator temp = *this;
            ++entryIter;
            return temp;
        }

        // Dereference operator to get the reference to the Entry
        reference operator*() const {
            return **entryIter;
        }

        // Arrow operator to get the pointer to the Entry
        pointer operator->() const {
            return &(**entryIter);
        }

        // Equality operator for iterators
        friend bool operator==(const iterator& lhs, const iterator& rhs) {
            return lhs.entryIter == rhs.entryIter;
        }

        // Inequality operator for iterators
        friend bool operator!=(const iterator& lhs, const iterator& rhs) {
            return !(lhs == rhs);
        }

    private:
        // Private constructor with an iterator to a list of Entry pointers
        explicit iterator(std::list<Entry*>::iterator entryIter) : entryIter(entryIter) {}

        std::list<Entry*>::iterator entryIter;  // Iterator to a list of Entry pointers

        friend class ChainingHashTable;
    };

    // Default constructor for ChainingHashTable, initializes with 16 buckets
    ChainingHashTable();

    // Deleted copy constructor to prevent unintentional copying
    ChainingHashTable(const ChainingHashTable&) = delete;

    // Deleted copy assignment operator to prevent unintentional copying
    ChainingHashTable& operator=(const ChainingHashTable&) = delete;

    // Move constructor
    ChainingHashTable(ChainingHashTable&&) = default;

    // Move assignment operator
    ChainingHashTable& operator=(ChainingHashTable&&) = default;

    // Destructor for ChainingHashTable
    ~ChainingHashTable() = default;

    // Returns the total number of entries in the hash table
    size_t size() const;

    // Checks if the given key is present in the hash table
    bool contains(int64_t key) const;

    // Overloaded operator[] to allow access and modification of values using keys
    GenericValue& operator[](int64_t key);

    // Overloaded function to insert a key-value pair into the hash table
    GenericValue& insert(int64_t key, GenericValue&& value);

    // Overloaded function to insert an Entry into the hash table
    GenericValue& insert(Entry entry);

    // Removes an entry with the specified key from the hash table
    void erase(int64_t key);

    // Returns an iterator pointing to the beginning of the hash table
    iterator begin();

    // Returns an iterator pointing to the end of the hash table
    iterator end();

    // Finds an entry with the specified key and returns an iterator to it
    iterator find(int64_t key);

private:
    std::vector<std::list<Entry>> buckets;    // Vector of linked lists representing buckets
    std::list<Entry*> entries;                // List of Entry pointers representing all entries

    // Rehashes the hash table to maintain load factor below 0.5
    void rehash();

    // Hash function using the identity function
    size_t hashFunction(int64_t key) const;
};

//---------------------------------------------------------------------------
} // namespace hashtable
//---------------------------------------------------------------------------
#endif
