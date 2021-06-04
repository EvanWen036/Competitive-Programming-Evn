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
int n,k;
vector<pii> adj[105];
int l[105];	
int cnt[105][55][105];
int dp[105][55][105];
int stz[105];
void dfs(int node){
	stz[node] = 1;
	for(pii edge : adj[node]){
		dfs(edge.f);
		stz[node] += stz[edge.f];
	}

}
int amt[105];
int dfs(int node, int sawmills, int anc){
	//cout << node << " " << sawmills << " " << anc << endl;

	if(dp[node][sawmills][anc] != 2e9)return dp[node][sawmills][anc];
	memset(amt, 0, sizeof(amt));
	if(node != 0 && node == anc)sawmills--;
	int best = 2e9;
	int bestcnt = 2e9;
	for(int j = 0;j <= sawmills;j ++){
		//give the j'th sawmill to each child
		for(pii edge : adj[node]){
			if(amt[edge.f] + 1 > stz[edge.f])continue;
			amt[edge.f]++;
			int curr = 0;
			int  currcnt = 0;
			for(pii edge2 : adj[node]){
				//do all the children
				int child = edge2.f;
				int c1 = dfs(child, amt[child], child);
				int c2 = 2e9;
				if(amt[child] != 0){
					int c2 = dfs(child, amt[child], anc);
					c2 += cnt[child][amt[child]][anc] * edge2.s;
				} 
				if(c1 <= c2){
					curr += c1;
				}
				else{
					curr += c2;
					currcnt += cnt[child][amt[child]][anc];
				}
			}
			if(curr < best){
				best = curr;
				bestcnt = currcnt;
			}
			if(curr == best){
				if(currcnt < bestcnt)bestcnt = currcnt;
			}
			amt[edge.f]--;
		}
	}
	if(adj[node].size() == 0){
		assert(sawmills <= 1);
		dp[node][sawmills][anc] = 0;
		if(node != anc){
			cnt[node][sawmills][anc] += l[node];
		}
		return dp[node][sawmills][anc];
	}
	if(node != anc){
		bestcnt += l[node];
	}
	dp[node][sawmills][anc] = best;
	cnt[node][sawmills][anc] = bestcnt;
	if(node == anc){
		cnt[node][sawmills][anc] = 0;
	}
	return dp[node][sawmills][anc];
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for(int i = 1; i <= n;i ++){
		cin >> l[i];
		int p, w;
		cin >> p >> w;
		adj[p].pb({i,w});
	}
	for(int i = 0; i <= n; i++){
		for(int j = 0;j  <= k;j ++){
			for(int x = 0; x <= n; x++){
				dp[i][j][x] = 2e9;
			}
		}
	}
	dfs(0);
	cout << dfs(0, k, 0) << '\n';
	for(int i = 0; i <= n; i++){
		for(int j = 0;j <= k;j ++){
			for(int x = 0; x <= n; x++){
				cout  << i << " " << j << " " << x << " " << dp[i][j][x] << '\n';
			}
		}
	}

}
