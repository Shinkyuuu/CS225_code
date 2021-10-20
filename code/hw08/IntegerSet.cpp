#include "IntegerSet.h"

// If the given value is not already in the set, add it.
int IntegerSet::add(int value) {
    if (index(value) == -1)
        return IntegerBuffer::add(value);

    return 0;
}