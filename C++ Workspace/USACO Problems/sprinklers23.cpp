#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9 + 7;
ll mat[2005][2005];
ll dp[2005][2005];
ll prefix[2005][2005];
ll po[2005];
ll inRange(ll bot, ll top, int col){
    return prefix[top][col] - prefix[bot == 0 ? 0 : bot-1][col];
}
int main(){
    freopen("sprinklers2.in", "r", stdin);
    freopen("sprinklers2.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
    cin >> N;
    for(int i = N; i >= 1; i--){
        string s;
        cin >> s;
        for(int j = 1; j <= N; j++){
            mat[i][j] = (s[j-1] == 'W' ? 1:0);
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            prefix[i][j] = prefix[i-1][j] + mat[i][j];
        }
    }
    /** 
    for(int i = N; i >= 1; i--){
        for(int j = 1; j <= N; j++){
            cout << prefix[i][j] << " ";
        }
        cout << endl;
    }
    **/
    po[0] = 1;
    for(int i = 1; i <= 2000; i ++){
        po[i] = po[i-1] * 2;
        po[i] %= mod;
    }
    dp[0][N] = 1;
    for(int col = 1; col <= N; col++){
        if(mat[col][N] == 1)continue;
        dp[col][N] = po[col - prefix[col-1][N] - 1];
        dp[col][N] %= mod;  
        //cout << dp[cul][N] << endl;
    }
   
    for(int col = N-1; col >= 1; col--){
        ll sum = 0;
        for(int row = 0; row <= N; row++){
            
            ll spotsBelow = (row == 0 ? 0: row-1) - inRange(0, max(0,row-1), col);
            ll spotsAbove = (N-row-1) - inRange(min(row+2,N), N, col + 1);
            ll spotsAbove2 = (N-row) - inRange(min(row+1, N), N, col+1);
            ll canToggle = (row == 0 || mat[row][col] == 1 ? 1 : 2);
            spotsAbove = max(0LL, spotsAbove);
            spotsAbove2 = max(0LL, spotsAbove2);                
            ll ways = 0;
            //cout << row << " " << col << " " << spotsBelow << " " << spotsAbove << " " << spotsAbove2 << " " << canToggle << endl;
            if(mat[row][col] != 1){
                ways += (po[spotsBelow]*sum)%mod;
            }
            //dp[row][col] %= mod;
            ways += (dp[row][col+1] * po[spotsBelow])%mod * (canToggle * po[spotsAbove2])%mod;
            ways %= mod;
            dp[row][col] = ways;
            if(mat[row+1][col+1] != 1){
                sum += (dp[row][col+1] * po[spotsAbove])%mod;
                sum %= mod;
            }
        }
    }
    /**
    for(int i = N; i >= 0; i--){
        for(int j = 1; j <= N; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }**/
    ll ans = 0;
    for(int i = 0; i <= N; i++){
        if(i == N){
            ans += dp[i][1];
        }
        else{
            if(mat[i+1][1] == 1)continue;
            ans += (dp[i][1] * po[N-i-1 -inRange(min(i+2, N), N, 1)])%mod;
        }
        ans %= mod;
    }
    cout << ans << endl;



}

