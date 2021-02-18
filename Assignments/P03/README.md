## Program 3 - Processing in Trie Tree Time

### Loic Konan

#### Description

This Program read in a dictionary file from dict_w_defs.json and store it in a Trie Tree.\
Define a wordNode to be a struct or a class to hold a word and definition.\
The binary tree hold wordNodes. It Time how long it takes to load the data \ into your binary search tree (we will use that later as well).
After the dictionary (tree) is loaded, it perform "autosuggestions" when a user types characters \ at the console.
Suggestions start after 1 character is typed, however only the top 10 suggestions \ will be printed along with the total number of matching words.\
The time it takes to find each suggestion will be displayed in seconds.

### Files

|  #  | File                                 | Description           |
| :-: | ------------------------------------ | --------------------- |
|  1  | [read_dict.cpp](read_dict.cpp)       |                       |
|  2  | [dict_w_defs.json](dict_w_defs.json) |                       |
|  3  | [Banner](Banner)                     | Banner for Assignment |
|  4  | [Timer.hpp](Timer.hpp)               |                       |
|  5  | []()                                 |                       |

### Instructions

- This program does not require any non standard libraries

### Example Command

-$ ./read_dict.cpp
