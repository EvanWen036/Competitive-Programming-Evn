#include <bits/stdc++.h>
#define ll long long;
using namespace std;
long long n, m;
vector<long long> primes;
void sieve(int n){
	bool prime[n+1];
	memset(prime, true, sizeof(prime));
	for(int p = 2; p * p <= n; p++){
		if(prime[p]){
			for(int i = p*p; i <= n; i += p){
				prime[i] = false;
			}
		}
	}
	for(int i = 2; i <= n; i++){
		if(prime[i])primes.push_back(i);
	}
}
void go(){
	sieve(n);
	long long k = (n*n)/4;
	int p = primes.size();
	cout << p << " " << k << endl;
	int dp[p+1][k+1];
	memset(dp, -1,  sizeof(dp));
	for(int i = 1; i <= p; i++){
		int curr = primes[i-1];
		dp[i][1] = 0;
		//cout << "hi" <<endl;
		for(int j = 1; j <= k; j++){
			if(dp[i-1][j] != -1)dp[i][j] = dp[i-1][j];
			if(dp[i][j] != -1 && j*curr <= k){
				int newV = dp[i][j];
				if(j == 1){
					newV++;
				}
				dp[i][j*curr] = max(dp[i][j*curr],  newV);
			}
			if(dp[i-1][j] != -1 && j * curr <= k){
				dp[i][j*curr] = max(dp[i][j*curr], dp[i-1][j] + 1);
			}
		}
	}
	long long ans = 0;
	for(int i = 1; i <= k; i++){
		if(i <= n)ans += i;
		else if(dp[p][i] > 1)ans += i;
		ans %= m;
	}
	
	cout << ans;
	
}
int main(){
	freopen("exercise.in", "r", stdin);
	freopen("exercise.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	go();
	


}