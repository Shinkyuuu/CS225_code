#include "IntegerSet.h"

// If the given value is not already in the set, add it.
int IntegerSet::add(int value) {
    if (index(value) == -1)
        return IntegerBuffer::add(value);

    return 0;
}

// Attempt to add each value in the given array to the set.
int IntegerSet::add(const int array[], int arrayLength) {
    int numOfAdded = 0;

    for (int i = 0; i < arrayLength; ++i) 
        numOfAdded += add(array[i]);
    
    return numOfAdded;
}


int IntegerSet::copy(const IntegerBuffer* other) {
    IntegerSet copyableSet;

    if (other != this) {
        this->clear();

        // Use the parent func "IntegerBuffer::copy" in copyableSet which 
        // will result in a set that contains duplicates (so not a set). 
        // Then, add it to the current set which will remove said duplicates.
        copyableSet.IntegerBuffer::copy(other);
        return this->add(copyableSet.data, copyableSet.dataLength);
    }

    return 0;
}

int IntegerSet::copy(const IntegerSet* other) {
    return IntegerBuffer::copy(other);
}