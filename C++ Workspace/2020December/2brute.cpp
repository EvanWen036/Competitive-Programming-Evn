#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int ans = 0;
string curr = "";
int len = 0;
string genes[4] = {"A","C","G","T"};
string normal = "";
int mod = 1000000007;
void go(int pos){
	if(pos == len){
		//cout << curr << '\n';
		int prev = 0;
		string transl = "";
		vector<int> partitions;
		for(int i = 1; i < curr.length(); i++){
			if(curr[i] == curr[i-1]){
				partitions.pb(i);
			}
		}
		partitions.pb(curr.length());
		for(int u : partitions){
			int current = u-1;
			string sub = curr.substr(prev, (current-prev+1));
			reverse(sub.begin(), sub.end());
			transl += sub;
			prev = u;
		}
		//cout << transl << '\n';
		for(int i = 0; i < transl.length(); i++){
			if(transl[i] != normal[i] && normal[i] != '?'){
				return;
			}
		}
		ans++;
		ans %= mod;
		return;
	}
	for(int i = 0;i  < 4;i ++){
		curr += genes[i];
		go(pos+1);
		curr = curr.substr(0, curr.length()-1);
	}

}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> normal;
	//cout << normal << '\n';
	len = normal.length();
	go(0);
	cout << ans << '\n';


}
