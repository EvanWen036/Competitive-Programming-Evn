#include <bits/stdc++.h>
using namespace std;

int main(){

	string s;
	cin >> s;
	bool out = false;
	for(int i = 0; i < s.length(); i++){
		
		if(s[i] == 'H' || s[i] == 'Q' || s[i] == '9')out = true;
		
	}
	cout << (out ? "YES":"NO");
}