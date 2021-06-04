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

int N, K;
int mat[16][16];
int dp[30][16];
int mxcst[16][16];
int sum[16][16];
int ans = 1e9;
int solve(int mask){
	int placed = __builtin_popcount(mask);
	for(int i =0; i <= 29;i ++){
		for(int j = 0;j <= 15;j ++){
			dp[i][j] = 1e9;
		}
	}
	memset(mxcst, 0, sizeof(mxcst));
	//cout << mask << '\n';
	for(int i = 1; i <= N;i ++){
		for(int j = i;j <= N;j ++){
			int curr = 0;
			for(int k = 1; k <= N;k ++){
				curr += sum[k][j] - sum[k][i-1];
				mxcst[i][j] = max(mxcst[i][j], curr);
				if(mask & (1 << (k-1))){
					curr=0;
					//cout << "BRUH " << mask << " " << k << '\n';
				}
				//cout << curr << '\n';
			}
			//cout << i << " " << j << " " << mxcst[i][j] << "\n";
		}
	}
	dp[0][0] = 0;
	for(int j = 0;j <= K-placed;j ++){
		for(int i = 0; i < N;i ++){
			for(int next = i+1; next <= N; next++){
				if(next == N){
					dp[j][next] = min(dp[j][next], max(dp[j][i], mxcst[i+1][N]));
				}
				else{
					dp[j+1][next] = min(dp[j+1][next], max(dp[j][i], mxcst[i+1][next]));
				}
			}
		}
	}
	return dp[K-placed][N];
}
int main(){
	freopen("partition.in", "r", stdin);
	freopen("partition.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	for(int i = 1; i <= N;i ++){
		for(int j = 1; j <= N;j ++){
			cin >> mat[i][j];
			sum[i][j] = sum[i][j-1] + mat[i][j];
		}
	}
	//try all possible horizontal walls 
	for(int i = 0; i < (1 << (N-1));i ++){
		int walls = __builtin_popcount(i);
		if(walls <= K){
			ans = min(ans, solve(i));
		}
	}
	cout << ans << '\n';
}
