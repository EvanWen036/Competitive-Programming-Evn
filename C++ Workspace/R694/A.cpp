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

void solve(){
	int n, x;
	cin >> n >> x;
	vector<ll> ar(n);
	ll s = 0;
	ll ma = 0;
	for(int i = 0; i  < n;i ++){
		cin >> ar[i];
		s += ar[i];
	}
	for(int i = 0; i  < n;i++){
		ma += (ar[i] / x);
		if(ar[i]%x != 0)ma++;
	}
	cout << s/x + (s % x == 0 ? 0:1) << " " <<  ma << '\n';

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
