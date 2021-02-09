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
int dp[100005][105];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> x(n+1);
	
	for(int i = 1; i <= n; i++){
		cin >> x[i];
	}	
	int ans = 0;
	int mod = 1000000007;
	if(x[1] == 0){
		for(int j = 1; j <= m; j++){
			dp[1][j] = 1;
		}
	}
	else{
		dp[1][x[1]] = 1;
	}
	for(int i = 2; i<= n;i++){
		//cout << "hi" << endl;
		if(x[i] == 0){
			for(int j = 1; j<= m;j ++){
				dp[i][j] += dp[i-1][j-1]; 
				dp[i][j] += dp[i-1][j];
				dp[i][j] %= mod;
				dp[i][j] += dp[i-1][j+1];
				dp[i][j] %= mod;
			}
		}
		else{
			dp[i][x[i]] += dp[i-1][x[i]];
			dp[i][x[i]] += dp[i-1][x[i]-1];
			dp[i][x[i]] %= mod;
			dp[i][x[i]] += dp[i-1][x[i]+1];
			dp[i][x[i]] %= mod;
		}
	}
	for(int i = 1; i <= m;i++){
		ans += dp[n][i];
		ans %= mod;
	}
	cout << ans << '\n';


}
