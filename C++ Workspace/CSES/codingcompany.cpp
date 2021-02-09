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
ll pre[52][15005];
ll current[52][15005];
int mod = 1e9+7;
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x;
	cin >> n >> x;
	vector<int> skill(n);
	for(int i = 0; i < n;i ++){
		cin >> skill[i];
	}
	sort(skill.begin(), skill.end());
	pre[0][5000] = 1;
	//dp[i][j][k] using first i people(sorted order) and j unfinished teams and k total penalty
	for(int i = 1;i <= n;i ++){
		for(int j = 0;j <= 50; j++){
			for(int k = 0; k <= 10000; k++){
				//team consisting only person i
				current[j][k] += 1LL * pre[j][k];
				//current[j][k] %= mod;
				//add i to unfinished team
				current[j][k] += 1LL * j * pre[j][k];
				//current[j][k] %= mod;
				//person i "finish" team
				current[j][k] += 1LL * (j+1) * pre[j+1][k-skill[i-1]];
				//current[j][k] %= mod;
				//start a new unfinished team
				if(j != 0){
					current[j][k] += 1LL * pre[j-1][k + skill[i-1]];
					//current[j][k] %= mod;
				}
				current[j][k] %= mod;
			}
		}
		for(int j = 0; j <= 50; j++){
			for(int k = 0; k <= 10000; k++){
				//cout << current[j][k] << " ";
				pre[j][k] = current[j][k];
				current[j][k] = 0;
			}
			//cout << '\n';
		}
		//cout << '\n';
	}
	ll ans = 0;
	for(int i = 5000; i <= 5000+x; i++){
		ans = (ans + pre[0][i])%mod;
	}
	cout << ans << '\n';

}
