## Program 1 - Resizing the Stack

### Loic Konan

#### Original Description:
- The stack implementation has a Resize method that ONLY will make the stack larger as we add items.
- This means that the stack will never shrink if we remove many items.
- We should probably remedy this issue.
- Too Full = 100% meaning no extra slots available in your array.
- Too Empty = 15% meaning in a stack of 100, if you get down to 15 items you need to shrink your stack.
- Enlarging = Double the size of the stack.
- Shrinking - Cut the size of the stack in half.

### Testing Your Code
- You will read numbers from the file [nums_test.dat](nums_test.dat).
- If a number is even, push it onto the stack.
- If a number is odd, perform a pop operation removing the last even value from the stack.
- Don't let your stack get smaller than 10 (our starting stack size).
- You need to keep track of the following:
> - **the max size the stack ever reached**
> - **how many times the stack was resized (grown or reduced)**
> - **final size of stack when program completed**

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
