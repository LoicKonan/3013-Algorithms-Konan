/*****************************************************************************
*
*    Author:           Loic Konan
*    Email:            loickonan.lk@gmail.com
*    Label:            P01
*    Title:            Assignment 4 - Resizing the Stack
*    Course:           CMPS 3013
*    Semester:         Spring 2021
*    Description:
*        
*           This program will read numbers from the file nums.dat. 
*           If a number is even it will push it onto the stack. If a number
*           is odd, it will perform a pop operation removing the last 
*           even value from the stack. The stack cannot get smaller than 10 
*           (our starting stack size). We need to keep track of the max size
*           and how many times the stack was resized and final size of stack
*           when program completed.
* 
*    Usage:
*        Enter the main file name, then the input file and the output file.
*        - $ ./ main.cpp
*        - $ ./ nums_test.dat
*        - $ ./ output.txt
*
*    Files:
*             main.cpp          : driver program
*             nums_test.dat     : Input file
*             output.txt        : Output file
*
******************************************************************************/

#include <iostream>
#include <fstream>

using namespace std;


// Funtion Prototype to Asked the user for name of files to be use.
void openFiles(ifstream &, ofstream &);


/*
*    Class Name: ArrayStack
*    Description:
*                Array based stack
*        
*    Public Methods:
*           ArrayStack();
*           ArrayStack(int s);
*           bool Empty();
*           bool Full();
*           int Peek();
*           int Pop();
*           void Print();
*           bool Push(int x);
*           void ContainerGrow();
*           void ContainerShrink();
*           void CheckResize();
*           int getSize();
*           int getTimesResized();
*           int getMaxSize();
*           int getTop();
*    Private Methods:
*        - No Private methods
*        - No Protected methods
*    Usage:
*        
*/
class ArrayBasedStackCode
{
private:
    int *A;           // pointer to array of int's
    int size;         // current max stack size
    int top;          // top of stack
    int timesResized; // times stack resized
    int MaxSize;      // the max size the stack reaches

public:
    ArrayBasedStackCode();
    ArrayBasedStackCode(int s);
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


/**
 *  Public :  ArrayBasedStackCode
 *
 * Description:
 *            Default Constructor
 *
 * Params:
 *          - None
 *
 * Returns:
 *          - NULL
 */
ArrayBasedStackCode::ArrayBasedStackCode()
{
    size = 10;
    A = new int[size];
    top = -1;
    timesResized = 0;
    MaxSize = size;
}


/**
 *  Public : ArrayBasedStackCode
 *
 * Description:
 *           Programmer Define Constructor
 *
 * Params:
 *           - int size
 *
 * Returns:
 *           - NULL
 */
ArrayBasedStackCode::ArrayBasedStackCode(int s)
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
 *              Is the Stack empty?
 *
 * Params:
 *              NULL
 *
 * Returns:
 *       [bool] true = empty
 */
bool ArrayBasedStackCode::Empty()
{
    return (top <= -1);
}


/**
 * Public bool: Full
 *
 * Description:
 *              Is Stack full?
 *
 * Params:
 *              NULL
 *
 * Returns:
 *      [bool] true = full
 */
bool ArrayBasedStackCode::Full()
{
    return (top >= size - 1);
}


/**
 * Public int:  Peek
 *
 * Description:
 *              Returns top value without altering the stack
 *
 * Params:
 *              NULL
 *
 * Returns:
 *       [int] top value if any
 */
int ArrayBasedStackCode::Peek()
{
    if (!Empty())
    {
        return A[top];
    }

    return -99;         // sentinel value
}


/**
 * Public int: Pop
 *
 * Description:
 *             Returns top value and removes it from stack
 *		       also checks if it needs to be resized
 *
 * Params:
 *             NULL
 *
 * Returns:
 *      [int] top value if any
 */
int ArrayBasedStackCode::Pop()
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
 *              Prints stack to standard out
 *
 * Params:
 *              NULL
 *
 * Returns:
 *              NULL
 */
void ArrayBasedStackCode::Print()
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
 *              Adds an item to top of stack and checks 
 *		        if resize is needed
 *
 * Params:
 *      [int] : item to be added
 * 
 * Returns:
 *      [bool] success = true
 */
bool ArrayBasedStackCode::Push(int x)
{
    A[++top] = x;
    CheckResize();
    return true;
}


/**
 * Public void: ContainerGrow
 *
 * Description:
 *              Resizes the container for the stack by 1.50 
 *              its capacity
 *
 * Params:
 *              NULL
 *
 * Returns:
 *              NULL
 */
void ArrayBasedStackCode::ContainerGrow()
{
    int newSize = size * 1.50;      // 150% size of original
    int *B = new int[newSize];      // allocate new memory

    for (int i = 0; i < size; i++)
    {                    // copy values to new array
        B[i] = A[i];
    }

    delete[] A;       // delete old array

    size = newSize;  // save new size

    A = B;          // reset array pointer

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
 *              Resizes the container for the stack by .5
 *              its capacity
 *
 * Params:
 *              NULL
 *
 * Returns:
 *              NULL
 */
void ArrayBasedStackCode::ContainerShrink()
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
 *              checks if the stack needs to be resized
 *
 * Params:
 *              NULL
 *
 * Returns:
 *              NULL
 */
void ArrayBasedStackCode::CheckResize()
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
 *              gets the size of the stack
 *
 * Params:
 *              NULL
 *
 * Returns:
 *       [int] size
 */
int ArrayBasedStackCode::getSize()
{
    return size;
}


/**
 * Public void: getTimesResized
 *
 * Description:
 *              gets the times the stack was resized
 *
 * Params:
 *              NULL
 *
 * Returns:
 *        [int] timesResized
 */
int ArrayBasedStackCode::getTimesResized()
{
    return timesResized;
}


/**
 * Public void: getMaxSize
 *
 * Description:
 *              gets the max size of the stack
 *
 * Params:
 *              NULL
 *
 * Returns:
 *       [int] MaxSize
 */
int ArrayBasedStackCode::getMaxSize()
{
    return MaxSize;
}


/**
 * Public void: getMaxSize
 *
 * Description:
 *              gets the top of the stack
 *
 * Params:
 *              NULL
 *
 * Returns:
 *      [int] tope
 */
int ArrayBasedStackCode::getTop()
{
    return top;
}


// Main Driver
int main()
{
    ArrayBasedStackCode stack; // stack for resizing
                      
    ifstream infile;  // Ifstream and ofstream object to read data.
    ofstream outfile;

    openFiles(infile, outfile);   // Calling the Function openFiles.

    int num; // num to put into stack or to read a pop

    while (!infile.eof())
    {
        infile >> num;
        if (num % 2 == 0) // pushe when evens.
        {
            stack.Push(num);
        }
        else // pops when odd.
        {
            stack.Pop();
        }
    }

   // Display the Heading and Result to the output file.
    outfile << "################################################################\n";
    outfile << "\tAssignment 4 - Resizing the Stack\n";
    outfile << "\tCMPS 3013\n";
    outfile << "\tLoic Konan\n\n";
    outfile << "\tMax Stack Size: " << stack.getMaxSize() << "\n";
    outfile << "\tEnd Stack Size: " << stack.getSize() << "\n";
    outfile << "\tStack Resized:  " << stack.getTimesResized() << " Times\n\n";
    outfile << "################################################################\n";
}


/**
 * 
 * Function Name: openFiles () 
 * 
 *  Description:
 *               To prompt the user for the infile and outfile
 *               name to be use.
 * 
 *  Parameters: ifstream& infile, ofstream& outfile
 * 
 * Returns:
 *              Void
 * 
 */
void openFiles(ifstream &infile, ofstream &outfile)
{
    char inFileName[40];
    char outFileName[40];

    cout << "Enter the input file name: ";	 // Prompt the User
    cin >> inFileName;

    infile.open(inFileName);                 // open input file
    cout << "Enter the output file name: ";
    cin >> outFileName;

    outfile.open(outFileName);               // Open output file.
}

