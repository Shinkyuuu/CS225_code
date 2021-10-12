#pragma once
#include "IntegerBuffer.h"

class OrderedIntegerBuffer : public IntegerBuffer {
public:
    int add(int value);
    int add(const int array[], int arrayLength);
};

