#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
vector<pii> adj[100005];
pii hb[100005];
int dp[100005][2];
vector<pii> edges;
int dfs(int u, int curr){
	if(dp[u][curr] != 1e9){
		return dp[u][curr];
	}
	if(u == 1){
		return 0;
	}
	for(auto it : adj[u]){
		//switch 
		dp[u][curr] = min(dp[u][curr], hb[curr].f + hb[curr].s * it.s + dfs(it.f,it.f));
		//don't switch
		dp[u][curr] = min(dp[u][curr], hb[curr].f + hb[curr].s * it.s + dfs(it.f,curr));
	}
	return dp[u][curr];
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for(int i = 0; i < N-1; i++){
		int a, b, c; cin >> a >> b >> c;
		a--; b--;
		adj[a].pb({b,c});
		adj[b].pb({a,c});
	}
	for(int i = 1; i <= N-1;i++){
		int a, b;
		cin >> a >> b;
		hb[i] = {a,b};
	}
	for(int i = 1; i < N; i++){
		for(int j =0; j < N; j++){
			dp[j][0] = 1e9;
			dp[j][1] = 1e9;
		}

		cout << dfs(i,i) << " " ;

	}

}
