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
*        - $ ./ nums_dat
*        - $ ./ output.txt
*
*    Files:
*             main.cpp    : driver program
******************************************************************************/
#include "ArrayStack.h"
#include <iostream>
#include <fstream>

using namespace std;


// Funtion Prototype to Asked the user for name of files to be use.
void openFiles(ifstream &, ofstream &);


// MAIN DRIVER
int main()
{
    ArrayStack stack; // stack for resizing
                      
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
    outfile << "\t\tAssignment 4 - Resizing the Stack\n";
    outfile << "\t\tCMPS 3013\n";
    outfile << "\t\tLoic Konan\n\n";
    outfile << "\t\tMax Stack Size: " << stack.getMaxSize() << "\n";
    outfile << "\t\tEnd Stack Size: " << stack.getSize() << "\n";
    outfile << "\t\tStack Resized:  " << stack.getTimesResized() << " Times\n\n";
    outfile << "################################################################\n";
}

/****************************************************************************
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
 *          Void
 * 
 ***************************************************************************/
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

