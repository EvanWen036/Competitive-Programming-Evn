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
//calculate tree depths
//can only be 2 tree depths otherwise it's not gonna work
//then start doing things on subtree
//does this subtree work
//yes if this subtree has no "shorts"
//yes if one child works and the other has 0 "longs"
//calculating moves shouldn't be that hard hopefully 
vector<int> adj[200005];
int depth[200005];
int shorts[200005];
int longs[200005];
int stz[200005];
int sdepth = 0;
bool possible = true;
int dp[200005];
int n;
void dfs1(int u){
	stz[u] = 1;
	for(int v : adj[u]){
		depth[v] = depth[u]+1;
		dfs1(v);
		stz[u] += stz[v];
	}
}
void dfs2(int u){
	assert(u <= 200000);
	if(u >= n){
		//this is a leaf
		if(depth[u] == sdepth)shorts[u]++;
		else{longs[u]++;}
		return;
	}
	for(int v : adj[u]){
		dfs2(v);
		longs[u] += longs[v];
		shorts[u] += shorts[v];
	}
	//cout << u << " " << shorts[u] << " " << longs[u] << endl;
	if(shorts[u] == 0){
		//everything is long
		dp[u] = 0;
		return;
	}
	if(longs[u] == 0){
		//everything is short
		dp[u] = 0;
		return;
	}
	if(shorts[adj[u][0]] == 0 && longs[adj[u][1]] == 0){
		dp[u] = 0;
		return;
	}
	bool enter = false;
	if(longs[adj[u][1]] == 0 || shorts[adj[u][1]] == 0){
		//left is fixable and right is guaranteed fix
		enter = true;
		int add = (longs[adj[u][1]] == 0 ? 0:1);
		dp[u] = dp[adj[u][0]] + add;
	}
	if(longs[adj[u][0]] == 0 || shorts[adj[u][0]] == 0){
		//left guaranteed fix
		enter = true;
		int add = (shorts[adj[u][0]] == 0 ? 0:1);
		dp[u] = dp[adj[u][1]]+add;
	}
	//cout << u << " " << dp[u] << '\n';
	if(!enter){
		cout << -1 << '\n';
		for(int i = 0; i < n;i ++)adj[i].clear();
		possible = false;
		return;
	}

}
void solve(){
	cin >> n;
	int leaf = n;
	memset(shorts,0, sizeof(shorts));
	memset(longs, 0, sizeof(longs));
	memset(dp, 0, sizeof(dp));
	memset(depth, 0, sizeof(depth));
	memset(stz, 0, sizeof(stz));
	possible = true;
	for(int i = 0; i < n; i++)assert(adj[i].size() == 0);
	for(int i = 0; i < n;i ++){
		int a, b;
		cin >> a >> b;
		a--; b--;

		if(a == -2){
			adj[i].pb(leaf++);
		}
		else{
			adj[i].pb(a);
		}
		if(b == -2){
			adj[i].pb(leaf++);
		}
		else{
			adj[i].pb(b);
		}
	}
	dfs1(0);
	set<int> ldepth;
	for(int i = n; i < leaf;i ++){
		ldepth.insert(depth[i]);
	}
	//cout << ldepth.size() << '\n';
	if(ldepth.size() > 2){
		cout << - 1 << '\n';
		for(int i = 0; i < leaf;i ++)adj[i].clear();
		return;
	}
	else if(ldepth.size() == 1){
		cout << 0 << '\n';
		for(int i = 0; i < leaf;i ++)adj[i].clear();
		return;
	}
	else{
		if(*(--ldepth.end()) - *ldepth.begin() > 1){
			cout << - 1 << '\n';
			for(int i = 0; i < leaf;i ++)adj[i].clear();
				return;
		}
		sdepth = *ldepth.begin();
	}
	dfs2(0);
	if(!possible)return;
	cout << dp[0] << '\n';
	for(int i = 0; i < leaf;i ++){
		adj[i].clear();
	}
}

int main(){
	//p3
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}	


}
