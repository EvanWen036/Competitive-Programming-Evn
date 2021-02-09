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
	vector<int> a(n+1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		dp[i] = -1;
	}
	sort(a.begin(), a.end());
	dp[0] = 0;
	for(int i =1; i <= n; i++){
		for(int j = i-a[i]; j >= 0; j--){
			if(dp[j] == -1)continue;
			dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	cout << dp[n] << '\n';

}
