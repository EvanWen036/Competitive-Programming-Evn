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
int dp[1000005][3];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	vector<int> x(N);
	for(int i = 0; i < N;i ++){
		cin >> x[i];
		dp[i][0] = 1e9;
		dp[i][1] = 1e9;
		dp[i][2] = 1e9;
	}
	
	dp[0][x[0]+1] = 0;
	int ans = 1e9;
	for(int i = 1; i < N; i++){
		for(int p = 0; p < 3; p++){
			if(dp[i-1][p] != 1e9){
				if(p == 1 && x[i] >= 0){
					dp[i][x[i]+1] = min(dp[i][x[i]+1], dp[i-1][1]);
				}
				if(p == 0){
					int cv = x[i];
					int cnt = 0;
					while(cv >= -1){
						dp[i][cv+1] = min(dp[i][cv+1], dp[i-1][p] + cnt); 
						cv--;
						cnt++;
					}
				}
				if(p == 2){
					dp[i][2] = min(dp[i][2], dp[i-1][2] + 1 - x[i]);
				}
			}
		}
	}
	for(int i = 0; i < N;i ++){
		//cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << '\n';
	}
	ans = min({dp[N-1][0], dp[N-1][1], dp[N-1][2]});
	if(ans == 1e9)cout << "BRAK\n";
	else{cout << ans << '\n';}


}
