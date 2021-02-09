#include <bits/stdc++.h>
#define ll long long;
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string x;
	cin >> x;
	string ch[] = {"", "", "2", "3", "322", "5", "53", "7", "7222", "7332"};
	vector<char> ans;
	for(int i =0;i < n; i++){
		string s = ch[x[i]-48];
		for(int j = 0; j < s.size(); j++){
			ans.push_back(s[j]);
		}
	}
	sort(ans.begin(), ans.end());
	while(ans.size() > 0){
		
		cout << ans.back();
		ans.pop_back();
	}

}