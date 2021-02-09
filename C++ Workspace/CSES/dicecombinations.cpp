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
int dp[1000005];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	dp[0] = 1;
	for(int i = 0; i< n;i ++){
		for(int j = 1;j <= 6; j++){
			if(i + j <= n){
				dp[i+j] += dp[i];
				dp[i+j] %= 1000000007;
			}
		}
	}
	cout << dp[n] << '\n';


}
