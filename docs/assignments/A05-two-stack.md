# Assignment 05: Stacks / Queues  

For this assignment you will be building a program to evaluate fully parenthesized arithmetic expressions using Djikstra's Two Stack Algorithm for expression evaluation.

## The Algorithm

Djikstra's two stack algorithm is a way to evaluate fully parenthesized infix expressions.

- Infixed expressions are those where the operators are placed between two operands, (2 + 4) is an infix expression.
- Full parenthesized means that every operator and it's operands are contained in parentheses, which means precedence and associativity do not matter.

An example expression:

$$((5 + ((10 - 4) * (3 + 2))) + 25)$$

For each element in the expression, the following rules are applied:

| Element           | Action                                                                                                                         |
| ----------------- | ------------------------------------------------------------------------------------------------------------------------------ |
| Operand           | Push to stack 1                                                                                                                |
| Operator          | Push to stack 2                                                                                                                |
| Left Parenthesis  | Ignore                                                                                                                         |
| Right Parenthesis | Pop an operator from stack 2 and two values from stack 1; apply the operator to the two operands; pushed the result to stack 1 |

Using only these simple rules, and two functioning stacks, you can solve any infix fully parenthesized expression!

## Instructions

This assignment will be hosted on Github Classroom.

1. Register for the assignment on our Github Classroom using [this link](https://classroom.github.com/a/jQi18jXV)
   1. Be sure to select your name from the list to link your Github to the class roster!
2. Clone the repository to your machine
   1. Open a terminal
   2. Navigate to your algorithms folder
   3. Go to the parent directory (`cd ..`)
   4. Clone the repository to this location (`git clone <your repository link here>`)
      1. Be sure to use the link for **your copy** of the repository for the assignment
3. Getting things in order
   1. Open your new folder in VS Code
   2. In your folder you should have: `calculator.cpp`, `source/Algorithms/twostack.hpp`, `source/Linear/Stack.test.cpp` and `source/Linear/Stack.cpp`.
   3. Check that you can compile and run your calculator program `make calculator`
   4. Check that you can compile and run the Two Stack starter code `make twostack`
      1. Ensure that your test cases fail.
4. Implement the `main` function (30 points)
   1. Following the pseudocode in `calculator.cpp`, implement the main function for your calculator.
5. Implement the algorithm (60 points)
   1. Write pseudocode for your algorithm
   2. Commit and push this pseudocode (`git add . && git commit -m "<message>" && git push`)
      1. Check that your pseudocode uploaded, and is visible on the master branch of your assignment.
   3. Implement the Stack datatype, as it is not provided.
   4. Implement your pseudocode in C++
   5. Pass all unit tests
   6. Commit and push your code (`git add . && git commit -m "<message>" && git push`)
      1. Check that all of your working code is uploaded, and visible on the master branch of your assignment.
6. Analyze your work (10 points)
   1. Provide your algorithms' Big-Oh notation as a function of expression length.

## Grading

| Criteria      | Points |
| ------------- | ------ |
| Functionality | 70     |
| Analysis      | 10     |
| Quality       | 20     |

## Submission

To submit this assignment, simply commit and push your work to your assignment repository.
Your last submission before the deadline will be graded.
