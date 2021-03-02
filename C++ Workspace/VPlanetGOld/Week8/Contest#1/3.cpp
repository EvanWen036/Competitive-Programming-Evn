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
ll bu[105];
ll dp[105][505];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll N, M, K;
	cin >> N >> M >> K;
	for(int i = 0; i < N;i ++){
		int x;
		cin >> x;
		bu[x]++;
	}
	for(int i = 0; i <= M;i ++){
		for(int j = 0;j <= K;j ++){
			dp[i][j] = 1e15;
		}
	}
	dp[0][0] = 0;
	for(int i = 1; i <= M;i ++){
		for(int j = 0;j <= K;j ++){
			for(int c = 0; c <= j; c++){
				int k = j-c;
				ll ans = 0;
				ll amt = (bu[i]/(k+1));
				ans += (k+1)*(amt*(amt+1))/2;
				ans += (bu[i] % (k+1)) * (amt+1);
				dp[i][j] = min(dp[i][j], dp[i-1][c] + ans);
			}
		}
	}
	cout << dp[M][K] << '\n';



}
