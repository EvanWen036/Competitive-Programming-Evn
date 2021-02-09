#include <bits/stdc++.h>
#include "stations.h"
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
int timer = 0;
int depth[1005];
int in[1005];
int out[1005];
vector<int> adj[1005];
vector<int> labels;

void dfs(int u, int p){
	in[u] = timer++;
	for(int v : adj[u]){
		if(v != p){
			depth[v] = depth[u]+1;
			dfs(v, u);
		}
	}
	out[u] = timer++;
}
vector<int> label(int n, int k, vector<int> u, vector<int> v) {
	labels.resize(n);
	for(int i = 0; i < n;i ++){
		adj[i].clear();
		depth[i] = 0;
		labels[i] = 0;
	}
	for(int i = 0; i < u.size(); i++){
		int a, b;
		a = u[i];
		b = v[i];
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(0, -1);
	vector<int> times;
	for(int i = 0; i < n;i ++){
		if(depth[i] % 2 == 0){
			times.pb(in[i]);
		}
		else{
			times.pb(out[i]);
		}
	}
	sort(times.begin(), times.end());
	map<int, int> x;
	int curr = 0;
	for(int i = 0; i < n;i ++){
		x[times[i]]=curr++;
	}
	for(int i = 0; i< n;i ++){
		int lbl =0;
		if(depth[i] % 2 ==0){
			lbl = x[in[i]];
		}
		else{
			lbl = x[out[i]];
		}
		labels[i] = lbl;
	}
	return labels;
}

int find_next_station(int s, int t, vector<int> c) {
	if(c.size() == 1)return c[0];
	if(c[0] > s){
		//this is the in value
		if(t < s || t >= c[c.size()-1])return c[c.size()-1];
		for(int i = 0;i < c.size()-1; i++){
			if(t <= c[i])return c[i];
		}
	}
	else{
		//this is the out value
		if(t <= c[0] || t > s)return c[0];
		for(int i = c.size()-1; i >= 1; i--){
			if(t >= c[i])return c[i];
		}
	}
}
