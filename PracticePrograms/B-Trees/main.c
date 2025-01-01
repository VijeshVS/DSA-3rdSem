#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 3 // Maximum number of keys in a node
#define MIN (MAX + 1) / 2 // Minimum number of children in a node

typedef struct BPTreeNode {
    int keys[MAX]; // Array of keys
    struct BPTreeNode *children[MAX + 1]; // Array of child pointers
    bool isLeaf; // Is this a leaf node?
    int keyCount; // Number of keys in the node
    struct BPTreeNode *next; // Pointer to the next leaf node (used in leaf nodes)
} BPTreeNode;

BPTreeNode *root = NULL;

// Function to create a new node
BPTreeNode *createNode(bool isLeaf) {
    BPTreeNode *newNode = (BPTreeNode *)malloc(sizeof(BPTreeNode));
    newNode->isLeaf = isLeaf;
    newNode->keyCount = 0;
    newNode->next = NULL;
    for (int i = 0; i <= MAX; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

// Function to split a node
void splitChild(BPTreeNode *parent, int index) {
    BPTreeNode *child = parent->children[index];
    BPTreeNode *newChild = createNode(child->isLeaf);
    newChild->keyCount = MIN - 1;

    // Transfer keys to the new child
    for (int i = 0; i < MIN - 1; i++) {
        newChild->keys[i] = child->keys[i + MIN];
    }

    // Transfer children to the new child if the child is not a leaf
    if (!child->isLeaf) {
        for (int i = 0; i < MIN; i++) {
            newChild->children[i] = child->children[i + MIN];
        }
    }

    child->keyCount = MIN - 1;

    // Insert the new child into the parent
    for (int i = parent->keyCount; i > index; i--) {
        parent->children[i + 1] = parent->children[i];
    }
    parent->children[index + 1] = newChild;

    // Move the middle key up to the parent
    for (int i = parent->keyCount - 1; i >= index; i--) {
        parent->keys[i + 1] = parent->keys[i];
    }
    parent->keys[index] = child->keys[MIN - 1];
    parent->keyCount++;
}

// Function to insert a key into a non-full node
void insertNonFull(BPTreeNode *node, int key) {
    int i = node->keyCount - 1;

    if (node->isLeaf) {
        // Shift keys to make space for the new key
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->keyCount++;
    } else {
        // Find the child to insert the key into
        while (i >= 0 && key < node->keys[i]) {
            i--;
        }
        i++;

        // Split the child if it is full
        if (node->children[i]->keyCount == MAX) {
            splitChild(node, i);
            if (key > node->keys[i]) {
                i++;
            }
        }
        insertNonFull(node->children[i], key);
    }
}

// Function to insert a key into the B+ Tree
void insert(int key) {
    if (root == NULL) {
        // Create the root node if the tree is empty
        root = createNode(true);
        root->keys[0] = key;
        root->keyCount = 1;
    } else {
        if (root->keyCount == MAX) {
            // Split the root if it is full
            BPTreeNode *newRoot = createNode(false);
            newRoot->children[0] = root;
            splitChild(newRoot, 0);
            root = newRoot;
        }
        insertNonFull(root, key);
    }
}

// Function to search for a key in the B+ Tree
bool search(BPTreeNode *node, int key) {
    int i = 0;
    while (i < node->keyCount && key > node->keys[i]) {
        i++;
    }
    if (i < node->keyCount && key == node->keys[i]) {
        return true;
    }
    if (node->isLeaf) {
        return false;
    }
    return search(node->children[i], key);
}

// Function to print the B+ Tree
void printTree(BPTreeNode *node) {
    if (node != NULL) {
        for (int i = 0; i < node->keyCount; i++) {
            printf("%d ", node->keys[i]);
        }
        printf("\n");
        if (!node->isLeaf) {
            for (int i = 0; i <= node->keyCount; i++) {
                printTree(node->children[i]);
            }
        }
    }
}

// Main function
int main() {
    insert(10);
    insert(20);
    insert(5);
    insert(6);
    insert(12);
    insert(30);
    insert(7);
    insert(17);

    printf("B+ Tree:\n");
    printTree(root);

    int key = 6;
    if (search(root, key)) {
        printf("Key %d is present in the B+ Tree.\n", key);
    } else {
        printf("Key %d is not present in the B+ Tree.\n", key);
    }

    return 0;
}
