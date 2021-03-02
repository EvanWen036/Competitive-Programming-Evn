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
int amt[100005];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//p1
	int N;
	cin >> N;
	for(int i = 1; i <= N;i++){
		cin >> amt[i];
	}
	ll ans = 0;
	for(int i = 1; i <= 1e6; i++){
		//# of elements greater than this one should be odd
		vector<int> v;
		for(int j=1;j <= N;j ++){
			if(amt[j] >= i){
				v.pb(amt[j]/i);
			}
		}
		sort(v.begin(), v.end());
		int mx = 0;
		int mxcnt = 0;
		for(int j = 0;j  < v.size(); j++){
			if(v[j] > mx){
				mxcnt = 1;
				mx = v[j];
			}
			else if(v[j] == mx)mxcnt++;
		}

		//cout << i << " " << mx << " " << mxcnt << '\n';
		if(v.size() == 0)continue;
		if(mx == v[0])mxcnt--;
		if(mxcnt % 2 == 1)continue;
		//cout << i << '\n';
		ans += v.size();
	}
	if(N==1){
		cout << (amt[1]+1)/2 << '\n';
		return 0;		
	}
	//assert(ans >= 0);
	cout << ans << '\n';

}
