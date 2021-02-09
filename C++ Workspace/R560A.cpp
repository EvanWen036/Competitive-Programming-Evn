#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;
	
	vector<int> A(n);
	for(int &a : A){
		cin >> a;
	}
	sort(A.begin(), A.end());
	int max = 0;
	int k = 1;
	for(int i = 0; i < n; i++){
		if(A[i] >= k){
			max++;
			k++;
		}
		
	}
	cout << max;

}