#include <iostream>
#include <fstream>
#ifndef ArrayStack_h
#define ArrayStack_h

using namespace std;

/**
 * ArrayStack
 *
 * Description:
 *      Array based stack
 *
 * Public Methods:
 *      - 
 *
 * Usage:
 *      - 
 *
 */
class ArrayStack
{
private:
    int *A;           // pointer to array of int's
    int size;         // current max stack size
    int top;          // top of stack
    int timesResized; // times stack resized
    int MaxSize;      // the max size the stack reaches

public:
    ArrayStack();
    ArrayStack(int s);
    bool Empty();
    bool Full();
    int Peek();
    int Pop();
    void Print();
    bool Push(int x);
    void ContainerGrow();
    void ContainerShrink();
    void CheckResize();
    int getSize();
    int getTimesResized();
    int getMaxSize();
    int getTop();
};
#endif