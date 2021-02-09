#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<ll> a(n);
	vector<ll> pref(n+1);
	for(int i = 0; i < n;i ++){
		cin >> a[i];
		pref[i+1] = pref[i] + a[i];
	}
	ll ans = 0;
	int j= 0;
	ll sum = 0;
	ll zeroeSums = 0;
	map<ll,int> map;
	int firstSafe = 0;
	for(int i = 0, j = 0; i <= n; i++){
		if(map.find(pref[i]) != map.end()){
			firstSafe = max(firstSafe, map[pref[i]] + 1);
		}
		ans += i-firstSafe;
		map[pref[i]] = i;
	}
	cout << ans;
}