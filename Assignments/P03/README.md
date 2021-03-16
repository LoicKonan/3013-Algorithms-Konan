## Program 3 - Processing in Tree Time

### Loic Konan

#### Description

This Project is about loading a Binary Search Tree with words, then timing how it takes to look them up,
it will perform **"autosuggestions"** when a user types characters at the console.
Suggestions start after **1 character** is typed, however only the top **10 suggestions**
will be printed along with the total number of **matching words**.
The time it takes to find each suggestion will be displayed in **seconds**.

### Files

|  #  | File                                 | Description                                         |
| :-: | ------------------------------------ | --------------------------------------------------- |
|  1  | [read_dict.cpp](read_dict.cpp)       | Example json reader with some timing.               |
|  3  | [Banner](Banner)                     | Banner for Assignment                               |
|  4  | [Timer.hpp](Timer.hpp)               | Timer helper class                                  |
|  5  | [JsonFacade.hpp](JsonFacade.hpp)     | Json helper class                                   |
|  6  | [json.hpp](json.hpp)                 | Json class written by nlohmann                      |

### Instructions

- This program does not require any non standard libraries

### Example Command

-$ ./main.cpp
