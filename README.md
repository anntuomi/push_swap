# push_swap
A sorting algorithm project where numbers get sorted using 2 stacks and certain actions.

This is a project done in Hive Helsinki where the aim is to sort a list of numbers using stacks A and B.
For the assignment, the following actions are available:

- sa / sb / ss:    Swaps around the two top numbers in stack a / stack b / both stacks.
- ra / rb / rr:    Shifts all values up in stack a / stack b / both stacks so that the top number
                 becomes the bottom number.
- rra / rrb / rrr: Shifts all values down in stack a / stack b / both stacks so that the bottom
                 number becomes the top number.
- a:              Pushes the top number in stack b to stack a.
- pb:              Pushes the top number in stack a to stack b.

The objective was to make 2 programs:

CHECKER
usage: ./checker (list of integers), for example ./checker 3 100 -1 0 2147483647
- Enter allowed commands (1 per line) and press ctrl + D.
Program will print OK if given commands sort the integer list, and KO if not.

PUSH_SWAP
usage: ./push_swap (list of integers):
- Produces a list of commands that sort the given list.

Can run the programs together like this:
ARG="-random numbers-"; ./push_swap $ARG | ./checker $ARG
To determine if the algorithm correctly sorts the numbers or not.

The algorithm didn't quite reach the top score with higher list sizes.
I reckon the problem is that I didn't do the sorting in any extra divisions when there are more numbers. I ran out of time, but if I hadn't, I would have optimized the algorithm that way.

Error codes for both programs(echo $? on mac after error):
- 1 - Memory allocation failure
- 2 - One or more of the arguments weren't a number
- 3 - One of the numbers was over or under integer limits
- 4 - List contained duplicate numbers
- 5 - Invalid command

File libft contains c library function copies made by me (including printf), in addition to some other useful ones.

In Hive we have to code C with certain limitations (to name a few):
- We can't use library functions (apart from malloc, free, write, read and exit)
unless we make one ourself
- Functions can only have up to 25 lines
- A .c file can only contain 5 functions
- Functions can only take 4 parameters and have 5 variable declarations
- No for loops or switch cases
- No comments inside function bodies
