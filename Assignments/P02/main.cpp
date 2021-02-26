#include <iostream>
#include "JsonFacade.hpp"       
#include <time.h>
#include <chrono> 
#include "Timer.hpp"            
#include "mygetch.hpp"
#include <fstream>

using namespace std;

/**
 * Node
 * 
 * Description:
 *      A node that holds 2 strings for a dictionary 
 * 		and a next pointer
 * 
 * Public Methods:
 *      string 					definition
 *		string 					Word
 *		Node* 					next	
 * 
 * Private Methods:
 *      None
 * 
 * Usage: 
 * 		Node Temp;				//Creates node
 *      
 */
struct Node
{
	string definition;			//holds def of word
	string Word;				//holds the word
	Node* next;					//pointer to a next node in the list
};

/**
 * ListDictionary
 * 
 * Description:
 *      A linked list that holds a dictionary and 
 * 		can search for substrings of chars
 * 
 * Public Methods:
 *      						ListDictionary() 
 *      void 					insert(string W, string D)
 *      void 					print()
 *		void 					search(string input) 
 * 		void 					printTenWords()
 * 		int 					getTermsFound()
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
 *      ListDictionary LL; 		//creates list
 * 		LL.insert("A", "B");	//adds a word A and a definition b to list
 * 		LL.print();				//prints the list to a Checking.txt file
 * 		LL.search("ste");		//searches list for words with substring ste
 * 		ll.printTenWords();		//prints top ten results from searching
 * 		ll.getTermsFound();		//returns the terms found from searching
 *      
 */
class ListDictionary
{
private:
	Node* Head;					//pointer to the head of the list
	Node* Tail;					//pointer to the tail of the list
	int length;					//length of the list
	string TenWords[10];		//top ten words found when searching the list
	int TermsFound;				//how many items found after searching list

public:
	
	/**
     * constructor : function_name
     * 
     * Description:
     *      loads private variables with default values
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      None
     */
	ListDictionary()
	{
		Head = nullptr;
		Tail = nullptr;
		length = 0;
		TermsFound = 0;
		for(int i = 0; i < 10; i++)
		{
			TenWords[i] = "ZZZ";
		}
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
	void insert(string W, string D)
	{
		Node* temp = new Node;
		temp->Word = W;
		temp->definition = D;
		temp->next = nullptr;
		if (Head == nullptr)
		{
			Head = temp;
			length++;
		}
		else if (Head->next == nullptr)
		{
			Tail = temp;
			Head->next = Tail;
			length++;
		}
		else
		{
			Tail->next = temp;
			Tail = temp;
			length++;
		}
		temp = nullptr;
	}

	/**
     * Public : print()
     * 
     * Description:
     *      prints the list onto a file "Checking.txt"
     * 
     * Params:
     *      none
     * 
     * Returns:
     *     None
     */
	void print()
	{
		ofstream outfile;
    	outfile.open("Checking.txt");
		Node* temp = new Node;	
		temp = Head;
		while (temp != nullptr)
		{
			outfile << '|' << temp->Word << "| -> (" << temp->definition 
				<< ")\n";
			temp = temp->next;
		}
		temp = nullptr;
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
	void search(string input)
	{
		int timeSeen = 0;
		Node* temp = new Node;	
		temp = Head;
		int i = 0;
		while (temp != nullptr)
		{
			string check = temp->Word;

			size_t found = check.find(input);

			if (found != string::npos)
			{
				if(i < 10)
				{
					TenWords[i] = temp->Word;
					i++;
				}
				timeSeen++;
			}

			temp = temp->next;
		}
		TermsFound = timeSeen; 
		temp = nullptr;
	}

	/**
     * Public : printTenWords()
     * 
     * Description:
     *      Prints the top 10 results from "search" to 
	 * 		the screen
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      None
     */
	void printTenWords()
	{
		bool printed = false;
		for(int i = 0; i < 10; i++)
		{
			if(TenWords[i] != "ZZZ")
			{
				printed = true;
				cout << TenWords[i] << " -> ";
			}
			else if(!printed)
			{
				cout << "No matches";
				printed = true;
			}
		}
		cout << '\n';
		for(int i = 0; i < 10; i++)
		{
			TenWords[i] = "ZZZ";
		}
	}

	/**
     * Public : getTermsFound()
     * 
     * Description:
     *      gets the amount of terms found from the search
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      return TermsFound	//the amount of terms found from search()
     */
	int getTermsFound()
	{
		return TermsFound;
	}
	

};

int main()
{
    Timer Load;                                 //timer used for loading list
    double TimeLoad;
    JsonFacade J("dict_w_defs.json");
    ListDictionary LList;                       //Linked list to hold dictionary

    char Typed;             
    string word = "";

    vector<string> keys = J.getKeys();           //list of words in alpha order

    Load.Start();
    for(int i = 0; i < keys.size(); i++)
    {
        string DicWord = J.getKey(i);            //gets terms in alpha order 0-X
        string DicDef = J.getValue(DicWord);     //gets def of term
        LList.insert(DicWord, DicDef);           //loads deg and term
    }
    
    Load.End();
    TimeLoad = Load.Seconds();                  //time in sec of loading

    cout << "To exit program press capital Z\n\n\n";

    while ((Typed = getch()) != 'Z') 
    {
        Timer T;                                  //makes timer for suggestion
        T.Start();
        word += Typed;                            //string for the chars typed

        

        if((int)Typed != 10)
        {                                         //if Typed is not a space print
            cout << word << "\n\n";
        }
        LList.search(word);                       //searches list for substrings

        T.End();
        double s = T.Seconds();                   //stores time of search

        cout << LList.getTermsFound() << " words found in: " << s 
            << " Seconds\n\n";

        LList.printTenWords();                    //prints top 10 results

        cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    }

    return 0;
}