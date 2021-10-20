#pragma once
#include "IntegerBuffer.h"

class OrderedIntegerBuffer : public IntegerBuffer {
public:
    OrderedIntegerBuffer() : IntegerBuffer() {}
    int add(int value);
    int add(const int array[], int arrayLength) { 
        return IntegerBuffer::add(array, arrayLength); 
    }
    int removeFast(int index) {
        return IntegerBuffer::removeStable(index);
    }
};

