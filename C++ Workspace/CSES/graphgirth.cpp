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
vector<int> adj[2505];
int par[2505];
bool vis[2505];
int dist[2505];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	queue<int> q;
	int ans = 1e9;
	for(int i = 0; i < n; i++){
		q.push(i);
		vis[i] = true;
		par[i] = -1;
		memset(par, 0, sizeof(par));
		memset(dist, 0,sizeof(dist));
		memset(vis, false, sizeof(vis));
		dist[i] = 0;

		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(int v : adj[u]){
				if(!vis[v]){
					vis[v] = true;
					dist[v]=dist[u]+1;
					q.push(v);
					par[v] = u;
				}
				else if(par[u] != v){
					ans = min(ans, dist[u]+dist[v]+1);
				}
			}
		}
	}
	cout << (ans == 1e9 ? -1:ans) << '\n';

}
