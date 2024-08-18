#include "lib/ObjectRepresentation.hpp"
#include <cstring>
#include <iostream>
//---------------------------------------------------------------------------
using namespace std;

//---------------------------------------------------------------------------
namespace object_representation {
//---------------------------------------------------------------------------
void printBinaryHelper(uint64_t representation, int startBit, int endBit) {
    for (int i = startBit; i >= endBit; --i) {
        cout << ((representation >> i) & 1);
    }
    cout << endl;
}

void printBinary(float value) {
    uint32_t representation;
    memcpy(&representation, &value, sizeof(float));

    cout << "sign: " << ((representation >> 31) & 1) << endl;
    cout << "exponent: ";
    printBinaryHelper(representation, 30, 23);
    cout << "mantissa: ";
    printBinaryHelper(representation, 22, 0);
}

void printBinary(double value) {
    uint64_t representation;
    memcpy(&representation, &value, sizeof(double));

    cout << "sign: " << ((representation >> 63) & 1) << endl;
    cout << "exponent: ";
    printBinaryHelper(representation, 62, 52);
    cout << "mantissa: ";
    printBinaryHelper(representation, 51, 0);
}

void push(std::vector<unsigned char>& stack, float value) {
    uint32_t representation;
    std::memcpy(&representation, &value, sizeof(float));

    const unsigned char* begin = reinterpret_cast<const unsigned char*>(&representation);
    const unsigned char* end = begin + sizeof(float);

    stack.insert(stack.end(), begin, end);
    stack.push_back(sizeof(float));
}

void push(std::vector<unsigned char>& stack, double value) {
    uint64_t representation;
    std::memcpy(&representation, &value, sizeof(double));

    const unsigned char* begin = reinterpret_cast<const unsigned char*>(&representation);
    const unsigned char* end = begin + sizeof(double);

    stack.insert(stack.end(), begin, end);
    stack.push_back(sizeof(double));
}

bool pop(std::vector<unsigned char>& stack, float& value) {
    if (stack.size() < sizeof(float) || stack.back() != sizeof(float)) {
        return false;
    }

    stack.pop_back();

    uint32_t representation;
    std::memcpy(&representation, &stack[stack.size() - sizeof(float)], sizeof(float));
    stack.resize(stack.size() - sizeof(float));

    std::memcpy(&value, &representation, sizeof(float));

    return true;
}

bool pop(std::vector<unsigned char>& stack, double& value) {
    if (stack.size() < sizeof(double) || stack.back() != sizeof(double)) {
        return false;
    }

    stack.pop_back();

    uint64_t representation;
    std::memcpy(&representation, &stack[stack.size() - sizeof(double)], sizeof(double));
    stack.resize(stack.size() - sizeof(double));

    std::memcpy(&value, &representation, sizeof(double));

    return true;
}
//---------------------------------------------------------------------------
} // namespace object_representation
//---------------------------------------------------------------------------
