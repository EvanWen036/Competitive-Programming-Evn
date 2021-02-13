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
set<pii> adj[50005];
int sub[50005];
int parent[50005];
ll ans[50005];
ll depth[50005];
ll depth2[50005];
ll anc[50005][30];
int type[50005];
int get_centroid(int u, int p, int n){
	for(pii v : adj[u]){
		//if v has more than n/2
		if(v.f != p && sub[v.f] > n/2)return get_centroid(v.f,u,n);
	}
	return u;
}
int dfs(int u, int p){
	///cout << u << " " << p << endl;
	sub[u] = 1;
	for(pii v : adj[u]){
		if(v.f != p){
			sub[u]+=dfs(v.f,u);
		}
	}
	return sub[u];
}
void dfs2(int u, int p){
	for(pii v : adj[u]){
		if(v.f != p){
			depth[v.f] = depth[u] + 1;
			depth2[v.f] = depth2[u] + v.s;
			anc[v.f][0] = u;
			dfs2(v.f, u);
		}
	}
}
void build(int u, int p){
	int n = dfs(u, p);
	int centroid = get_centroid(u,p,n);
	parent[centroid] = p;
	set<pii> erase;
	for(pii v : adj[centroid]){
		erase.insert(v);
	}
	for(pii v : erase){
		adj[centroid].erase({v.f, v.s});
		adj[v.f].erase({centroid, v.s});
		build(v.f, centroid);
	}
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
ll dist(int a, int b){
	int an = lca(a,b);
	return depth2[a] - depth2[an] + depth2[b] - depth2[an];
}
map<pii, ll> di;
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for(int i = 1;i <= N;i ++){
		cin >> type[i];
	}
	for(int i = 1;i <= M;i ++){
		ans[i] = 1e18;
	}
	for(int i = 0; i < N-1; i++){
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].insert({b,c});
		adj[b].insert({a,c});
	}
	dfs2(1,0);
	build(1,0);

	for(int j = 1;j <= 29;j ++){
		for(int i = 1; i <= N;i ++){
			int mid = anc[i][j-1];
			if(mid != -1){
				anc[i][j] = anc[mid][j-1];
			}
		}
	}	
	for(int i = 1; i <= N;i ++){
		//cout << parent[i] << '\n';
		int curr = i;
		while(curr != 0){
			//cout << curr << '\n';
			//cout << i << " " << curr << " " << lca(curr, i) << " " << dist(curr,i) << '\n';
			if(di.count({curr, type[i]})){
				ans[type[i]] = min(ans[type[i]], di[{curr,type[i]}] + dist(curr, i));
				di[{curr,type[i]}] = min(di[{curr,type[i]}], dist(curr, i));
			}
			else{
				di[{curr,type[i]}] = dist(curr,i);
			}
			curr = parent[curr];
		}
	}
	for(int i = 1; i <= M;i ++){
		cout << (ans[i]==1e18 ? -1:ans[i]) << " ";
	}
	cout << '\n';


}
