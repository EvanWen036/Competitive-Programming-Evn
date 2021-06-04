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
int cs = 1;
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n;i ++)cin >> a[i];
	int mxDigits = (int)log(a[0])+1;
	int mx = a[0];
	int ans = 0;
	for(int i = 1; i < n;i ++){
		if((int)log(a[i])+1 > mxDigits){
			mxDigits = (int)log(a[i])+1;
			mx = max(mx, a[i]);
		}
		if((int)log(a[i])+1 <= mxDigits){
			ans += mxDigits - ((int)log(a[i])+1);
			if(a[i] > mx){
				mx = a[i];
				continue;
			}
			ans++;
			mxDigits++;
			mx = max(mx,a[i]);
		}
	}
	cout << "Case #" << cs++ << ": " << ans << '\n';

}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--)solve();	


}
