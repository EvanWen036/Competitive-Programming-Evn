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
int stz[200005];
vector<int> adj[200005];
int n;
void dfs(int u, int p){
	stz[u] = 1;
	for(int v : adj[u]){
		if(v ==p)continue;
		dfs(v,u);
		stz[u] += stz[v];
	}
	//cout << u << " " << stz[u] << '\n';
	for(int v : adj[u]){
		int nodes = 0;
		if(v==p){
			nodes = n - stz[u];
		}
		else{
			nodes = stz[v];
		}
		if(nodes > n/2)return;
	}
	cout << u+1 << '\n';
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n-1;i ++){
		int a, b;
		cin >> a >> b; 
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}	
	dfs(0, -1);

}
