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
	void solve(){
		ll n;
		cin >> n;
		vector<ll> a(n);
		ll mod = 1e9+7;
		ll o = 0;
		ll an = 0;
		ll cnt[65];
		memset(cnt, 0, sizeof(cnt));
		for(int i = 0; i < n; i++){
			cin >> a[i];
			for(int j= 0; j <= 60; j++){
				if(a[i] & (1LL << j)){
					cnt[j]++;
					//cout << i << " " << j << '\n';
				}
			}
		}
		
		//test
		ll ans = 0;
		for(int j = 0;j < n;j ++){
			ll s1 = 0;
			ll s2 = 0;
			for(int i = 0; i <= 60;i ++){
				assert(cnt[i] <= n);
				if(a[j] & (1LL << i)){
					s2 += (1LL << i)%mod * (cnt[i]) % mod;
					s1 += (1LL << i)%mod * (n) % mod;
				}
				else{
					s1 += (1LL << i)%mod*(cnt[i])%mod;
				}
				//cout << s1 << '\n';
				s1 %= mod;
				s2 %= mod;
			}
			//s1 += a[j];
			//cout << s22 << " " << s11<< '\n';
			//cout << s1 << " " << s2 << '\n';
			ans += (s1 * s2);
			ans %= mod;
			//cout << temp << '\n';
		}
		cout << ans << '\n';

	}
	signed main(){

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		int t;
		cin >> t;
		while(t--){
			solve();
		}


	}
