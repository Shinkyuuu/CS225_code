// 
// File: hw13.cpp
// Project: Assignment 13
// Author: Michael Van Hilst 
// Version: 2.0 June 10, 2019 
//
#include <string>
#include <iostream>
#include "TBuffer.h"
// #include "TOrderedBuffer.h" // extra credit only
// #include "TSetOrderedBuffer.h" // extra credit only
using namespace std;
void baseTest();
// void extraCreditTest(); // extra credit only

int main() {
    baseTest();
    //    extraCreditTest(); // extra credit only
    return 0;
}

void baseTest() {
    TBuffer<int, 12> ib(0);
    int i_array[10] = { 12, -4, 6, 8, 6, 5, -4, -6, 11, 88 };
    ib.add(7);
    ib.add(12);
    ib.add(17);
    ib.add(i_array, 9);
    cout << "Length: " << ib.getDataLength() << endl;
    ib.print();
    cout << "Sum: " << ib.sum() << endl;
    TBuffer<double, 10> db(0.0);
    db.add(8.463);
    db.add(3.74);
    db.add(5.231);
    db.add(3.74);
    db.print();
    cout << "Sum: " << db.sum() << endl;
    TBuffer<string, 10> sb("");
    sb.add("John");
    sb.add("Sarah");
    sb.add("John");
    sb.add("Sarah");
    sb.add("Miguel");
    sb.add("Fred");
    sb.add("Klyde");
    sb.add("Clara");
    sb.print();
    cout << "Sum: " << sb.sum() << endl;
}
