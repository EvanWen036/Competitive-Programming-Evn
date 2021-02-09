#include <bits/stdc++.h>
#include<vector>
#include<algorithm>
#include<iostream>
#include<cassert>
using namespace std;

int main(){

	int t;
	cin >> t;
	while(t--){
		
		int n;
		cin >> n;
		vector<int> A(n);
		for(int i = 0; i < n; i++){
			int a;
			cin >> a;
			A.push_back(a);
		}
		sort(A.rbegin(), A.rend());
		for(int i = 0; i < n; i++){
			cout << A[i];
			if(i < n-1){
				cout << " ";
			}else{
				cout << "\n";
			}
		}
		
		
	}
}
