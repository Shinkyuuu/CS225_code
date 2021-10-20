#include "OrderedIntegerBuffer.h"

// Add a value such that the IntegerBuffer maintains its order.
int OrderedIntegerBuffer::add(int value) {
    if (dataLength >= dataCapacity)
        return 0;

    int i = 0;

    // While "i" is equal to a valid index and the given value is less than or 
    // equal to the data array value, move the value at the index 
    // back one position.
    for (i = dataLength - 1; (i >= 0) && (value <= data[i]); --i)
        data[i + 1] = data[i];

    // If i == -1 (which is      to say dataLength = 0), 
    // then i = 0 (Add value into index 0). 
    // Else, i = i + 1 (Add value into the index before the for-loop ended)
    data[(i < 0) ? 0 : (i + 1)] = value;
    ++dataLength;

    return 1;
}