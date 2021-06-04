#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define sz(a) a.size()
typedef long long ll;
typedef pair<int, ll> pii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
int N;
ll L;
int pre[400005];
int mx[400005];
ll depth[200005];
vector<pair<int,ll>> adj[200005];
int BIT[400005];
int timer = 1;
ll ans[200005];
void dfs(int u){
	pre[u] = timer++;
	for(pair<int, ll> edge : adj[u]){
		depth[edge.f] = depth[u] + edge.s;
		dfs(edge.f);
	}

	mx[u] = timer-1;
}
void update(int idx, int val){
    for(int i = idx; i <= 200000; i += i & -i){
        BIT[i] += val;
    }
}
int query(int idx){
    int s = 0;
    if(idx == 0)return 0;
    for(int i = idx; i >= 1; i -= i & -i){
       s  += BIT[i];
    }
    return s;
}
main(){
	freopen("runaway.in", "r", stdin);
	freopen("runaway.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> L;
	for(int i = 1; i < N; i++){
		int p; ll w;
		cin >> p >> w; p--;
		adj[p].pb({i,w});
	}
	dfs(0);
	vector<array<ll,3>> event;
	for(int i = 0; i < N;i ++){
		event.pb({depth[i], 1, i});
		event.pb({depth[i] + L , 2, i});
	}
	sort(event.begin(), event.end());
	for(auto it : event){
		if(it[1] == 1){
			//update
			update(pre[it[2]], 1);
		}
		else{
			ans[it[2]] = query(mx[it[2]]) - query(pre[it[2]]-1);
		}
	}
	for(int i = 0; i < N;i ++){
		cout << ans[i] << '\n';
	}
}
