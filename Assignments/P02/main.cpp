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

int main() 
{
    LinkedList L1;
    vector<string> Dictionary;

    ifstream in;
    in.open("Words.txt");


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

    cout << "\nloading linked list\n";
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