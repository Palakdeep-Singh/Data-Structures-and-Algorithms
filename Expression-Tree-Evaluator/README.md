# Expression Tree Evaluator

## Overview
This project implements an **Expression Tree Evaluator** in C++ that constructs and evaluates arithmetic expressions using a **binary expression tree**.  
The program reads a postfix (Reverse Polish Notation) expression, builds a corresponding tree, and evaluates it recursively while displaying its **infix**, **prefix**, and **postfix** representations.

---

## Features
- Builds an **Expression Tree** from a postfix expression input.
- Evaluates the expression using **recursion** and **tree traversal**.
- Displays the expression in **infix**, **prefix**, and **postfix** formats.
- Includes input validation and error handling for malformed expressions.
- Demonstrates practical use of **stacks**, **trees**, and **recursion** in compiler-like operations.

---

## Technologies Used
- **Language:** C++  
- **Concepts:** Binary Trees, Recursion, Stacks, Expression Parsing  

---

## Input Format
- The program accepts a **postfix expression**, where tokens are separated by spaces.  
- Operands and operators must be entered in correct order.

**Example Input:**

```
3 4 + 2 * 7 /
```

---

## Sample Output

```
Expression Tree Evaluator

Enter postfix expression (tokens separated by spaces):
3 4 + 2 * 7 /

Infix Expression: ((3+4)*2)/7
Prefix Expression: / * + 3 4 2 7
Postfix Expression: 3 4 + 2 * 7 /

Evaluated Result: 2
```


---

## How to Run

### Using a local compiler (VS Code, Code::Blocks, etc.)
1. Save the file as `expression_tree_evaluator.cpp`.
2. Compile the program:
   ```bash
   g++ expression_tree_evaluator.cpp -o evaluator
3.Run the executable:
  ```
./evaluator
```

This project is licensed under the MIT License.
You are free to use, modify, and distribute it for educational or personal purposes.
