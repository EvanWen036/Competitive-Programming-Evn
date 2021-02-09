#include "supertrees.h"
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

int N;
vector<int> dsu;
vector<int> sz;
vector<vector<int>> adj;
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
int cmp[1005];
int r = 0;
void dfs(int u){
	cmp[u] = r;
	for(int i = 0; i < N;i ++){
		if(adj[u][i] != 0 && cmp[i] == -1){
			dfs(i);
		}
	}
}
int pre[1005];
int pcmp[1005];
int f[1005];

int construct(vector<vector<int>> p){
	N = p.size();
	dsu.resize(N);
	sz.resize(N);
	assert(N <= 1000);
	bool c0 = false;
	bool c1 = false;
	bool c2 = false;
	bool c3 = false;
	for(int i = 0; i < N; i++){
		for(int j = 0;j  < N; j++){
			if(p[i][j] == 0)c0 = true;
			if(p[i][j] == 1)c1 = true;
			if(p[i][j] == 2)c2 = true;
			if(p[i][j] == 3)c3 = true;
		}
	}
	if(!c0 && c1 && !c2 && !c3){
		//tree case
		vector<vector<int>> b;
		for(int i = 0; i < N;i ++){
			int c1 = 2*i + 1;
			int c2 = 2*i + 2;
			int p = (i-1)/2;
			if(i == 0)p =-1;
			vector<int> curr;
			for(int j = 0;j  < N; j++){
				if(j == p || j == c1 || j== c2){
					curr.pb(1);
				}
				else{
					curr.pb(0);
				}
			}
			b.pb(curr);
		}
		build(b);
		return 1;
	}
	else if(c1 && c2 && !c3){
		//subtask 4/5
		//assert(false);
		vector<vector<int>> edges(N);
		dsu.resize(N);
		sz.resize(N);
		adj.resize(N);
		memset(pre, -1, sizeof(pre));
		for(int i =0;i < N;i ++){
			dsu[i] = i;
			sz[i] = 1;
			edges[i].resize(N);
			adj[i].resize(N);
		}
		for(int i =0;i < N;i ++){
			for(int j = 0;j < N; j++){
				adj[i][j] = p[i][j];
				if(p[i][j] == 1){
					//same branch
					merge(i, j);
				}				
			}
		}	
		memset(cmp, -1, sizeof(cmp));
		for(int i = 0; i < N; i++){
			if(cmp[i] == -1){
				r++;
				dfs(i);
			}
		}
		
		assert(r <= N);
		set<int> parents;
		for(int i = 0; i < N;i ++){
			parents.insert(find(i));
		}
		vector<int> p;
		for(int u : parents)p.pb(u);
		memset(f, -1, sizeof(f));
		memset(pcmp, -1, sizeof(pcmp));
		for(int i = 0;i < (int)p.size(); i++){
			assert(cmp[p[i]] >= 0 && cmp[p[i]] < N);
			assert(p[i] < N && p[i] >= 0);
			if(f[cmp[p[i]]] == -1){
				f[cmp[p[i]]] = p[i];
			}
			if(pcmp[cmp[p[i]]] != -1){
				assert(pcmp[cmp[p[i]]] < N && pcmp[cmp[p[i]]] >= 0);
				edges[pcmp[cmp[p[i]]]][p[i]] = 1;
				edges[p[i]][pcmp[cmp[p[i]]]] = 1;
			}
			pcmp[cmp[p[i]]] = p[i];
		}
		for(int i = 0;i < r; i++){
			assert(i <= N);
			if(pcmp[i] != -1 && f[i] != -1){
				assert(f[i] < N && pcmp[i] < N && f[i] >= 0 && pcmp[i] >= 0);
				edges[pcmp[i]][f[i]] = 1;
				edges[f[i]][pcmp[i]] = 1;
			}
		}
		for(int i= 0;i < N; i++){
			assert(find(i) >= 0 && find(i) < N);
			if(pre[find(i)] != -1){
				assert(pre[find(i)] >= 0 && pre[find(i)] < N);
				edges[pre[find(i)]][i] = 1;
				edges[i][pre[find(i)]] = 1;
			}
			pre[find(i)] = i;
		}
		build(edges);
		return 1;
	}
	else if(c3){
		//subtask 6
		return 0;		
	}
	else{
		//subtask 2/3
		//do dsu
		adj.resize(N);
		for(int i = 0;i  < N; i++){
			dsu[i] = i;
			sz[i] = 1;
			adj[i].resize(N);
		}
		for(int i = 0; i < N;i ++){
			for(int j = 0;j < N; j++){
				if(p[i][j] == 0){
					if(find(i) == find(j)){
						//not possible
						//assert(false);
						return 0;
					}
				}
				else{
					merge(i, j);
				}
			}

		}
		for(int i = 0; i < N;i ++){
			assert(find(i) < N && find(i) >= 0); 
			int g = 0;
			for(int j = 0;j  < N;j ++){
				g = max(g, p[i][j]);
			}
			if(sz[find(i)] <= g && sz[find(i)] != 1)return 0;
		}
		
			//subtask 2
			//make a line 
		vector<vector<int>> edges(N);
		for(int i = 0; i < N;i ++){
			edges[i].resize(N);
		}
		int prev[N];
		int f[N];
		memset(f, -1, sizeof(f));
		memset(prev, -1, sizeof(prev));
		for(int i = 0; i < N;i ++){
			int cmp = find(i);
			if(prev[cmp] != -1){	
				edges[prev[cmp]][i] = 1;
				edges[i][prev[cmp]] = 1;
			}
			if(f[cmp] == -1){
				f[cmp] = i;
			}
			prev[cmp] = i;
		}
		if(c2){
			for(int i = 0; i < N;i ++){
				if(prev[i] != -1 && prev[i] != f[i]){
					edges[prev[i]][f[i]] = 1;
					edges[f[i]][prev[i]] = 1;
				}
			}
		}
		build(edges);
		return 1;
	}
	
	return 0;
}
