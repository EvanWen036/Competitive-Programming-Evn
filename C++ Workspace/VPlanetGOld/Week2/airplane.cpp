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
int dp[10005];
int pre[10005];
int main(){
	int t;
	cin >> t;
	while(t--){
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		int N;
		cin >> N;
		assert(N <= 10000);
		memset(dp, 0, sizeof(dp));
		vector<tuple<int,int,int>> ranges;
		for(int i = 0;i < N;i ++){
			int a, b, c;
			cin >> a >> b >> c;
			b = a+b-1;
			ranges.pb(make_tuple(b,a,c));
		}
		
		sort(ranges.begin(), ranges.end());
		dp[0] = 0;
		vector<pii> endPoints;
		for(int i = 1; i <= N;i ++){
			vector<pii>::iterator it = lower_bound(begin(endPoints), end(endPoints), mp(get<1>(ranges[i-1]), 0));
			int ind = 0;
			if(it != begin(endPoints)){
				it--;
				ind = (*it).s;
			}	
			pre[i] = ind;
			endPoints.pb({get<0>(ranges[i-1]),i});
		}
		
		for(int i = 1; i <= N;i ++){
			dp[i] = max(dp[i-1], get<2>(ranges[i-1]) + dp[pre[i]]);
		}
		cout << dp[N] << '\n';
		
	}
}
