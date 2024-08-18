#include "simplevm/simplevm.hpp"
#include <iostream>
//---------------------------------------------------------------------------
namespace simplevm {
//---------------------------------------------------------------------------
int32_t A = 0, B = 0, C = 0, D = 0;
float X = 0.0f, Y = 0.0f;
int32_t A, X, Y;

int32_t runVM()

{
    int opcode;
    while (std::cin >> opcode) {
        switch (opcode) {
            case 0: // halt
                return A;
            case 10: // movi
                char ireg;
                int32_t iimm;   
                std::cin >> ireg >> iimm;
                switch (ireg) {
                    case 'A': A = iimm; break;
                    case 'B': B = iimm; break;
                    case 'C': C = iimm; break;
                    case 'D': D = iimm; break;
                }
                break;
            case 11: // movf
                char freg;
                float fimm;
                std::cin >> freg >> fimm;
                switch (freg) {
                    case 'X': X = fimm; break;
                    case 'Y': Y = fimm; break;
                }
                break;
            case 20: // loada
                char ireg_loada;
                std::cin >> ireg_loada;
                A = getRegisterValue(ireg_loada);
                break;
            case 21: // storea
                char ireg_storea;
                std::cin >> ireg_storea;
                setRegisterValue(ireg_storea, A);
                break;
            case 22: // swapab
                std::swap(A, B);
                break;
            case 30: // loadx
                char freg_loadx;
                std::cin >> freg_loadx;
                X = getFloatRegisterValue(freg_loadx);
                break;
            case 31: // storex
                char freg_storex;
                std::cin >> freg_storex;
                setFloatRegisterValue(freg_storex, X);
                break;
            case 32: // swapxy
                std::swap(X, Y);
                break;
            case 40: // itof
                X = static_cast<float>(A);
                break;
            case 41: // ftoi
                A = static_cast<int32_t>(X);
                break;
            case 50: // addi
                A = addWithOverflow(A, B);
                break;
            case 51: // subi
                A = subtractWithOverflow(A, B);
                break;
            case 52: // rsubi
                A = subtractWithOverflow(B, A);
                break;
            case 53: // muli
                A = multiplyWithOverflow(A, B);
                break;
            case 54: // divi
                if (B == 0) {
                    std::cout << "division by 0" << std::endl;
                    return A;
                }
                A = A / B;
                B = A % B;
                break;
            case 60: // addf
                X = X + Y;
                break;
            case 61: // subf
                X = X - Y;
                break;
            case 62: // mulf
                X = X * Y;
                break;
            case 63: // divf
                if (Y == 0.0f) {
                    std::cout << "division by 0" << std::endl;
                    return A;
                }
                X = X / Y;
                break;
            default:
                break;
        }
    }
    return A;
}
int32_t getRegisterValue(char reg) {
    switch (reg) {
        case 'A': return A;
        case 'B': return B;
        case 'C': return C;
        case 'D': return D;
        default: return 0; // Handle unknown register gracefully
    }
}

void setRegisterValue(char reg, int32_t value) {
    switch (reg) {
        case 'A': A = value; break;
        case 'B': B = value; break;
        case 'C': C = value; break;
        case 'D': D = value; break;
        default: // Ignore if register is unknown
            break;
    }
}

float getFloatRegisterValue(char reg) {
    switch (reg) {
        case 'X': return X;
        case 'Y': return Y;
        default: return 0.0f; // Handle unknown register gracefully
    }
}

void setFloatRegisterValue(char reg, float value) {
    switch (reg) {
        case 'X': X = value; break;
        case 'Y': Y = value; break;
        default: // Ignore if register is unknown
            break;
    }
}

int32_t addWithOverflow(int32_t a, int32_t b) {
    // Check for integer overflow
    if ((b > 0 && a > INT32_MAX - b) || (b < 0 && a < INT32_MIN - b)) {
        // Overflow occurred
        std::cout << "Integer overflow" << std::endl;
        return a;
    }
    return a + b;
}

int32_t subtractWithOverflow(int32_t a, int32_t b) {
    // Check for integer overflow
    if ((b < 0 && a > INT32_MAX + b) || (b > 0 && a < INT32_MIN + b)) {
        // Overflow occurred
        std::cout << "Integer overflow" << std::endl;
        return a;
    }
    return a - b;
}

int32_t multiplyWithOverflow(int32_t a, int32_t b) {
    // Check for integer overflow
    if (a > INT32_MAX / b || a < INT32_MIN / b) {
        // Overflow occurred
        std::cout << "Integer overflow" << std::endl;
        return a;
    }
    return a * b;
}

void fibonacciProgram(unsigned n) {
    // Generate a simple VM program to calculate the nth Fibonacci number
    
    movi('A', 0); 
    movi('B', 1); 
    movi('C', 0); 

    while (C < n) {
        // Swap A and B, then add them and store the result in A
        swapab();
        addi('A', 'B');
        storea('B'); // B = A
        addi('C', 1); // Increment counter
    }
}
void movi(char ireg, int32_t iimm) {
    switch (ireg) {
        case 'A': A = iimm; break;
        case 'B': B = iimm; break;
        case 'C': C = iimm; break;
        case 'D': D = iimm; break;
        default: // Ignore if register is unknown
            break;
    }
}

void swapab() {
    std::swap(A, B);
}

void storea(char ireg) {
    switch (ireg) {
        case 'A': A = A; break; // No-op
        case 'B': B = A; break;
        case 'C': C = A; break;
        case 'D': D = A; break;
        default: 
            break;
    }
}

void addi(char ireg, char jreg) {
    int32_t i_value = getRegisterValue(ireg);
    int32_t j_value = getRegisterValue(jreg);
    A = addWithOverflow(i_value, j_value);
}

}

//---------------------------------------------------------------------------
 // namespace simplevm
//---------------------------------------------------------------------------
