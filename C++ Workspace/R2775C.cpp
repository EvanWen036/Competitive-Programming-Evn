#include <bits/stdc++.h>
#define ll long long;
using namespace std;

bool can(int m, int s){
	return s >= 0 && s <= 9 *m;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int m, s;
	cin >> m >> s;
	string num1;
	string num2;
	int sum = s;
	for(int i = 0; i < m; i++){
		for(int d = 0; d < 10; d++){
			if((i > 0 || d > 0 || (m==1 && d == 0)) && can(m-i-1, sum-d)){
				num1 += to_string(d);
				sum -= d;
				break;
			}
		}
	}
	sum = s;
	for(int i = 0; i < m; i++){
		for(int d = 9; d >= 0; d--){
			if((i > 0 || d > 0 || (m ==1 && d == 0)) && can(m-i-1, sum-d)){
				num2 += to_string(d);
				sum -= d;
				break;
			}
		}
	}
	if(num1.length() == m){
		cout << num1;
	}
	else{
		cout << -1;
	}
	cout << " ";
	if(num2.length() == m){
		cout << num2;
	}
	else{
		cout << -1;
	}
	
}