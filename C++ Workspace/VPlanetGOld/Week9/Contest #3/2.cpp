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
multiset<int> ca[105][105];
int weights[105][105];
int dp[105][2][105];
vector<pii> adj[105];
int l[105];
void combine(int u, int v, int in){
	for(int i = in; i <= k; i++){
		//have already built a total of i 
		//combining in j built from this subtree
		for(int j =0; i + j <= k;j++){
			int cst1 = dp[v][1][j] + (dp[u][in][i]==2e9?0:dp[u][in][i]);
			int cst2 = dp[v][0][j] + (dp[u][in][i]==2e9?0:dp[u][in][i]);
			//process carries from this node
			for(int x : ca[v][j]){
				cst2 += x * weights[u][v];
			}
			cout << u << " " << in << " " << i << " " << j << " " << cst1 << " " << cst2 << '\n';
			//if(dp[u][in][i+j] == 2e9)dp[u][in][i+j] = 0;
			
			dp[u][in][i+j] = min({dp[u][in][i+j], cst1,cst2});
			
			if(in == 0){
				//bring over carries 
				if(cst1 <= cst2)continue;
				for(int x : ca[v][j]){
					ca[u][i+j].insert(x);
				}
				ca[u][i+j].insert(l[u]);
			}
		}
	}
}
void dfs(int u){
	for(pii v : adj[u]){
		dfs(v.f);
	}
	dp[u][1][1] = 0;
	if(adj[u].size() == 0){
		dp[u][0][0] = 0;
		dp[u][1][1] = 0;
		ca[u][0].insert(l[u]); 
	}
	for(pii v : adj[u]){
		combine(u,v.f, 1);
		combine(u,v.f, 0);
	}
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		int a, b, c;
		cin >> l[i] >> b >> c;
		weights[i][b] = c;
		weights[b][i] = c;
		adj[b].pb({i, c});
	}
	for(int i = 0; i <= n;i ++){
		for(int j = 0;j <= k;j ++){
			dp[i][0][j] = 2e9;
			dp[i][1][j] = 2e9;
		}
	}
	dfs(0);
	int ans = 2e9;
	for(int i = 0; i <= n; i++){
		for(int j = 0;j <= k;j ++){
			cout << i << " " << 0 << " " << j << " " << dp[i][0][j] << '\n';
			cout << i << " " << 1 << " " << j << " " << dp[i][1][j] << '\n';
		}
	}
	for(int i = 0; i <= k; i++){
		ans = min({ans, dp[0][0][i], dp[0][1][i]});
	}
	cout << ans << '\n';


}
