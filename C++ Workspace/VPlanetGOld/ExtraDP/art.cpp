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
vector<pair<ll, ll>> art;
ll dp[500005];
ll ans = 0;
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;	
	for(int i = 0; i < N;i ++){
		ll s, v;
		cin >> s >> v;
		art.pb({s,v});
	}
	sort(art.begin(), art.end());
	dp[1] = art[0].s;
	ans = dp[1];
	for(int i = 2; i <= N; i++){
		dp[i] = max(art[i-1].s, dp[i-1] - (art[i-1].f - art[i-2].f) + art[i-1].s);
		ans = max(ans, dp[i]);
	}
	cout << ans << '\n';

}
