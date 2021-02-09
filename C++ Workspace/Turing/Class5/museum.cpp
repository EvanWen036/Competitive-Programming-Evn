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
vector<pii> adj[10005];
bool counted[100005];
int ans = 1e9;
//min weight if you visit u and have counted v nodes
bool states[10005][10005];
int calc(int u, int v){
	states[u][v] = true;
	cout << u << " " << v << "\n";
	if(v == 0){
		return 0;
	}
	int best = 1e9;
	for(pii it : adj[u]){
		if(counted[it.f]){
			if(states[it.f][v])continue;
			best = min(best, it.s + calc(it.f,v));
		}
		else{
			counted[it.f] = true;
			if(states[it.f][v-1])continue;
			best = min(best, it.s + calc(it.f,v-1));
			counted[it.f] = false;
		}
	}
	return best;
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, start;
	cin >> n >> k >> start; start--;
	for(int i = 0; i < n-1; i++){
		int a, b, w;
		cin >> a >> b >> w;
		a--; b--;
		adj[a].pb({b,w});
		adj[b].pb({a,w});
	}
	/**
	for(int i = 0; i < n;i ++){
		for(int j = 0;j <= k; j++){
			states[i][j] = -1;
		}
	}**/
	counted[start] = true;
	cout << calc(start, k-1) << '\n';

}
