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
ll BIT[200005];
void update(int p, ll v){
	for(int i = p; i <= 200000; i+= i & -i){
		BIT[i]+=v;
	}
}
ll query(int p){
	ll sum = 0;
	for(int i = p; i >= 1; i -= i & -i){
		sum += BIT[i];
	}
	return sum;
}
int main(){
	ll mod = 1e9+7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	set<int> val;
	map<int, int> reg;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		val.insert(a[i]);
	}
	int r = 0;
	for(int u : val){
		reg[u] = ++r;
	}
	ll ans = 0;
	for(int i = 0; i < n; i++){
		ll sub = 0;
		if(reg[a[i]] > 1){
			sub = query(reg[a[i]]-1);
		}
		sub++;
		sub %= mod;
		ans += sub;
		ans %= mod;
		update(reg[a[i]], sub);
	}
	cout << ans << '\n';


}
