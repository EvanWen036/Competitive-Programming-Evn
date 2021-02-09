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
//Use dijkstra method here
//save the parents on the first dijkstra to make sure you can extract the shortest path
int N, M;
int pa[255];
vector<pii> adj[255];
vector<int> dijkstra(int type){
	//run dijkstra and return an array
	pa[0] = -1;
	vector<int> dist(N);
	dist[0] = 0;
	for(int i = 1; i < N; i++){
		dist[i] = 1e9;
	}
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0,0});
	while(!pq.empty()){
		pii st = pq.top(); pq.pop();
		if(dist[st.s] != st.f)continue;
		for(pii e : adj[st.s]){
			int weight = e.s;
			int nx = e.f;
			//cout << st.s << " " << nx << " " << weight << '\n';
			if(dist[nx] > dist[st.s] + weight){
				if(type == 0){
					pa[nx] = st.s;
				}
				dist[nx] = dist[st.s] + weight;
				pq.push({dist[nx],nx});
			}
		}
	}
	return dist;
}
int main(){
	freopen("rblock.in", "r", stdin);
	freopen("rblock.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		adj[a].pb({b,c});
		adj[b].pb({a,c});
	}
	vector<int> og = dijkstra(0);
	int curr = N-1;
	int ans = 0;
	while(pa[curr] != -1){
		//cout << "hi" << endl;
		for(int i = 0; i < adj[pa[curr]].size(); i++){
			pii e = adj[pa[curr]][i];
			if(e.f == curr){
				adj[pa[curr]][i] = {e.f, e.s*2};
			}
		}
		for(int i = 0; i < adj[curr].size(); i++){
			pii e = adj[curr][i];
			if(e.f == pa[curr]){
				adj[curr][i] = {e.f, e.s*2};
			}
		}
		vector<int> ne = dijkstra(1);
		
		ans = max(ans, ne[N-1]-og[N-1]);
		for(int i = 0; i < adj[pa[curr]].size(); i++){
			pii e = adj[pa[curr]][i];
			if(e.f == curr){
				adj[pa[curr]][i] = {e.f, e.s/2};
			}
		}
		for(int i = 0; i < adj[curr].size(); i++){
			pii e = adj[curr][i];
			if(e.f == pa[curr]){
				adj[curr][i] = {e.f, e.s/2};
			}
		}
		curr = pa[curr];
	}
	cout << ans << '\n';
}
