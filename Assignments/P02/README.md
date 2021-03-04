## Program 2 - Processing in Linear Time

### Loic Konan

#### Description

- This project is about loading a **singly linked list** with Animals names, Then perform "**autosuggestions**" when a user types characters at the console, the console will display the time it took to look them up.

  - Suggestions will start after **_1 character_** is typed.
  - Only the top **_10 suggestions_** will be printed along with the total number of matching words.
  - Matching suggestions will ONLY be words that match the **substring** starting from **_position zero_**.
  - As typing, the time it takes to find suggestions will be displayed in **_seconds_** with some **_color effects_**.

- We are doing this with the knowledge that this is slow, and we plan on applying our "lookup" code <br>
  to other backend data structures with better performance.

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
- $ ./animals.txt
- $  Z to terminate the program.
  
- **Example:**
  <img src="pic.owl" width="200" height= "200">
  <img src="pic.snake" width="200" height= "200">
  <img src="pic.rabbit" width="200" height= "200">
  <img src="pic.monkey" width="200" height= "200">



