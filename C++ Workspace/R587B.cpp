#include <bits/stdc++.h>
using namespace std;

int main(){


	int n;
	cin >> n;
	vector<pair<int, int>> dur;
	for(int i = 0; i < n;i ++){
		int a;
		cin >> a;
		dur.push_back(make_pair(a, i));
	}
	
	sort(dur.begin(), dur.end());
	
	vector<int> ans;
	int cost = 0;
	for(int i = n-1; i >= 0; i--){
		cost += dur[i].first*(n-1-i) + 1;
		ans.push_back(dur[i].second+1);
	}
	cout << cost << "\n";
	for(int i = 0; i < n; i++){
		
		cout << ans[i] << " ";
	}


}