#pragma once
class IntegerBuffer {
protected:
    int* data;
    int dataLength;
    int dataCapacity;
public:
    IntegerBuffer(int dataCapacity);
    IntegerBuffer(const IntegerBuffer& other) :
        IntegerBuffer(other.dataCapacity) {
        copy(&other);
    }

    IntegerBuffer* clone();
    bool compare(const IntegerBuffer& other) const;
    void clear();
    int add(int value);
    int add(const int array[], int arrayLength);
    int removeFast(int index);
    int removeStable(int index);
    int index(int value) const;
    int rindex(int value) const;
    void print(int numberOfColumns, int columnWidth) const;
    int getCapacity() const { return dataCapacity; }
    int getLength() const { return dataLength; }
    int copy(const IntegerBuffer* other);

    ~IntegerBuffer();
};
