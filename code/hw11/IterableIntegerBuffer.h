#pragma once
#include "Iterator.h"
#include "IntegerBuffer.h"
#include "IntegerBufferIterator.h"

class IterableIntegerBuffer : public IntegerBuffer {
public:
    friend class IntegerBufferIterator;
    IterableIntegerBuffer(int dataCapacity) : IntegerBuffer(dataCapacity) {}
    IterableIntegerBuffer(const IntegerBuffer& other) : IntegerBuffer(other) {}
    Iterator* createIterator() { return new IntegerBufferIterator(this); }
};

