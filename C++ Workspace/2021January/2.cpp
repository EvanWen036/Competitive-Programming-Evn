#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define sz(a) a.size()
typedef long long ll;
typedef pair<ll, int> pii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
int breedDist[55];
int pa[55];
bool vis[55];
vector<int> of[55];
vector<int> adj[50005];
ll dist[50005];
int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	vector<int> type(N);
	for(int i = 0; i < N;i ++){
		cin >> type[i]; type[i]--;
		of[type[i]].pb(i);
	}
	int mat[K][K];
	for(int i = 0;i  < K; i++){
		string s;
		cin >> s;
		for(int j = 0;j < K; j++){
			mat[i][j] = s[j] - '0';
		}
	}
	//find shortest path amongst breeds
	//find sp of breeds from b[1] to b[N]
	queue<int> q;
	q.push(type[0]);
	pa[type[0]] = -1;
	memset(breedDist, -1, sizeof(breedDist));
	breedDist[type[0]] = 0;
	while(!q.empty()){
		int u = q.front(); q.pop();
		//cout << u << " " << breedDist[u] << '\n';
		vis[u] = true;
		for(int i = 0; i < K; i++){
			if(mat[u][i] == 1){
				if(!vis[i]){
					pa[i] = u;
					breedDist[i] = breedDist[u]+1;
					q.push(i);
				}
			}
		}
	}
	if(breedDist[type[N-1]] == -1){
		cout << -1 << '\n';
		return 0;
	}

	int curr = type[N-1];
	while(curr != -1){
		//cout << curr << '\n';
		//build some edges
		//if(pa[curr] == -1)break;
		if(pa[curr] != -1){
			for(int u : of[pa[curr]]){
				for(int v : of[curr]){
					adj[u].pb(v);
					adj[v].pb(u);
				}
			}
		}
		/**
		for(int u : of[curr]){
			for(int v : of[curr]){
				if(u == v)continue;
				adj[u].pb(v);
				adj[v].pb(u);
			}
		}**/
		curr = pa[curr];
	}
	//minimize edges = minimize cost
	//build a smaller graph and run dijkstras
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0LL,0});
	dist[0]=0;
	for(int i = 1; i < N;i ++)dist[i] = 1e18;
	while(!pq.empty()){
		pii curr = pq.top(); pq.pop();
		int u = curr.s;
		if(curr.f != dist[u])continue;
		//assert(dist[u] >= 0);
		for(int v : adj[u]){
			int weight = abs(u-v);
			if(dist[v] > dist[u] + weight){
				dist[v] = dist[u]+weight;
				pq.push({dist[v], v});
			}
		}
	}
	//assert(dist[N-1] != 1e18);
	if(N <= 1000){
		//wrong answer lul
		for(int i =0;i < N;i ++){
			adj[i].clear();
		}
		for(int i = 0;i < N;i ++){
			for(int j = 0;j < N;j ++){
				if(j == i)continue;
				if(mat[type[i]][type[j]] == 1){
					//add edge
					adj[i].pb(j);
				}
			}
		}
		for(int i = 1; i < N; i++){
			dist[i] = LLONG_MAX;
		}
		dist[0] = 0LL;
		vector<bool> vis(N);
		for(int i = 0; i < N;i ++){
			int v = -1;
			for(int j = 0;j < N;j ++){
				if(!vis[j] && (v==-1 || dist[j] < dist[v]))v = j;
			}
			if(dist[v] == LLONG_MAX)break;
			vis[v] = true;
			for(int u : adj[v]){
				int weight = abs(u-v);
				if(dist[v] + weight < dist[u]){
					dist[u] = dist[v]+weight;

				}
			}
		}
		cout << (dist[N-1] != LLONG_MAX ? dist[N-1]:-1) << '\n';
		return 0;
	}
	cout << dist[N-1] << '\n';
}
