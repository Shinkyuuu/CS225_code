#pragma once
#include "IntegerBuffer.h"

class IntegerSet : public IntegerBuffer {
public:
    IntegerSet() : IntegerBuffer() {}
    int add(int value) override;
    inline int add(const int array[], int arrayLength) {
        return IntegerBuffer::add(array, arrayLength);
    }
};

