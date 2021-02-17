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
int dp[155][155];
int main(){
	freopen("recording.in", "r", stdin);
	freopen("recording.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	vector<pii> intervals;
	for(int i = 0; i < N;i ++){
		int a, b;
		cin >> a >> b;
		b--;
		intervals.pb({b,a});
	}	
	sort(intervals.begin(), intervals.end());
	for(int i = 0; i < N;i ++){
		swap(intervals[i].f, intervals[i].s);
	}
	dp[0][0] = 0;
	int ans=  0;
	for(int s1 = 0; s1 <= N; s1++){
		for(int s2 = 0; s2 <= N; s2++){
			if(s1 == s2)continue;
			//could have came from x, s2 or s1, x
			if(s1 != 0){
				for(int x = 0; x < s1; x++){
					if(x==0){
						dp[s1][s2] = max(dp[s1][s2], 1+dp[0][s2]);
						continue;
					}
					if(intervals[x-1].s < intervals[s1-1].f){
						dp[s1][s2] = max(dp[s1][s2], 1+dp[x][s2]);
					}
				}
			}
			if(s2 != 0){
				for(int x = 0; x < s2; x++){
					if(x==0){
						dp[s1][s2]=max(dp[s1][s2], 1 + dp[s1][0]);
						continue;
					}
					if(intervals[x-1].s < intervals[s2-1].f){
						dp[s1][s2] = max(dp[s1][s2], 1 + dp[s1][x]);
					}
				}
			}
			dp[s1][s2] = max(dp[s1][s2], 1);
			//cout << s1 << " " << s2 << " " << dp[s1][s2] << '\n';
			ans = max(ans, dp[s1][s2]);
		}
	}
	cout << ans << '\n';



}
