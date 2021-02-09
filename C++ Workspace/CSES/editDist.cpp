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
int dp[5005][5005];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string a, b;
	cin >> a >> b;
	memset(dp, 0x3f, sizeof(dp));
	for(int j = 0; j <= b.length();j ++){
		dp[0][j] = j;
	}
	for(int i = 0; i <= a.length(); i++){
		dp[i][0] = i;
	}
	for(int i = 1; i <= a.length(); i++){
		for(int j = 1; j <= b.length();j ++){
			dp[i][j] = 1+min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
			if(a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1];
			}
		}
	}
	cout << dp[a.length()][b.length()];


}
