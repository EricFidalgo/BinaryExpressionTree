# Binary Expression Tree

**[→ View Project Page](https://ericfidalgo.github.io/portfolio/projects/BinaryExpressionTree)**

## Project Description

This project implements a Binary Expression Tree (BET) in C++. A BET is a specific application of a binary tree used to represent arithmetic expressions. Each leaf node in the tree is an operand (a number or a variable), and each internal node is an operator.

This implementation can:

- Construct a binary expression tree from a given postfix (Reverse Polish Notation) expression string.
- Validate the postfix expression to ensure it's well-formed.
- Print the equivalent infix expression, automatically adding parentheses where necessary to maintain the correct order of operations.
- Print the original postfix expression from the tree.
- Calculate the total number of nodes (operators and operands).
- Calculate the number of leaf nodes (operands).

The class is designed with proper memory management, including a destructor, a copy constructor, and a copy assignment operator to handle deep copying and prevent memory leaks.

## Technologies Used

- **Language:** C++
- **Core Libraries:** `<iostream>`, `<string>`, `<stack>`
- **Frameworks:** None
- **Tools:** g++ (or any standard C++ compiler)

## How to Run

Follow these steps to compile and run the project on a system with a C++ compiler like g++.

1.  **Prerequisites**

    - A C++ compiler (e.g., g++, Clang).

2.  **Compilation**
    Navigate to the project directory in your terminal and run the following command to compile the source files into an executable named `expression_tree`.

    ```bash
    g++ proj4_driver.cpp bet.cpp -o expression_tree
    ```

3.  **Execution**
    Run the compiled program with the following command:
    ```bash
    ./expression_tree
    ```
    The program will then prompt you to enter a postfix expression.

## Project Output

Here is an example of the program's execution flow and output:

```text
Enter the first postfix expression: a b + c d e + * *
Infix expression: ( a + b )* ( c * ( d + e ))
Postfix expression: a b + c d e + * * 
Number of nodes: 9
Number of leaf nodes: 5
Testing copy constructor: ( a + b )* ( c * ( d + e ))
Testing assignment operator: ( a + b )* ( c * ( d + e ))
Enter a postfix expression (or "quit" to quit): 4 5 6 * + 2 /
Infix expression: ( 4 + 5 * 6 )/ 2 
Postfix expression: 4 5 6 * + 2 / 
Number of nodes: 7
Number of leaf nodes: 4
Enter a postfix expression (or "quit" to quit):
```
