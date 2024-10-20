#include <bits/stdc++.h>
using namespace std;
#include <iostream>

struct Stack {
public:
	int *arr;
	int size;
	int top;
	Stack(int size){
		this->size = size;
		arr = new int[size];
		this->top = -1;
	}

	void push(int x){
		if(top == size-1){
			cout<<"Stack overflow"<<endl;
			return;
		}

		arr[++top] = x;
	}

	int peek(){
		if(top == -1){
			return -1;
		}

		return arr[top];
	}

	void pop(){
		if(top == -1){
			cout<<"Stack Underflow"<<endl;
			return;
		}

		--top;
	}

	bool isEmpty(){
		if(top == -1){
			return true;
		}
		
		return false;
	}

};

int main() {
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif  

    string exp;
    cin>>exp;
    int n = exp.length();
    reverse(exp.begin(),exp.end());
    Stack s(n+1);

 	for(int i = 0;i<n;i++){
 		if(isdigit(exp[i])){
 			s.push(exp[i]-'0');
 		}
 		else{
 			char op = exp[i];
 			int top1 = s.peek();
 			s.pop();
 			int top2 = s.peek();
 			s.pop();
 			int ans;

 			switch(op){
 			case '+':
 				ans = top1 + top2;
 				break;
 			case '-':
 				ans = top1 - top2;
 				break;
 			case '*':
 				ans = top1*top2;
 				break;
 			case '/':
 				ans = top1/top2;
 				break;
 			}

 			s.push(ans);
 		}
 	}

 	int ans = s.peek();

 	cout<<"Expression is evaluated to "<<ans<<endl;
}