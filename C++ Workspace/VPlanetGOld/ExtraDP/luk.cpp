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
int N;
vector<int> adj[300005];
int dp[300005];

void dfs(int u, int p, int k){
	int child = 0;
	dp[u] = 0;
	for(int v : adj[u]){
		if(v != p){
			child++;
			dfs(v, u, k);
			dp[u] += dp[v];
		}
	}
	dp[u] += child - k;
	dp[u] = max(dp[u], 0);
}
bool ok(int k){
	memset(dp, 0, sizeof(dp));
	dfs(0, -1, k);
	return dp[0] == 0;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for(int i = 0; i < N-1;i ++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	int lo =0; int hi = N;
	while(lo < hi){
		int mid = (lo+hi)/2;
		if(ok(mid)){
			hi = mid;
		}
		else{
			lo = mid+1;
		}
	}
	cout << lo << '\n';

}
