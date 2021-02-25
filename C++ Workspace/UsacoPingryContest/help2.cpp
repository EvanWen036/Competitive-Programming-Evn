#include <bits/stdc++.h>
using namespace std;
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	string s;
	cin >> s;
	int ans = 0;
	//iterate through endpoints of substrings and test if they are equal
	for(int i = 0; i < N; i++){
		for(int j = i; j < N; j++){
			if(s[i] == s[j])ans++;
		}
	}
	cout << ans << '\n';

}
