#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
typedef long long ll;
typedef pair<int, int> pii;
int N;
int mat[2005][2005];
int prefix[2005][2005];
ll dp[2005][2005];
ll po[2005];
ll mod = 1e9+7;
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
    for(int i = N-1; i >= 0; i--){
        string s;
        cin >> s;
        for(int j = 0; j < N; j++){
            mat[i][j] = (s[j] == 'W' ? 1 : 0);
            //cout << mat[i][j] << " ";
        }
        //cout << endl;
    }
    //compute po 
    po[0] = 1;
    for(int i = 1; i <= 2003; i++){
        po[i] = 2 * po[i-1];
        po[i] %= mod;
    }
    /**
    for(int i = 1 ; i <= 20;i ++){
        cuut << po[i] << endl;
    }
    **/
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            prefix[i][j] += mat[i][j];
            if(i != 0){
                prefix[i][j] += prefix[i-1][j];
            }
        }
    }
    /**
    for(int i = N-1; i >= 0; i--){
        for(int j = 0;j < N; j++){
            cout << prefix[i][j] << " ";
        }
        cout << endl;
    }
    **/
    //calculate back column
    for(int i = 0; i < N; i++){
        if(mat[i][N-1] != 1){
            if(i == 0){
                dp[i][N-1] = 1;
                continue;
            }
            int cows = prefix[i-1][N-1];
            dp[i][N-1] = po[i - cows];
        }
        else{
            dp[i][N-1] = 0;
        }
        //cout  << dp[i][N-1] << endl;
    }
    for(int col  = N-2; col >= 0;col --){
        //cout << "hi" << endl;
        for(int i = 0; i < N; i++){
            if(i ==0){
                //is guaranteed to not be a corner
                //we need a corner at (0, col + 1)
                int cows = prefix[N-1][col+1] - prefix[0][col+1];
                //can place a sprinkler here or not doesn't matter
                dp[i][col] += dp[i][col+1] * po[cows] * 2;
                dp[i][col] %= mod;
            }
            else{
                for(int x = 0; x < i; x++){
                    //it is guaranteed to be a corner and there is also an A corner right above x
                    int cows = prefix[N-1][col+1] - prefix[x][col+1];
                    if(mat[x+1][col+1] == 1)continue;
                    //cout << x << endl;
                    int below = prefix[i-1][col];
                    assert(N-1-x-cows >= 0);
                    dp[i][col] += dp[x][col+1] * po[N-1-x-cows] * po[i-below];
                    dp[i][col] %= mod;
                }
                //x == i case
            }
                int cows = prefix[N-1][col+1] - (i == 0 ? 0: prefix[i][col+1]);
                if(col == 0 && i == 0){
                    cout << cows << endl;
                }
                //cuut << col << " " << i << " " << cuws << endl;
                int below = (i == 0 ? 0:prefix[i-1][col]);
                assert(N-1-i-cows >= 0);
                dp[i][col] += dp[i][col+1] * 2 * po[N-1-i-cows] * po[i-below];
                dp[i][col] %= mod;

        }
            //cout << dp[i][col] << " ";
       
    }
        //cout << endl;
    
    //calculate the last culumn to get the answer
    for(int i = N-1; i >= 0; i--){
        for(int j = 0; j < N; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    ll ans = 0;
    for(int i = 0; i < N; i++){
        int cows = prefix[N-1][0] - (i == 0 ? 0:prefix[i-1][0]);
        ans += dp[i][0] * po[N-1-i-cows];
        ans %= mod;
    }
    cout << ans << endl;
}

