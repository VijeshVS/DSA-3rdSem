#include <bits/stdc++.h>
#include <iostream>

using namespace std;

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

int priority(char s){
	if(s == '^'){
		return 3;
	}
	else if(s == '*' || s == '/'){
		return 2;
	}
	else if(s == '+' || s == '-'){
		return 1;
	}
	else {
		return -1;
	}
}

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
    Stack s(n+1);

    string ans = "";

    for(int i = 0;i<n;i++){
    	if(isalnum(exp[i])){
    		ans += exp[i];
    	}
    	else if(exp[i] == '('){
    		s.push(exp[i]);
    	}
    	else if(exp[i] == ')'){
    		while(s.peek() != '('){
    			char ch = s.peek();
    			ans += ch;
    			s.pop();
    		}
    		s.pop();
    	}
    	else {
    		if(s.isEmpty()){
    			s.push(exp[i]);
    		}
    		else if(priority(exp[i]) > priority(s.peek())){
    			s.push(exp[i]);
    		}
    		else{
    			while(!s.isEmpty() && priority(exp[i]) <= priority(s.peek())){
    				char ch = s.peek();
    				ans += ch;
    				s.pop();
    			}
    			s.push(exp[i]);
    		}
    	}
    }

    while(!s.isEmpty()){
    	char ch = s.peek();
    	ans += ch;
    	s.pop();
    }

    cout<<"Postfix expression is "<<ans<<endl;
}