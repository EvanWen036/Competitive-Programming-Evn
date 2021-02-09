#include <bits/stdc++.h>
using namespace std;

int main(){

	int n,m;
	cin >> n >> m;
	vector<long long> mod(5);
	for(int i = 1; i<= n; i++){
		mod[i%5]++;
	}
	vector<long long> mod2(5);
	for(int i = 1; i<=m; i++){
		mod2[i%5]++;
	}
	
	long long sum = 0;
	for(int i = 0; i <= 4; i++){
		sum += mod[i] * mod2[(5-i)%5];
	}
	cout << sum;


}