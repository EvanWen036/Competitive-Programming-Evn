#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
int dp[1000005];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for(int i = 0; i < n;i ++){
        cin >> c[i];
    }
    dp[0] = 1;
    int mod = 1e9+7;
    for(int i = 0; i < x; i++){
        for(int ci = 0; ci < n; ci++){
            if(i + c[ci] <= x){
                dp[i+c[ci]] += dp[i];
                dp[i+c[ci]] %= mod;
            }
        }
    }
    cout << dp[x] << endl;


}

