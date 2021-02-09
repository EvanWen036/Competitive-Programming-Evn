#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, k;
	cin >> n >> k;
	ll k2 = k * (n/k);
	cout << min(n - k2, (k2+k)-n);


}