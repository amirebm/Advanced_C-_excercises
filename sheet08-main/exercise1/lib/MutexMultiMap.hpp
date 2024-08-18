#ifndef H_lib_MutexMultiMap
#define H_lib_MutexMultiMap
//---------------------------------------------------------------------------
#include <cstdint>
#include <mutex>
#include <utility>
#include <vector>

//---------------------------------------------------------------------------
namespace hashtable {
//---------------------------------------------------------------------------
class MutexMultiMap {
    public:
    using value_type = std::pair<uint32_t, uint32_t>;

    private:
    struct Node {
        value_type value = {};
        Node* next = nullptr;

        Node() = default;
        explicit Node(value_type value);
    };

    std::vector<Node*> hashTable;
    std::allocator<Node> nodeAllocator;
    std::vector<std::mutex> mutexes; // Added mutexes for each bucket

    public:
    class Iterator {
        private:
        Node** bucket;
        Node** end;
        Node* node;
        void advance();

        friend class MutexMultiMap;

        Iterator(Node** bucket, Node** end, Node* node);

        public:
        using difference_type = std::ptrdiff_t;
        using value_type = MutexMultiMap::value_type;
        using pointer = value_type*;
        using reference = value_type&;
        using iterator_category = std::forward_iterator_tag;

        reference operator*();
        pointer operator->();
        Iterator& operator++();
        Iterator operator++(int);
        bool operator==(const Iterator& other) const;
    };

    explicit MutexMultiMap(uint32_t bucketCount);
    ~MutexMultiMap();

    Iterator insert(value_type value);
    Iterator findFirst(uint32_t key);
    Iterator findNext(Iterator& it);
    Iterator begin();
    Iterator end();
};
//---------------------------------------------------------------------------
} // namespace hashtable
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------