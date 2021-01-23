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
*           If a number is even, push it onto the stack. If a number is odd,
*           it will perform a pop operation removing the last even value
*           from the stack. The stack cannot get smaller than 10 
*           (our starting stack size). We need to keep track ofthe max size
*           the stack ever reached, how many times the stack was resized
*           (grown or reduced) and final size of stack when program completed.
* 
*    Usage:
*        - $ ./ main.cpp
*
*    Files:
*             main.cpp    : driver program
******************************************************************************/

#include <iostream>
#include <fstream>

using namespace std;


int main(){
    ifstream fin("nums.dat");
    int num=0;

    int max=10;
    int count=0;
    int evens=0;
    int odds=0;
    int last=0;

    while(!fin.eof())
    {
        fin>>num;
        if(num % 2 == 0){
            count++;
            evens++;
            last=0;
        }else{
            count--;
            odds++;
            last=1;
        }

        if(count >= max){
            max *= 1.75;
        }

    }

    cout<<max<<" "<<evens<<" "<<odds<<endl;
}