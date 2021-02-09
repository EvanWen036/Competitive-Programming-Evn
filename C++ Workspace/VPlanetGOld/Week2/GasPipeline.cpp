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
ll dp[200005][3];
void solve(){
	int n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;
	for(int i = 0;i < n;i ++){
		dp[i][1] = 1e15;
		dp[i][2] = 1e15;
	}
	//dp[i][j] = min cost to get the first i with height j
	dp[0][1] = b;
	for(int i = 1; i <= n;i ++){
		if(s[i] != '1' && s[i-1] != '1'){
			//can be not elevated
			dp[i][1] = min(dp[i-1][2] + 2 * a + b, dp[i-1][1] + a + b);
		}
		//elevated
		dp[i][2] = dp[i-1][2] + a + 2 * b;
		dp[i][2] = min(dp[i][2], dp[i-1][1] + 2 * a + 2 * b);
		//cout << dp[i][1] << " " << dp[i][2] << '\n';
	}
	cout << dp[n][1] << '\n';
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}


}
