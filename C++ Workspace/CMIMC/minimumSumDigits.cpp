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

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	
	while(t--){
		cerr << t << endl
		ll ans = 0;
		ll currMin = 1e18;
		int K;
		cin >> K;
		for(int i = 1; i <= 1e8;i ++){
			ll prod = 1LL * K * i;
			ll sum = 0;
			while(prod > 0){
				sum += prod % 10;
				prod /= 10;
			}
			if(sum < currMin){
				ans = i;
				currMin = sum;
			}
		}
		cout << ans << '\n';
	}	

}
