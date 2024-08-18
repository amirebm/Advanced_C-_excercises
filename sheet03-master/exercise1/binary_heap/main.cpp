#include "lib/BinaryHeap.hpp"
#include <fstream>
#include <iostream>
//---------------------------------------------------------------------------
using namespace std;
using namespace binary_heap;
//---------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "USAGE: " << argv[0] << " file" << endl;
        return 1;
    }

    ofstream out(argv[1]);
    vector<unsigned> heap;

    // Example usage
    insert(heap, 35);
    insert(heap, 33);
    insert(heap, 42);
    insert(heap, 10);
    insert(heap, 14);
    insert(heap, 19);
    insert(heap, 27);
    insert(heap, 44);
    insert(heap, 26);
    insert(heap, 31);

    //unsigned extractsedValue = extract(heap);

    printDot(out, heap);

    return 0;
}

//---------------------------------------------------------------------------
