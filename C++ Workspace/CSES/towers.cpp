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
ll dp[1000005][3];
ll mod = 1e9+7;
int n;


void solve(){
	memset(dp, 0LL, sizeof(dp));
	dp[1][1] = 1LL;
	dp[1][2] = 1LL;
	for(int i = 2; i <= 1000000; i++){
		//don't extend
		dp[i][1] += dp[i-1][1] + dp[i-1][2];
		//extend both
		dp[i][1] += dp[i-1][1];
		dp[i][1] %= mod;
		//don't extend
		dp[i][2] += dp[i-1][1] + dp[i-1][2];
		//extend both
		dp[i][2] += dp[i-1][2];
		//extend one
		dp[i][2] += 2LL * dp[i-1][2];
		dp[i][2] %= mod;
	}	
	//cout << (dp[n][1] + dp[n][2]) % mod << '\n';
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	solve();
	while(t--){
		int n;
		cin >> n;
		cout << (dp[n][1]+dp[n][2])%mod<<'\n';
	}


}
