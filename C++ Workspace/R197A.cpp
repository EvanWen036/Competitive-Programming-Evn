#include <bits/stdc++.h>
using namespace std;

int main(){

	string s;
	cin >> s;
	vector<int> num;
	for(int i = s.length()-1; i >= 0; i-= 2){
		num.push_back(s[i]-48);
	}
	sort(num.begin(), num.end());
	for(int i = 0; i < num.size(); i++){
		cout << num[i];
		if(i != num.size()-1)cout << "+";
	}


}