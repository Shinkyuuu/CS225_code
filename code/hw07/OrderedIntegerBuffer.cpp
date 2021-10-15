#include "OrderedIntegerBuffer.h"

// Add a value such that the IntegerBuffer maintains its order.
int OrderedIntegerBuffer::add(int value) {
    if (dataLength >= dataCapacity)
        return 0;

    int i = 0;

    // While "i" is equal to a valid index and the given value is less than or 
    // equal to the data array value, move the value at the index 
    // back one position.
    for (i = dataLength-1; (i >= 0) && (value <= data[i]); --i)
        data[i + 1] = data[i];      
    
    // If i == -1 (which is      to say dataLength = 0), 
    // then i = 0 (Add value into index 0). 
    // Else, i = i + 1 (Add value into the index before the for-loop ended)
    data[(i < 0) ? 0 : (i + 1)] = value;
    ++dataLength;

    return 1;
}

// Attempt to add each value in the given array to the ordered buffer.
int OrderedIntegerBuffer::add(const int array[], int arrayLength) {
    int numOfAdded = 0;

    for (int i = 0; i < arrayLength; ++i) 
        numOfAdded += add(array[i]);
    
    return numOfAdded;
}

int OrderedIntegerBuffer::removeFast(int index) {
    return IntegerBuffer::removeStable(index);
}

int OrderedIntegerBuffer::copy(const IntegerBuffer* other) {
    OrderedIntegerBuffer copyableOBuffer;

    if (other != this) {
        this->clear(); 

        // Use the parent func "IntegerBuffer::copy" in copyableOBuffer which 
        // will result in a buffer that is out of order. Then, add it to the
        // current ordered buffer which will insert the values in order.
        copyableOBuffer.IntegerBuffer::copy(other);
        return this->add(copyableOBuffer.data, copyableOBuffer.dataLength);
    }

    return 0;
}

int OrderedIntegerBuffer::copy(const OrderedIntegerBuffer* other) {
    return IntegerBuffer::copy(other);
}