#include <iostream>
#include <iomanip>
#include <new>
#include "IntegerBuffer.h"
using namespace std;

IntegerBuffer::IntegerBuffer(int dataCapacity) {
    dataLength = 0;
    this->dataCapacity = dataCapacity;

    // Try memory allocation for data array
    try {
        data = new int[dataCapacity];
    }
    catch (const bad_alloc& e) {
        cerr << "Allocation failed: " << e.what() << '\n';
        data = nullptr;
        this->dataCapacity = 0;
    }
}

IntegerBuffer* IntegerBuffer::clone() {
    return new IntegerBuffer(*this);
}

bool IntegerBuffer::compare(const IntegerBuffer& other) const {
    // Make sure both dataLength's are equal first.
    if (dataLength != other.dataLength)
        return false;

    // If any of the index's values differ, return false.
    for (int i = 0; i < dataLength; ++i)
        if (data[i] != other.data[i])
            return false;

    return true;
}

void IntegerBuffer::clear() {
    dataLength = 0;
}

// If there is still space in the buffer, add the given value.
int IntegerBuffer::add(int value) {
    if (dataLength < dataCapacity) {
        data[dataLength] = value;
        ++dataLength;

        return 1;
    }
    return 0;
}

// Attempt to add each value in the given array to the buffer.
int IntegerBuffer::add(const int array[], int arrayLength) {
    int numOfAdded = 0;

    for (int i = 0; i < arrayLength; ++i)
        numOfAdded += add(array[i]);

    return numOfAdded;
}

// Remove the element at the given index by replacing it with the
// last element in the bufffer. Then decrement dataLength by 1.
int IntegerBuffer::removeFast(int index) {
    if (index >= 0 && index < dataLength) {
        data[index] = data[dataLength - 1];
        --dataLength;

        return 1;
    }
    return 0;
}

// Remove the element at the given array by moving every element
// After it to the left by 1. Then decrement dataLength by 1.
int IntegerBuffer::removeStable(int index) {
    if (index >= 0 && index < dataLength) {
        for (int i = (index + 1); i < dataLength; ++i)
            data[i - 1] = data[i];

        --dataLength;

        return 1;
    }
    return 0;
}

// Find the first instance of the value's index from the left side.
int IntegerBuffer::index(int value) const {
    for (int i = 0; i < dataLength; ++i)
        if (data[i] == value)
            return i;

    return -1;
}

// Find the first instance of the value's index from the right side.
int IntegerBuffer::rindex(int value) const {
    for (int i = dataLength; i > 0; --i)
        if (data[i] == value)
            return i;

    return -1;
}

void IntegerBuffer::print() const {
    for (int i = 0; i < dataLength; ++i) {
        if (i % 10 == 0 and i != 0)
            cout << "\n";

        cout << setw(7) << data[i];
    }
    cout << endl;
}

int IntegerBuffer::copy(const IntegerBuffer* other) {
    // If the given IntegerBuffer is not equal to the current one (this),
    // Clear the current one and add the given buffer's conents to it.
    if (other != this) {
        this->clear();
        return this->add(other->data, other->dataLength);
    }

    return 0;
}

IntegerBuffer::~IntegerBuffer() {
    dataCapacity = 0;
    dataLength = 0;

    if (data != nullptr) {
        int* mem = data;
        data = nullptr;
        delete[] mem;
    }
}