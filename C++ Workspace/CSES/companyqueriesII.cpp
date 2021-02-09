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
vector<int> adj[200005];
int depth[200005];
int anc[200005][30];
void dfs(int v, int p){
	for(int u : adj[v]){
		if(u == p)continue;
		depth[u] = depth[v]+1;
		anc[u][0] = v;
		dfs(u, v);
	}
}
void fillTable(){
    for(int k = 1; k <= 24; k++){
        for(int i = 0; i < N; i++){
            int mid = anc[i][k-1];
            if(mid != -1){
                anc[i][k] = anc[mid][k-1];
            }
        }
    }
}
int walk(int i, int k){
    for(int d =0; d <= 24 && i != -1; d++){
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
    for(int d= 24; d >= 0; d--){
        if(anc[i][d] != anc[j][d]){
            i = anc[i][d];
            j = anc[j][d];
        }
    }
    return anc[i][0];
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin >> N >> q;
	for(int i = 1; i <= N-1; i++){
		int a;
		cin >> a;
		a--;
		adj[a].pb(i);
	}	
	memset(anc, -1, sizeof(anc));
	dfs(0, -1);
	fillTable();
	for(int i = 0;i < q;i ++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		//cout<<a << " " << b << " " << depth[a] << " " << depth[b] << endl;
		cout << lca(a,b)+1<< "\n";
	}

}
