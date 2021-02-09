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
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    dp[0]=  1;
    int mod = 1e9+7;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < x; j++){
            if(j + coins[i] <= x){
                dp[j+coins[i]] += dp[j];
                dp[j+coins[i]] %= mod;
            }
        }
    }
    cout << dp[x] << endl;


}

