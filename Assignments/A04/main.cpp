/*****************************************************************************
*
*    Author:           Loic Konan
*    Email:            loickonan.lk@gmail.com
*    Label:            3013 Commenting C++ code
*    Title:            Linked List Comments
*    Course:           CMPS 3013
*    Semester:         Spring 2021
*    Description:
*        Program create a Linked List with various Nodes.
*        This program implements a class that allows a linked list
*        to be used just like an array. It overloads the "[]" to simulate
*        accessing seperate array elements. It also overloads the "+" signs
*        allowing a user "push" items onto the end of the list, 
*        as well as "pop" items off the end of our array.
*    Usage:
*        - $ ./main filename
*
*    Files:
*         3013 main.cpp    : driver program
******************************************************************************/


#include <iostream>
#include <string>

using namespace std;

int A[100];


/*
*  Struct Name: Node
*  Description:
*       Node struct, used to represents a node of some 
*       data and also a pointer to another structure of the same kind.
*       This pointer holds the address of the next node and creates
*       the link between two nodes.
*  Public Methods:
*       - Default constructor
*       - Programmer defined constructor that accepts
*         an integer.
*  Usage:
*       - examples of how to use your struct for linked list. 
*       - Used to create nodes that will be links within a linked list. 
*       
*/


struct Node 
{
    int x;
    Node* next;
    Node() 
    {
        x = -1;
        next = NULL;
    }
    Node(int n) 
    {
        x = n;
        next = NULL;
    }
};


/*
*    Class Name: List
*    Description:
*        This class implements a linked list with various methods
*        such as push and pop to add or remove nodes from the list.
*        There are also function for printing results and
*        overloaded operators to perform operations on the class objects.
*    Public Methods:
*        - List() - default constructor
*        - void Push(int val)
*        - void Insert(int val)
*        - void PrintTail()
*        - string Print()
*        - int Pop()
*        - List operator+(const List& Rhs)
*        - int operator[](int index)
*        - friend ostream& operator<<(ostream& os, List L)
*    Private Methods:
*        - No Private methods
*        - No Protected methods
*    Usage:
*        - Create a class object of a Linked List
*        - insert or delete nodes from the Linked List
*        - Print results
*        - print and outfile results
*/

class List 
{
private:
    Node* Head;
    Node* Tail;
    int Size;

public:
    List() 
    {
        Head = Tail = NULL;
        Size = 0;
    }

    void Push(int val) 
    {
        // allocate new memory and init node
        Node* Temp = new Node(val);

        if (!Head && !Tail) 
        {
            Head = Tail = Temp;
        }
        else
         {
            Tail->next = Temp;
            Tail = Temp;
        }
        Size++;
    }

    void Insert(int val) 
    {
        // allocate new memory and init node
        Node* Temp = new Node(val);

        Temp->next = Head;
        Head = Temp;
        if (!Tail)      
        {
            Tail = Head;
        }
        Size++;
    }

    void PrintTail() 
    {
        cout << Tail->x << endl;
    }

    string Print()
     {
        Node* Temp = Head;
        string list;

        while (Temp != NULL)
         {
            list += to_string(Temp->x) + "->";  
            Temp = Temp->next;
        }

        return list;
    }

    // not implemented.
    int Pop() 
    {
        Size--;
        return 0; //
    }

    List operator+(const List& Rhs) 
    {
        // Create a new list that will contain both when done
        List NewList;

        // Get a reference to beginning of local list
        Node* Temp = Head;

        // Loop through local list and Push values onto new list
        while (Temp != NULL)
         {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Get a reference to head of Rhs
        Temp = Rhs.Head;

        // Same as above, loop and push
        while (Temp != NULL)
         {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Return new concatenated version of lists
        return NewList;
    }

    // Implementation of [] operator.  This function returns an
    // int value as if the list were an array.
    int operator[](int index) 
    {
        Node* Temp = Head;

        // Error Control
        if (index >= Size) 
        {
            cout << "Index out of bounds, exiting";
            exit(0);
        }
        else
         {

            for (int i = 0; i < index; i++)
             {
                Temp = Temp->next;
            }
            return Temp->x;
        }
    }


    friend ostream& operator<<(ostream& os, List L) 
    {
        os << L.Print();
        return os;
    }
};


int main(int argc, char** argv) 
{
    // Declare two different Linked List objects.
    List L1;
    List L2;

    for (int i = 0; i < 25; i++)
     {
        L1.Push(i);
    }

    for (int i = 50; i < 100; i++) 
    {
        L2.Push(i);
    }

    //cout << L1 << endl;
    L1.PrintTail();
    L2.PrintTail();

    // Using overloading "the + operator" to add the objects.
    List L3 = L1 + L2;
    cout << L3 << endl;

    // Print out the contents.
    cout << L3[5] << endl;
    return 0;
} 
