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
int dp[1000005];
int solve(int n){
	//cout << n << endl;
	if(dp[n] == -1){
		if(n == 0){
			dp[0] = 0;
			return 0;
		}
		string s = to_string(n);
		int poss = 1e9;
		for(int i = 0; i < s.length(); i++){
			int dig = s[i] - '0';
			if(dig == 0)continue;
			poss = min(poss, 1+solve(n-dig));
		}
		dp[n] = poss;
	}
	return dp[n];
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	memset(dp, -1, sizeof(dp));
	cout << solve(n) << '\n';


}
