# ```Push_swap```
*a 19 Coding School project*

This project goal is to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. Depending on the data, the most appropriate algorithm has to be chosen to optimise data sorting.

### Instruction set

Code	| Instruction			| Action
--------|-----------------------|----------------------------------------------
`sa`	| swap a				| swaps the 2 top elements of stack _a_
`sb`	| swap b				| swaps the 2 top elements of stack _b_
`ss`	| swap a & b			| both `sa` and `sb`
`pa`	| push a				| moves the top element of stack _b_ at the top of stack _a_
`pb`	| push b				| moves the top element of stack _a_ at the top of stack _b_
`ra`	| rotate a				| shifts all elements of stack _a_ from bottom to top
`rb`	| rotate b				| shifts all elements of stack _b_ from bottom to top
`rr`	| rotate a &  b			| both `ra` and `rb`
`rra`	| reverse rotate a		| shifts all elements of stack _a_ from top to bottom
`rrb`	| reverse rotate b		| shifts all elements of stack b from top to bottom
`rrr`	| reverse rotate a & b	| both `rra` and `rrb`

## How to use it

### Get the instructions to sort a given list:
```
make
./push_swap 1 5 2 4 3
pb
ra
pb
sa
pa
pa
```
### To check if the list is properly sorted:
First, one need to give the list to be sorted as an argument, and then write each instruction one per line (the checker program reads instructions from standard input).
```
make bonus
./checker 1 5 2 4 3
pb
ra
pb
sa
pa
pa
OK
```
### Doing both at the same time:
```
LIST="1 5 2 4 3"; ./push_swap $LIST | ./checker $LIST
```
or 
```
./run_test X
```
Where a list from _0_ to _X_ is shuffled and then passed as an argument to both `push_swap` and `checker`. 

## Results
- 5 items: ~7 moves,
- 100 items: ~650 moves,
- 500 items: ~5020 moves.

## Acknowledgements
- Stackoverflow's questions [Merge sort vs Quick sort](https://stackoverflow.com/questions/5222730/why-is-merge-sort-preferred-over-quick-sort-for-sorting-linked-lists)
- Stackoverflow's questions [Sorting 2 stack with a limited set of operations](https://stackoverflow.com/questions/33704858/sorting-2-linked-list-of-50000-numbers-with-a-limited-set-of-operations#)
- Dhanam Parekh's article [Sorting Algorithms: Slowest to Fastest!](https://medium.com/javarevisited/sorting-algorithms-slowest-to-fastest-a9f0e30937b9)

## License

Everything in this repository is released under the [Unlicense](https://github.com/maxdesalle/42/blob/main/LICENSE).
