#include <bits/stdc++.h>
#include "supertrees.h"
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
int cmp[1005];
int cmpSize[1005];
vector<vector<int>> adj;
int r = 0;
int cs = 0;
int N;
void dfs(int u){
	cmp[u] = r;
	cs++;
	for(int i = 0; i < N;i ++){
		if(adj[u][i] != 0 && cmp[i] == -1){
			dfs(i);
		}
	}
}
int dsu[1005];
int sz[1005];
int find(int u){
	if(dsu[u] == u)return u;
	return dsu[u] = find(dsu[u]);
}
void merge(int u, int v){
	u = find(u);
	v = find(v);
	if(u == v)return;
	if(sz[u] < sz[v])swap(u,v);
	dsu[v] = u;
	sz[u] += sz[v];
}
int construct(vector<vector<int>> p)
{	N = p.size();
	adj.resize(N);
	vector<vector<int>> edges;
	edges.resize(N);
	for(int i = 0; i < N; i++){
		adj[i].resize(N);
		edges[i].resize(N);
		dsu[i] = i;
		sz[i] = 1;
		for(int j = 0;j < N;j ++){
			adj[i][j] = p[i][j];
			if(p[i][j] == 3)return 0;
		}
	}
	memset(cmp, -1, sizeof(cmp));
	for(int i = 0; i < N; i++){
		if(cmp[i] == -1){
			cs = 0;
			r++;
			dfs(i);
			cmpSize[r] = cs;
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0;j < N;j ++){
			if(cmp[i] == cmp[j] && p[i][j] == 0){
				return 0;
			}
		}
	}
	for(int i = 0; i < N;i ++){
		int g = 0;
		for(int j =0;j < N; j++){
			g = max(g, p[i][j]);
		}
		if(cmpSize[cmp[i]] <= g && cmpSize[cmp[i]] != 1)return 0;
	}
	//0 = different components
	//1 = same branch
	//2 = in da cycle. can't have multiple cycles in one connected component
	//dsu to store the branches
	for(int i = 0; i < N; i++){
		for(int j =0;j < N; j++){
			if(p[i][j] == 1){
				merge(i,j);
			}
		}
	}
	//store the possible parents of branches
	set<int> pa;
	vector<int> parents;
	for(int i = 0; i < N;i ++){
		pa.insert(find(i));
	}
	for(int u : pa)parents.pb(u);
	//add edges between parents that are in the same cycle
	int prevCmp[N+5];
	int fCmp[N+5];
	memset(fCmp, -1, sizeof(fCmp));
	memset(prevCmp, -1, sizeof(prevCmp));
	for(int i = 0; i < parents.size(); i++){
		int curr = parents[i];
		int comp = cmp[curr];
		if(fCmp[comp] == -1){
			fCmp[comp] = curr;
		}
		//find the previous one in curr's connected comp
		if(prevCmp[comp] != -1){
			//add edge
			edges[prevCmp[comp]][curr] = 1;
			edges[curr][prevCmp[comp]] = 1;
		}
		prevCmp[comp] = curr;
	}
	//create the loop in each component
	for(int i = 1; i <= r; i++){
		if(prevCmp[i] != fCmp[i]){
			if(prevCmp[i] == -1 || fCmp[i] == -1)continue;
			edges[prevCmp[i]][fCmp[i]] = 1;
			edges[fCmp[i]][prevCmp[i]] = 1;
		}
	}
	//add edges in the branches
	int prevD[N+5];
	memset(prevD, -1, sizeof(prevD));
	for(int i = 0; i < N; i++){
		if(prevD[find(i)] != -1){
			edges[prevD[find(i)]][i] = 1;
			edges[i][prevD[find(i)]] = 1;
		}
		prevD[find(i)] = i;
	}
	build(edges);
	return 1;	
} 
