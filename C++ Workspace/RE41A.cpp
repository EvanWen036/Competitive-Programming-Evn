#include <bits/stdc++.h>
using namespace std;

int main(){

	int n, m;
	cin >> n >> m;
	vector<int> col(n+1);
	for(int i = 0; i < m; i++){
		int a;
		cin >> a;
		col[a]++;		
	}
	int ans = 1000000000;
	for(int i = 1; i <= n; i++){
		ans = min(ans, col[i]);
	}
	cout << ans;


}