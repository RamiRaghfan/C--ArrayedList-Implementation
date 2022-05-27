-------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------
A hybrid between arrays and lists. 

REQUIRES A C++ COMPILER g++ OR IDE TO WORK/TEST
-------------------------------------------------------------------------------------

ArrayedList.h function descriptions:

Constructor
ArrayedList

Initilizes members

-------------------------------------------------------------------------------------


Cell<T> createNode(T x)

creates a new Cell<T> node and intilizes all of its members, 
appends x to the beginning of its array

returns a reference to the new node
-------------------------------------------------------------------------------------

void add(T x)

if list is empty, adds element to head and tail, othewise, appends data x to tail's array.
if tail's array is full, a new node Cell<T> is created, and data x will be added to the beginning of the new node. 

-------------------------------------------------------------------------------------

T getElement(int idx)

traverses the list node by node starting from head, on each node the array is also traversed.
Between each array iteration, a counter is incrementing until it reaches idx. 
when it reaches idx the element at position idx will be returned, if it doesn't exist control will reach end of the function and return an error.

-------------------------------------------------------------------------------------

void remove(int idx)

Searches for the array element to remove and removes it if it's found, exits if not found.
after it is removed all the arrays of the whole list are shifted to the left to keep all list nodes filled anywhere before tail node

If the node that we extract an element from for shifting becomes empty, it is deallocated and all pointers to it are set to NULL.

-------------------------------------------------------------------------------------

void display()

Prints all elements in every node like a table form, for each node the array will be printed on a new line.
-------------------------------------------------------------------------------------

void removeFromCell(Cell<T> *node, int idxRemove)

Helper function to remove an element from node, given a pointer to the node and an index to remove.
------------------------------------------------------------------------------------- 

void shiftAllNodes(Cell<T> *start)

Given a pointer to a node, it will begin "shifting" all the arrays of the nodes until tail starting from the given pointer.

It takes the first element of the array of the next node and inserts into the end of the array of current node, then it will remove the taken element from the next node using removeFromCell(). This will repeat and the end of the list is reached.

-------------------------------------------------------------------------------------