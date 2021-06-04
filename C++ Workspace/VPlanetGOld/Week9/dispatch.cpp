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
#define int long long
int N, M;
vector<int> adj[100005];
ll l[100005];
ll s[100005];
ll sum[100005];
multiset<int> val[100005];

ll ans = 0;
void dfs(int u){
	sum[u] = s[u];
	int big = u;
	for(int v : adj[u]){
		dfs(v);
		if(val[v].size() > val[big].size()){
			big = v;
		}
		sum[u] += sum[v];
		//val[v].clear();
	}
	swap(val[u], val[big]);
	val[u].insert(s[u]);
	for(int v : adj[u]){
		if(v == big)continue;
		for(int x : val[v]){
			val[u].insert(x);
		}
	}
	multiset<int>::iterator it = val[u].end();
	multiset<int> remove;
	while(sum[u] > M){
		--it;
		sum[u] -= *it;
		remove.insert(*it);
	}
	for(auto it : remove){
		val[u].erase(val[u].find(it));
	}
	ans = max(ans,1LL * (ll)val[u].size() * l[u]);

}
int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for(int i = 0; i < N;i ++){
		int x;
		cin >> x >> s[i] >> l[i];;
		x--;
		if(x >= 0){
			adj[x].pb(i);
		}
	}
	dfs(0);
	cout << ans << '\n';
}