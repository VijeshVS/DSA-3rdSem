#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool checkSorted(int i,int cnt,vector<int> arr){
	if(i == arr.size()){
		if(cnt == arr.size()-1 || cnt == 0){
			return true;
		}

		return false;
	}

	if(arr[i] < arr[i-1]) cnt++;
	return checkSorted(i+1,cnt,arr);
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
    vector<int> arr(n,0);
    for(int i = 0;i<n;i++){
    	cin>>arr[i];
    }

   	bool ans = checkSorted(1,0,arr);

   	if(ans){
   		cout<<"YES"<<endl;
   	}else{
   		cout<<"NO"<<endl;
   	}   
}