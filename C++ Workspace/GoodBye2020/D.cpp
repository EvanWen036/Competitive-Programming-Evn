#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll, ll> pii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
void solve(){
	int n;
	cin >> n;
	vector<int> weights;
	int s = 0;
	for(int i = 0; i < n; i++){
		int w;
		cin >> w;
		weights.pb(w);
		s += w;
	}
	vector<int> adj[n];
	int degree[n];
	for(int i = 0; i < n-1; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	multiset<pii> nonleafs;
	for(int i = 0; i < n;i ++){
		degree[i]=adj[i].size();
		if(adj[i].size() != 1){
			nonleafs.insert({weights[i], i});
		}
	}
	cout << s << " ";
	for(int k = 2; k <= n-1;k ++){
		if(nonleafs.size() > 0){
			s += (*(--nonleafs.end())).f;
			degree[(*(--nonleafs.end())).s]--;
			if(degree[(*(--nonleafs.end())).s] <= 1){
				nonleafs.erase(--nonleafs.end());
			}
		}
		cout << s << " ";
	}
	cout << '\n';
}
int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}


}
