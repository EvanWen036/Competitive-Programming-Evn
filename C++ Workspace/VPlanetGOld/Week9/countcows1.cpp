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
ll dp[40];
ll dia[40];
vector<ll> pow3;
ll go(int k, ll diag){

	//# of cows on this x-y diagonal that are x,y < 3 ^ k
	//cout << k << " " << diag << '\n';
	diag = abs(diag);
	dia[k] = diag;
	if(k == 0){
		dp[0] = (diag==0);
		return dp[0];
	}
	
	else if(diag < pow3[k-1]){
		dp[k] = 3 * go(k-1,diag);
	}
	else{
		dp[k] = go(k-1,diag - 2 * pow3[k-1]);
	}
	return dp[k];
}
ll query(ll x, ll y, ll k){
	//count # of cows on segment from edge to (x,y) with x < 3^k and y < 3^k
	x %= pow3[k]; y %= pow3[k];
	if(k == 0)return 1;
	ll diag = abs<ll>(x-y);
	if(diag >= pow3[k-1]){

	}
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	pow3.pb(1);
	for(int i = 1; i <= 40; i++){
		pow3.pb(3 * pow3.back());
	}
	int Q;
	cin >> Q;
	for(int i = 1; i <= Q;i ++){
		ll d, x, y;
		cin >> d >> x >> y;
		go(39, x-y);
		//if(x-y == 0)dp[0] = 1;
		for(int j = 0;j  <= 4;j ++){
			cout << dia[j] << " " << dp[j] << '\n';
		}
		cout << query(x+d, y+d) << " " << query(x-1,y-1) << '\n';
		memset(dp, 0, sizeof(dp));
		    	
	}
}
