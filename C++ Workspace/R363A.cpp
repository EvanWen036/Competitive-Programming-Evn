#include <bits/stdc++.h>
#define ll long long;
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int dp[N][3];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[0][2] = 0;
	for(int i = 1; i <= N;i ++){
		int a;
		cin >> a;
		dp[i][1] = max(dp[i-1][0] , dp[i-1][2]);
		dp[i][0] = max(dp[i-1][1], dp[i-1][2]);
		if(a >= 2){
			dp[i][1]++;
		}
		if(a % 2 == 1){
			dp[i][0]++;
		}
		dp[i][2] = max(dp[i-1][1], max(dp[i-1][0], dp[i-1][2]));
		//cout << dp[i][1] << " " << dp[i][2] << " " << dp[i][0];
		
	}
	cout << N - max(dp[N][0], max(dp[N][1], dp[N][2]));


}