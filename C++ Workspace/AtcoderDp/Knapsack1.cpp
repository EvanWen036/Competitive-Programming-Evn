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
ll dp[100005];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, W;
	cin >> N >> W;
	vector<ll> weights(N+1);
	vector<ll> values(N+1);
	for(int i = 1; i <= N;i ++){
		cin >> weights[i] >> values[i];
	}
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	ll ans = 0;
	for(int i = 1; i <= N;i ++){
		for(int j = W; j >= weights[i]; j--){
			if(dp[j-weights[i]] != -1){
				dp[j] = max(dp[j], dp[j-weights[i]] + values[i]);
				ans = max(ans, dp[j]);
			}
		}
	}
	cout << ans << '\n';

}
