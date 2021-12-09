#pragma once
#include <string>
#include "IntegerBuffer.h"

class FileDataBuffer : public IntegerBuffer {
public:
    FileDataBuffer(int capacity): IntegerBuffer(capacity) {}
    bool store(std::string filename);
    bool load(std::string filename);
    bool operator==(IntegerBuffer& other);
};

