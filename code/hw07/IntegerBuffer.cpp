#include <iostream>
#include<iomanip>
#include "IntegerBuffer.h"
using std::cout;
using std::setw;
using std::endl;

IntegerBuffer::IntegerBuffer() {
    dataLength = 0;
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

    for (int i = 0; i < arrayLength; ++i) {
        numOfAdded += add(array[i]);
    }
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
        for (int i = (index + 1); i < dataLength; ++i) {
            data[i - 1] = data[i];
        }
        --dataLength;

        return 1;
    }
    return 0;
}

int IntegerBuffer::index(int value) const {
    for (int i = 0; i < dataLength; ++i) {
        if (data[i] == value) {
            return i;
        }
    }

    return -1;
}

int IntegerBuffer::rindex(int value) const {
    for (int i = dataLength; i > 0; --i) {
        if (data[i] == value) {
            return i;
        }
    }
    return -1;
}

void IntegerBuffer::print(int numOfColumns, int columnWidth) const {
    for (int i = 0; i < dataLength; ++i) {
        if (i % numOfColumns == 0 and i != 0) {
            cout << "\n";
        }
        cout << setw(columnWidth) << data[i];
    }
    cout << endl;
}

int IntegerBuffer::copy(const IntegerBuffer* other) {
    if (other != this) {
        this->clear();
        return this->add(other->data, other->dataLength);
    }
        
    return 0;
}

bool IntegerBuffer::compare(IntegerBuffer* other) const {
    if (this->dataLength != other->dataLength)
        return false;

    for (int i = 0; i < this->dataLength; ++i) 
        if (this->data[i] != other->data[i])
            return false;

    return true;
}