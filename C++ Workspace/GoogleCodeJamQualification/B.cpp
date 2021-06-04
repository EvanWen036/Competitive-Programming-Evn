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
int dp[1005][2];
char let[2] = {'C', 'J'};
void solve(){
	//cout << '\n';
	int x, y;
	string s;
	cin >> x >> y >> s;
	for(int i = 0;i <= 1000;i ++){
		dp[i][0] = 1e9;
		dp[i][1] = 1e9;
	}
	dp[0][0] = 0;
	dp[0][1] = 0;
	for(int i = 1; i <= s.length(); i++){
		for(int j = 0;j < 2;j ++){
			if(s[i-1] != '?' && s[i-1] != let[j])continue;
			if(j == 0){
				dp[i][j] = min(dp[i][j], dp[i-1][0]);
				dp[i][j] = min(dp[i][j], dp[i-1][1] + y);
			}
			if(j == 1){
				dp[i][j] = min(dp[i][j], dp[i-1][1]);
				dp[i][j] = min(dp[i][j], dp[i-1][0] + x);
			}
			//cout << dp[i][j] << " ";
		}
		//cout << '\n';
	}
	cout << min(dp[s.length()][0], dp[s.length()][1]) << '\n';
	//cout << x << " " << y << '\n';
	
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for(int i = 1;i <= T;i ++){
		cout << "Case #" << i << ": ";
		solve();
	}


}
