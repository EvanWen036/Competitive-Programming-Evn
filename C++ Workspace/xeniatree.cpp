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
int n, m;
set<int> adj[100005];
int sub[100005];
int parent[100005];
int ans[100005];
int depth[100005];
int anc[100005][30];
int get_centroid(int u, int p, int n){
	for(int v : adj[u]){
		//if v has more than n/2
		if(v != p && sub[v] > n/2)return get_centroid(v,u,n);
	}
	return u;
}
int dfs(int u, int p){
	///cout << u << " " << p << endl;
	sub[u] = 1;
	for(int v : adj[u]){
		if(v != p){
			sub[u]+=dfs(v,u);
		}
	}
	return sub[u];
}
void dfs2(int u, int p){
	//cout << u << " " << p << "\n";
	for(int v: adj[u]){
		if(v != p){
			//cout << u << " " << v  << '\n';
			depth[v] = depth[u]+1;
			anc[v][0] = u;
			dfs2(v, u);
		}
	}
}
void build(int u, int p){
	int n = dfs(u, p);
	int centroid = get_centroid(u,p,n);
	parent[centroid] = p;
	//cout << u << " " << p << " " << centroid << endl;
	set<int> erase;
	for(int v : adj[centroid]){
		erase.insert(v);
	}
	for(int v : erase){
		adj[centroid].erase(v);
		adj[v].erase(centroid);
		build(v, centroid);
	}
	//cout << "BYE: " << u << " " << p << endl;
}
int walk(int i, int k){
    for(int d =0; d <= 25 && i != -1; d++){
        if(((1<<d) & k)){
            i = anc[i][d];
        }
    }
    return i;
}
int lca(int i, int j){
    if(depth[i] > depth[j]){
        i = walk(i, depth[i] - depth[j]);
    }
    if(depth[j] > depth[i]){
        j = walk(j, depth[j] -depth[i]);
    }
    //cout << i << " " << j << endl;
    if(i == j){
        return i;
    }
    for(int d= 25; d >= 0; d--){
        if(anc[i][d] != anc[j][d]){
            i = anc[i][d];
            j = anc[j][d];
        }
    }
    return anc[i][0];
}
int dist(int a, int b){
	int an = lca(a,b);
	//cout << a << " " << b << " " << an << '\n';
	return depth[a]-depth[an]+depth[b]-depth[an];
}
void update(int a){
	//paint node a rose
	int curr = a;
	while(curr != 0){
		ans[curr] = min(ans[curr], dist(a,curr));
		curr = parent[curr];
	}
}
int query(int a){
	//return closest rose node to a
	int curr = a;
	int ret = 2e9;
	while(curr != 0){
		ret = min(ret, ans[curr] + dist(curr, a));
		curr = parent[curr];
	}
	return ret;
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n-1; i++){
		int a, b;
		cin >> a >> b;
		adj[a].insert(b);
		adj[b].insert(a);
	}	
	for(int i = 1;i  <= n; i++){
		ans[i] = 1e9;
		for(int j = 0;j <= 25;j ++){
			anc[i][j] = -1;
		}
	}
	dfs2(1,0);
	depth[1] = 0;
	build(1, 0);
	for(int j = 1;j <= 29;j ++){
		for(int i = 1; i <= n;i ++){
			int mid = anc[i][j-1];
			if(mid != -1){
				anc[i][j] = anc[mid][j-1];
			}
		}
	}	
	update(1);
	for(int i = 0; i < m; i++){
		int a, x;
		cin >> a >> x;
		if(a == 1){
			//update
			update(x);
		}
		else{
			cout << query(x) << '\n';
		}
	}


}
