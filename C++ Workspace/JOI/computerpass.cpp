#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll, ll> pii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
vector<pii> adj[100005];
set<int> parents[100005];
ll dijkstra[100005];
ll dijkstra2[100005];
bool vis[100005];
signed main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, S, T, U, V;
	cin >> N >> M >> S >> T >> U >> V; S--; T--; U--; V--;
	for(int i = 0; i < M;i ++){
		ll a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		adj[a].pb({b,c});
		adj[b].pb({a,c});
	}
	//run yikstras once
	for(int i =0; i < N;i ++){
		dijkstra[i] = 1e18;
		dijkstra2[i] = 1e18;
	}
	dijkstra[S] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq; 
	pq.push({0,S});
	while(!pq.empty()){
		pii curr = pq.top(); pq.pop();
		if(dijkstra[curr.s] != curr.f)continue; 
		for(auto it : adj[curr.s]){
			ll next = it.f;
			ll weight = it.s;
			if(weight + dijkstra[curr.s] == dijkstra[next]){
				parents[next].insert(curr.s);
			}
			if(weight + dijkstra[curr.s] < dijkstra[next]){
				parents[next].clear();
				parents[next].insert(curr.s);
				dijkstra[next] = weight + dijkstra[curr.s];
				pq.push({dijkstra[next], next});
			}
		}
	}
	queue<int> q;
	vis[T] = true;
	q.push(T);
	while(!q.empty()){
		int top = q.front(); q.pop();
		for(int u : parents[top]){
			if(!vis[u]){
				adj[u].pb({top,0});
				adj[top].pb({u,0});
				vis[u] = true;
				q.push(u);
			}
		}
	}
	dijkstra2[U] = 0;
	pq.push({0, U});
	while(!pq.empty()){
		pii curr = pq.top(); pq.pop();
		if(dijkstra2[curr.s] != curr.f)continue;
		for(auto it : adj[curr.s]){
			ll next = it.f;
			ll weight = it.s;
			if(weight + dijkstra2[curr.s] < dijkstra2[next]){
				//cout << curr.s << " " << next << " " << weight << '\n';
				dijkstra2[next] = weight+dijkstra2[curr.s];
				pq.push({dijkstra2[next], next});
			}
		}
	}
	cout << dijkstra2[V] << '\n';




}
