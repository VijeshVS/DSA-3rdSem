# Postfix Expression Evaluation using Stack

This program evaluates a postfix expression (using operators like `+`, `-`, `*`, `/`) with a custom stack implementation in C++. It reads a postfix expression, processes each operand and operator, and calculates the result.

## Sample Inputs and Outputs

### Example 1
**Input:** `53+82-*`

**Output:** `Expression is evaluated to 48`

### Example 2
**Input:** `23*54*+9-`

**Output:** `Expression is evaluated to 17`

### Example 3
**Input:** `921*-8-4+`

**Output:** `Expression is evaluated to 3`

The program reads each character of the postfix expression, pushes operands onto the stack, and, for each operator, pops the necessary operands to evaluate and push the result back on the stack. At the end, the final result is obtained by popping the last element from the stack.
