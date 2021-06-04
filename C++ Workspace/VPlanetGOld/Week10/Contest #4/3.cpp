#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define sz(a) a.size()
typedef long long ll;
typedef pair<int, long long> pii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
int N;
ll L;
vector<pair<int,long long>> adj[200005];
ll depth[200005];
multiset<ll> st[200005];
int ans[200005];
void dfs(int u){
	for(pii edge : adj[u]){
		depth[edge.f] = depth[u] + edge.s;
		dfs(edge.f);
	}
}
void dfs2(int u){
	int big = u;
	ll bigwt = -1;
	for(pair<int, ll> edge: adj[u]){
		dfs2(edge.f);
		if(st[edge.f].size() > st[big].size()){
			big = edge.f;
			bigwt = edge.s;
		}
	}
	//remove the ones that are too big
	/**
	swap(st[u], st[big]);
	multiset<ll> remove;
	multiset<ll> add;
	multiset<ll>::iterator it = st[u].begin();
	while(it != st[u].end()){
		remove.insert(*it);
		if(*it >= bigwt){
			add.insert(*it - bigwt);
		}
		it++;
	}
	for(ll r : remove)st[u].erase(st[u].find(r));
	for(ll r : add)st[u].insert(r);
	**/
	st[u].insert(L);

	for(pair<int, ll> edge : adj[u]){
		//int big = (st[u].size() > st[edge.f].size() ? u:edge.f);
		//int small = (big == u ? edge.f:u);
		for(ll x : st[edge.f]){
			if(x >= edge.s){
				st[u].insert({x - edge.s});
			}
		}
	}
	/**
	cout << u << '\n';
	for(ll x : st[u]){
		cout << x << " ";
	}
	cout << '\n';**/
	ans[u] = st[u].size();
}
main(){
	freopen("runaway.in", "r", stdin);
	freopen("runaway.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//p3
	cin >> N >> L;
	for(int i = 1; i < N; i++){
		int p; ll wt;
		cin >> p >> wt;
		adj[p-1].pb({i, wt});
	}
	//dfs to compute node depths
	dfs(0);
	//dfs with small to large merging
	dfs2(0);
	for(int i = 0; i < N;i ++){
		cout << ans[i] << '\n';
	}
}
