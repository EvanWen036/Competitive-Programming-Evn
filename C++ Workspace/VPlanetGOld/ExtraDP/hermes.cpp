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
int N;
int pre[2001][2];
int dp[2001][2];
vector<pii> pts(20001);
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	pts[0].f = 1000;
	pts[0].s = 1000;
	for(int i = 1; i <= N;i ++){
		cin >> pts[i].f >> pts[i].s;
		pts[i].f += 1000; pts[i].s += 1000;
		for(int j = 0;j <= 2000; j++){
			pre[j][0] = 1e9;
			pre[j][1] = 1e9;
			dp[j][0] = 1e9;
			dp[j][1] = 1e9;
		}
	}
	pre[1000][0] = 0;
	pre[1000][1] = 0;
	int ans = 1e9;
	for(int j = 0;j <= 2000;j ++){
		pre[j][0] = abs(1000-j);
		pre[j][1] = abs(1000-j);
	}
	for(int i = 1; i <= N; i++){
		for(int j = 0;j <= 2000;j ++){
			for(int k = 0; k < 2; k++){
				//k == 0 x = j, y = pts[i].s
				if(k == 0){
					dp[j][k] = min(pre[j][0] + abs(pts[i].s - pts[i-1].s), pre[pts[i].s][1] + abs(j - pts[i-1].f));
				}
				//k == 1 y = j, x = pts[i].f
				else{
					dp[j][k] = min(pre[pts[i].f][0] + abs(j-pts[i-1].s), pre[j][1] + abs(pts[i].f - pts[i-1].f));
				}
				if(i == N){
					ans = min(ans, dp[j][k]);
				}
			}
		}
		for(int j = 0;j <= 2000;j ++){
			for(int k = 0; k < 2;k ++){
				pre[j][k] = dp[j][k];
			}
		}
	}
	cout << ans << '\n';
}
