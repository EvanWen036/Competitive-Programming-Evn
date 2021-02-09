#include <bits/stdc++.h>
#define ll long long;
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unordered_set<long double> mp;
	mp.reserve(512);
	int n;
	cin >> n;
	long long x0;
	long long y0;
	cin >> x0 >> y0;
	for(int i = 0; i < n; i++){
		int x,y;
		cin >> x >> y;
		long double slope = ((double)(y - y0)) / (x-x0);
		if(x == x0)slope = 1000000000;
		mp.insert(slope);
	}
	cout << mp.size();


}