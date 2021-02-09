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
void solve(){
	//cout << "hi" << endl;
	int n, m;
	n = 1e5;
	m = 1e5-1;
	//cin >> n >> m;
	vector<int> adj[n];
	vector<pii> adjList;
	for(int i = 0; i < m;i ++){
		adj[i].pb(i+1);
	}
	//bfs to get the d values
	int dist[n];
	bool vis[n];
	vector<int> par[n];
	int ans[n];
	memset(par, 0, sizeof(par));
	memset(vis, false, sizeof(vis));
	memset(dist, 0, sizeof(dist));

	vis[0] = true;
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		int u = q.front(); q.pop();
		
		for(int v : adj[u]){
			if(!vis[v]){
				par[v].pb(u);
				dist[v] = dist[u]+1;
				q.push(v);
				vis[v]=true;
			}
			else{
				if(dist[v] == dist[u]+1){
					par[v].pb(u);
				}
			}
		}
	}
	for(int i =0;i <n;i++)ans[i] = dist[i];
	//cout << "hi" << endl;
	for(pii e : adjList){
		if(dist[e.f]>=dist[e.s]){

			//cout << e.f << " " << e.s << " " << dist[e.s] <<  '\n';

			//special edge
			
			q.push(e.f);
			while(!q.empty()){
				int tp = q.front(); q.pop();
				ans[tp] = min(ans[tp], dist[e.s]);
				if(tp == 0)continue;
				for(int u : par[tp]){
					q.push(u);
				}
			}
		}
	}
	for(int i =0;i < n;i++){
		cout << ans[i] << " ";
	}
	cout << '\n';

}
int main(){
	//freopen("test.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; 
	t = 1;
	//cin >> t; 	
	while(t--){
		solve();
	}


}
