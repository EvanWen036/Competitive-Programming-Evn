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
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	vector<pii> pts(N);
	for(int i =0;i <N;i++){
		cin >> pts[i].f >> pts[i].s;
	}	
	sort(pts.begin(), pts.end());

	ll ans = N+1;
	for(int l = 0; l < N; l++){
		oset<int> y;
		y.insert(pts[l].s);
		for(int r = l+1; r < N; r++){
			y.insert(pts[r].s);
			ll bottom = y.order_of_key(min(pts[l].s, pts[r].s)+1);
			ll top = y.order_of_key(1e9) - y.order_of_key(max(pts[l].s, pts[r].s));
			//cout << l << " " << r << " " << bottom << " " << top << '\n';
			ans += bottom * top;

		}
	}
	cout <<  ans << '\n';

}
