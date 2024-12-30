#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Tree {
    Tree* left;
    Tree* right;
    int data;

    Tree(int data){
        this->data = data;
        left = right = NULL;
    }
};

Tree* insertNode(Tree* root,int data){
    if(root == NULL){
        Tree* node = new Tree(data);
        return node;
    }

    if(root->data < data){
        root->right = insertNode(root->right,data);
    }
    else {
        root->left = insertNode(root->left,data);
    }

    return root;
}

int getMax(Tree *root){
    while(root->right != NULL) {
        root = root->right;
    }

    return root->data;
}

Tree* deleteNode(Tree* root,int data){
    if (root == NULL) {
        return NULL;
    }

    if(root->data == data){
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }
        else if(root->left == NULL && root->right != NULL){
            Tree* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->left != NULL && root->right == NULL){
            Tree* temp = root->left;
            free(root);
            return temp;
        }
        else {
            int maxi = getMax(root->left);
            root->data = maxi;
            root->left = deleteNode(root->left,maxi);
        }
    }

    if(root->data < data){
        root->right = deleteNode(root->right,data);
    }
    else {
        root->left = deleteNode(root->left,data);
    }

    return root;
}

void display(Tree* root){
    if(root == NULL) return;

    display(root->left);
    cout<<root->data<<" ";
    display(root->right);
}

int main(){
    Tree* root = NULL;
    root = insertNode(root,10);
    root = insertNode(root,70);
    root = insertNode(root,20);
    root = insertNode(root,90);
    root = insertNode(root,30);

    root = deleteNode(root,70);
    display(root);
}