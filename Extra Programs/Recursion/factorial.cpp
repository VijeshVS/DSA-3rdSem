#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int fact(int n){
	if(n == 0){
		return 1;
	}

	return n*fact(n-1);
}

int main() {
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("../input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("../output.txt", "w", stdout);
    #endif  

    int n;
    cin>>n;

    cout<<fact(n)<<endl;
}