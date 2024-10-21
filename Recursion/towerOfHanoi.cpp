#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void towerOfHanoi(int n,char src,char helper,char dest){
	if(n == 1){
		cout<<"Disk "<<n<<" is transferred from "<<src<<" to "<<dest<<endl;
		return;
	}

	towerOfHanoi(n-1,src,dest,helper);
	cout<<"Disk "<<n<<" is transferred from "<<src<<" to "<<dest<<endl;
	towerOfHanoi(n-1,helper,src,dest);
}


int main() {
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif  

    int n;
    cin>>n;

    towerOfHanoi(n,'S','H','D');  
}