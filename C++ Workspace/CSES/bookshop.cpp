#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int dp[100005];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x;
	cin >> n >> x;
	vector<pii> books(n+1);
	for(int i = 0; i < n; i++){
		cin >> books[i].f;
	}
	for(int i = 0; i < n;i ++){
		cin >> books[i].s;
	}
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	int ans = 0;
	for(int i  =0; i < n; i++){
		for(int j = x; j >= 0; j--){
			if(j + books[i].f <= x && dp[j] != -1){
				dp[books[i].f + j] = max(dp[books[i].f+j], dp[j] + books[i].s);
				ans = max(ans, dp[books[i].f+j]);		
			}
		}
	}
	cout << ans << '\n';

}
