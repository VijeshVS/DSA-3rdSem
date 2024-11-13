#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int gcd(int a,int b){
	if(a == 0) return b;
	if(b == 0) return a;

	if(a>b){
		return gcd(a%b,b);
	}

	return gcd(a,b%a);
}

int main() {
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("../input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("../output.txt", "w", stdout);
    #endif  

    int n,m;
    cin>>n>>m;  
    cout<<gcd(n,m)<<endl;
}