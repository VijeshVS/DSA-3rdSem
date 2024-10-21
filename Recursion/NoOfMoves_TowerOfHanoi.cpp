#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int towerOfHanoi(int n){
	if(n == 1){
		return 1;
	}

	int cnt1 = towerOfHanoi(n-1);
	int cnt2 = towerOfHanoi(n-1);
	
	return cnt1+cnt2+1;
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

    // 2^n - 1 moves in TowerofHanoi
    // Below function replicates the same
    int ans = towerOfHanoi(n);
    cout<<"No of moves to solve tower of hanoi are "<<ans<<endl;
}