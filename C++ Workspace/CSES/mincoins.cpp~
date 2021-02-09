#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
const int mx = 1e6+5;
int dp[mx];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for(int i = 0; i< n; i++){
        cin >> coins[i];
    }
    for(int i = 1; i <= x; i++){
        dp[i] = 100000000;
    }
    for(int i = 0; i <= x; i++){
        for(int c = 0; c < n; c++){
            if(coins[c] + i <= x){
                dp[coins[c]+i] = min(dp[coins[c]+i], dp[i]+1);
            }
        }
    }
    cout << (dp[x] != 100000000 ? dp[x]:-1);

}

