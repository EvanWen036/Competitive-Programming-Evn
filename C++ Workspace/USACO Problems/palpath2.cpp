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
int mat[505][505];
ll dp[2][505][505];
ll mod = 1e9+7;
int N;

int main(){
	freopen("palpath.in", "r", stdin);
	freopen("palpath.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;

	for(int i = 1; i <= N;i ++){
		string s;
		cin >> s;
		for(int j = 1; j <= N;j ++){
			mat[i][j] = s[j-1] - 'A';
		}
	}
	if(mat[1][1] != mat[N][N]){
		cout << 0 << '\n';
		return 0;
	}
	//dp[i][j] will impact dp[i+1][j-1] dp[i+1][j] dp[i][j-1] dp[i][j]
	dp[0][1][N] = 1;
	for(int i = 1; i <= N-1;i ++){
		for(int r1 = 1;r1 <= N; r1++){
			for(int r2 = 1; r2 <= N; r2++){
				int col = i - r1 + 2;
				int col2 = 2 * N - r2 - i;
				if(col <= 0 || col > N || col2 <= 0 || col2 > N)continue;
				if(mat[r1][col] != mat[r2][col2]){
					dp[i%2][r1][r2] = 0;
					continue;
				}
				ll ways = 0;
				ways += dp[(i-1)%2][r1][r2];
				ways += dp[(i-1)%2][r1-1][r2+1];
				ways += dp[(i-1)%2][r1-1][r2];
				ways += dp[(i-1)%2][r1][r2+1];
				ways %= mod;
				dp[i%2][r1][r2] = ways;
			}
		}
		memset(dp[(i-1)%2], 0, sizeof(dp[(i-1)%2]));
	}
	ll ans = 0;
	for(int i = 1; i <= N; i++){
		ans += dp[(N-1)%2][i][i];
		ans %= mod;
	}
	cout << ans << '\n';

}
