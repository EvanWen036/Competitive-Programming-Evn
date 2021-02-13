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
int N, M;
const int maxN = 1e3+5;
vector<pii> adj[maxN];
map<pii, ll> trav;
map<pii, ll> temp;
priority_queue<pii, vector<pii>, greater<pii>> pq;
set<int> parents[maxN];
ll dp[maxN];
int indeg[maxN];
queue<int> q;
vector<pii> edges;
ll mod = 1e9+7;
vector<int> graph2[maxN];
vector<int> dijk(maxN);
vector<int> graph3[maxN];
int indeg2[maxN];
int dp2[maxN];
int ogIndg[maxN];
queue<int> q2;
void solve(int src){
	//do a dijkstras starting at this position
	for(int i = 1; i <= N;i ++){
		dijk[i] = 1e9;
		parents[i].clear();
		dp[i] = 1;
		indeg[i] = 0;
		graph2[i].clear();
		graph3[i].clear();
		indeg2[i] = 0;
		dp2[i] = 0;
	}
	dijk[src] = 0;
	pq.push({0,src});
	while(!pq.empty()){
		pii cur = pq.top(); pq.pop();
		if(dijk[cur.s] != cur.f)continue;
		for(pii e : adj[cur.s]){
			if(cur.f + e.s < dijk[e.f]){
				dijk[e.f] = cur.f + e.s;
				pq.push({dijk[e.f], e.f});
			}
			
		}
	}
	for(int i = 1; i <= N;i ++){
		for(pii e : adj[i]){
			if(dijk[i] - dijk[e.f] == e.s){
				parents[i].insert(e.f);
			}
		}
	}
	/**
	for(int i = 1; i <= N;i ++){
		cerr << dijk[i] << " ";
	}
	cerr << '\n';
	**/
	//build dag
	
	for(int i = 1; i <= N;i ++){
		assert(dijk[i] != 1e9);
		for(int u : parents[i]){
			//cerr << u << " " << i << '\n';
			graph2[i].pb(u);
			graph3[u].pb(i);
			indeg[u]++;
			indeg2[i]++;
		}
	}
	//do dp
	for(int i =  1; i <= N;i ++){
		if(indeg[i] == 0){
			q.push(i);
		}
		ogIndg[i] = indeg[i];
		if(indeg2[i] == 0)q2.push(i);
	}
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(int v : graph2[u]){
			//cout << u << " " << v << '\n';
			//trav[{min(u,v), max(u,v)}] += dp[u];
			//trav[{min(u,v), max(u,v)}] %= mod;
			dp[v] += dp[u];
			dp[v] %= mod;
			indeg[v]--;
			if(indeg[v] == 0)q.push(v);
		}
	}
	dp2[src] = 1;
	while(!q2.empty()){
		int u = q2.front(); q2.pop();
		for(int v : graph3[u]){
			//cout << u << " " << v << '\n';
			//trav[{min(u,v), max(u,v)}] += dp[u];
			//trav[{min(u,v), max(u,v)}] %= mod;
			dp2[v] += dp2[u];
			dp2[v] %= mod;
			indeg2[v]--;
			if(indeg2[v] == 0)q2.push(v);
		}
	}
	
	for(int i = 1; i <= N;i ++){
		for(int u : graph2[i]){
			trav[{min(i,u), max(i,u)}] += (dp[i] * dp2[u]);
			trav[{min(i,u), max(i,u)}] %= mod;
		}
	}

}
int32_t main(){
	freopen("roadhelp.in", "r", stdin);
	freopen("roadhelp.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	set<pii> test;
	for(int i = 0;i < M; i++){
		int a, b, c;
		cin >> a >> b >> c;
		//cout << a << " " << b << '\n';
		adj[a].pb({b,c});
		adj[b].pb({a,c});
		edges.pb({min(a,b), max(a,b)});
	}
	for(int i = 1; i <= N;i ++){
		solve(i);
	}
	for(int i = 0;i < M;i ++){
		cout << trav[{min(edges[i].f, edges[i].s), max(edges[i].f, edges[i].s)}] << '\n';
	}



}
