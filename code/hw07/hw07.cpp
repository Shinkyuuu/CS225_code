//#include <iostream>
//#include "IntegerSet.h"
//#include "OrderedIntegerBuffer.h"
//using namespace std;
//void testIntegerSet(int arr[], int arrLength);
//void testOrderedIntegerBuffer(int arr[], int length);
//void testCopy();
//int main() {
//    const int ARR0_LEN = 2;
//    int arr0[ARR0_LEN] = { -2, -1 };
//    const int ARR1_LEN = 10;
//    int arr1[ARR1_LEN] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//    const int ARR2_LEN = 25;
//    int arr2[ARR2_LEN] = { 2, 4, 6, 8, 10, 12, 14, 16, 7, 6, 22, 8,
//    9, 16, 5, 2, 7, 8, 12, 2, 0, 14, 17, 19, 22 };
//    testIntegerSet(arr0, ARR0_LEN);
//    testIntegerSet(arr1, ARR1_LEN);
//    testIntegerSet(arr2, ARR2_LEN);
//    testOrderedIntegerBuffer(arr0, ARR0_LEN);
//    testOrderedIntegerBuffer(arr2, ARR2_LEN);
//    testCopy();
//    cout << "Press any key to continue ...";
//    char c;
//    cin.get(c);
//    return 0;
//}
//void testIntegerSet(int arr[], int arrLength) {
//    IntegerSet buf;
//    IntegerSet buf2;
//    buf.add(4);
//    buf.add(arr, arrLength);
//    cout << "Display after add 4 and add arr" << endl;
//    buf.print(10, 7);
//    cout << "Display after copy IntegerSet" << endl;
//    buf2.add(17);
//    buf2.copy(&buf);
//    buf2.print(10, 7);
//}
//void testOrderedIntegerBuffer(int arr[], int arrLength) {
//    OrderedIntegerBuffer obuf;
//    obuf.add(5);
//    obuf.add(0);
//    cout << "\n Ordered data buffer" << endl;
//    obuf.print(10, 7);
//    obuf.add(arr, arrLength);
//    obuf.add(13);
//    cout << " Ordered data buffer after adds" << endl;
//    obuf.print(10, 7);
//    obuf.removeFast(2);
//    obuf.removeStable(8);
//    cout << " After removes" << endl;
//    obuf.print(10, 7);
//}
//void testCopy() {
//    IntegerBuffer ibuf;
//    IntegerBuffer ibuf2;
//    OrderedIntegerBuffer obuf;
//    OrderedIntegerBuffer obuf2;
//    OrderedIntegerBuffer obuf3;
//    IntegerSet sbuf;
//    IntegerSet sbuf2;
//    IntegerSet sbuf3;
//    static const int LENGTH = 8;
//    int arr[LENGTH] = { 5, 7, 2, 5, 4, 1, 4, 3 };
//    ibuf.add(arr, LENGTH);
//    cout << "\nOriginal IntegerBuffer to copy" << endl;
//    ibuf.print(8, 7);
//    cout << "Simple copy" << endl;
//    ibuf2.copy(&ibuf);
//    ibuf2.print(8, 7);
//    obuf.add(arr, LENGTH);
//    obuf2.copy(&obuf);
//    obuf3.copy(&ibuf);
//    cout << "Original OrderedIntegerBuffer to copy" << endl;
//    obuf.print(10, 7);
//    cout << "OrderedIntegetBuffer to OrderedIntegerBuffer copy" << endl;
//    obuf2.print(10, 7);
//    cout << "IntegetBuffer to OrderedIntegerBuffer copy" << endl;
//    obuf3.print(10, 7);
//    sbuf.add(arr, LENGTH);
//    sbuf2.copy(&sbuf);
//    sbuf3.copy(&ibuf);
//    cout << "Original IntegerSet to copy" << endl;
//    sbuf.print(10, 7);
//    cout << "IntegerSet to IntegerSet copy" << endl;
//    sbuf2.print(10, 7);
//    cout << "IntegerBuffer to IntegerSet copy" << endl;
//    sbuf3.print(10, 7);
//}

