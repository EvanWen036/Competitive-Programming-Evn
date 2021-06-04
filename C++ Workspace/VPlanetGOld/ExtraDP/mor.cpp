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
int n, m, k;
short dp[5005][5005][2];
vector<int> adj[5005];
bool vis[5005][2];
queue<pair<int,short>> q;
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	for(int i = 0; i < n;i ++){
		for(int j = 0;j < n;j ++){
			dp[i][j][0] = 5001;
			dp[i][j][1] = 5001;
		}
	}
	for(int i = 0; i < m;i ++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		dp[a][a][0] = 0;
		dp[b][b][0] = 0;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	for(int i = 0;i < n; i++){
		//launch a bfs from node i
		memset(vis, false, sizeof(vis));
		vis[i][0] = true;
		q.push({i,0});
		while(!q.empty()){
			pair<int,short> c = q.front(); q.pop();
			//if(vis[c.f][c.s%2])continue;
			if(dp[i][c.f][c.s%2] != c.s)continue;
			vis[c.f][c.s%2] = true;
			//if(c.s != dp[i][c.f][c.s%2])continue;
			for(int u : adj[c.f]){
				int pa = c.s%2;
				if(c.s+1 < dp[i][u][(pa+1)%2]){
					assert(c.s+1 <= 5000);
					dp[i][u][(pa+1)%2] = min(dp[i][u][(pa+1)%2], (short)(c.s+1));
					q.push({u, (c.s+1)});
				}
			}
		}
	}
	for(int i = 0; i < k;i ++){
		int a, b, d;
		cin >> a >> b >> d;
		a--; b--;
		bool works = false;
		if(dp[a][b][d%2] <= d && dp[a][b][d%2] != 5001)works = true;
		cout << (works ? "TAK":"NIE") << '\n';
	}

}
