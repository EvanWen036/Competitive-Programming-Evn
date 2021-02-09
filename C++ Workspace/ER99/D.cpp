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
	vector<int> a(n);
	for(int i = 0; i < n;i ++){
		cin >> a[i];
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		bool greaterThan = false;
		for(int j = i+1; j < n;j ++){
			if(a[j] < a[j-1]){
				greaterThan = true;
			}
		}
		if(greaterThan && a[i] > x){
			int temp = a[i];
			a[i] = x;
			x = temp;
			ans++;
		}
	}
	for(int i = 1; i < n;i ++){
		if(a[i] < a[i-1]){
			cout << -1 << '\n';
			return;
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
