#include <iostream>

using namespace std;

struct ListNode {
	int data;
	ListNode* next;

	ListNode(int data){
		this->data = data;
		this->next = NULL;
	}
};

ListNode* insertHead(ListNode* head,int data){
	ListNode* temp = new ListNode(data);
	temp->next = head;

	return temp;
}
	
ListNode* insertTail(ListNode* head,int data){
	ListNode* temp = new ListNode(data);
	if(head == NULL) return temp;
	ListNode* it = head;
	while(it->next){
		it = it->next;
	}

	it->next = temp;

	return head;
}

ListNode* insertAtPos(ListNode* head,int data,int pos){

	if(pos == 1){
		head = insertHead(head,data);
		return head;
	}

	int cnt = 1;
	ListNode* it = head;	
	while(it && cnt < pos-1){
		it = it->next;
		cnt++;
	}
	if(!it) return head;
	ListNode* temp = new ListNode(data);
	temp->next = it->next;
	it->next = temp;

	return head;
}

int countNodes(ListNode* head){
	int cnt = 0;
	ListNode* it = head;

	while(it){
		it = it->next;
		cnt++;
	}

	return cnt;
}

ListNode* deleteHead(ListNode* head){
	if(head == NULL) return head;
	ListNode* del = head;
	head = head->next;
	free(del);
	return head;
}

void display(ListNode* head){
	ListNode* it = head;

	while(it){
		cout<<it->data<<" ";
		it = it->next;
	}

	cout<<endl;
}

int main(){
	ListNode* head = new ListNode(10);
	head = insertHead(head,20);
	head = insertHead(head,30);

	head = insertAtPos(head,100,1);
	display(head);
}
