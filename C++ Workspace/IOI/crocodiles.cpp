#include <bits/stdc++.h>
//#include "crocodile.h"
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
int dist[1005];
vector<pii> adj[1005];
bool isExit[1005];
int ans = 1e9;
void dfs(int u, int p){
	//cout << u << " " << p << '\n';
	for(pii e : adj[u]){
		int v=e.f;
		int w = e.s;
		if(v == p)continue;
		dfs(v, u);
	}
	if(isExit[u]){
		dist[0] = 0;
	}
	vector<int> children;
	for(pii e : adj[u]){
		if(e.f != p){
			children.pb(dist[e.f] + e.s);
		}
	}
	sort(children.begin(), children.end());
	if(children.size() >= 2){
		dist[u] = children[1];
	}
}
int travel_plan(int N, int M, int R[][2], int L[], int K, int P[]){
	for(int i =0; i < M; i++){
		adj[R[i][0]].pb({R[i][1], L[i]});
		adj[R[i][1]].pb({R[i][0], L[i]});
	}
	for(int i = 0; i < K; i++){
		isExit[P[i]] = true;
	}
	dfs(0, -1);
	return dist[0];
}
/**
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, K;
	cin >> N >> M >> K;
	int R[M][2];
	int L[M];
	for(int i = 0; i < M;i ++){
		cin >> R[i][0] >> R[i][1] >> L[i];
	}
	
	int P[K];
	for(int i = 0;i  < K; i++)cin >> P[i];
	cout << travel_plan(N, M, R, L, K, P);
}
**/