#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
vector<int> lunlun;
void dfs(string curr, int pos){
	cout << curr << " " << pos << endl;
	if(pos == 6){
		for(int i = 1; i < curr.length(); i++){
			
			if(abs(curr[i] - curr[i-1]) > 1){
				return;
			}
		}
		int x = stoi(curr);
		lunlun.push_back(x);
		return;
	}
	for(int i = 0; i <= 10; i++){
		if(i != 10){
			curr += to_string(i);
		}
		if(pos == 0 && i == 0)continue;
		dfs(curr, pos+1);
	}
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	cin >>k;
	dfs("", 0);
	sort(lunlun.begin(), lunlun.end());
	cout << lunlun[k-1];
}
//100,000
