#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Tree
{
  char data;
  Tree *left;
  Tree *right;
  Tree(char data)
  {
    this->data = data;
    left = right = nullptr;
  }
};

int priority(char ch)
{

  if (ch == '^')
  {
    return 3;
  }
  else if (ch == '*' || ch == '/')
  {
    return 2;
  }
  else if (ch == '+' || ch == '-')
  {
    return 1;
  }
  else
  {
    return -1;
  }
}

void inorder(Tree* node){
  if(!node) return;

  inorder(node->left);
  cout<<node->data<<" ";
  inorder(node->right);
}

int main()
{
  stack<Tree *> treeStack;
  stack<Tree *> operatorStack;

  string expression = "a-b*c+d";

  for (int i = 0; i < expression.length(); i++)
  {
    Tree *temp = new Tree(expression[i]);
    if ((expression[i] >= 'a' && expression[i] <= 'z') || (expression[i] >= 'A' && expression[i] <= 'Z'))
    {
      treeStack.push(temp);
    }
    else
    {
      if (operatorStack.empty())
      {
        operatorStack.push(temp);
      }
      else if (priority(expression[i]) > priority(operatorStack.top()->data))
      {
        operatorStack.push(temp);
      }
      else
      {
        Tree *top1 = treeStack.top();
        treeStack.pop();
        Tree *top2 = treeStack.top();
        treeStack.pop();

        Tree *operatorTop = operatorStack.top();
        operatorStack.pop();
        operatorTop->right = top1;
        operatorTop->left = top2;

        treeStack.push(operatorTop);
        operatorStack.push(temp);
      }
    }
  }

  while (operatorStack.size())
  {
    Tree *top1 = treeStack.top();
    treeStack.pop();
    Tree *top2 = treeStack.top();
    treeStack.pop();

    Tree *operatorTop = operatorStack.top();
    operatorStack.pop();
    operatorTop->right = top1;
    operatorTop->left = top2;

    treeStack.push(operatorTop);
  }
  
  inorder(treeStack.top());
  cout<<endl;
}
