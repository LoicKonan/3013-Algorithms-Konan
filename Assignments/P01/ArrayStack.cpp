#include <iostream>
#include <fstream>
#include "ArrayStack.h"

using namespace std;


/**
 * ArrayStack
 *
 * Description:
 *      Default Constructor
 *
 * Params:
 *     - None
 *
 * Returns:
 *     - NULL
 */
ArrayStack::ArrayStack()
{
    size = 10;
    A = new int[size];
    top = -1;
    timesResized = 0;
    MaxSize = size;
}

/**
 * ArrayStack
 *
 * Description:
 *      Programmer Define Constructor size parameter
 *
 * Params:
 *     - int size
 *
 * Returns:
 *     - NULL
 */
ArrayStack::ArrayStack(int s)
{
    size = 10;
    A = new int[s];
    top = -1;
    timesResized = 0;
    MaxSize = size;
}

/**
 * Public bool: Empty
 *
 * Description:
 *      Is the Stack empty?
 *
 * Params:
 *      NULL
 *
 * Returns:
 *      [bool] true = empty
 */
bool ArrayStack::Empty()
{
    return (top <= -1);
}

/**
 * Public bool: Full
 *
 * Description:
 *      Is Stack full?
 *
 * Params:
 *      NULL
 *
 * Returns:
 *      [bool] true = full
 */
bool ArrayStack::Full()
{
    return (top >= size - 1);
}

/**
 * Public int: Peek
 *
 * Description:
 *      Returns top value without altering the stack
 *
 * Params:
 *      NULL
 *
 * Returns:
 *      [int] top value if any
 */
int ArrayStack::Peek()
{
    if (!Empty())
    {
        return A[top];
    }

    return -99; // sentinel value
}

/**
 * Public int: Pop
 *
 * Description:
 *      Returns top value and removes it from stack
 *		also checks if it needs to be resized
 *
 * Params:
 *      NULL
 *
 * Returns:
 *      [int] top value if any
 */
int ArrayStack::Pop()
{
    if (!Empty())
    {
        CheckResize();
        return A[top--];
    }

    return -99; // sentinel value
}

/**
 * Public void: Print
 *
 * Description:
 *      Prints stack to standard out
 *
 * Params:
 *      NULL
 *
 * Returns:
 *      NULL
 */
void ArrayStack::Print()
{
    for (int i = 0; i <= top; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

/**
 * Public bool: Push
 *
 * Description:
 *      Adds an item to top of stack and checks 
 *		if resize is needed
 *
 * Params:
 *      [int] : item to be added
 * 
 * Returns:
 *      [bool] success = true
 */
bool ArrayStack::Push(int x)
{
    A[++top] = x;
    CheckResize();
    return true;
}

/**
 * Public void: ContainerGrow
 *
 * Description:
 *      Resizes the container for the stack by 1.75 
 *      its capacity
 *
 * Params:
 *      NULL
 *
 * Returns:
 *      NULL
 */
void ArrayStack::ContainerGrow()
{
    int newSize = size * 1.75; // 175% size of original
    int *B = new int[newSize]; // allocate new memory

    for (int i = 0; i < size; i++)
    { // copy values to new array
        B[i] = A[i];
    }

    delete[] A; // delete old array

    size = newSize; // save new size

    A = B; // reset array pointer

    if (MaxSize < newSize)
    {
        MaxSize = size; // checks if maxsize needs
                        // increase
    }
}

/**
 * Public void: ContainerShrink
 *
 * Description:
 *      Resizes the container for the stack by .5
 *      its capacity
 *
 * Params:
 *      NULL
 *
 * Returns:
 *      NULL
 */
void ArrayStack::ContainerShrink()
{
    int newSize = size / 2; // halves size of original
    if (newSize < 10)
    {
        newSize = 10;
    }
    int *B = new int[newSize]; // allocate new memory

    for (int i = 0; i <= top; i++)
    { // copy values to new array
        B[i] = A[i];
    }

    delete[] A; // delete old array

    size = newSize; // save new size

    A = B; // reset array pointer
}

/**
 * Public void: CheckResize
 *
 * Description:
 *      checks if the stack needs to be resized
 *
 * Params:
 *      NULL
 *
 * Returns:
 *      NULL
 */
void ArrayStack::CheckResize()
{
    if (Full())
    {
        ContainerGrow(); // shrinks
        timesResized++;  // increments times resized
    }
    else if (top < (size / 2) && size > 10)
    {
        ContainerShrink(); // grows
        timesResized++;    // increments times resized
    }
}

/**
 * Public void: getSize
 *
 * Description:
 *      gets the size of the stack
 *
 * Params:
 *      NULL
 *
 * Returns:
 *      [int] size
 */
int ArrayStack::getSize()
{
    return size;
}

/**
 * Public void: getTimesResized
 *
 * Description:
 *      gets the times the stack was resized
 *
 * Params:
 *      NULL
 *
 * Returns:
 *      [int] timesResized
 */
int ArrayStack::getTimesResized()
{
    return timesResized;
}

/**
 * Public void: getMaxSize
 *
 * Description:
 *      gets the max size of the stack
 *
 * Params:
 *      NULL
 *
 * Returns:
 *      [int] MaxSize
 */
int ArrayStack::getMaxSize()
{
    return MaxSize;
}

/**
 * Public void: getMaxSize
 *
 * Description:
 *      gets the top of the stack
 *
 * Params:
 *      NULL
 *
 * Returns:
 *      [int] tope
 */
int ArrayStack::getTop()
{
    return top;
}