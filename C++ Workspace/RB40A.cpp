#include <bits/stdc++.h>
using namespace std;

int main(){

	string s;
	string s2;
	cin >> s >> s2;
	
	for(int i = 0; i < s.length(); i++){
		if(s[i] != s2[s2.length()-i-1]){
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";

}