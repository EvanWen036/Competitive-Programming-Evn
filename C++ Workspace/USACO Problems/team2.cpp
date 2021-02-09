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
ll dp[15][1005][1005];
int main(){
	freopen("team.in", "r", stdin);
	freopen("team.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, K;
	cin >> N >> M >> K;
	vector<int> A(N);
	vector<int> B(M);
	for(int i = 0; i < N;i ++){
		cin >> A[i];
	}	
	for(int j = 0;j < M;j ++){
		cin >> B[j];
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	ll mod = 1e9+9;
	dp[0][0][0] = 1;
	for(int k = 0;k <= K;k ++){
		for(int i = 0; i <= N;i ++){
			for(int j = 0; j<= M; j++){
				if(k == 0 && i == 0 && j ==0)continue;
				//solve dp[i][j][k]
				ll ways = 0;
				if(i > 0){
					ways += dp[k][i-1][j];
				}
				if(j > 0){
					ways += dp[k][i][j-1];
				}
				ways %= mod;
				ways += mod;
				if(i > 0 && j > 0){
					ways -= dp[k][i-1][j-1];
				}
				assert(ways >= 0);
				ways %= mod;
				if(k > 0 && i > 0 && j > 0 && A[i-1] > B[j-1]){
					ways += dp[k-1][i-1][j-1];
				}
				ways %= mod;
				dp[k][i][j] = ways;
				//cout << k << " " << i << " " << j << " " << dp[k][i][j] << '\n';
			}
		}
	}
	cout << dp[K][N][M];
}
