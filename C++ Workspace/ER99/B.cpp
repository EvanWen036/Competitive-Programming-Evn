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
	int x;
	cin >> x;
	int curr = 1;
	int cnt = 1;
	int ad = 2;
	while(curr < x){
		curr += ad;
		cnt++;
		ad++;
	}
	//cout << curr << '\n';
	if(curr - x >= 2 && curr - x <= ad){
		cout << cnt << '\n';
	}
	else{
		cout << cnt + curr - x << '\n';
	}
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
