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
int N, K;
vector<pii> pts;
int dp[505][505];
int dist(pii a, pii b){
	return abs(a.f - b.f) + abs(a.s - b.s);
}
int main(){
	freopen("marathon.in", "r", stdin);
	freopen("marathon.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	for(int i = 0; i < N;i ++){
		int a, b;
		cin >> a >> b;
		pts.pb({a,b});
	}
	for(int i = 0; i <= K; i++)dp[0][i] = 0;
	for(int i = 1;i < N;i ++){
		for(int j = 0;j <= K;j ++){
			dp[i][j] = 2e9;
		}
	}
	int ans = 2e9;
	for(int i = 1; i < N;i ++){
		for(int j  =0;j <= K; j++){
			for(int x = 0; x <= j;x++){
				//the number of skips
				int pos = i-x-1;
				//cout << i << " " << x << " " << pos << '\n';
				if(pos < 0)break;
				dp[i][j] = min(dp[i][j], dp[pos][j-x] + dist(pts[pos], pts[i]));
			}
			if(i == N-1)ans = min(ans, dp[i][j]);
			//cout << dp[i][j] << " ";
		}
		//cout << '\n';
	}
	cout << ans << '\n';
}
