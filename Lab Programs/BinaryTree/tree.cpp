#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Tree
{
  int data;
  Tree *left;
  Tree *right;
  Tree(int data)
  {
    this->data = data;
    left = right = nullptr;
  }
};

void inorder(Tree* node){
  if(!node) return;

  inorder(node->left);
  cout<<node->data<<" ";
  inorder(node->right);
}

Tree* constructTree(vector<int> &nums){
    if(nums.empty()) return NULL;

    queue<Tree*> q;
    Tree* root = new Tree(nums[0]);
    q.push(root);
    int i = 1;
    while(i < nums.size()){
        Tree* front = q.front();
        q.pop();
        if(i < nums.size()){
            Tree* node = new Tree(nums[i++]);
            front->left = node;
            q.push(front->left);
        }

        if(i < nums.size()){
            Tree* node = new Tree(nums[i++]);
            front->right = node;
            q.push(front->right);
        }
    }

    return root;
}

int countNodes(Tree* root){
    if(root == NULL){
        return 0;
    }

    int fs = countNodes(root->left);
    int ss = countNodes(root->right);

    return fs+ss+1;
}

int countLeafNodes(Tree* root){
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    int fs = 0;
    int ss = 0;

    if(root->left) fs = countLeafNodes(root->left);
    if(root->right) ss = countLeafNodes(root->right);

    return fs+ss;
}

int main(){
    vector<int> v = {2,34,22,11,6};
    Tree* root = constructTree(v);

    int nodes = countNodes(root);
    int leafNodes = countLeafNodes(root);
    
    cout<<"No of nodes "<<nodes<<endl;
    cout<<"No of leaf nodes "<<leafNodes<<endl;
    cout<<"Inorder: ";
    inorder(root);
}