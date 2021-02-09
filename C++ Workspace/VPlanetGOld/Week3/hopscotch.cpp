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
int mat[105][105];
int dp[105][105];
int main(){
	freopen("hopscotch.in", "r", stdin);
	freopen("hopscotch.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int R, C, K;
	cin >> R >> C >> K;
	int mod = 1e9+7;
	for(int i = 0; i < R;i ++){
		for(int j = 0;j < C; j++){
			cin >> mat[i][j];
		}
	}	
	dp[0][0] = 1;
	for(int i = 0; i < R;i ++){
		for(int j = 0;j < C;j ++){
			for(int r = 0; r < i; r++){
				for(int c = 0; c < j; c++){
					if(mat[r][c] != mat[i][j]){
						dp[i][j] += dp[r][c];
						dp[i][j] %= mod;
					}	
				}
			}
			//cout << dp[i][j] << " ";
		}
		//cout << '\n';
	}
	cout << dp[R-1][C-1] << '\n';

}
