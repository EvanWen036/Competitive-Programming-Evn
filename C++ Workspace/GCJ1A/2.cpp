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
int cs = 1;
set<pair<ll,ll>> pre;
set<pair<ll,ll>> dp;
void solve(){
	int m;
	cin >> m;
	vector<int> pa;
	int n = 0;
	for(int i =0; i < m;i ++){
		int pi, ni;
		cin >> pi >> ni;
		for(int j = 0;j < ni; j++){
			pa.pb(pi);
		}
		n += ni;
	}
	sort(pa.begin(), pa.end());
	pre.insert({0,1});
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		for(auto it : pre){
			//add to the left
			dp.insert({it.f + pa[i-1], it.s});
			if(it.s * pa[i-1] <= 50000){
				dp.insert({it.f, it.s * pa[i-1]});
			}
		}
		pre.clear();
		for(auto it : dp){
			pre.insert(it);
		}
		dp.clear();
	}
	for(auto it : pre){
		if(it.f == it.s){
			ans = max(ans, it.f);
		}
	}
	pre.clear();
	cout << "Case #" << cs++ << ": " << ans << '\n';
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//p2	
	int t;
	cin >> t;
	while(t--)solve();

}
