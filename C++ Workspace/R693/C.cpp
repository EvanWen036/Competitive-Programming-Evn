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
	vector<int> a(n);
	int sum[n+1];
	memset(sum, 0, sizeof(sum));
	for(int i = 0; i < n;i ++){
		cin >> a[i];
	}
	sum[n] = 0;
	int ans = 0;
	for(int i = n-1; i >= 0; i--){
		if(i + a[i] >= n){
			sum[i] = a[i];
		}
		else{
			sum[i] = a[i]  + sum[i+a[i]];
		}
		ans =max(ans, sum[i]);
	}
	cout << ans << '\n';
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--)solve();


}
