#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll, ll> pii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
ll dp[605][55];
ll mdist(pii a, pii b){
	return abs(a.f - b.f) + abs(a.s - b.s);
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	vector<pii> pts(N);
	for(int i = 0; i < N; i++){
		cin >> pts[i].f >> pts[i].s;
	}
	sort(pts.begin(), pts.end());
	for(int i = 1; i <= N; i++){
		for(int k = 1; k <= i && k <= K;k ++){
			//use the i'th as the k'th 
			for(int x = 1; x < i; x++){
				ll dist = mdist(pts[i-1], pts[x-1]);
				if(k==1)dist = 0;
				dp[i][k] = max(dp[i][k], dp[x][k-1] + dist);
			}
			//cout << dp[i][k] << " ";
		}
		//cout << '\n';
	}
	ll ans = 0;
	for(int i = 1; i <= N;i ++){
		ans = max(ans, dp[i][K]);

	}
	cout << ans << '\n';

}
