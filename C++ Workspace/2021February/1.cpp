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
#define int long long
int N;
vector<int> stones;
ll BIT[1000005];
void update(int idx, int val){
    for(int i = idx; i <= 1000000; i += i & -i){
        BIT[i] += val;
    }
}
ll query(int idx){
    ll s = 0;
    for(int i = idx; i >= 1; i -= i & -i){
       s  += BIT[i];
    }
    return s;
}
int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for(int i = 1; i <= N;i ++){
		int x;
		cin >> x;
		stones.pb(x);
	}
	sort(stones.begin(), stones.end());
	for(int i = 0; i < N;i ++){
		//cout << stones[i] << '\n';
		update(stones[i], 1);
	}
	if(N == 1){
		cout << (stones[0]+1)/2 << '\n';
		return 0;
	}
	ll ans = 0;
	for(int i = 1; i <= 1e6;i ++){
		//cout << i << " "<< query(i-1) << '\n';
		if((N-query(i-1)) % 2 == 1){
			ans += N - query(i-1);
		}
	}
	cout << ans << '\n';


}
