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
      return;
    }

    Node* temp = new Node(data);
    currSize++;
    if(last == NULL){
      temp->next = temp;
      last = temp;
    } else {
      temp->next = last->next;
      last->next = temp;
      last = temp;
    }
  }

  int dequeue(){
    if(isEmpty()){
      return -1;
    }

    currSize--;
    if(last->next == last){
      int ele = last->data;
      delete last;
      last = NULL;
      return ele;
    }

    int ele = last->next->data;
    Node* save = last->next;
    last->next = last->next->next;
    delete save;
    return ele;
  }

  bool isFull(){
    return size == currSize;
  }

  bool isEmpty(){
    return last == NULL;
  }

  void display(){
    if(last == NULL){
      return;
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
  int size, choice, value;
  cin >> size;
  Queue q(size);

  while(cin >> choice) {
    switch(choice) {
      case 1:
        cin >> value;
        q.enqueue(value);
        break;
      case 2:
        q.dequeue();
        break;
      case 3:
        q.display();
        break;
      default:
        return 0;
    }
  }
  return 0;
}
