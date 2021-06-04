#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
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
vector<pii> adj[100005];
map<int, bool> vis[100005];
priority_queue<pii, vector<pii>, greater<pii>> pq;
int main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < m;i ++){
		int a, b, w;
		cin >> a >> b >> w;
		a--; b--;
		adj[a].pb({b,w});
		adj[b].pb({a,w});
	}
	//for(int i = 0; i )
	vis[0][1] = true;
	pq.push({1,0});
	int ans = 1e9;
	while(!pq.empty()){
		auto it = pq.top(); pq.pop();
		if(it.s == n-1){
			ans = min(ans, it.f);
		}
		for(auto e : adj[it.s]){
			int newV = std::lcm(e.s, it.f);
			if(!vis[e.f][newV]){
				vis[e.f][newV] = true;
				pq.push({newV, e.f});
			}
		}
	}
	cout << ans << '\n';
 
}