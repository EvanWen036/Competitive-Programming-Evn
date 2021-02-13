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
#define int long long
int x, y;
int search(int i){
	int lo = (int)sqrt(x)+1;
		int hi = x;
		while(lo < hi){
			int mid = (lo+hi)/2;
			if(x / (mid+1) > i){
				//ok we need to move lo up
				lo = mid+1;
			}
			else{
				hi = mid;
			}
		}
	return lo;
}
void solve(){
	cin >> x >> y;
	ll ans = 0;
	/**
	for(int i = 1; i <= x; i++){
		for(int j =1 ;j <= x;j ++){
			if(i/j == i % j)cnt[j]++;
		}
	}**/
	for(int i = 2; (i*i) <= x && i <= y;i ++){
		//factors of i+1 <= x
		//cout << i << '\n';
		ans += (i*i) / (i+1);
	}
	//cout << ans << '\n';
	//the rest we just need to count multiples
	int mx = x / ((int)sqrt(x)+2);
	//cout << mx << " " << sqrt(x)+1;
	//cout << mx << '\n';
	//cout << mx << '\n';
	for(int i = mx; i >= 1; i--){
		//find number of places where x / k = i
		int pos1 = search(i);
		int pos2 = search(i-1)-1;
		if(pos1 > y || pos1 > pos2)continue;
		//cout <<pos1 << " " << pos2 << " " << i << '\n';
		pos2=min(pos2, y);
		ans += (pos2-pos1+1)*i;
	}
	cout << ans << '\n';
}
main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--)solve();
}
