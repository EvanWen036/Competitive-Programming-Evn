#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    int dp[2][M+2][2];
    for(int i = 0; i < 2; i++){
        for(int j =0; j <= M; j++){
            dp[i][j][0] = -1;
            dp[i][j][1] = -1;
        }
    }
    dp[0][0][0] = 0;
    dp[0][0][1] = 0;
    for(int i = 1; i <= N; i++){
        int x;
        cin >> x;
        for(int j =0; j <= M; j++){
            for(int l = 0; l < 2; l++){
                if(dp[(i-1)%2][j][l] != -1){
                    //state has been visited
                    //cout << i << " " << j << " " << l << " " << dp[i-1][j][l] << endl;
                    if(!(l == 0 && j != 0) && j+1 <= M){
                        //can run
                        dp[i%2][j+1][1] = max(dp[i%2][j+1][1], dp[(i-1)%2][j][l] + x);
                    }
                    //rest
                    dp[i%2][max(j-1,0)][0] = max(dp[i%2][max(j-1,0)][0], dp[(i-1)%2][j][l]); 
                }
            }
            
        }
        for(int j = 0; j <= M; j++){
            for(int l = 0; l < 2; l++){
                dp[(i-1)%2][j][l] = -1;
            }
        }
    }
    cout << max(dp[N%2][0][0], dp[N%2][0][1]) << endl;


}

