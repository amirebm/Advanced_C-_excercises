#include "lib/AtomicMultiMap.hpp"
#include <cassert>
#include <new>
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
namespace hashtable {
//---------------------------------------------------------------------------
AtomicMultiMap::Node::Node(value_type value)
    : value(move(value))
// Constructor
{
}

AtomicMultiMap::Iterator::Iterator(Node** bucket, Node** end, Node* node)
    : bucket(bucket),
      end(end),
      node(node)
// Constructor
{
    advance();
}
//---------------------------------------------------------------------------
void AtomicMultiMap::Iterator::advance()
// Advance to the next entry
{
    while (!node && (bucket != end)) {
        ++bucket;
        node = (bucket == end) ? nullptr : *bucket;
    }
}
//---------------------------------------------------------------------------
AtomicMultiMap::Iterator::reference AtomicMultiMap::Iterator::operator*()
// Dereference
{
    assert(bucket != end);
    return node->value;
}
//---------------------------------------------------------------------------
AtomicMultiMap::Iterator::pointer AtomicMultiMap::Iterator::operator->()
// Pointer to member
{
    assert(bucket != end);
    return &node->value;
}
//---------------------------------------------------------------------------
AtomicMultiMap::Iterator& AtomicMultiMap::Iterator::operator++()
// Pre-increment
{
    assert(bucket != end);
    node = node->next;

    advance();

    return *this;
}
//---------------------------------------------------------------------------
AtomicMultiMap::Iterator AtomicMultiMap::Iterator::operator++(int)
// Post-increment
{
    assert(bucket != end);

    Iterator it(*this);
    operator++();
    return it;
}
//---------------------------------------------------------------------------
bool AtomicMultiMap::Iterator::operator==(const Iterator& other) const
// Equality comparison
{
    return (bucket == other.bucket) && (end == other.end) && (node == other.node);
}

AtomicMultiMap::AtomicMultiMap(uint32_t bucketCount)
    : hashTable(bucketCount), mutexes(bucketCount) {
}
//---------------------------------------------------------------------------
AtomicMultiMap::~AtomicMultiMap()
// Destructor
{
    for (auto* node : hashTable) {
        while (node) {
            auto* next = node->next;
            node->~Node();
            nodeAllocator.deallocate(node, 1);
            node = next;
        }
    }
}
//---------------------------------------------------------------------------
AtomicMultiMap::Iterator AtomicMultiMap::insert(value_type value) {
    auto hash = value.first;
    auto slot = hash % hashTable.size();

    std::lock_guard<std::mutex> lock(mutexes[slot]); // Lock the bucket

    auto* node = new (nodeAllocator.allocate(1)) Node(move(value));

    node->next = hashTable[slot];
    hashTable[slot] = node;

    return {&hashTable[slot], &hashTable[hashTable.size()], node};
}

AtomicMultiMap::Iterator AtomicMultiMap::findFirst(uint32_t key) {
   // Find the first value with the specified key
     
    auto hash = key;
    auto slot = hash % hashTable.size();

    std::lock_guard<std::mutex> lock(mutexes[slot]); // Lock the bucket

    auto* node = hashTable[slot];

    while (node && (node->value.first != key))
        node = node->next;

    return node ? Iterator{&hashTable[slot], &hashTable[hashTable.size()], node} : end();
}

AtomicMultiMap::Iterator AtomicMultiMap::findNext(Iterator& it) {
    // Find the next value with the specified key

    assert(it != end());

    auto key = it.node->value.first;
    auto* node = it.node->next;

    while (node && (node->value.first != key))
        node = node->next;

    return node ? Iterator(it.bucket, it.end, node) : end();
}

AtomicMultiMap::Iterator AtomicMultiMap::begin() {
    // Return an iterator pointing to the first element

    return {&hashTable[0], &hashTable[hashTable.size()], hashTable[0]};
}

AtomicMultiMap::Iterator AtomicMultiMap::end() {
    // Return an iterator pointing to the first element

    return {&hashTable[hashTable.size()], &hashTable[hashTable.size()], nullptr};
}
//---------------------------------------------------------------------------
} // namespace hashtable
//---------------------------------------------------------------------------