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
void solve(){
	int m;
	cin >> m;
	map<int,int> cnt;
	ll sum = 0;
	ll ans = 0;
	for(int i = 0; i < m;i ++){
		int pi, ni;
		cin >> pi >> ni;
		sum += pi*ni;
		cnt[pi] = ni;
	}
	for(auto it : cnt){
		for(auto it2 : cnt){
			if(it.f == it2.f && it.s < 2)continue;
			ll prod = it.f*it2.f;
			ll rem = sum - (it.f + it2.f);
			if(rem == prod)ans = max(ans, prod);
		}
	}
	cout << ans << '\n';
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--)solve();	


}
