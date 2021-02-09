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
vector<int> adj[100005];
multiset<pii> edges[100005];
int base = 0;
int merge(int u, int v){
	if(edges[v].size() > edges[u].size())swap(u,v);
	//u is bigger
	for(auto it : edges[v]){
		edges[u].insert(it);
	}
	return u;
}
void dfs(int node, int parent){
	//cout << node << " " << parent << endl;
	for(int u : adj[node]){
		if(u == parent)continue;
		dfs(u, node);
	}
	for(int u : adj[node]){
		if(u == parent)continue;
		swap(edges[merge(u, node)], edges[node]);
	}
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, K;
	cin >> N >> M >> K;
	for(int i = 0; i < N-1; i++){
		int a, b;
		cin >> a >> b; a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	for(int i = 0; i < M; i++){
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		edges[a].insert({c,b});
		edges[b].insert({c,a});
	}
	for(int i = 0; i < N;i ++){
		if(edges[i].size() == M){
			base = i;
		}
	}
	dfs(base, -1);
	ll ans = 1e18;
	for(int u : adj[base]){
		if(edges[u].size() >= K){
			ll sum = 0;
			int ind = 0;
			multiset<pii>::iterator it = edges[u].begin();
			while(ind < K && it != edges[u].end()){
				sum += (*it).f;
				it++;
				ind++;
			}
			ans = min(ans, sum);
		}
	}
	cout << ans << '\n';
}
