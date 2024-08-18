
#include "lib/ChainingHashTable.hpp"
#include "GenericValue.hpp"
#include <algorithm> // For std::max
#include <cassert>
#include <cmath> // For std::ceil

//---------------------------------------------------------------------------
namespace hashtable {
//---------------------------------------------------------------------------

// Constructor for ChainingHashTable, initializes with 16 buckets
ChainingHashTable::ChainingHashTable() : buckets(16) {}

// Returns the total number of entries in the hash table
size_t ChainingHashTable::size() const {
    return entries.size();
}

// Checks if the given key is present in the hash table
bool ChainingHashTable::contains(int64_t key) const {
    size_t index = hashFunction(key) % buckets.size();
    auto& chain = buckets[index];

    // Iterate through the chain at the calculated index
    for (const auto& entry : chain) {
        if (entry.key == key) {
            return true;
        }
    }
    return false;
}

// Overloaded operator[] to allow access and modification of values using keys
GenericValue& ChainingHashTable::operator[](int64_t key) {
    size_t index = hashFunction(key) % buckets.size();
    auto& chain = buckets[index];

    // Search for the key in the chain
    for (auto& entry : chain) {
        if (entry.key == key) {
            return entry.value;
        }
    }

    // If the key is not found, insert a new entry at the beginning of the chain
    Entry newEntry{key, GenericValue()};
    chain.push_front(std::move(newEntry));
    entries.push_back(&chain.front());

    // Check if rehashing is needed to maintain load factor below 0.5
    if (static_cast<double>(entries.size()) / buckets.size() > 0.5) {
        auto itInEntries = entries.begin();
        rehash();
        // Recalculate the index after rehashing
        index = hashFunction(key) % buckets.size();

        // Find the new iterator for the entry in the updated buckets
        while (itInEntries != entries.end() && **itInEntries != newEntry) {
            ++itInEntries;
        }
    }

    return chain.front().value;
}

// Overloaded function to insert a key-value pair into the hash table
GenericValue& ChainingHashTable::insert(int64_t key, GenericValue&& value) {
    size_t index = hashFunction(key) % buckets.size();
    auto& chain = buckets[index];

    // Search for the key in the chain and update the value if found
    for (auto& entry : chain) {
        if (entry.key == key) {
            entry.value = std::move(value);
            return entry.value;
        }
    }

    // If the key is not found, insert a new entry at the beginning of the chain
    Entry newEntry{key, std::move(value)};
    chain.push_front(std::move(newEntry));
    entries.push_back(&chain.front());

    // Check if rehashing is needed to maintain load factor below 0.5
    if (static_cast<double>(entries.size()) / buckets.size() > 0.5) {
        auto itInEntries = entries.begin();
        rehash();
        // Recalculate the index after rehashing
        index = hashFunction(key) % buckets.size();

        // Find the new iterator for the entry in the updated buckets
        while (itInEntries != entries.end() && **itInEntries != newEntry) {
            ++itInEntries;
        }

        if (itInEntries != entries.end()) {
            return (*itInEntries)->value;
        }
    }

    return chain.front().value;
}

// Overloaded function to insert an Entry into the hash table
GenericValue& ChainingHashTable::insert(Entry entry) {
    size_t index = hashFunction(entry.key) % buckets.size();
    auto& chain = buckets[index];

    // Search for the key in the chain and update the value if found
    for (auto& existingEntry : chain) {
        if (existingEntry.key == entry.key) {
            existingEntry.value = std::move(entry.value);
            return existingEntry.value;
        }
    }

    // If the key is not found, insert a new entry at the beginning of the chain
    chain.push_front(std::move(entry));
    entries.push_back(&chain.front());

    // Check if rehashing is needed to maintain load factor below 0.5
    if (static_cast<double>(entries.size()) / buckets.size() > 0.5) {
        rehash();
        // Recalculate the index after rehashing
        index = hashFunction(entry.key) % buckets.size();
    }

    return chain.front().value;
}

// Removes an entry with the specified key from the hash table
void ChainingHashTable::erase(int64_t key) {
    size_t index = hashFunction(key) % buckets.size();
    auto& chain = buckets[index];

    // Find the entry in the chain using a lambda function
    auto entryIter = std::find_if(chain.begin(), chain.end(),
                                  [key](const Entry& entry) { return entry.key == key; });

    // If the entry is found, remove it from both the chain and the entries list
    if (entryIter != chain.end()) {
        entries.remove(&(*entryIter));
        chain.erase(entryIter);
    }
}

// Returns an iterator pointing to the beginning of the hash table
ChainingHashTable::iterator ChainingHashTable::begin() {
    return iterator(entries.begin());
}

// Returns an iterator pointing to the end of the hash table
ChainingHashTable::iterator ChainingHashTable::end() {
    return iterator(entries.end());
}

// Finds an entry with the specified key and returns an iterator to it
ChainingHashTable::iterator ChainingHashTable::find(int64_t key) {
    size_t index = hashFunction(key) % buckets.size();
    auto& chain = buckets[index];

    // Find the entry in the chain using a lambda function
    auto entryIter = std::find_if(chain.begin(), chain.end(),
                                  [key](const Entry& entry) { return entry.key == key; });

    // If the entry is found, find its iterator in the entries list
    if (entryIter != chain.end()) {
        auto itInEntries = std::find(entries.begin(), entries.end(), &(*entryIter));
        return iterator(itInEntries);
    } else {
        // If the entry is not found, return an iterator pointing to the end
        return iterator(entries.end());
    }
}

// Rehashes the hash table to maintain load factor below 0.5
void ChainingHashTable::rehash() {
    size_t newBucketSize = buckets.size() * 2;
    std::vector<std::list<Entry>> newBuckets(newBucketSize);

    // Move entries to new buckets
    for (auto& entry : entries) {
        size_t newIndex = hashFunction(entry->key) % newBucketSize;
        newBuckets[newIndex].push_front(std::move(*entry));
    }

    // Replace the old buckets with the new ones
    buckets = std::move(newBuckets);

    // Update the entries list after rehashing
    entries.clear();
    for (auto& bucket : buckets) {
        for (auto& entry : bucket) {
            entries.push_back(&entry);
        }
    }
}

// Hash function using the identity function
size_t ChainingHashTable::hashFunction(int64_t key) const {
    // Using the identity function as the hash function
    return static_cast<size_t>(key);
}

//---------------------------------------------------------------------------
} // namespace hashtable
//---------------------------------------------------------------------------
