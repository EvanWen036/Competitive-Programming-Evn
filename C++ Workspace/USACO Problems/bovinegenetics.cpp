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
ll mod = 1e9+7;
ll dp[100005][4][4][4];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	char bases[4] = {'A','C','T','G'};
	if(s[0] == '?'){
		for(int i = 0; i < 4; i++){
			for(int j = 0;j < 4;j ++){
				dp[0][i][j][j] = 1;
			}
		}
	}
	else{
		int ind = 0;
		for(int i = 0; i < 4;i ++){
			if(bases[i] == s[0])ind = i;
		}
		for(int i = 0; i < 4; i++){

			dp[0][i][ind][ind] = 1;
		}
	}
	for(int i = 1; i < s.length(); i++){
		for(int j = 0; j < 4;j ++){
			for(int k = 0;k < 4; k++){
				for(int l = 0; l < 4; l++){
					if(bases[l] != s[i] && s[i] != '?'){
						dp[i][j][k][l] = 0;
						continue;
					}
					//case 1: add l to the previous division as long as i != i-1
					for(int x = 0; x < 4; x++){
						if(x != l){
							dp[i][j][k][l] += dp[i-1][j][k][x];
						}
						dp[i][j][k][l] %= mod;
					}
					//case 2: start a new division
					if(k == l){ 
						for(int x = 0; x < 4; x++){
							dp[i][j][k][l] += dp[i-1][x][j][x];
						}
					}
					
					//cout << i << " " << j << " " << k << " " << l << " " << dp[i][j][k][l] << '\n';
				}
			}
		}
	}
	ll ans = 0;
	for(int i =0;i < 4; i++){
		for(int j = 0; j < 4; j++){
			ans += dp[s.length()-1][i][j][i];
		}
	}
	ans %= mod;
	cout << ans << '\n';


}
