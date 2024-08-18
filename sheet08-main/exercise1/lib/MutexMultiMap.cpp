#include "lib/MutexMultiMap.hpp"
#include <cassert>
#include <mutex>
#include <new>
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
namespace hashtable {
//---------------------------------------------------------------------------
MutexMultiMap::Node::Node(value_type value)
    : value(move(value)) {
}

MutexMultiMap::Iterator::Iterator(Node** bucket, Node** end, Node* node)
    : bucket(bucket),
      end(end),
      node(node) {
    advance();
}

void MutexMultiMap::Iterator::advance() {
    while (!node && (bucket != end)) {
        ++bucket;
        node = (bucket == end) ? nullptr : *bucket;
    }
}

MutexMultiMap::Iterator::reference MutexMultiMap::Iterator::operator*() {
    assert(bucket != end);
    return node->value;
}

MutexMultiMap::Iterator::pointer MutexMultiMap::Iterator::operator->() {
    assert(bucket != end);
    return &node->value;
}

MutexMultiMap::Iterator& MutexMultiMap::Iterator::operator++() {
    assert(bucket != end);
    node = node->next;

    advance();

    return *this;
}

MutexMultiMap::Iterator MutexMultiMap::Iterator::operator++(int) {
    assert(bucket != end);

    Iterator it(*this);
    operator++();
    return it;
}

bool MutexMultiMap::Iterator::operator==(const Iterator& other) const {
    return (bucket == other.bucket) && (end == other.end) && (node == other.node);
}

MutexMultiMap::MutexMultiMap(uint32_t bucketCount)
    : hashTable(bucketCount), mutexes(bucketCount) {
}

MutexMultiMap::~MutexMultiMap() {
    for (auto* node : hashTable) {
        while (node) {
            auto* next = node->next;
            node->~Node();
            nodeAllocator.deallocate(node, 1);
            node = next;
        }
    }
}

MutexMultiMap::Iterator MutexMultiMap::insert(value_type value) {
    auto hash = value.first;
    auto slot = hash % hashTable.size();

    std::lock_guard<std::mutex> lock(mutexes[slot]); // Lock the bucket

    auto* node = new (nodeAllocator.allocate(1)) Node(move(value));

    node->next = hashTable[slot];
    hashTable[slot] = node;

    return {&hashTable[slot], &hashTable[hashTable.size()], node};
}

MutexMultiMap::Iterator MutexMultiMap::findFirst(uint32_t key) {
    // Find the first value with the specified key

    auto hash = key;
    auto slot = hash % hashTable.size();

    std::lock_guard<std::mutex> lock(mutexes[slot]); // Lock the bucket

    auto* node = hashTable[slot];

    while (node && (node->value.first != key))
        node = node->next;

    return node ? Iterator{&hashTable[slot], &hashTable[hashTable.size()], node} : end();
}

MutexMultiMap::Iterator MutexMultiMap::findNext(Iterator& it) {
    // Find the next value with the specified key

    assert(it != end());

    auto key = it.node->value.first;
    auto* node = it.node->next;

    while (node && (node->value.first != key))
        node = node->next;

    return node ? Iterator(it.bucket, it.end, node) : end();
}

MutexMultiMap::Iterator MutexMultiMap::begin() {
    // Return an iterator pointing to the first element

    return {&hashTable[0], &hashTable[hashTable.size()], hashTable[0]};
}

MutexMultiMap::Iterator MutexMultiMap::end() {
    // Return an iterator pointing to the first element

    return {&hashTable[hashTable.size()], &hashTable[hashTable.size()], nullptr};
}

//---------------------------------------------------------------------------
} // namespace hashtable
//---------------------------------------------------------------------------
