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
int dp[100005][3];

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[0][2] = 0; 
	for(int i = 1; i <= N; i++){
		vector<int> a(3);
		for(int j = 0; j < 3;j ++)cin >> a[j];
		for(int j = 0;j < 3; j++){
			for(int k = 0;k < 3;k ++){
				if(k != j){
					assert(i - 1 >= 0);
					dp[i][j] = max(dp[i][j], dp[i-1][k] + a[j]);
				}
			}
		}
		//cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << '\n';
	}	
	cout << max({dp[N][0], dp[N][1], dp[N][2]}) << '\n';

}
