#include <iostream>

using namespace std;

class Heap {
    public:
        int arr[100];
        int size;

        Heap(int size){
            this->size = size;
        }

        void insert(int value){
            arr[size++] = value;
            int index = size;
            while(index > 1){
                int parent = index/2;

                if(arr[parent] < arr[index]){
                    swap(arr[parent],arr[index]);
                    index = parent;
                }
            }
        }

};