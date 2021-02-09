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
int dp[505][505];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;
	cin >> a >> b;
	memset(dp, 0x3f, sizeof(dp));
	for(int i = 0; i <= a; i++){
		for(int j = 0;j <= b; j++){
			if(i == j){
				dp[i][j] = 0;
				continue;
			}
			//cut horizontally
			for(int k = 1; k < i;k ++){
				dp[i][j] = min(dp[i][j], 1 + dp[k][j]+dp[i-k][j]);
			}
			for(int k = 1; k < j;k ++){
				dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j-k]);
			}
		}
	}
	cout << dp[a][b] << '\n';
}
