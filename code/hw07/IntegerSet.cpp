#include "IntegerSet.h"


int IntegerSet::add(int value) {
    if (index(value) != -1)
        return IntegerBuffer::add(value);

    return 0;
}
int IntegerSet::add(const int array[], int arrayLength) {
    int numOfAdded = 0;

    for (int i = 0; i < arrayLength; ++i) {
        numOfAdded += add(array[i]);
    }
    return numOfAdded;
}