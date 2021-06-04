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
int N, L;
int wt[25];
vector<int> st[25];
int dp[1 << 20];
int main(){
	freopen("movie.in", "r", stdin);
	freopen("movie.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//p2 
	cin >> N >> L;
	for(int i = 0 ; i < N;i ++){
		cin >> wt[i];
		int amt = 0;
		cin >> amt;
		for(int j = 0;j < amt;j ++){
			int ct;
			cin >> ct;
			st[i].pb(ct);
		}
	}
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	int ans = 1e9;
	for(int i = 0; i < (1<<20); i++){
		if(dp[i] != -1){
			//cout << i << " " << dp[i] << '\n';
			for(int j = 0;j < N;j ++){
				if(!(i & (1<<j))){
					vector<int>::iterator it = upper_bound(begin(st[j]), end(st[j]), dp[i]);

					if(it != st[j].begin()){
						it--;
						if((*it) + wt[j] < dp[i])continue;
						int nm = i;
						nm ^= (1 << j);
						dp[nm] = max(dp[nm], (*it) + wt[j]);
					}
				}
			}
		}
		if(dp[i] >= L)ans = min(ans, __builtin_popcount(i));
	}
	cout << (ans==1e9 ? -1 : ans) << '\n';

}
