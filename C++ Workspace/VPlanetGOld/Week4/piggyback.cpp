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
int B, E, P, N, M;
vector<int> adj[40005];
vector<int> dist1;
vector<int> dist2;
vector<int> dist3;
vector<int> dijkstra(int weight, int src){
	vector<int> dist(N);
	for(int i = 0; i < N;i++)dist[i] = 2e9;
	dist[src] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0,src});
	while(!pq.empty()){
		pii cur = pq.top(); pq.pop();
		if(cur.f != dist[cur.s])continue;
		for(int u : adj[cur.s]){
			if(weight  + cur.f < dist[u]){
				pq.push({dist[u] = weight + cur.f, u});
			}
		}
	}
	return dist;
}
int main(){
	freopen("piggyback.in", "r", stdin);
	freopen("piggyback.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> B >> E >> P >> N >> M;
	for(int i = 0;i < M; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dist1 = dijkstra(B, 0);
	dist2 = dijkstra(E, 1);
	dist3 = dijkstra(P, N-1);
	int ans = 2e9;
	for(int i = 0; i < N;i ++){
		//cout << dist1[i] << " " << dist2[i] << " " << dist3[i] << '\n';
		ans = min(ans, dist1[i] + dist2[i] + dist3[i]);
	}
	cout << ans << '\n';
}
