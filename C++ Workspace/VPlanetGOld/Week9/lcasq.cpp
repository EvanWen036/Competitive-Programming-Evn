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
	int N;
	int anc[10005][30];
	int depth[10005];
	vector<int> adj[10005];
	void dfs(int u){
		for(int v : adj[u]){
			anc[v][0] = u;
			depth[v] = depth[u]+1;
			dfs(v);
		}
	}
	int lca(int a, int b){
		if(depth[a] > depth[b])swap(a,b);
		int d = depth[b]-depth[a];
		for(int i = 0; i < 30; i++){
			if(d & (1 << i)){
				b = anc[b][i];
			}
		}
		if(a == b)return a;
		for(int i = 20; i >= 0; i--){
			if(anc[a][i] != anc[b][i]){
				a = anc[a][i];
				b = anc[b][i];
			}
		}
		return anc[a][0];
	}
	int main(){

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cin >> N;
		for(int i = 0; i < N;i ++){
			int x;
			cin >> x;
			for(int j = 0;j < x;j ++){
				int y;
				cin >> y;
				adj[i].pb(y);
			}
		}
		memset(anc, -1, sizeof(anc));
		dfs(0);
		for(int i = 1; i < 30; i++){
			for(int j = 0; j < N;j ++){
				int mid = anc[j][i-1];
				if(mid != -1){
					anc[j][i] = anc[mid][i-1];
				}
			}
		}
		int Q;
		cin >> Q;
		for(int i = 0; i < Q;i ++){
			int a, b;
			cin >> a >> b;
			cout << lca(a,b) << '\n';
		}

	}
