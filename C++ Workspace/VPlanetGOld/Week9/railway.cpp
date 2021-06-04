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
int n, m, k;
vector<pii> adj[100005];
int depth[100005];
int anc[100005][30];
set<pii> tr[100005];
int cnt[100005];
void dfs(int u, int p){
	for(pii v : adj[u]){
		if(v.f != p){
			depth[v.f] = depth[u]+1;
			anc[v.f][0] = u;
			dfs(v.f,u);
		}
	}
}
int lca(int a, int b){
	if(depth[a] > depth[b])swap(a,b);
	int d = depth[b]-depth[a];
	for(int i = 0; i <= 25; i++){
		if(d & (1 << i)){
			b = anc[b][i];
		}
	}
	if(a == b)return a;
	for(int i = 25; i >= 0; i--){
		if(anc[a][i] != anc[b][i]){
			a = anc[a][i];
			b = anc[b][i];
		}
	}
	return anc[a][0];
}
void dfs2(int u, int p){
	int big = u;
	//cout << u << " " << tr[u].size() << '\n';
	for(pii v : adj[u]){
		if(v.f != p){
			dfs2(v.f, u);
			//cout << "FROM " << v.f << " to " << u << " " << tr[v.f].size() << '\n'; 

			cnt[v.s] += tr[v.f].size();
			if(tr[v.f].size() > tr[big].size())big = v.f;
			//merge(u, v.f, v.s);
		}
	}
	swap(tr[big], tr[u]);
	set<pii> remove;
	set<pii>::iterator ite = tr[u].lower_bound({u,0});
	while(ite != tr[u].end()){
		if((*ite).f == u)remove.insert(*ite);
		ite++;
	}
	for(auto it : remove){
		tr[u].erase(it);
	}
	for(pii v : adj[u]){
		if(v.f != p){
			for(auto it : tr[v.f]){
				if(it.f == u)continue;
				tr[u].insert(it);
			}
		}
	}

}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	memset(anc, -1, sizeof(anc));
	for(int i = 0; i < n-1; i++){
		int a, b;
		cin >> a >> b; a--; b--;
		adj[a].pb({b,i});
		adj[b].pb({a,i});
	}
	dfs(0, -1);
	for(int i = 1; i <= 25;i ++){
		for(int j = 0;j < n;j ++){
			int mid = anc[j][i-1];
			if(mid != -1){
				anc[j][i] = anc[mid][i-1];
			}
		}
	}
	for(int i = 0; i < m;i ++){
		int si;
		cin >> si;
		vector<int> k(si);
		for(int j = 0;j  < si;j ++){
			cin >> k[j];
			k[j]--;
		}
		int cl = k[0];
		for(int j = 0;j  < si; j++){
			cl = lca(cl, k[j]);
		}
		for(int j = 0;j < si;j ++){
			//cout << k[j] << '\n';
			tr[k[j]].insert({cl, i});
		}
		//cout << cl << '\n';
	}
	dfs2(0, -1);
	vector<int> ot;
	for(int i = 0; i < n-1; i++){
		//cout << i << " " << cnt[i] << '\n';
		if(cnt[i] >= k){
			ot.pb(i);
		}
	}
	cout << ot.size() << '\n';
	for(int u : ot){
		cout << u +1 << " ";
	}
}
