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
ll dp[1005];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	vector<int> A(N+1);
	for(int i = 1; i <=  N;i ++){
		cin >> A[i];
		dp[i] = 1e18;
	}
	dp[0] = 0;
	for(int i= 1; i <= N; i++){
		ll sum1 = A[i];
		ll sum2 = 0;
		int mi = A[i];
		dp[i] = min(dp[i], dp[i-1] + min(A[i], K+1-A[i]));
		//cout << dp[i] << " ";
		for(int j = i-1; j >= 1; j--){
			//decrease everything from j to i
			sum1 += max(0, A[j] - A[j+1]);
			sum2 += max(0, A[j] - A[j+1]);
			dp[i] = min(dp[i], dp[j-1] + sum1);
			dp[i] = min(dp[i], dp[j-1] + sum2 + (K+1-A[j]));

			//cout << dp[i] << " ";
		}
		//cout << dp[i] << '\n';
	}
	cout << dp[N] << '\n';
}
	