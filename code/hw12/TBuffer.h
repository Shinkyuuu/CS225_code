#pragma once
#include <iostream>
#include <iomanip>

template<class T, int CAPACITY>
class TBuffer {
private:
    T data[CAPACITY];
    T nullValue;
    int dataLength;
public:
    TBuffer(T nullValue) : nullValue(nullValue), dataLength(0) {}
    void clear();
    int add(T value);
    int add(const T array[], int arrayLength);
    int removeFast(int index);
    int removeStable(int index);
    int index(T value) const;
    int rindex(T value) const;
    void print() const;
    inline int getCapacity() const { return CAPACITY; }
    inline int getDataLength() const { return dataLength; }
    T sum();
};

template<class T, int CAPACITY>
void TBuffer<T, CAPACITY>::clear() {
    dataLength = 0;
}

// If there is still space in the buffer, add the given value.
template<class T, int CAPACITY>
int TBuffer<T, CAPACITY>::add(T value) {
    if (dataLength < CAPACITY) {
        data[dataLength] = value;
        ++dataLength;

        return 1;
    }
    return 0;
}

// Attempt to add each value in the given array to the buffer.
template<class T, int CAPACITY>
int TBuffer<T, CAPACITY>::add(const T array[], int arrayLength) {
    int numOfAdded = 0;

    for (int i = 0; i < arrayLength; ++i) {
        numOfAdded += add(array[i]);
    }
    return numOfAdded;
}

// Remove the element at the given index by replacing it with the
// last element in the bufffer. Then decrement dataLength by 1.
template<class T, int CAPACITY>
int TBuffer<T, CAPACITY>::removeFast(int index) {
    if (index >= 0 && index < dataLength) {
        data[index] = data[dataLength - 1];
        --dataLength;

        return 1;
    }
    return 0;
}

// Remove the element at the given array by moving every element
// After it to the left by 1. Then decrement dataLength by 1.
template<class T, int CAPACITY>
int TBuffer<T, CAPACITY>::removeStable(int index) {
    if (index >= 0 && index < dataLength) {
        for (int i = (index + 1); i < dataLength; ++i) {
            data[i - 1] = data[i];
        }
        --dataLength;

        return 1;
    }
    return 0;
}

template<class T, int CAPACITY>
int TBuffer<T, CAPACITY>::index(T value) const {
    for (int i = 0; i < dataLength; ++i) {
        if (data[i] == value) {
            return i;
        }
    }

    return -1;
}

template<class T, int CAPACITY>
int TBuffer<T, CAPACITY>::rindex(T value) const {
    for (int i = dataLength; i > 0; --i) {
        if (data[i] == value) {
            return i;
        }
    }
    return -1;
}

template<class T, int CAPACITY>
void TBuffer<T, CAPACITY>::print() const {
    for (int i = 0; i < dataLength; ++i) {
        if (i % 10 == 0 and i != 0) 
            std::cout << "\n";
        
        std::cout << std::setw(8) << data[i];
    }
    std::cout << std::endl;
}

//template<class T, int CAPACITY>
//void TBuffer<T, CAPACITY>::print() const {
//    for (int i = 0; i < dataLength; ++i)
//        std::cout << 
//}

template<class T, int CAPACITY>
T TBuffer<T, CAPACITY>::sum() {
    T sum = nullValue;

    for (int i = 0; i < dataLength; ++i)
        sum = sum + data[i];

    return sum;
}