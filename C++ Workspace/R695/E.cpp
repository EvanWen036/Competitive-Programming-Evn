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
vector<int> color(200005);
vector<int> adj[200005];
bool possible = true;
void dfs(int u, int p){
	for(int v:adj[u]){
		if(v != p){
			if(color[v] == color[u])possible = false;
			dfs(v,u);
		}
	}
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> color[i];
	}
	for(int i = 0; i < n-1; i++){
		int a,b;
		cin >> a >> b;
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(0, -1);
	if(!possible){
		cout << 0 << '\n';
		return 0;
	}
	map<int, int> cnt;
	for(int i = 0; i < n; i++){
		cnt[color[i]]++;
	}
	int ans = 0;
	for(auto it : cnt){
		if(it.s == 1)ans++;
	}
	cout << ans << '\n';
}
