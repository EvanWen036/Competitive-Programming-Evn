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
int dp[1005][1005];
int mod = 1e9+7;
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int H, W;
	cin >> H >> W;
	int mat[H+1][W+1];
	for(int i = 1; i <= H;i ++){
		string line;
		cin >> line;
		for(int j = 1;j <= W; j++){
			mat[i][j] = line[j-1];
		}
	}
	if(mat[1][1] == '#'){
		//bruh
		cout << 0 << '\n';
		exit(0);
	}
	dp[1][1] = 1;
	for(int i = 1; i<= H;i ++){
		for(int j = 1; j<=W;j ++){
			if(i == 1 && j==1)continue;
			if(mat[i][j] == '#')continue;
			dp[i][j] = dp[i-1][j]+dp[i][j-1];
			dp[i][j] %= mod;
		}
	}
	cout << dp[H][W] << '\n';
}
