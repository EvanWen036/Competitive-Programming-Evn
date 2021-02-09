#include <bits/stdc++.h>
using namespace std;


int main(){

	int N;
	string s;
	cin >> N;
	cin >> s;
	int pairs = 0;
	for(int i = 1; i < N; i++){
		if(s[i] == s[i-1]){
			pairs++;
		}
		
	}
	cout << pairs;
	

}