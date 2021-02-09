#include <bits/stdc++.h>
#include<set>
using namespace std;

int main(){

	set<char> seen;
	string s;
	cin >> s;
	int distinct = 0;
	for(int i = 0; i < s.length(); i++){
		
		if(!seen.count(s[i])){
			distinct++;
			seen.insert(s[i]);
		}
		
	}
	cout << (distinct % 2 == 0 ? "CHAT WITH HER!" : "IGNORE HIM!");



}