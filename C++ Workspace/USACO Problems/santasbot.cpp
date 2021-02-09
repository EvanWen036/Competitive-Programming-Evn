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
ll mod = 998244353;
const int maxN = 1e6+5;
ll prob[maxN];
ll cnt[maxN];

ll binpow(ll a, ll b){
	
  	ll ret=1;  
  	for (; b; (a*=a)%=mod, b>>=1)
    	if (b&1)
      	(ret*=a)%=mod;
  	return ret;
	
}
int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n;
	set<ll> gifts;
	for(int i = 0; i < n; i++){
		ll k;
		cin >> k;
		for(int j = 0; j < k; j++){
			ll x;
			cin >> x;
			gifts.insert(x);
			cnt[x]++;
			cnt[x]%=mod;
			ll temp = binpow(n, mod-2)%mod*binpow(k,mod-2)%mod;
			prob[x] += temp;
			prob[x] %= mod;
		}
	}
	ll ans = 0;
	for(ll x : gifts){
		//prob of x giving gifted to a good person
		//cout << prob[x] << '\n';
		ll chance = prob[x];
		ll chance2 = binpow(n,mod-2)%mod*cnt[x]%mod;
		ll add = (chance*chance2)%mod;
		ans = (ans+add)%mod;
	}
	cout << ans << '\n';
}
