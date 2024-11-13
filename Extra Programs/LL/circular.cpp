#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next;

  Node(int data){
   this->data = data;
   this->next = nullptr;
  }
};

Node* insertFirst(Node* last,int data){
  Node* temp = new Node(data);

  if(last == NULL) {
    temp->next = temp;
    return temp;
  }
  
  temp->next = last->next;
  last->next = temp;
  
  return temp;
}

Node* deleteFirst(Node* last){
  if(last == NULL) return NULL;

  if(last->next == last){
    free(last);
    return NULL;
  }

  Node* save = last->next;
  last->next = last->next->next;
  free(save);

  return last;
}

Node* deleteLast(Node* last){
  if(last == NULL) return NULL;

  Node* it = last;

  if(it->next == it){
    free(it);
    return NULL;
  }

  while(it->next != last){
    it = it->next;
  }

  Node* save = it->next;
  it->next = it->next->next;

  free(save);

  return it;
}

void display(Node *last){
  if(last == NULL) return;
  
  Node* it = last->next;
  Node* head = last->next;

  do {
    cout<<it->data<<"-->";
    it = it->next;
  } 
  while(it != head);

  cout<<"head"<<endl;
}

int main(){
  Node* last = NULL;
  last = insertFirst(last,10);
  last = insertFirst(last,20);
  last = insertFirst(last,40);
  last = insertFirst(last,50);
 
  display(last);

   
  last = deleteLast(last);
  last = deleteFirst(last);
  display(last);
} 
