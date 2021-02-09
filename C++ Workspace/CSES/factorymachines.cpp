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
#define int long long
vector<ll> machines;
ll T;
bool ok(ll x){
	ll amt = 0;
	for(ll i = 0; i < machines.size(); i++){
		amt += x/machines[i];
		if(amt >= T)return true;
	}
	return amt >= T;
}
int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll N;
	cin >> N >> T;
	for(int i = 0; i < N; i++){
		ll x;
		cin >> x;
		machines.pb(x);
	}	
	ll lo = 0;
	ll hi = 1e18;
	while(lo < hi){
		ll mid = (lo+hi)/2;
		if(ok(mid)){
			hi = mid;
		}
		else{
			lo = mid+1;
		}
	}
	cout << lo << '\n';
}
