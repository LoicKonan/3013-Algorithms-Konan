## Program 1 - Resizing the Stack

### Loic Konan

#### Description:
This program will read numbers from the file [nums.dat](nums.dat).
If a number is even, push it onto the stack.
If a number is odd, it will perform a pop operation removing the last even value from the stack.
The stack cannot get smaller than 10 (our starting stack size).
We need to keep track of the max size the stack ever reached,
how many times the stack was resized (grown or reduced) and
final size of stack when program completed.

### Files

|   #   | File                             | Description                                            |
| :---: | -------------------------------- | ------------------------------------------------------ |
|   1   | [main.cpp](main.cpp)             | The main cpp  (The Driver)                             |
|   2   | [nums.dat](nums.dat)             | The input file to test the code                        |
|   3   | [output.txt](output.txt)         | The output file to print the results                   |
|   4   | [ArrayStack.cpp](ArrayStack.cpp) | Where the member functions are all define              |
|   5   | [ArrayStack.h](ArrayStack.h)     | Header file Where the member functions are all declare |

### Instructions

- This program does not require any non standard libraries

### Example Command
 Enter the main file name, then the input file and the output file.
        - Example:
        - $ ./ main.cpp
        - $ ./ nums_dat
        - $ ./ output.txt