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
int W, H, N;
int dp[605][605];
pii rect[205];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> W >> H >> N;
	for(int i = 0; i < N;i ++){
		cin >> rect[i].f >> rect[i].s;
	}
	for(int i = 1;i <= W; i++){
		for(int j = 1;j <= H;j ++){
			dp[i][j] = i*j;
			for(int k = 0;k < N;k ++){
				if(rect[k].f <= i && rect[k].s <= j){
					dp[i][j] = min(dp[i][j], dp[rect[k].f][j - rect[k].s] + dp[i-rect[k].f][j]);
					dp[i][j] = min(dp[i][j], dp[i-rect[k].f][rect[k].s] + dp[i][j - rect[k].s]);
				}
			}
			//cout << dp[i][j] << " ";
		}
		//cout << '\n';
	}
	cout << dp[W][H] << '\n';


}
