#include <fstream>
#include<iomanip>
#include "FileDataBuffer.h"
using namespace std;

bool FileDataBuffer::store(std::string filename) {
    ofstream outFile;
    outFile.open(filename);

    if (outFile.is_open()) {
        for (int i = 0; i < dataLength; ++i) {
            if (i % 10 == 0 and i != 0)
                outFile << "\n";

            outFile << setw(7) << data[i];
        }
        outFile << endl;
        outFile.close();
        return true;
    } else {
        return false;
    }
}

bool FileDataBuffer::load(std::string filename){
    ifstream inFile;
    int integerData;
    inFile.open(filename);

    if (inFile.is_open()) {
        while (inFile >> integerData) {
            if (inFile.fail())
                inFile.clear();
            else
                this->add(integerData);
        }
        return true;
    } else {
        return false;
    }
}

bool FileDataBuffer::operator==(IntegerBuffer& other) {
    return compare(other);
}
