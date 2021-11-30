#pragma once
#include "IntegerBuffer.h"

class STLIntegerBuffer : public IntegerBuffer {
public:
    class Iterator {
    private:
        STLIntegerBuffer* target = nullptr;
        int cursor = 0;
        // a zero valued variable to return if empty in operator*
        int null = 0;
        // private constructor usable only in a friend class
        Iterator(STLIntegerBuffer* target, int cursor);
        // needed for parent class to access private constructor
        friend class STLIntegerBuffer;
    public:
        // only one gets fully implemented, the other is ! the first
        bool operator==(const Iterator& rhs) const;
        bool operator!=(const Iterator& rhs) const;
        // this declaration is for ++iter
        Iterator& operator++();
        // operator overload for iter++
        Iterator operator++(int);
        // note that *iter returns an implicit memory reference
        int& operator*();
    };
    // Two factory methods that return objects of the inner class
    Iterator begin();
    Iterator end();
};