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
#define int long long
ll dp[1005*100];
int32_t main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, W;
	cin >> N >> W;
	//dp[i] = min weight for carry a value of i
	vector<ll> values(N+1);
	vector<ll> weights(N+1);
	for(int i = 1;i <= N; i++){
		cin >> weights[i] >> values[i];
	}
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	ll ans = 0;
	for(int i = 1; i <= N; i++){
		for(int j = 1000*100;j >= values[i]; j--){
			if(dp[j - values[i]] != -1){
				
				if(dp[j] == -1){
					dp[j] = dp[j-values[i]] + weights[i];
					if(dp[j] <= W)ans = max(ans, 1LL * j);
				}
				else{
					dp[j] = min(dp[j], dp[j-values[i]] + weights[i]);
					if(dp[j] <= W) ans = max(ans,1LL * j);
				}
			}
		}
	}
	cout << ans << '\n';
}