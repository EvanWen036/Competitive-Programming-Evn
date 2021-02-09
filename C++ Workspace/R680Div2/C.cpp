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
ll binpow(ll a, ll b){
    if( b== 0){
        return 1;
    }
    if(b == 1){
        return a;
    }
    if(b % 2){
        return a * binpow(a, b-1);
    }
    ll temp = binpow(a,b/2);
    return temp * temp;
    
}
void solve(){
	ll p, q;
	cin >> p >> q;
	ll og = q;
    map<ll,ll> cnt;
	if(p % q != 0){
		cout << p << "\n";
		return;
	}

	for(ll i = 2; i *i <= q; i++){
		int f = 1;
		while(q % i == 0){
			cnt[i]++;
			q/=i;
		}
	}
	if(q != 1){
		cnt[q]++;
	} 
  map<ll,ll>::iterator it = cnt.begin();
  ll ans = 1;
  while(it != cnt.end()){
    ll times = it->second;
    ll pow = it->first;
 	ll temp = og/it->first;
 	ll temp2 = p/temp;
 	while(temp2 % it->first == 0){
 		temp2 /= it->first;
 	}
 	ans = max(ans, temp * temp2);
    it++;
  }
  cout << ans << "\n";
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}


}
