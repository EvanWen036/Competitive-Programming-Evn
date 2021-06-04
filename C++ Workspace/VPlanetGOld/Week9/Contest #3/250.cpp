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
int n, k;
vector<pii> adj[105];
int l[105];
bool toggled[105];
int can = 0;
multiset<int> fi[105];
int mask = 0;
void merge(int u, int v, int w){
	for(int x : fi[v]){
		can += x * w;
		fi[u].insert(x);
	}
}
void dfs(int u){
	assert(fi[u].size() == 0);
	for(pii v : adj[u]){
		dfs(v.f);
		merge(u, v.f, v.s);
	}
	if(!toggled[u]){
		fi[u].insert(l[u]);
	}
	if(toggled[u]){
		fi[u].clear();
	}
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for(int i = 1; i <= n;i ++){
		int pa, w;
		cin >> l[i] >> pa >> w;
		adj[pa].pb({i,w});
	}
	int ans = 2e9;
	for(int i = 0;i < (1 << n); i++){
		if(__builtin_popcount(i) == k){
			memset(toggled, false, sizeof(toggled));
			for(int j = 0;j < n; j++){
				if(i & (1 << j)){
					toggled[j+1] = true;
				}
			}
			mask = i;
			toggled[0] = true;
			can = 0;
			for(int j = 0;j <= n;j ++){
				fi[j].clear();
			}
			dfs(0);
			ans = min(ans, can);
		}
	}
	cout << ans << '\n';

}
