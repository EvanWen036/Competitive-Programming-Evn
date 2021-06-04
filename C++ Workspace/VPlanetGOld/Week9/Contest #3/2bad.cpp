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
int n, k;
vector<pii> adj[105];
int dp[105][55][2];
multiset<int> carries[105][55][2];
int l[105];
int ck = 0;
int cz = 0;
int go(int u, int kt, int po){
	if(po >= adj[u].size())return 0;
	//cout << po << endl;
	for(int i = 0; i <= min(kt, 1 + (int)adj[adj[u][po].f].size()); i++){
		//cout << adj[u][po].f << endl;
		//take i from here
		/**
		if(dp[adj[u][po].f][i][0] < dp[adj[u][po].f][i][1]){
			//deal with carries
			int cst = dp[adj[u][po].f][i][0];
			for(auto it : carries[adj[u][po].f][i][0]){
				cst += it * adj[u][po].s;
				if(cz == 0){
					carries[u][ck][cz].insert(it);
				}
			}

			return cst + go(u, kt-i, po+1);
		}
		
			//no carries needed from here
		return dp[adj[u][po].f][i][1] + go(u, kt-i, po+1);
		**/
		int cst = go(u, kt-i,po+1);

	}
	assert(false);
}
void dfs(int u){
	//cout << u << endl;
	for(auto it : adj[u]){
		dfs(it.f);
	}
	if(adj[u].size() == 0){
		//base case
		dp[u][1][1] = 0;
		dp[u][0][0] = 0;
		carries[u][0][0].insert(l[u]);
	}
	else{
		for(int i = 0; i <= min(k, 1 + (int)adj[u].size()); i++){
			for(int j = 0;j < min();j ++){
				//cout << u << " " << i << " " << j << endl;
				ck = i;
				cz = j;

				dp[u][i][j] = go(u, i, j);
				if(j == 0){
					carries[u][i][j].insert(l[u]);
				}
				cout << u << " " << i << " " << j << " " << dp[u][i][j] << "\n";
			}
		}
	}
}
int main(){
	//p2
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		int a, b, c;
		cin >> l[i] >> b >> c;
		adj[b].pb({i, c});
	}
	dfs(0);
	int ans = 2e9;
	for(int i = 0; i <= k; i++){
		ans = min({ans, dp[0][i][0], dp[0][i][1]});
	}
	cout << ans << '\n';
}
