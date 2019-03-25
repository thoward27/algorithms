# Lab 08: Mancala Solitaire with Linked Lists

In this lab, you will implement a class called MancalaSolitaire, which internally uses a circular singly-linked list to "play a game" called Mancala Solitaire, given some input.  The goal of this lab is to give you a deeper understanding of the linked list data structure that you have been learning about. **This lab comes with starter code, provided in the files main.cpp, mancala.hpp and mancala.cpp**

### Visual Aids

Linked list. Contains data and a pointer to the next node.

![image](http://www.java2novice.com/images/linked_list.png)

Pictoral representation of adding a node to a linked list.

![image](http://www.java2novice.com/images/sll_insert_after.png)

Pictoral representation of removing a node from a linked list. Notice how the pointer just skips over the removed node.

![image](http://www.java2novice.com/images/sll_delete_after.png)

***IMPORTANT NOTE**: The tail node of a **circular** singly-linked list points to the head node instead of NULL.*  

## Mancala Solitaire

The game(\*) your algorithm will play/solve is based on a two-player game called Mancala, in which players take turns moving glass pieces amongst pits in a wooden board. Mancala Solitaire is a one-player game using the same mechanic.
 
#### Rules

You are given a board with N pits indexed 0 to N-1, each containing some number of pieces, and a starting index idx. You play the game by carrying out the following:

1. Take all the pieces out of the pit with index idx. This pit is now considered dead and will not receive pieces anymore.
2. Place one piece in each pit after the pit at index idx (wrapping from pit N-1 to pit 0)
3. Whichever pit receives the last piece is the new starting pit (its index is the new idx)
4. Repeat steps 1 through 3 until only one pit remains. This pit is the winning pit.

The starting index of the process is chosen to be 1 for this example. The pieces are removed from the pit at index 1 and the pit is removed from play.
The initial call of your solve should be done using 
```c++
int MancalaSolver::solve(int idx)
```
You should only call solve _once_.

The removal of pieces and the removal of the pit from play should both be done by the function

```c++
int MancalaSolver::removeByIndex(unsigned int idx);
```
Where idx is the index of the pit being operated on and the returned int is the number of pieces in that pit.

The image below represents the starting state of a game of Mancala Solitaire. Since the starting index i is 1, the game will start at the pit with index 1.

![Mancala Solitaire 1](/lab-08/mancala1.png "Mancala Solitaire 1")

The 3 pieces from the pit are distributed one-by-one following the pointer arrows.
The pit where the last piece was dropped is the next pit to be removed.

![Mancala Solitaire 2](/lab-08/mancala2.png "Mancala Solitaire 2")

The pieces from this pit are distributed in the same manner as the first pit.

![Mancala Solitaire 3](/lab-08/mancala3.png "Mancala Solitaire 3")

This process continues until there is only one pit remaining.
Once there is only one pit left, the index of that pit is returned.

![Mancala Solitaire 4](/lab-08/mancala4.png "Mancala Solitaire 4")

\*Although Mancala Solitaire is based on the game Mancala, it would probably be better described as a simulation as opposed to a game,  since there is no real winning or losing.

## Starter Code/Objective

#### Starter Code

The starter code for this lab is contained within the `mancala.hpp`, `mancala.cpp` and `main.cpp` files. You are given the entire class definition for `MancalaSolver`, which internally uses a circular singly-linked list to solve Mancala Solitaire, along with the entire implementation of the `Pit` class, which corresponds to the nodes in the linked list. You are also given implementations of `MancalaSolver`'s constructor, destructor, and print function.

*You should compile your code with the following line:*

```bash
g++ -g -std=c++11 mancala.cpp main.cpp -o main
```

Note that both mancala.cpp *and* main.cpp must be in the compile command, otherwise it will not work.

#### Input/Output

Your program will take a file `filename` which contains the number of pieces in each pit, the number of pits `N` and the starting index `idx`, and will output the index of the winning pit. Thus, your function will receive input as follows:

```bash
./main filename N idx
```

Given the file in.txt, which contains the integers (3, 3, 4, 3) each on a separate line, examples of correct input and output are as follows:

```bash
./main in.txt 4 1
2
./main in.txt 4 3
1
```

#### Objective

Your objective for this lab will be to do the following (preferrably in order):

1. Implement `MancalaSolver`'s `append` function.
2. Write the code to read the data from the file and create an instance of `MancalaSolver`.
3. Implement `removeAtIndex` and `solve`.
4. Call `solve` and output the index of the winning pit.

#### Questions

> What is the key advantage of using linked lists for functions such as append and removeByIndex over traditional arrays?

> What is the BigO runtime of append? What is the BigO runtime of removeByIndex?

#### Submission
Your **Gradescope** submission for this lab will include your `main.cpp` and `mancala.cpp` files containing your class and function implementations, as well as a file `lab-08.txt` containing your answers to the above questions

* If you did not finish the lab within the period you should submit the `mancala.cpp` and `main.cpp` files containing everything you were able to implement. 
* If you did not answer the questions for this week, submit a blank `lab-08.txt` file.
