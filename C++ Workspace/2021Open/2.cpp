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
int dsu[400005];
int sz[400005];
pii portal[200005];
int p[100005][5];
int c[100005];
int ans = 0;
int find(int u){
	if(dsu[u] == u)return u;
	return dsu[u] = find(dsu[u]);
}
void merge(int u, int v){
	u=find(u);
	v=find(v);
	if(u == v)return;
	if(sz[v] > sz[u])swap(u,v);
	dsu[v] = u;
	sz[u] += sz[v];
}

/**
void dfs(int v, int po){
	if(vis[v][po])return;
	vis[v][po] = true;
	cout << v << " " << po << '\n';

	int nv = (portal[p[v][po]].f == v ? portal[p[v][po]].s : portal[p[v][po]].f); 
	//cout << v << " " << po << " " << nv << '\n';
	for(int j = 0;j < 4;j ++){
		if(p[nv][j] == p[v][po]){
			dfs(nv,j);
		}
	}
	if(po == 0)dfs(v, 1);
	if(po == 1)dfs(v,0);
	if(po == 2)dfs(v,3);
	if(po == 3)dfs(v,2);
}**/
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//p2
	int N;
	cin >> N;
	for(int i = 0; i <= 200000;i ++){
		portal[i].f = -1;
		portal[i].s = -1;
	}
	for(int i = 0; i < N;i ++){
		cin >> c[i];
		for(int j = 0;j < 4;j ++){
			dsu[i*4 + j] = i*4 + j;
			sz[i*4 + j] = 1;
			cin >> p[i][j];
			if(portal[p[i][j]].f == -1){
				portal[p[i][j]].f = i;
			}
			else{
				portal[p[i][j]].s = i;
			}
		}
	}
	vector<array<int,5>> edges;
	for(int i = 0;i  < N;i ++){
		//cout << i << endl;
		merge(i*4, i*4+1);
		merge(i*4 + 2, i*4 + 3);
		for(int j = 0;j < 4;j ++){
			int nv = (portal[p[i][j]].f == i ? portal[p[i][j]].s : portal[p[i][j]].f);
			//cout << nv << endl;
			for(int x = 0; x < 4; x++){
				//cout << x << " " << nv << endl;
				if(p[nv][x]==p[i][j]){
					//cout << i*4 + j << " " << nv*4 + x << endl;
					merge(i*4 + j, nv*4 + x);
				}
				//cout << j << " " << x << endl;
			} 
		}
		edges.pb({c[i], i*4, i*4+3, i*4+1, i*4+2});
		edges.pb({c[i], i*4+2,i*4, i*4+3, i*4+1});
		
	}
	//cout << ans << '\n';
	sort(edges.begin(), edges.end());

	for(auto it : edges){
		if(find(it[1]) != find(it[2]) || find(it[3] != find(it[4]))){
			merge(it[1], it[2]);
			merge(it[3], it[4]);
			ans += it[0];
		}
	}
	cout << ans << '\n';
}
