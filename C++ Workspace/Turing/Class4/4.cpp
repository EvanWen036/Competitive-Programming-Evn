#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll, int> pii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, m, o;
	cin >> n >> m >> o;
	multiset<ll> rooms;
	vector<pii> times;
	for(int i = 0; i < n;i ++){
		 ll x, y;
		 cin >> x >> y;
		 times.pb({y,x});
	}
	vector<pii> offers;
	for(int i = 0; i < m ;i++){
		ll x, y;
		cin >> x >> y;
		offers.pb(mp(-1*y,-1*x));
	}
	sort(offers.begin(), offers.end());
	sort(times.begin(), times.end());
	ll ans = 0;
	int ptr = times.size()-1;
	int cnt = 0;
	for(auto it : offers){
		if(cnt >= o){
			break;
		}
		it.f *= -1;
		while(ptr >= 0 && times[ptr].f >= it.f){
			rooms.insert(times[ptr].s);
			ptr--;
		}
		if(rooms.size() == 0)continue;
		//cout << rooms.size() << "\n";
		ll val = *rooms.begin();
		//cout << val << "\n";
		if(it.s * - 1 > val){
			rooms.erase(rooms.begin());
			ans += (it.s*-1) - val;
			cnt++;
		}	
		//cout << ans << "\n";
	}
	cout << ans << "\n";

}
