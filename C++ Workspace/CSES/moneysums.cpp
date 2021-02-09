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
bool dp[100005];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> coins(n);
	for(int i = 0; i < n;i ++){
		cin >> coins[i];
	}
	memset(dp, false, sizeof(dp));
	dp[0] = true;
	for(int i = 0; i < n;i ++){
		for(int j = 100000; j >= 0; j--){
			if(dp[j] && coins[i] + j < 100005){
				dp[j+coins[i]] = true;
			}
		}
	}
	int cnt = 0;
	vector<int> possible;
	for(int i = 1; i <= 100000;i ++){
		if(dp[i]){
			cnt++;
			possible.pb(i);
		}
	}
	cout << cnt << '\n';
	for(int u  : possible){
		cout << u << " ";
	}
	cout << '\n';

}
