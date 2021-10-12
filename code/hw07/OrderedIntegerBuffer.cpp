#include "OrderedIntegerBuffer.h"

//2, 3, 5, 6, 7

int OrderedIntegerBuffer::add(int value) {
    if (dataLength >= dataCapacity)
        return 0;

    int i  = dataLength - 1;

    // REWORK THIS
    for (i = (dataLength-1); i >= 0; --i) 
        if (value < data[i]) 
            data[i + 1] = data[i];

    data[i] = value;

    return 1;
}
int OrderedIntegerBuffer::add(const int array[], int arrayLength) {

}