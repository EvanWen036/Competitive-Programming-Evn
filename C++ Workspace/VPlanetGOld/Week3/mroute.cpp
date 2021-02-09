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
int N, M, X;
vector<pair<int, pii>> adj[505];
set<int> cap;
priority_queue<pii, vector<pii>, greater<pii>> pq;
bool vis[505];
int ans = 2e9;
int main(){
	freopen("mroute.in", "r", stdin);
	freopen("mroute.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> X;
	for(int i = 0; i < M;i ++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--; b--;
		adj[a].pb({b,{c,d}});
		adj[b].pb({a,{c,d}});
		cap.insert(d);
	}
	for(int u : cap){
		pq.push({0,0});
		memset(vis, false, sizeof(vis));
		int l = 0;
		while(!pq.empty()){
			pii cur = pq.top(); pq.pop();
			if(vis[cur.s])continue;
			vis[cur.s] = true;
			if(cur.s == N-1)l = cur.f;
			for(auto it : adj[cur.s]){
				if(it.s.s >= u){
					if(!vis[it.f]){
						pq.push({cur.f + it.s.f, it.f});
					}
				}
			}
		}
		if(!vis[N-1])continue;
		double curr = l + X * 1.0 / u;
		ans = min(ans, (int)curr);
	}
	cout << ans << '\n';


}
