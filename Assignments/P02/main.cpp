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
*       A linked list search program that stores a json file with a dictionary
*       in it seperating the words and definition. With that information the program 
*       then allowes the user to type in a series of charecters. Everytime a user 
*       enters a char the program will search through the list to find all the words
*       with a substring of the chars entered and returns the top ten results plus 
*       the time it took to search the list.
*
*    Usage:
*           Enter the main file name, then the input file and the output file.
*           - $ ./ main.cpp
*           - $ ./ nums_test.dat
*           - $ ./ output.txt
*
*    Files:
*           main.cpp          : driver program
*           nums_test.dat     : Input file
*           output.txt        : Output file
*
******************************************************************************/
#include <iostream>
#include <time.h>
#include <chrono> 
#include "Timer.hpp"           
#include "mygetch.hpp"
#include <string>
#include <vector>
#include <fstream>
#include "termcolor.hpp"

using namespace std;



/**
 * wordNode
 * 
 * Description:
 *      A node that holds a next pointer string.
 * 
 * Public Methods:
 *		string 					Word
 *		wordNode* 				next	
 * 
 * Private Methods:
 *      None
 * 
 * Usage: 
 *      - 
 */

struct wordNode
{
    wordNode* Next;
    string word;

    wordNode()
    {
        Next = NULL;
        word = "";
    }

};


/**
 * LinkedList
 * 
 * Description:
 *      A linked list that holds a dictionary and 
 * 		can search for substrings of chars
 * 
 * Public Methods:
 *      						LinkedList() 
 *      void 					insert(string W, string D)
 *      void 					print()
 *		void 					search(string input) 
 * 		void 					printTenWords()
 * 
 * Private Methods:
 *      Node* 					Head;
 *		Node* 					Tail;	
 *		int 					length;
 *		string 					TenWords[10];
 *		int 					TermsFound;
 * 
 * Usage: 
 * 
 *      LinkedList ; 		    // creates list
 * 		insert("A");	        // adds a word A and a definition b to list
 * 		print();				// prints the list to a Checking.txt file
 * 		search("cat");		    // searches list for words with substring ste
 */
class LinkedList
{
protected:
    wordNode* Head;
    wordNode* Tail;
    int Size;

public:

    LinkedList()
    {
        Head = NULL;
        Tail = NULL;
        Size = 0;
    }

    int Get_Size()
    {
        return Size;
    }

/**
     * Public : insert(string W, string D)
     * 
     * Description:
     *      places a new node onto the list with a 
	 * 		given word and deginition
     * 
     * Params:
     *     	string W			//string for word
	 * 		string D			//string for definition
     * 
     * Returns:
     *     	None
     */
    void Insert_Data(wordNode* entry)
    {
        if (!Head)
        {
            Head = Tail = entry;
        }

        else
        {
            Tail->Next = entry;
            Tail = entry;
        }

        Size++;
    }


	/**
     * Public : print()
     * 
     * Description:
     *      prints the list onto a file "animals.txt"
     * 
     * Params:
     *      none
     * 
     * Returns:
     *     None
     */
    void Print() 
    {
        wordNode* Current = Head;                        // Always copy head so you don't destroy the list
        while (Current)                                               
        {                                                // Standard traversal Start at head and then goto next node
            cout << Current->word << endl;
            cout << "->";                                // awesome graphics
            Current = Current->Next;                     // goto next node
        }
        cout << "NULL" << endl;                          // End of list points to NULL
    }


/**
     * Public: search(string input)
     * 
     * Description:
     *      Looks into the list for substrings of the given 
	 * 		string and also loads the first ten similar strings 
	 *      into an array. Also gets increments terms found
     * 
     * Params:
     *      string input		//a given string for searching substrings
     * 
     * Returns:
     *      None
     */
   vector<string> Find(string typed)
    {
       cout << "Looking for matches.\n";

       vector<string> Results;
       size_t found;

       wordNode* Current = Head;
        
       while (Current)
       {
           found = Current->word.find(typed);

           if (found != string::npos)
           {
               Results.push_back(Current->word);
           }

           Current = Current->Next;
       }

       int len = typed.length();

       for (int i = 0; i < Results.size(); i++)
       {
           string temp = Results[i].substr(0, len);

           if (temp != typed)
           {
               Results[i].erase();
           }
       }

        return Results;
    }
};

/**
 * Main Driver
 *
 * For this program
 * *
 */
int main() 
{
    LinkedList L1;
    vector<string> Dictionary;

    ifstream in;
    in.open("animals.txt");


    Timer T1000;
    T1000.Start();
    while (!in.eof())
    {
        string Temp;

        in >> Temp;

        Dictionary.push_back(Temp);
    }

    T1000.End();


    cout << T1000.Seconds() << " seconds to read in the data." << endl;
    cout << T1000.MilliSeconds() << " milliseconds to read in the data." << endl;


    Timer T2;

    T2.Start();

    cout << "\nLoading linked list\n";
    for (int j = 0; j < Dictionary.size(); j++) 
    {
        wordNode* Temp = new wordNode;

        string item = Dictionary[j];

        Temp->word = item;

        L1.Insert_Data(Temp);
    }

    T2.End();


    cout << T2.Seconds() << " seconds to read in the data." << endl;
    cout << T2.MilliSeconds() << " milliseconds to read in the data." << endl;



    char k;                                                     // holder for character being typed
    string word = "";                                           // var to concatenate letters to
    vector<string> Matches;                                     // any matches found in vector of Dictionary Words

    string Top_Results[10];
    int SearchResults;

    cout << endl << "Type keys and watch what happens. Type capital Z to quit." << endl;

    while ((k = getch()) != 'Z') 
    {
        if ((int)k == 127)                                       // Tests for a backspace and if pressed deletes 
        {                                                        // last letter from "word".
            if (word.size() > 0) 
            {
                word = word.substr(0, word.size() - 1);
            }
        }

        else 
        {
            if (!isalpha(k))                                      // Make sure a letter was pressed and only letter
            {
                cout << "Letters only!" << endl;
                continue;
            }

            if ((int)k >= 97)                                     // We know its a letter, lets make sure its lowercase.
            {                                                     // Any letter with ascii value < 97 is capital so we
                k -= 32;                                          // lower it.
            }
            word += k;                                            // append char to word
        }


       Timer Auto_Suggestion;

       Auto_Suggestion.Start();
       Matches = L1.Find(word);
       Auto_Suggestion.End();

       SearchResults = Matches.size();


        if ((int)k != 32) 
        {                                                          // if k is not a space print it
            cout << "Keypressed: " << k << " = " << (int)k << endl;
            cout << "Current Substr: " << word << termcolor::reset << endl;
            cout << SearchResults << " words found in " << Auto_Suggestion.Seconds() << " seconds" << endl << endl;

            cout << "Animals Found: " << termcolor::green;

                                                                    
            for (int i = 0; i < 10; i++)                            // This prints out the top ten results
            {
                Top_Results[i] = Matches[i];
                cout << Top_Results[i] << " ";
            }

            cout << termcolor::reset << endl << endl;       
             }
    }


    return 0;
}