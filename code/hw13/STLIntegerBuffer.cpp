
#include <iostream>
#include "STLIntegerBuffer.h"

STLIntegerBuffer::Iterator::Iterator(STLIntegerBuffer* target, int cursor) {
    this->target = target;
    this->cursor = cursor;
}

bool STLIntegerBuffer::Iterator::operator==(const Iterator& rhs) const {
    return this->cursor == rhs.cursor;
}

bool STLIntegerBuffer::Iterator::operator!=(const Iterator& rhs) const {
    return !(*this == rhs);
}

STLIntegerBuffer::Iterator& STLIntegerBuffer::Iterator::operator++() {
    ++cursor;
    return *this;
}

STLIntegerBuffer::Iterator STLIntegerBuffer::Iterator::operator++(int) {
    return ++*this;
}

int& STLIntegerBuffer::Iterator::operator*() {
    if (cursor < target->dataLength)
        return target->data[cursor];
    else 
        return null;
}

STLIntegerBuffer::Iterator STLIntegerBuffer::begin() {
    return Iterator(this, 0);
}

STLIntegerBuffer::Iterator STLIntegerBuffer::end() {
    return Iterator(this, dataLength);
}