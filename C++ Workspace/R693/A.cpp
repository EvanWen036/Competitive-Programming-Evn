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
	int w, h, n;
	cin >> w >> h >> n;
	int pieces = 1;
	while(w % 2 == 0){
		pieces *= 2;
		w/=2;
	}
	while(h % 2 == 0){
		pieces *= 2;
		h/=2;
	}
	cout << (pieces>= n ? "YES":"No") << '\n';
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
