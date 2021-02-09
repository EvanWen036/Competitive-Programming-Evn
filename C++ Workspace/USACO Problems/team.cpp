#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

int main(){
    //freopen("team.in", "r", stdin);
    //freopen("team.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> A(N);
    vector<int> B(M);
    for(int i = 0; i < N; i++){
        cin >> A[i];
        //cout << " " << A[i];
    }
    //cout << endl;
    for(int i = 0; i < M; i++){
        cin >> B[i];
        //cout << " " << B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    ll mod = 1e9+9;
    ll dp[N+1][M+1][K+1];
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for(int k= 0; k <= K; k++){
        for(int i = 0; i <= N; i++){
            for(int j = 0; j <= M; j++){
                //don't include the next one
                //dp[i+1][j+1][k] += dp[i][j][k];
                if(i != N){
                   dp[i+1][j][k] = dp[i+1][j][k] + (dp[i][j][k])%mod;
                }
                if(j != M){
                  dp[i][j+1][k] = dp[i][j+1][k] +(dp[i][j][k])%mod;
                }
                if(i != 0 && j != 0){
                    //dp[i+1][j+1][k] -= dp[i][j][k];
                    dp[i][j][k] -= dp[i-1][j-1][k];
                    //assert(dp[i+1][j+1][k] >= 0);
                    //dp[i+1][j+1][k] += mod;
                    //dp[i+1][j+1][k] %= mod;
                }
                if(i != N && j != M && k != K && A[i] > B[j]){
                    //try to add the next one
                    
                    dp[i+1][j+1][k+1] += (dp[i][j][k])%mod;
                }
                
            }
        }
        //if(k != 0)continue;
        //for(int i = 0; i <= N;i ++){
            //for(int j =0 ;j  <= M; j++){
                //cout << dp[i][j][k] << " ";
            //}
            //cout  << "\n";
        
    }
    cout << dp[N][M][K]%mod;

}

