# Expression Tree Construction and Traversal

This project demonstrates the construction of an **expression tree** from an infix expression and performs a **level-order traversal** to display the structure of the tree. An expression tree is a binary tree where operands (variables or constants) are leaf nodes, and operators are internal nodes.

---

## Features
1. **Expression Parsing**:  
   Parses an infix expression (e.g., `a-b*c+d`) and constructs a binary expression tree based on operator precedence.

2. **Tree Construction**:  
   - Uses two stacks (`treeStack` and `operatorStack`) to handle operands and operators.
   - Supports standard operator precedence rules (`+`, `-`, `*`, `/`, `^`).

3. **Level-Order Traversal**:  
   Displays the tree structure in level order, showing the hierarchy of operators and operands.

4. **Null Child Representation**:  
   If a node does not have a left or right child, it displays `x` in place of the missing child.

---

## Implementation

### Key Components

1. **Tree Node Structure**:  
   Each node of the tree is represented using the following struct:
   ```cpp
   struct Tree {
       char data;
       Tree *left, *right;
       Tree(char data) {
           this->data = data;
           left = right = nullptr;
       }
   };
   ```

2. **Operator Precedence Function**:  
   A helper function to determine the precedence of operators:
   ```cpp
   int priority(char ch) {
       if (ch == '^') return 3;
       else if (ch == '*' || ch == '/') return 2;
       else if (ch == '+' || ch == '-') return 1;
       return -1;
   }
   ```

3. **Expression Parsing and Tree Construction**:  
   - Operands (e.g., `a`, `b`, `c`) are pushed directly onto the `treeStack`.  
   - Operators (e.g., `+`, `-`, `*`, `/`) are pushed onto the `operatorStack` based on precedence.  
   - When an operator is processed, it combines the top two nodes from `treeStack` into a subtree.

4. **Level-Order Traversal**:  
   Uses a queue to traverse and display the tree level by level, with `x` marking null children:
   ```cpp
   void levelOrderTraversal(Tree *node) {
       queue<Tree *> q;
       q.push(node);
       cout << node->data << endl;

       while (!q.empty()) {
           int size = q.size();
           for (int i = 0; i < size; i++) {
               Tree *top = q.front();
               q.pop();
               if (top->left) {
                   q.push(top->left);
                   cout << top->left->data << " ";
               } else {
                   cout << "x ";
               }
               if (top->right) {
                   q.push(top->right);
                   cout << top->right->data << " ";
               } else {
                   cout << "x ";
               }
           }
           cout << endl;
       }
   }
   ```

---

## Example Execution

### Input
The input expression is hardcoded in the `main` function:
```cpp
string expression = "a-b*c+d";
```

### Output
The program constructs the following expression tree:  
```
      +
     / \
    -   d
   / \
  a   *
     / \
    b   c
```

Level-order traversal output:
```
+ 
- d 
a * x x 
b c x x 
```

Here:
- `+` is the root operator.
- `a`, `b`, `c`, and `d` are operands.
- `x` represents null children.

---

## How to Run

1. **Compile the Program**:
   ```bash
   g++ expression_tree.cpp -o expression_tree
   ```

2. **Run the Program**:
   ```bash
   ./expression_tree
   ```

---

## Customization

- Modify the `expression` string in the `main` function to test other infix expressions.
- Ensure that the expression is valid and follows standard precedence rules.

---

## Notes

- The program assumes that the input is a valid infix expression consisting of single-character operands and standard operators.
- Future enhancements can include support for multi-character operands and parentheses.

---

## Author

Developed with C++ for educational purposes to demonstrate binary expression tree construction and traversal.