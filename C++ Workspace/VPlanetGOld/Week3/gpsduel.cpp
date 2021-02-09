#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define sz(a) a.size()
typedef long long ll;
typedef pair<ll, ll> pii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
int N, M;
vector<pii> P[50005];
vector<pii> Q[50005];
vector<pii> G[50005];
priority_queue<pii, vector<pii>, greater<pii>> pq;
//dijkstra's shortest path algorithm
//dist[i] = shortest path from node 0 to node i
vector<int> dijkstra(vector<pii> graph[], int src){
	vector<int> dist(N);
	pq.push({0,src});
	for(int i = 0; i < N; i++)dist[i] = 2e9;
	dist[src] = 0;
	while(!pq.empty()){
		pii cur = pq.top(); pq.pop();
		if(cur.f != dist[cur.s])continue;
		for(pii e : graph[cur.s]){
			//cout << cur.s << " " << e.f << " " << e.s << '\n';
			if(dist[e.f] > dist[cur.s]+e.s){
				pq.push({dist[e.f] = dist[cur.s]+e.s, e.f});
			}
		}
	}
	return dist;
}
main(){
	freopen("gpsduel.in", "r", stdin);
	freopen("gpsduel.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--; b--;
		P[b].pb({a,c});
		Q[b].pb({a,d});
	}
	vector<int> dist = dijkstra(P, N-1);
	vector<int> dist2 = dijkstra(Q, N-1);
	for(int i = 0;i < N;i ++){
		assert(dist[i] >= 0 && dist2[i] >= 0);

		int Pdist = dist[i];
		int Qdist = dist2[i];

		//cout << Pdist << " " << Qdist << '\n';
		vector<pii> edges;
		for(pii e : P[i]){
			int edgewt = 0;
			if(dist[e.f] - e.s != Pdist){
				edgewt++;
			}
			edges.pb({e.f, edgewt});
		}
		for(int j = 0; j < Q[i].size(); j++){
			if(dist2[Q[i][j].f] - Q[i][j].s != Qdist){
				assert(Q[i][j].f == edges[j].f);
				edges[j].s++;
			}
		}
		for(auto it: edges){
			G[it.f].pb({i, it.s});
		}
	}
	vector<int> ans = dijkstra(G, 0);
	cout << ans[N-1] << '\n';

}
