#include <bits/stdc++.h>
using namespace std;

int main(){

	int k,n,w;
	cin >> k >> n >> w;
	
	int cost = w * (w+1) / 2;
	cost *= k;
	int ans = (n >= cost ? 0 : cost - n);
	cout << ans;


}