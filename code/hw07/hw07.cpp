#include <iostream>
#include "IntegerSet.h"
#include "OrderedIntegerBuffer.h"
using namespace std;
void testIntegerSet(int arr[], int arrLength);
void testOrderedIntegerBuffer(int arr[], int length);
void testCopy();
int main() {
    const int ARR0_LEN = 2;
    int arr0[ARR0_LEN] = { -2, -1 };
    const int ARR1_LEN = 10;
    int arr1[ARR1_LEN] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    const int ARR2_LEN = 25;
    int arr2[ARR2_LEN] = { 2, 4, 6, 8, 10, 12, 14, 16, 7, 6, 22, 8,
    9, 16, 5, 2, 7, 8, 12, 2, 0, 14, 17, 19, 22 };
    testIntegerSet(arr0, ARR0_LEN);
    testIntegerSet(arr1, ARR1_LEN);
    testIntegerSet(arr2, ARR2_LEN);
    testOrderedIntegerBuffer(arr0, ARR0_LEN);
    testOrderedIntegerBuffer(arr2, ARR2_LEN);
    testCopy();
    cout << "Press any key to continue ...";
    char c;
    cin.get(c);
    return 0;
}
void testIntegerSet(int arr[], int arrLength) {
    IntegerSet buf;
    IntegerSet buf2;
    buf.add(4);
    buf.add(arr, arrLength);
    cout << "Display after add 4 and add arr" << endl;
    buf.print(10, 7);
    cout << "Display after copy IntegerSet" << endl;
    buf2.add(17);
    buf2.copy(&buf);
    buf2.print(10, 7);
}
void testOrderedIntegerBuffer(int arr[], int arrLength) {
    OrderedIntegerBuffer obuf;
    obuf.add(5);
    obuf.add(0);
    cout << "\n Ordered data buffer" << endl;
    obuf.print(10, 7);
    obuf.add(arr, arrLength);
    obuf.add(13);
    cout << " Ordered data buffer after adds" << endl;
    obuf.print(10, 7);
    obuf.removeFast(2);
    obuf.removeStable(8);
    cout << " After removes" << endl;
    obuf.print(10, 7);
}
void testCopy() {
    IntegerBuffer ibuf;
    IntegerBuffer ibuf2;
    OrderedIntegerBuffer obuf;
    OrderedIntegerBuffer obuf2;
    OrderedIntegerBuffer obuf3;
    IntegerSet sbuf;
    IntegerSet sbuf2;
    IntegerSet sbuf3;
    static const int LENGTH = 8;
    int arr[LENGTH] = { 5, 7, 2, 5, 4, 1, 4, 3 };
    ibuf.add(arr, LENGTH);
    cout << "\nOriginal IntegerBuffer to copy" << endl;
    ibuf.print(8, 7);
    cout << "Simple copy" << endl;
    ibuf2.copy(&ibuf);
    ibuf2.print(8, 7);
    obuf.add(arr, LENGTH);
    obuf2.copy(&obuf);
    obuf3.copy(&ibuf);
    cout << "Original OrderedIntegerBuffer to copy" << endl;
    obuf.print(10, 7);
    cout << "OrderedIntegetBuffer to OrderedIntegerBuffer copy" << endl;
    obuf2.print(10, 7);
    cout << "IntegetBuffer to OrderedIntegerBuffer copy" << endl;
    obuf3.print(10, 7);
    sbuf.add(arr, LENGTH);
    sbuf2.copy(&sbuf);
    sbuf3.copy(&ibuf);
    cout << "Original IntegerSet to copy" << endl;
    sbuf.print(10, 7);
    cout << "IntegerSet to IntegerSet copy" << endl;
    sbuf2.print(10, 7);
    cout << "IntegerBuffer to IntegerSet copy" << endl;
    sbuf3.print(10, 7);
}