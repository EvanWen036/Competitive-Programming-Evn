#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
vector<int> primes;
void sieve(){
	vector<bool> composite(355);
	for(int i = 2; i <= 350; i++){
		if(!composite[i]){
			primes.pb(i);
			for(int j = 2*i; j <= 350; j += i){
				composite[j] = true;
			}
		}
	}
}
//dp[i][j] = maximum order when using the first i prime numbers in a way that sums to j
double dp[76][10005];
int pa[76][10005];
void solve(){
	int N;
	cin >> N;
	for(int p = 0; p <= 70; p++){
		for(int i = 0; i <= N;i ++){
			dp[p][i] = 0.0;
			pa[p][i] = 0;
		}
	}
	for(int p = 1; p <= 70; p++){
		for(int j = 0;j <= N; j++){
			dp[p][j] = dp[(p-1)][j];
			pa[p][j] = 0;
		}
		for(int i = 0;i <= N; i++){			
			ll pr = primes[p-1];
			if(i+1 <= N && dp[p-1][i] > dp[p][i+1]){
				dp[p][i+1] = dp[p-1][i];
				pa[p][i+1] = 1;
			}
			while(i + pr <= N){
				//cout << pr << " " << dp[p-1][i] << " " << pr * dp[p-1][i] << '\n';
				assert(pr > 0);
				if(log((double)pr) + dp[(p-1)][i] > dp[p][i+pr]){
					dp[p][i+pr]=log((double)pr)+dp[(p-1)][i];
					pa[p][i+pr] = pr;
				}
				pr *= primes[p-1]; 
			}
		}
	}
	int sum = N;
	vector<int> factors;
	for(int i = 70; i >= 0; i--){
		if(pa[i][sum] == 0)continue;
		factors.pb(pa[i][sum]);
		sum -= pa[i][sum];
	}
	while(sum > 0){
		factors.pb(1);
		sum--;
	}
	sort(factors.begin(), factors.end());
	int next = 1;
	for(auto it : factors){
		assert(it >= 1);
		for(int i = next+1; i < next + it; i++){
			assert(i <= N);
			cout << i << " ";
		}
		cout << next << " ";
		next = it+next;
	}
	cout << '\n';

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	sieve();
	while(t--)solve();



}
