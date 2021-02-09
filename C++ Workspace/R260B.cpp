#include <bits/stdc++.h>
using namespace std;

int main(){

	string s;
	cin >> s;
	int tens = 0;
	if(s.length() >= 2){
		tens = (s[s.length()-2] - '0') * 10;
	}
	int ones = s[s.length()-1] - '0';
	cout << ((tens+ones)%4 == 0 ? 4:0);


}
