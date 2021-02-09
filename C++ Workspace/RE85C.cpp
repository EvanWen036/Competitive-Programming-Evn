#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<ll> a(n);
		vector<ll> b(n);
		for(int i = 0; i < n;i ++){
			cin >> a[i];
			cin >> b[i];
		}
		ll cost[n];
		ll total = 0;
		for(int i= 0; i < n;i++){
			int prev = i-1;
			if(prev == -1)prev = n-1;
			cost[i] = (0 > a[i]-b[prev] ? 0:a[i]-b[prev]);
			total += cost[i];
		}
		ll ans = 1000000000000000000;
		for(int i = 0; i < n;i ++){
			ans = min(ans, total - cost[i] + a[i]);
		}
		cout << ans << endl;
		
	}


}
