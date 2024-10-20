#include <bits/stdc++.h>
#include <iostream>
using namespace std;

template<typename T>

struct Stack {
public:
	T *arr;
	int size;
	int top;
	Stack(int size){
		this->size = size;
		arr = new T[size];
		this->top = -1;
	}

	void push(T x){
		if(top == size-1){
			cout<<"Stack overflow"<<endl;
			return;
		}

		arr[++top] = x;
	}

	T peek(){
		if(top == -1){
			return "";
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
    int n = exp.size();
    reverse(exp.begin(),exp.end());

    Stack<string> s(n+1);
    for(int i = 0;i<n;i++){
    	if(isalnum(exp[i])){
    		string k = "";
    		k+=exp[i];
    		s.push(k);
    	}
    	else{
    		string top1 = s.peek();
    		s.pop();
    		string top2 = s.peek();
    		s.pop();

    		s.push(top1 + top2 + exp[i]);
    	}
    }

    cout<<"After conversion "<<s.peek()<<endl;

}