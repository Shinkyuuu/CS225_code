#include <iostream>
#include<iomanip>
#include "IntegerBuffer.h"
using namespace std;

IntegerBuffer::IntegerBuffer() {
    dataLength = 0;
}

int IntegerBuffer::add(int value) {
    if (dataLength >= (dataCapacity-1)) {
        return 0;
    }
    data[dataLength] = value;
    ++dataLength;

    return 1;
}

int IntegerBuffer::add(const int array[], int arrayLength) {
    int numOfAdded = 0;

    for (int i; i < arrayLength; ++i) {
        numOfAdded += add(array[i]);
    }

    return numOfAdded;
}

int IntegerBuffer::index(int value) const {
    for (int i=0; i < dataLength; ++i) {
        if (data[i] == value) {
            return i;
        }
    }

    return -1;
}

int IntegerBuffer::rindex(int value) const {
    for (int i=dataLength; i > 0; --i) {
        if (data[i] == value) {
            return i;
        }
    }

    return -1;
}

void IntegerBuffer::clear() {
    dataLength = 0;
}

int IntegerBuffer::removeFast(int index) {
    if (index >= 0 && index < dataLength) {
        data[index] = data[dataLength - 1];
        --dataLength;

        return 1;
    }

    return 0;
}

int IntegerBuffer::removeStable(int index) {
    if (index >= 0 && index < dataLength) {
        for (int i = (index+1); i < dataLength; ++i) {
            data[i - 1] = data[i];
        }
        --dataLength;

        return 1;
    }

    return 0;
}

void IntegerBuffer::print(int numOfColumns, int columnWidth) const {

}