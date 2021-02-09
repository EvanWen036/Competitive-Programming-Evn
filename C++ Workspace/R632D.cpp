#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	int pos[n];
	string s;
	cin >> s;
	for(int i = 0; i < n;i ++){
		pos[i] = (s[i] == 'L' ? 0:1);
	}
	bool sort = false;
	vector< vector<int> > ans;
	while(!sort){
		sort = true;
		vector<int> y;
		ans.push_back(y);
		for(int i = 0; i < n-1; i++){
			if(pos[i] == 1 && pos[i+1] == 0){
				pos[i] = 0;
				pos[i+1] = 1;
				ans[ans.size()-1].push_back(i+1);
				sort = false;
				i++;
			}
		}
	}
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i].size();
		for(int j = 0; j < ans[i].size(); j++){
			cout << " " << ans[i][j];
		}
	}


}