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
int dp[200005];
vector<int> A(200005);
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> x(n+1);
	for(int i = 1; i <= n; i++){
		cin >> x[i];
	}
	for(int i = 1; i<= 200004;i ++){
		A[i] = 1000000000;
	}	
	A[0] = 0;
	int ans = 0;
	for(int i = 1; i <= n;i ++){
		vector<int>::iterator it = lower_bound(begin(A),end(A),x[i]);
		if(it == begin(A))continue;
		if(*(--it) >= x[i])continue;
		//cout << *it<< " " << it - A.begin() << " ";
		dp[i] = 1 + (it-A.begin());
		ans = max(ans, dp[i]);
		//cout << dp[i] << "\n";
		A[dp[i]] = min(A[dp[i]], x[i]);
	}
	cout << ans << '\n';

}
