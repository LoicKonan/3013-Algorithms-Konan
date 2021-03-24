#include <iostream>
#include <time.h>
#include <chrono>
#include "Timer.hpp"
#include "mygetch.hpp"
#include <string>
#include <vector>
#include <fstream>
#include "termcolor.hpp"
#include <algorithm>

using namespace std;


// Define the character size
// #define CHAR_SIZE 128
#define CHAR_SIZE 26

bool isUpper(char letter) 
{
    int l = letter;
    return (l >= 65 && l <= 90);
}

bool isLower(char letter) 
{
    int l = letter;
    return (l >= 97 && l <= 122);
}

bool isLetter(char letter) 
{
    int l = letter;
    return isUpper(l) || isLower(l);
}

bool isAlphaOnly(string word) 
{

    for (int i = 0; i < word.length(); i++) 
    {
        if (!isLetter(word[i])) 
        {
            return false;
        }
    }
    return true;
}

void makeUpper(string &word) 
{
    for (int i = 0; i < word.length(); i++) 
    {
        if (isLower(word[i])) {
            word[i] -= 32;
        }
    }
}

struct TrieNode 
{
    bool isLeaf;
    TrieNode *character[CHAR_SIZE];
    string word;
    
    TrieNode() 
    {
        this->isLeaf = false;

        for (int i = 0; i < CHAR_SIZE; i++) 
        {
            this->character[i] = nullptr;
        }
    }
};

vector<char> countLetters(string filename) 
{
    ifstream fin;
    vector<char> alph;

    fin.open(filename);

    string word;
    while (!fin.eof()) 
    {
        fin >> word;
        for (int j = 0; j < word.size(); j++) 
        {
            if (std::find(alph.begin(), alph.end(), word[j]) == alph.end()) 
            {
                alph.push_back(word[j]);
            }
        }
    }
    return alph;
}

// A class to store a Trie node
class Trie 
{
    TrieNode *root;
    bool deletion(TrieNode *&, string);
    void find_all(TrieNode *&, string);
    vector<string> results;

public:
    Trie() 
    {
        root = new TrieNode;
    }
    void insert(string);
    bool deletion(string);
    bool search(string);
    bool haveChildren(TrieNode const *);
    vector<string> find_all(string);
};


void Trie::find_all(TrieNode *&curr,string key)
{
    if(curr->isLeaf){
        results.push_back(key);
    }

    for (int i = 0; i < 26; i++) {
        if(curr->character[i]){
            find_all(curr->character[i],key+char(i+65));
        }
    }
}

vector<string> Trie::find_all(string key)
{
    TrieNode* curr = root;

    results.clear();

    for (int i = 0; i < key.length(); i++) 
    {
        // go to the next node
        curr = curr->character[key[i] - 65];

    }

    find_all(curr,key);
    return results;
}

// Iterative function to insert a key into a Trie
void Trie::insert(string key) 
{
    makeUpper(key);

    // start from the root node
    TrieNode *curr = root;
    for (int i = 0; i < key.length(); i++) 
    {

        // create a new node if the path doesn't exist
        if (curr->character[key[i] - 65] == nullptr) {
            curr->character[key[i] - 65] = new TrieNode();
        }

        // go to the next node
        curr = curr->character[key[i] - 65];
    }

    // mark the current node as a leaf
    curr->isLeaf = true;
}

// Iterative function to search a key in a Trie. It returns true
// if the key is found in the Trie; otherwise, it returns false
bool Trie::search(string key) 
{
    makeUpper(key);
    TrieNode *curr = root;
    // return false if Trie is empty
    if (curr == nullptr) 
    {
        return false;
    }

    for (int i = 0; i < key.length(); i++) 
    {

        // go to the next node
        curr = curr->character[key[i] - 65];

        // if the string is invalid (reached end of a path in the Trie)
        if (curr == nullptr) 
        {
            return false;
        }
    }

    // return true if the current node is a leaf and the
    // end of the string is reached
    return curr->isLeaf;
}

// Returns true if a given node has any children
bool Trie::haveChildren(TrieNode const *curr) 
{
    for (int i = 0; i < CHAR_SIZE; i++) 
    {
        if (curr->character[i]) {
            return true; // child found
        }
    }

    return false;
}


bool Trie::deletion(string key) 
{
    makeUpper(key);
    return deletion(root, key);
}

