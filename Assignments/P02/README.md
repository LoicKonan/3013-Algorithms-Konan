## Program 2 - Processing in Linear Time

### Loic Konan

#### Description

This project is about loading a **singly linked list** with Animals names, Then perform "**autosuggestions**" when a user types characters at the console, the console will display the time it took to look them up.<br>
Suggestions will start after ***1 character*** is typed, however only the top ***10 suggestions*** will be printed along with the total number of matching words.<br>
>
  - Matching suggestions will ONLY be words that match the substring starting from ***position zero***.
  - As typing, the time it takes to find suggestions will be displayed in ***seconds***.
  - We are doing this with the knowledge that this is slow, and we plan on applying our "lookup" code <br>
  - to other backend data structures with better performance.

### Files

|  #  | File                           | Description                              |
| :-: | ------------------------------ | ---------------------------------------- |
|  1  | [main.cpp](main.cpp)           | The main cpp file.                       |
|  2  | [Banner](Banner)               | Banner for Assignment                    |
|  3  | [Timer.hpp](Timer.hpp)         | Timer helper class                       |
|  4  | [mygetch.hpp](mygetch.hpp)     | Get character, without printing it .     |
|  5  | [animals.txt](animals.txt)     | Animals names ... lots of animals names. |
|  6  | [termcolor.hpp](termcolor.hpp) | Class to color text                      |

### Instructions

- $ ./main.cpp

- **Example:** cat would match cat, caterpillar, and cattle. But NOT wildcat.
