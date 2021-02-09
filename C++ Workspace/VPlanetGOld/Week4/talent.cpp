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
#define int long long
int N, W;
vector<pii> cows;
bool ok(int x){
	vector<int> adjust;
	int dp[N+1][W+1];
	//cout << x << "\n";
	for(int i = 0; i < N;i ++){
		adjust.pb(1000 * cows[i].f - x * cows[i].s);
		//cout << adjust[i] << " ";
	}
	//cout << '\n';

	for(int i = 0; i <= N;i ++){
		for(int j = 0;j <= W;j ++)dp[i][j] = LLONG_MIN;	
	}
	dp[0][0] = 0;
	for(int i = 1; i <= N; i++){
		for(int j = 0;j  <= W; j++){
			dp[i][j] = max(dp[i][j], dp[i-1][j]);
			int newW = cows[i-1].s + j;
			newW = min(W, newW);
			if(dp[i-1][j] != LLONG_MIN){
				dp[i][newW] = max(dp[i][newW], dp[i-1][j] + adjust[i-1]); 
			}
			//cout << dp[i][j] << " ";
		}
		//cout << '\n';
	}
	return dp[N][W] >= 0;
}
int32_t main(){
	freopen("talent.in", "r", stdin);
	freopen("talent.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> W;
	for(int i = 0; i < N;i ++){
		int a, b;
		cin >> a >> b;
		cows.pb({b,a});
	}
	int lo = 0; int hi = 1e5;
	while(lo < hi){
		int mid = (lo+hi+1)/2;
		if(ok(mid)){
			//can try higher
			lo = mid;
		}
		else{
			//answer def lower
			hi = mid-1;
		}
	}
	cout << lo << '\n';


}