#include <iostream>         /* for printf() */
#include "IntegerBuffer.h"  /* homework project header file */
#include "IntegerSet.h"
#include "OrderedIntegerBuffer.h"
using std::cout;
using std::endl;
void hw04test(IntegerBuffer& ibuf, int data[], int dataSz);
void hw08aTest(IntegerSet& ibuf, int data[], int dataSz);
void hw08bTest(OrderedIntegerBuffer& ibuf, int data[], int dataSz);
void fillRandom(int array[], int arrLen, int lowerBound, int upperBound);
int myrand(void);
#define MYRAND_MAX 32768
/* DATASZ is set to exceed size of array in the IntegerBuffer */
int main(void) {
    static const int DATASZ = 64;
    int data[DATASZ];
    fillRandom(data, DATASZ, 20, 40);
    IntegerBuffer ibuf;
    cout << "** Plain IntegerBuffer **" << endl;
    hw04test(ibuf, data, DATASZ);
    cout << "\n\n** Set IntegerBuffer **" << endl;
    IntegerSet sbuf1;
    IntegerSet sbuf2;
    cout << "   * Original test *" << endl;
    hw04test(sbuf1, data, DATASZ);
    cout << "\n   * Test specific for Set *" << endl;
    hw08aTest(sbuf2, data, DATASZ);
    cout << "\n\n** Ordered IntegerBuffer **" << endl;
    OrderedIntegerBuffer obuf1;
    OrderedIntegerBuffer obuf2;
    cout << "   * Original test *" << endl;
    hw04test(obuf1, data, DATASZ);
    cout << "\n   * Test specific for OrderedBuffer *" << endl;
    hw08bTest(obuf2, data, DATASZ);
    system("pause");
    return 0;
}
void hw04test(IntegerBuffer& ibuf, int data[], int dataSz) {
    int i = 0;
    int index = 0;
    int result = 0;
    /* test that ibufInit is working correctly */
    cout << "Phase 1: ";
    cout << "capacity: " << ibuf.getCapacity()
        << ", length: " << ibuf.getLength() << endl;
    /* test that ibufAdd is working correctly */
    cout << "Phase 2:";
    ibuf.add(5);
    ibuf.add(17);
    ibuf.print(10, 7);
    /* test that ibufAddArray is working correctly */
    cout << "Phase 3: ";
    result = ibuf.add(data, dataSz);
    cout << "reported adding " << result << " of " << dataSz << endl;
    ibuf.print(9, 7);
    /* test that ibufClear is working correctly */
    cout << "Phase 4:";
    ibuf.clear();
    for (i = 0; i < 5; i++)
        ibuf.add(i);
    for (i = 5; i > 0; i--)
        ibuf.add(i);
    ibuf.print(10, 7);
    /* test that ibufIndex, ibufRemoveDast and ibufRemoveStable work */
    cout << "Phase 5:";
    index = ibuf.index(2);
    ibuf.removeFast(index);
    ibuf.removeFast(ibuf.rindex(3));
    ibuf.print(10, 5);
}
void hw08aTest(IntegerSet& ibuf, int data[], int dataSz) {
    int i = 0;
    int index = 0;
    int result = 0;
    /* test that ibufInit is working correctly */
    cout << "Phase 1: ";
    cout << "capacity: " << ibuf.getCapacity()
        << ", length: " << ibuf.getLength() << endl;
    /* test that ibufAdd is working correctly */
    cout << "Phase 2:";
    ibuf.add(5);
    ibuf.add(17);
    ibuf.print(10, 7);
    /* test that ibufAddArray is working correctly */
    cout << "Phase 3: ";
    result = ibuf.add(data, dataSz);
    cout << "reported adding " << result << " of " << dataSz << endl;
    ibuf.print(9, 7);
    /* test that ibufClear is working correctly */
    cout << "Phase 4:";
    ibuf.clear();
    for (i = 0; i < 5; i++)
        ibuf.add(i);
    for (i = 5; i > 0; i--)
        ibuf.add(i);
    ibuf.print(10, 7);
    /* test that ibufIndex, ibufRemoveDast and ibufRemoveStable work */
    cout << "Phase 5:";
    index = ibuf.index(2);
    ibuf.removeFast(index);
    ibuf.removeFast(ibuf.rindex(3));
    ibuf.print(10, 5);
}
void hw08bTest(OrderedIntegerBuffer& ibuf, int data[], int dataSz) {
    int i = 0;
    int index = 0;
    int result = 0;
    /* test that ibufInit is working correctly */
    cout << "Phase 1: ";
    cout << "capacity: " << ibuf.getCapacity()
        << ", length: " << ibuf.getLength() << endl;
    /* test that ibufAdd is working correctly */
    cout << "Phase 2:";
    ibuf.add(5);
    ibuf.add(17);
    ibuf.print(10, 7);
    /* test that ibufAddArray is working correctly */
    cout << "Phase 3: ";
    result = ibuf.add(data, dataSz);
    cout << "reported adding " << result << " of " << dataSz << endl;
    ibuf.print(9, 7);
    /* test that ibufClear is working correctly */
    cout << "Phase 4:";
    ibuf.clear();
    for (i = 0; i < 5; i++)
        ibuf.add(i);
    for (i = 5; i > 0; i--)
        ibuf.add(i);
    ibuf.print(10, 7);
    /* test that ibufIndex, ibufRemoveDast and ibufRemoveStable work */
    cout << "Phase 5:";
    index = ibuf.index(2);
    ibuf.removeFast(index);
    ibuf.removeFast(ibuf.rindex(3));
    ibuf.print(10, 5);
}
/* Function: fillRandom
 * Purpose:  fill an integer array with random values in a given range
 * Argument: array      - an array of integers
 * Argument: arrLen     - the number of integers to generate
 * Argument: upperBound - the highest value that could be generated
 * Returns:  nothing
 * Precondition: array points to a valid array of ints
 * Precondition: arrLen is not greater than the available space in array
 */
void fillRandom(int array[], int arrLen, int lowerBound, int upperBound) {
    int i;
    /* static makes this a persistent variable
     * that is initialized only once */
    static int notSeeded = 1;
    double range = 1.0 + upperBound - lowerBound;
    if (notSeeded) {
        /* if we want it seeded, the srand goes here */
        notSeeded = 0;
    }
    for (i = 0; i < arrLen; i++) {
        /* refactored the order to force doubles to be used w/o cast */
        /* a good optimizer will also recognize that (range / RAND_MAX)
         * can be done outside the loop */
        array[i] = (int)(myrand() * (range / MYRAND_MAX) + lowerBound);
    }
}
/* POSIX.1-2001 gives the following example of an implementation of rand(),
 * useful when one needs the same sequence on different machines.
 */
int myrand(void) {
    static unsigned long next = 1;
    next = next * 1103515245 + 12345;
    return((unsigned)(next / 65536) % MYRAND_MAX);
}