#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next;

  Node(int data){
    this->data = data;
    this->next = NULL;
  }
};

struct Queue {
  Node* last;
  int size,currSize;
  
  Queue(int size){
    this->size = size;
    this->currSize = 0;
    last = NULL;
  }

 
  void enqueue(int data){
    if(isFull()) {
      cout<<"Queue overflow"<<endl;
      return;
    }

    Node* temp = new Node(data);
    currSize++;
    if(last == NULL){
      temp->next = temp;
      last = temp;
    }

    temp->next = last->next;
    last->next = temp;

    last = temp;
  }

  int dequeue(){
    if(isEmpty()){
      cout<<"Queue underflow"<<endl;
      return -1;
    }

    currSize--;
    if(last->next == NULL){
      int ele = last->data;
      free(last);
      return ele;
    }

    int ele = last->next->data;
    Node* save = last->next;
    last->next = last->next->next;
  }

  bool isFull(){
    if(size == currSize) return true;
    return false;
  }

  bool isEmpty(){
    if(last == NULL) return true;
    return false; 
  }

  void display(){
    if(last == NULL){
      cout<<"List is empty"<<endl;
    }

    Node* it = last->next;
    do {
      cout<<it->data<<" ";
      it = it->next;
    }
    while(it != last->next); 
    cout<<endl;
  }
  
};

int main(){
  Queue q(5);
  q.enqueue(10);
  q.enqueue(30);
  q.enqueue(30);
  q.enqueue(30);
  q.enqueue(30);
  q.display();
  q.dequeue();
  q.dequeue();
  q.display();
}
