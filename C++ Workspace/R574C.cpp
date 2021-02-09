#include <bits/stdc++.h>
#define ll long long;
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	long long dp[n+1][2];
	long long max1 = 0;
	long long max2 = 0;
	vector<long long> a(n);
	vector<long long> b(n);
	for(int i = 0; i <n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n;i ++){
		cin >> b[i];
	}
	for(int i = 1; i <= n; i++){
		dp[i][0] = max(max1, max2 + a[i-1]);
		dp[i][1] = max(max2, max1 + b[i-1]);
		long long temp = max2;
		max2 = max(max2, max1 + b[i-1]);
		max1 = max(max1, temp + a[i-1]);
		//cout << dp[i][0] << " " << dp[i][1] << " " << max1 << " " << max2 << "\n";

	}
	
	cout << max(dp[n][0] , dp[n][1]);


}