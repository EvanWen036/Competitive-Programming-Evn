#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
int N;
int mat[2005][2005];
ll prefix[2005][2005];
ll dp[2005][2005];
ll po[2005];
ll mod = 1e9+7;
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
    for(int i = N; i >= 1;i --){
        string s;
        cin >> s;
        for(int j =1; j <= N; j++){
            mat[i][j] = (s[j-1] == 'W' ? 1 : 0);
            //cout << mat[i][j] << " ";
        }
        //cout << endl;
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            prefix[i][j] = prefix[i-1][j] + mat[i][j];
            //cout << prefix[i][j] << " ";
        }
        //cuut << endl;
    }
    /**
    for(int i = N; i >= 1; i--){
        for(int j = 1; j <= N; j++){
            cout << prefix[i][j] <<  " ";
        }
        cout << endl;
    }
    **/
    po[0] = 1;
    for(int i = 1;  i<= 2000; i ++){
        po[i] = po[i-1] * 2;
        po[i] %= mod;
    }
    //compute the last column
    for(int row = 1; row <= N; row++){
        //guaranteed corner
        if(mat[row][N] == 1)continue;
        dp[row][N] = po[row-prefix[row][N]-1];
        //cout << dp[row][N] << endl
    }
    for(int col = N-1; col >= 1; col--){
        ll sum = 0;
        for(int row = 1; row <= N; row ++){
            if(mat[row][col] == 1)dp[row][col] = 0;
            else{
                dp[row][col] = sum * po[row - prefix[row][N]-1] + dp[row][col+1] * po[row-1-prefix[row-1][col]] * (mat[row][col] == 1 ? 1:2);
                dp[row][col] %= mod;
            }
            sum += dp[row][col+1] * po[N-row-prefix[N][col+1]-prefix[row-1][col+1]];
        }
    }
    for(int i = N; i >= 1; i--){
        for(int j = 1; j <= N; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    ll ans = 0;
    for(int row = 1; row <= N; row++){
        if(row == N){
            ans += dp[N][1];
            break;
        }
        ans += dp[row][1] * po[N-row-1];
    }
    cout << ans<< endl;



}

