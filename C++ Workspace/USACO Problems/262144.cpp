#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

int main(){
    freopen("262144.in", "r", stdin);
    freopen("262144.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i < N;i ++){
        cin >> A[i];
    }
    int dp[65][N+1];
    for(int i = 0; i < 65; i++){
        for(int j = 0; j <= N; j++){
            dp[i][j]  = -1;
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        dp[A[i]][i] = i+1;
        //cout << A[i] << " " << i << endl;
        ans = max(ans, A[i]);
    }
    
    for(int i = 2; i <= 60; i++){
        for(int j = 0; j < N; j++){
            if(dp[i-1][j] != -1){
                //cout << i-1 << " " << j << endl;
                if(dp[i-1][dp[i-1][j]] != -1){
                    dp[i][j] = dp[i-1][dp[i-1][j]];
                    //cout << i << " " << j << " " << dp[i][j] << endl;
                    ans = max(ans, i);
                }
            }
        }
    }
    cout << ans << endl;

}

