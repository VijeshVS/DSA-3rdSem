#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Poly{
	int data,power;
	Poly* next;

	Poly(int data,int power){
		this->data = data;
		this->power = power;
	}
};

Poly* convertArrToPoly(vector<int> arr){
	int n = arr.size();
	Poly* head = new Poly(arr[0],n-1);
	Poly* it = head;
	
	for(int i = 1;i<n;i++){
		Poly* temp = new Poly(arr[i],n-i-1);
		it->next = temp;
		it = it->next;	
	}	

	return head;
}

Poly* multiply(Poly* pol1,Poly* pol2){
	Poly* pol3 = NULL;
	Poly* it1 = pol1;
	Poly* it2 = pol2;
	Poly* it3 = pol3;

	while(it1){
		while(it2){
			Poly* temp = new Poly(it1->data*it2->data,it1->power+it2->power);
			if(pol3 == NULL){
				pol3 = temp;
				it3 = temp;	
			}
			else {
				it3->next = temp;
				it3 = it3->next;
			}
			it2 = it2->next;
		}
		it2 = pol2;
		it1 = it1->next;
	}

	return pol3;
}

Poly* reducePoly(Poly* pol,int degree){
	Poly* ans = NULL;
	Poly* it = ans;	
	while(degree >= 0){
		Poly* temp = new Poly(0,degree);
		if(ans == NULL){
			ans = temp;
			it = ans;	
		}
		else{
			it->next = temp;
			it = it->next;
		}

		Poly* k = pol;
		while(k){
			if(k->power == degree){
				temp->data += k->data;
			}
			k = k->next;
		}

		degree--;
	}
	
	return ans;
}

void display(Poly* head){
	Poly* it = head;

	while(it){
		cout<<it->data<<"|"<<it->power;
		it = it->next;
		cout<<" --> ";
	}

	cout<<"x";
	cout<<endl;
}

int main(){
	vector<int> arr1 = {1,2,1};
	vector<int> arr2 = {3,1};

	Poly* pol1 = convertArrToPoly(arr1);
	Poly* pol2 = convertArrToPoly(arr2);

	display(pol1);
	display(pol2);
	Poly* pol3 = multiply(pol1,pol2);
	display(pol3);
	int highestDegree = arr1.size()+arr2.size()-2
	Poly* ans = reducePoly(pol3,highestDegree);
	display(ans);
}
