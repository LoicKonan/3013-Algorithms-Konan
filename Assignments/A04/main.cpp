/*
    Author:           Loic Konan
    Email:            loickonan.lk@gmail.com
    Label:            3013 Comments
    Title:            Linked List Comments
    Course:           3013
    Semester:         Spring 2021
    Description:
         Program created a Linked List with various Nodes.
    Usage:
         Creates a Linked List that can be used for further 
         applications such as expanding into a lookup table
         or hash table / hash map.
    Files:
         3013 Comments.cpp
*/

#include <iostream>
#include <string>

using namespace std;

int A[100];


/*
  Struct Name: Node
  Description:
       Node struct used to create nodes that are
       members of a linked list.
  Public Methods:
       - Default constructor
       - Programmer defined constructor that accepts
         an integer passed in.
  Usage:
       - Used to create nodes that will be links within
         a linked list. 
       - Includes an integer as well as 
         a struct Node pointer to keep track of the index
         of the linked list.
 */

struct Node {
    int x;
    Node* next;
    Node() {
        x = -1;
        next = NULL;
    }
    Node(int n) {
        x = n;
        next = NULL;
    }
};


/*
    Class Name: List
    Description:
        This class implements a linked list with various methods
        such as push and pop to add or remove nodes from the list.
        There are also methods for printing results or sections as
        well as overloaded operators to perform operations on the
        class objects.
    Public Methods:
        - List() - default constructor
        - void Push(int val)
        - void Insert(int val)
        - void PrintTail()
        - string Print()
        - int Pop()
        - List operator+(const List& Rhs)
        - int operator[](int index)
        - friend ostream& operator<<(ostream& os, List L)
    Private Methods:
        - No Private or Protected methods
    Usage:
        - Create a class object of a Linked List
        - Add or remove nodes to or from the Linked List
        - Print results
        - print and outfile results
 */

class List {
private:
    Node* Head;
    Node* Tail;
    int Size;

public:
    List() {
        Head = Tail = NULL;
        Size = 0;
    }

    void Push(int val) {
        // allocate new memory and init node
        Node* Temp = new Node(val);

        if (!Head && !Tail) {
            Head = Tail = Temp;
        }
        else {
            Tail->next = Temp;
            Tail = Temp;
        }
        Size++;
    }

    void Insert(int val) {
        // allocate new memory and init node
        Node* Temp = new Node(val);

        /* The Temp Node Pointer "next" is set to equal the head index of the Linked List.
           If the new Node becomes the Tail, then the Tail is set to equal the head thereby
           inserting the new element at the end of the Linked list growing it by a size of 1.
        */

        Temp->next = Head;
        Head = Temp;
        if (!Tail) {
            Tail = Head;
        }
        Size++;
    }

    void PrintTail() {
        cout << Tail->x << endl;
    }

    string Print() {
        Node* Temp = Head;
        string list;

        while (Temp != NULL) {
            list += to_string(Temp->x) + "->";      // to_string requires #include<string>
            Temp = Temp->next;
        }

        return list;
    }

    // not implemented, would need to call the node destructor, would need to be user defined
    int Pop() {
        Size--;
        return 0; //
    }

    List operator+(const List& Rhs) {
        // Create a new list that will contain both when done
        List NewList;

        // Get a reference to beginning of local list
        Node* Temp = Head;

        // Loop through local list and Push values onto new list
        while (Temp != NULL) {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Get a reference to head of Rhs
        Temp = Rhs.Head;

        // Same as above, loop and push
        while (Temp != NULL) {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Return new concatenated version of lists
        return NewList;
    }

    // Implementation of [] operator.  This function returns an
    // int value as if the list were an array.
    int operator[](int index) {
        Node* Temp = Head;

        // Error Control
        if (index >= Size) {
            cout << "Index out of bounds, exiting";
            exit(0);
        }
        else {

            for (int i = 0; i < index; i++) {
                Temp = Temp->next;
            }
            return Temp->x;
        }
    }


    friend ostream& operator<<(ostream& os, List L) {
        os << L.Print();
        return os;
    }
};


int main(int argc, char** argv) 
{
    // Declaring Objects into memory, two different Linked List objects
    List L1;
    List L2;

    for (int i = 0; i < 25; i++) {
        L1.Push(i);
    }

    for (int i = 50; i < 100; i++) {
        L2.Push(i);
    }

    //cout << L1 << endl;
    L1.PrintTail();
    L2.PrintTail();

    // Arithmetic on the Objects, possible by overloading the + operator
    List L3 = L1 + L2;
    cout << L3 << endl;

    /* Printing out the contents up to the index passed in as long
       as the index is not out of the range of the current size.
    */
    cout << L3[5] << endl;
    return 0;
}