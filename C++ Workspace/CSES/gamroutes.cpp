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
vector<int> adj[100005];
int indeg[100005];
int cnt[100005];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;

	for(int i = 0;i < m; i++){
		int a, b;
		cin >> a >> b; a--; b--;
		adj[a].pb(b);
		indeg[b]++;
	}
	queue<int> q;
	for(int i= 0; i < n; i++){
		if(indeg[i] == 0){
			q.push(i);
		}
	}
	cnt[0] = 1;
	while(!q.empty()){
		int fi = q.front(); q.pop();
		for(int u : adj[fi]){
			indeg[u]--;
			if(indeg[u] == 0)q.push(u);
			cnt[u] = (cnt[u] + cnt[fi]) % 1000000007;
		}
	}
	cout << cnt[n-1];

}
