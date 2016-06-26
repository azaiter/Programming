HW5

Problem 1:

Create a doubly linked list in C++. The data section of each node holds one integer value.

Operations (handled by a menu) are:

1) Insert: at the beginning, at the end, in the middle (position is specified by number. e.g., 1 for insert at second position, 2 for insert at third position and so on), and into an empty list.

2) Delete: the head, the tail, any node in the middle (position is specified by number. e.g., 1 for delete the second node, 2 for delete the third node and so on), and from an one-node list.

3) Show: To view the data in nodes.

 

Problem 2:

Develop a C++ program to compute the result from a postfix (Inverse Polish Notation) mathematical expression using stack. The stack can be implemented by one char array. Max size of the stack is 30. 

The program will read the postfix notations from a file (say "input.txt") where each line represents one postfix notation. Your program will be able to handle multiple lines (for multiple postfix notations) and the file will end with a '0'. The outputs will be shown on monitor. The characters are single space-separated in each line.

 

Sample Input (will be taken from a file):

3  5  +  8  2  2  +  /  *  (the characters are single space-separated)

3  2  3  +  * 

0

Sample Output (shown on monitor):

16

15

 

Problem 3:

Write a Binary Search program in C++ using recursive function. The search will be applied on a sorted array (max. size 20). The array elements are to be taken from keyboard. Use of Recursion is mandatory.  

Sample Input:

2  5  78  99 (sorted integers separated by single space)

Enter the item to search: 6

Sample Output:

Item not found.

 

 Sample Input:

 -52  5  34  67  99

 Enter the item to search: 34

 

Sample Output:

 Item found.