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
int mat[1005][1005];
int dp[1005][1005];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		string s;
		cin >> s;
		for(int j = 1;j <= n;j ++){
			if(s[j-1] == '*'){
				mat[i][j] = 1;
			}
		}	
	}
	int mod = 1e9+7;
	if(mat[1][1]){
		cout << 0 << '\n';
		return 0;
	}
	dp[1][1]=1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j<= n; j++){
			if(mat[i][j])continue;
			dp[i][j] += dp[i-1][j] + dp[i][j-1];
			dp[i][j] %= mod;
		}
	}
	cout << dp[n][n] << '\n';


}
