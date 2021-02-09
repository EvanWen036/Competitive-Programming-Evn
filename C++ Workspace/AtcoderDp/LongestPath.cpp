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
int indeg[100005];
vector<int> adj[100005];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	for(int i = 0;i  < M;i ++){
		int a, b;
		cin >> a >> b; a--; b--;
		adj[a].pb(b);
		indeg[b]++;
	}
	queue<int> q;
	for(int i = 0; i < N;i ++){
		if(indeg[i] == 0){
			q.push(i);
		}
	}
	int dp[100005];
	memset(dp, 0, sizeof(dp));
	int ans = 0;
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(int v : adj[u]){
			dp[v] = max(dp[v], dp[u]+1);
			ans = max(ans, dp[v]);
			indeg[v]--;
			if(indeg[v] == 0)q.push(v);
		}
	}
	cout << ans << '\n';

}
