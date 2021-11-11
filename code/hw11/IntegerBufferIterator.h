#ifndef INTEGER_BUFFER_ITERATOR_H
#define INTEGER_BUFFER_ITERATOR_H
#include "Iterator.h"
// Declare the collection class as a class but no more.
class IterableIntegerBuffer;
/* Because IterableIntegerBuffer.h includes this file, we
* avoid looping on the includes. Here the compiler only
* needs to know that IterableIntegerBuffer is a class. It
* does not need the details. Include "InterableIntegerBuffer.h"
* in IntegerBufferIterator.cpp, where the details are needed.
*/
class IntegerBufferIterator : public Iterator {
protected:
    IterableIntegerBuffer* collection;
    int cursor;
public:
    IntegerBufferIterator(IterableIntegerBuffer* collection);

    void first() override;
    void next() override;
    bool isDone() override;
    int currentItem() override;
};
#endif // INTEGER_BUFFER_ITERATOR_H