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
	int n;
	cin >> n;
	string ans = "";
	ans += "9";
	if(n == 1){
		cout << ans << '\n';
		return;
	}
	ans += "8";
	if(n == 2){
		cout << ans << '\n';
		return;
	}
	cout << ans;
	for(int i = 2; i < n;i ++){
		cout << (8+i-1)%10;
	}
	cout << '\n';

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
