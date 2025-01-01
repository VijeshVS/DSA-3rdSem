#include <iostream>

using namespace std;

int H[50];
int heapSize = -1;

int parent(int i){
    return (i-1)/2;
}

int rightChild(int i){
    return 2*i+2;
}

int leftChild(int i){
    return 2*i+1;
}

int shiftUp(int i){
    while(i > 0 && H[i] > H[parent(i)]){
        swap(H[i],H[parent(i)]);
        i = parent(i);
    }
}

int shiftDown(int i){

    int left = leftChild(i);
    int maxIndex = -1;

    while(left <= heapSize && H[left] > H[i]){
        maxIndex = left;
    }

    int right = rightChild(i);

    while(right <= heapSize && H[right] > H[i]){
        maxIndex = right;
    }

    if(i != maxIndex) {
        swap(H[i],H[maxIndex]);
        shiftDown(maxIndex);
    }
}

int insert(int data){
    heapSize += 1;
    H[heapSize] = data;

    shiftUp(heapSize);
}