#include "IntegerBufferIterator.h"
#include "IterableIntegerBuffer.h"

IntegerBufferIterator::IntegerBufferIterator(IterableIntegerBuffer* collection) {
    this->collection = collection;
    first();
}

void IntegerBufferIterator::first() {
    cursor = (collection->dataLength > 0) ? 0 : -1;
}

void IntegerBufferIterator::next() {
    if (!isDone())
        cursor += 1;
}

bool IntegerBufferIterator::isDone() {
    return (cursor >= collection->dataLength) || (cursor < 0);
}

int IntegerBufferIterator::currentItem() {
    return isDone() ? 0 : collection->data[cursor];
}
