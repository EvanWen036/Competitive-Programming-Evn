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
int cnt[200005];
int last[200005];
void solve(){
	int n;
	cin >> n;
	vector<int> a(n+1);
	memset(cnt, 0, sizeof(cnt));
	memset(last, 0, sizeof(last));
	for(int i =1; i <= n; i++){
		cin >> a[i];
		if(i - last[a[i]] != 1){
			cnt[a[i]]++;
		}
		last[a[i]] = i;
	}
	int ans = 1e9;
	for(int i = 1; i <= n; i++){
		int curr = cnt[i];
		if(last[i] == 0)continue;
		if(last[i] != n)curr++;
		ans = min(ans, curr);
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
