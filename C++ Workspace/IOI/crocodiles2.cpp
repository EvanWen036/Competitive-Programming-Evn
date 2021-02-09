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
int vis[100005];
int dist[100005];
vector<pii> adj[100005];
int travel_plan(int N, int M, int R[][2], int L[], int K, int P[]){
	for(int i =0; i < M; i++){
		adj[R[i][0]].pb({R[i][1], L[i]});
		adj[R[i][1]].pb({R[i][0], L[i]});
	}
	for(int i = 0; i < N;i ++){
		dist[i] = 1e9;
	}
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	for(int i = 0; i < K; i++){
		dist[P[i]] = 0;
		pq.push({0, P[i]});
		vis[P[i]] = 1;
	}
	while(!pq.empty()){
		pii curr = pq.top(); pq.pop();
		int u = curr.s;
		if(vis[u] == 0){
			vis[u] = 1;
			continue;
		}
		if(vis[u] == 2)continue;
		vis[u] = 2;
		dist[u] = curr.f;
		for(pii edge : adj[u]){
			int next = edge.f;
			int weight = edge.s;
			if(vis[next] >= 2)continue;
			pq.push({weight+curr.f, next});
		}
	}
	return dist[0];

}