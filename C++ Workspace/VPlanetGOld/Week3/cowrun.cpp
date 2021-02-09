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
int dp[1005][1005][2];
vector<int> A;
int main(){
	freopen("cowrun.in", "r", stdin);
	freopen("cowrun.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for(int i = 0; i < N;i ++){
		int x;
		cin >> x;
		A.pb(x);
	}	
	sort(begin(A), end(A));
	for(int i = 0; i < N;i ++){
		dp[i][i][0] = abs(A[i]) * N;
		dp[i][i][1] = abs(A[i]) * N;
	}
	for(int i = N-1; i >= 0; i--){
		for(int j = i+1;j < N;j ++){
			for(int k = 0; k < 2;k ++){
				if(k == 0){
					dp[i][j][k] = min(dp[i+1][j][0] + abs(A[i+1]-A[i]) * (N-(j-i)), dp[i+1][j][1] + abs(A[j] - A[i]) * (N-(j-i)));
				}
				else{
					dp[i][j][k] = min(dp[i][j-1][0] + abs(A[i] - A[j]) * (N-(j-i)), dp[i][j-1][1] + abs(A[j-1] - A[j]) * (N-(j-i)));
				}
			}
		}
	}
	cout << min(dp[0][N-1][0], dp[0][N-1][1]) << '\n';


}
