#include "lib/BinaryHeap.hpp"
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
namespace binary_heap {
std::vector<int> heap;

void heapify_down(std::vector<unsigned>& heap, unsigned index) {
    unsigned size = heap.size();

    while (true) {
        unsigned left_child = 2 * index + 1;
        unsigned right_child = 2 * index + 2;
        unsigned largest = index;

        if (left_child < size && heap[left_child] > heap[largest]) {
            largest = left_child;
        }

        if (right_child < size && heap[right_child] > heap[largest]) {
            largest = right_child;
        }

        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            index = largest;
        } else {
            break;
        }
    }
}

void heapify_up(std::vector<unsigned>& heap, unsigned index) {
    while (index > 0 && heap[index] > heap[(index - 1) / 2]) {
        std::swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}
void insert(std::vector<unsigned>& heap, unsigned value) {
    heap.push_back(value);
    heapify_up(heap, heap.size() - 1);
}
unsigned extract(std::vector<unsigned>& heap) {
    assert(!heap.empty() && "empty heap");

    unsigned root = heap.front();
    std::swap(heap.front(), heap.back());
    heap.pop_back();
    heapify_down(heap, 0);

    return root;
}

void printdotformatHelper(ostream& out, const vector<unsigned>& heap, unsigned index, unsigned size) {
    if (index >= size) {
        return;
    }

    unsigned left_child = 2 * index + 1;
    unsigned right_child = 2 * index + 2;

    if (left_child < size) {
        out << "\t" << index << " -> " << left_child << ";\n";
        printdotformatHelper(out, heap, left_child, size);
    }
    if (right_child < size) {
        out << "\t" << index << " -> " << right_child << ";\n";
        printdotformatHelper(out, heap, right_child, size);
    }
}

void printDot(ostream& out, const vector<unsigned>& heap) {
    out << "digraph {\n";

    for (unsigned i = 0; i < heap.size(); ++i) {
        out << "\t" << i << " [label=\"" << heap[i] << "\"];\n";
    }

    printdotformatHelper(out, heap, 0, heap.size());

    out << "}\n";
}

} 

// namespace binary_heap
//---------------------------------------------------------------------------