// Recursive function to delete a key in the Trie
bool Trie::deletion(TrieNode *&curr, string key) 
{

    // return if Trie is empty
    if (curr == nullptr) 
    {
        return false;
    }

    // if the end of the key is not reached
    if (key.length()) 
    {
        // recur for the node corresponding to the next character in the key
        // and if it returns true, delete the current node (if it is non-leaf)

        if (curr != nullptr &&
            curr->character[key[0] - 65] != nullptr &&
            deletion(curr->character[key[0] - 65], key.substr(1)) &&
            curr->isLeaf == false) {
            if (!haveChildren(curr)) 
            {
                delete curr;
                curr = nullptr;
                return true;
            } 
            else 
            {
                return false;
            }
        }
    }

    // if the end of the key is reached
    if (key.length() == 0 && curr->isLeaf) 
    {
        // if the current node is a leaf node and doesn't have any children
        if (!haveChildren(curr)) 
        {
            // delete the current node
            delete curr;
            curr = nullptr;

            // delete the non-leaf parent nodes
            return true;
        }

        // if the current node is a leaf node and has children
        else 
        {
            // mark the current node as a non-leaf node (DON'T DELETE IT)
            curr->isLeaf = false;

            // don't delete its parent nodes
            return false;
        }
    }

    return false;
}


void loadDictionary(Trie *&T, string filename = "")
{
    string word;
    size_t found;
    ifstream fin;

    if (filename == "")
        fin.open("dictionary.txt");
    else
        fin.open(filename);

    Timer time;                             // Create a timer.
    time.Start();                           // Start the timer.

    while (!fin.eof()) 
    {
        fin >> word;
        if (isAlphaOnly(word)) 
        {
            T->insert(word);
        }
    }

     time.End();

       cout << termcolor::green << time.Seconds() << termcolor::reset 
         << " seconds to read in the 1st data." << endl;
}

void TestSearch(Trie *T, string word) 
{
    cout << word;
    if (T->search(word)) {
        cout << " found." << endl;
    } else {
        cout << " not found." << endl;
    }
}



// C++ implementation of Trie data structure
int main() 
{
    Trie *T = new Trie();
    vector<string> animals_Data;            // Placeholder animals_Data to read in the words.txt data

    cout << "loading dictionary..." << endl;
    loadDictionary(T, "dictionary.txt");


    char k;                                 // Hold the character being typed.
    string word = "";                       // Use to Concatenate letters.
    vector<string> Matches;                 // Any matches found in vector of animals_Data Words.

    string Top_Results[10];                 // Initializing 10 words to print.
    int SearchResults;                      // Initializing the integer SearchResults.

    cout << "Type keys and watch what happens. Type capital" 
         << termcolor::red << " Z to quit." << termcolor::reset << endl;

    while ((k = getch()) != 'Z')            // While capital Z is not typed keep looping.
    {
        if ((int)k == 127)                  // Tests for a backspace and if pressed deletes.
        {
            if (word.size() > 0)
            {
                word = word.substr(0, word.size() - 1);
            }
        }

        else
        {
            if (!isalpha(k))                // Making sure a letter was pressed.
            {
                cout << "Letters only!\n";
                continue;
            }

            if ((int)k >= 97)               // Making sure its lowercase.
            {
                k -= 32;                    // Make the input word  capital letters.
            }
        }
        word += k;                          // Append character to word.

        Timer Auto_Suggestion;              // Timer for (word suggestions and total words found).
        Auto_Suggestion.Start();  
        Matches = T->find_all(word);
        Auto_Suggestion.End();
        
        SearchResults = Matches.size();

        if ((int)k != 32)                   // When the key pressed is not "Space bar".
        {
            cout << "Keypressed: "     << termcolor::red   << k      << " = " 
                 << termcolor::green   << (int)k << termcolor::reset << endl;
            cout << "Current Substr: " << termcolor::red   << word 
                 << termcolor::reset   << endl;
            cout << termcolor::red     << SearchResults    << termcolor::reset 
                 << " words found in " << termcolor::green << Auto_Suggestion.Seconds() 
                 << termcolor::reset   << " seconds"       << termcolor::reset << endl;
           
            if (Matches.size() >= 10)       // Prints out the top 10 results.
            {
                for (int i = 0; i < 10; i++)
                {
                    Top_Results[i] = Matches[i];
                    cout << Top_Results[i] << " ";
                }
            }
            else
            {
                for (int j = 0; j < Matches.size(); j++)
                {
                    Top_Results[j] = Matches[j];
                    cout << Top_Results[j] << " ";
                }
            }

            cout << termcolor::reset << endl << endl;
        }
    }

    return 0;
}