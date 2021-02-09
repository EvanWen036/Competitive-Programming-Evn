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
	vector<pii> pts(4);
	int sX = 0;
	int sY = 0;
	for(int i = 0; i < 4; i++){
		cin >> pts[i].f >> pts[i].s;
		sX += pts[i].f;
		sY += pts[i].s;
	}
	
	sX /= 4;
	sY /= 4; 
	int ans = 0;
	for(int sz = 1; sz <= 1e5; sz++){ 

		for(int i = 0; i < 4; i++){
			ans += abs(pts[i].f - sX);
			ans += abs(pts[i].s - sY);
		}
	}
	cout << ans << '\n';
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
