#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
vector<ll> primes;
void sieve(int n){
	vector<bool> composite(n+1);
	for(int i = 2; i <= n; i++){
		if(!composite[i]){
			primes.pb(i);
			for(int j = 2 *i; j <= n; j += i){
				composite[j] = true;
			}
		}
	}
}
	
int main(){
	freopen("exercise.in", "r", stdin);
	freopen("exercise.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	sieve(n);
	
	
	int p = primes.size();
	ll dp[p+1][n+1];
	for(int i= 0; i <= p; i++){
		for(int j = 0; j <= n; j++){
			dp[i][j] = 1;
		}
	}
	for(int i = 1; i <= p; i++){
		for(int j = 0; j <= n;j ++){
			dp[i][j]= dp[i-1][j];
		}
		for(int j = 0; j <= n; j++){
			
			int pr = primes[i-1];
			while(j + pr <= n){
				dp[i][j+pr] += dp[i-1][j] * pr;
				dp[i][j+pr] %= m;
				pr = pr*primes[i-1];
			}
		}
	}
	cout << dp[p][n];

}