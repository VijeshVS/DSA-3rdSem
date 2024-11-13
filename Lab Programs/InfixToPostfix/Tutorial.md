# Infix to Postfix Conversion using Stack

This program converts an infix expression (with operators like `+`, `-`, `*`, `/`, and `^`) to a postfix expression using a custom stack implementation in C++. Below are some sample inputs and outputs for better understanding.

## Sample Inputs and Outputs

### Example 1
**Input:** `A+B*(C^D-E)`

**Output:** `Postfix expression is ABCD^E-*+`

### Example 2
**Input:** `(A-B/C)*(A/K-L)`

**Output:** `Postfix expression is ABC/-AK/L-*`

### Example 3
**Input:** `X^Y/(A*B)+C`

**Output:** `Postfix expression is XY^AB*/C+`

The program reads the infix expression, manages operator precedence, and handles parentheses using a stack to produce the correct postfix expression.
