#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define sz(a) a.size()
typedef long long ll;
typedef pair<int, int> pii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int cnt[25][25];
int dp[1 << 20];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	set<string> le;
	map<string, int> nl;
	for(int i = 0; i < s.length(); i++){
		le.insert(s.substr(i, 1));
	}
	int r = 0;
	for(auto it : le){
		//cout << it << " " << r << '\n';
		nl[it] = r++;
	}
	for(int i = 0; i < s.length()-1; i++){
		cnt[nl[s.substr(i,1)]][nl[s.substr(i+1,1)]]++;
		//cout << nl[s.substr(i,1)] << " " << nl[s.substr(i+1,1)] << '\n';
	}

	int let = le.size();
	for(int i = 1; i < (1 << let); i++)dp[i] = 1e9;
	dp[0] = 1;
	for(int i = 0; i < (1 << let); i++){
		//cout << i << " " << dp[i] << '\n';
		for(int j = 0; j < let; j++){
			if(!(i & (1 << j))){
				//cout << i << " " << j << "\n";
				int add = 0;
				for(int x = 0; x < let; x++){
					if(i & (1<<x)){
						add += cnt[j][x];
					}
				}
				add += cnt[j][j];
				int nm = i | (1 << j);
				//cout << i << " " << j << " " << add << '\n';
				//cout << i << " " << j << " " << nm << "\n";
				dp[nm] = min(dp[nm], dp[i] + add);
			}
		}
	}
	cout << dp[(1 << let)-1];
}
