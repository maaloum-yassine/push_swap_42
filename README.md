<p align="center">
  <img src="https://github.com/mcombeau/mcombeau/blob/main/42_badges/push_swape.png" alt="Push_swap 42 project badge"/>
</p>

# Push_swap

## Description
**Push_swap** is a project from 42 School that consists of sorting a stack of numbers using a limited set of operations and a second stack. The goal is to sort the numbers with the minimum number of moves.

## Features
- Implements sorting using stack-based operations
- Efficient sorting algorithm for a given set of numbers
- Optimized for a minimal number of moves

## Allowed Operations
- `sa` (swap a): Swap the first two elements of stack A
- `sb` (swap b): Swap the first two elements of stack B
- `ss` (swap a and b): Swap the first two elements of both stacks
- `pa` (push a): Move the top element from stack B to stack A
- `pb` (push b): Move the top element from stack A to stack B
- `ra` (rotate a): Shift all elements of stack A up by one
- `rb` (rotate b): Shift all elements of stack B up by one
- `rr` (rotate a and b): Shift all elements of both stacks up by one
- `rra` (reverse rotate a): Shift all elements of stack A down by one
- `rrb` (reverse rotate b): Shift all elements of stack B down by one
- `rrr` (reverse rotate a and b): Shift all elements of both stacks down by one

## Usage
### Compilation
To compile the project, use:
```sh
make
```
This will generate the `push_swap` executable.

### Running the Program
Run the program with a list of numbers:
```sh
./push_swap 4 2 3 1 5
```
The program will output the sequence of operations needed to sort the numbers.

### Testing the Output
To check if the output is correct, you can use:
```sh
./push_swap 4 2 3 1 5 | ./checker 4 2 3 1 5
```
If the output is correct, the checker will print `OK`, otherwise `KO`.

## Example Output
### Input:
```sh
./push_swap 3 2 1
```
### Output:
```sh
pb
pb
sa
pa
pa
```

## Bonus
For the bonus part, you need to implement a **checker** program that reads the operations from standard input and applies them to verify if the stack is sorted.

### Running the Checker
```sh
./checker 3 2 1
```
Then, enter the operations manually or pipe them from `push_swap`:
```sh
./push_swap 3 2 1 | ./checker 3 2 1
```

## Restrictions
- No use of standard sorting functions
- The number of moves should be as minimal as possible
- Code must follow the 42 Norm

## Possible Improvements
- Implement an alternative sorting strategy
- Optimize for larger inputs
- Improve visualization tools
