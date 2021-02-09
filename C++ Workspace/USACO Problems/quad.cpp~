#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N;
    cin >> N;
    int dp[N+1][5];
    for(int i = 0; i<=N; i++){
        for(int j = 0; j < 5; j++){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    int maxVal = 0;
    if(N%2==0)maxVal = N/2-1;
    else{maxVal = N/2;}
    for(int j = 0; j < 4; j++){
        for(int i = 0; i <= N;i ++){
            if(dp[i][j] != 0){
                for(int x = 1; x <= maxVal; x++){
                    if(i + x <= N){
                        dp[i+x][j+1] += dp[i][j];
                    }
                }
            }
        }
    }
    cout << dp[N][4];


}

