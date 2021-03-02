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

ll dp[10005][405];
vector<pair<int,long>> adj[10005];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, h;	
	cin >> n >> m >> h;
	for(int i = 0; i < n-1;i ++){
		for(int j = 0;j < h;j ++){
			int a, b;
			cin >> a >> b;
			if(a <= i)continue;
			adj[i].pb({a,b});
		}
	}
	dp[0][0] = 1;
	for(int i = 0; i < n;i ++){
		for(int j = 0;j <= m; j++){
			for(auto it : adj[i]){
				if(it.s + j <= m){
					dp[it.f][j+it.s] += dp[i][j];
					dp[it.f][j+it.s]=min(dp[it.f][j+it.s], 500000001LL);
				}
			}
			if(i != 0 && j != m){
				dp[i][j+1] += dp[i][j];
				dp[i][j+1] = min(dp[i][j+1], 500000001LL);
			}
		}
	}
	
	for(int i = 0; i < m; i++){
		cout << min(500000001LL, dp[n-1][i]) << " ";
	}
}
