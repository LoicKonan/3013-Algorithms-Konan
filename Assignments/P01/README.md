## Program 1 - Resizing the Stack

### Loic Konan

#### Description

This program will read numbers from the file  [nums_test.dat](nums_test.dat).
If a number is even, push it onto the stack.
If a number is odd, it will perform a pop operation removing the last even value from the stack.
The stack cannot get smaller than 10 (our starting stack size).
We need to keep track of the max size the stack ever reached,
how many times the stack was resized (grown or reduced) and
final size of stack when program completed.

### Files

|   #   | File                           | Description                          |
| :---: | ------------------------------ | ------------------------------------ |
|   1   | [main.cpp](main.cpp)           | The main cpp  (The Driver)           |
|   2   | [nums_test.dat](nums_test.dat) | Input file to test the code          |
|   3   | [commands.dat](commands.dat)   | Input file to test the code          |
|   4   | [nums.dat](nums.dat)           | Input file to test the code          |
|   5   | [output.txt](output.txt)       | The output file to print the results |


### Instructions

- This program does not require any non standard libraries

### Example Command

 You will be prompt to Enter the main file name, and the input file and the output file name.
>
> Example:
>>
        - $ ./ main.cpp
        - $ ./ nums_test.dat
        - $ ./ output.txt
