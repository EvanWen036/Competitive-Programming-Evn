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
	int a, b;
	cin >> a >> b;
	int a2 = a;
	int ans = 1e9;
	if(a == 1 && b == 1){
		cout << 2 << '\n';
		return;
	}
	if(a < b){
		cout << 1 << '\n';
		return;
	}
	int prevMoves = 1e9;
	for(int i = b;i <= a; i++){
		int moves = i-b;
		if(i == 1)continue;
		int temp = a;
		while(temp != 0){
			temp /= i;
			moves++;
		}
		ans = min(ans, moves);
		if(moves > prevMoves)break;
		prevMoves = moves;
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
