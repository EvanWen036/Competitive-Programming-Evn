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
ll sum[5005][5005];
ll memo[5005][5005];
vector<ll> A;
ll dp(int l, int r){
	if(memo[l][r] == -1){
		//take left
		if(l == r){
			memo[l][r] = A[l];
			return A[l];
		}
		ll poss = -1e18;
		poss = max(poss,A[l] + (sum[l+1][r] - dp(l+1,r)));
		poss = max(poss,A[r] + (sum[l][r-1] - dp(l,r-1)));
		memo[l][r] = poss;
	}
	return memo[l][r];
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for(int i = 0; i < N; i++){
		ll x;
		cin >> x;
		A.pb(x);
	}
	for(int i = 0; i < N; i++){
		ll s = 0;
		for(int j = i; j < N; j++){
			s += A[j];
			sum[i][j] = s;
		}
	}
	memset(memo, -1,sizeof(memo));
	cout << dp(0,N-1) << '\n';


}
