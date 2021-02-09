#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N;
    int A, B;
    cin >> N >> A >> B;
    bool dp[N+1][2];
    
    memset(dp, false,sizeof(dp)); 
    dp[0][0]= true;
    for(int i = 0; i <= N; i++){
        if(dp[i][0]){
            if(i + A <= N){
                dp[i+A][0] = true;
                dp[i+A][1] = true;
            }
            if(i + B <= N){
                dp[i+B][0] = true;
                dp[i+B][1] = true;
            }
            
        }
    }
    for(int i = 0 ; i <= N; i++){
        if(i * 2 <= N && dp[i*2][0]){
            dp[i][1] = true;
        }
        if(i*2+1<=N && dp[i*2+1][0]){
            dp[i][1] = true;
        }
        if(dp[i][1]){
            if(i + A <= N){
                dp[i+A][1] = true;
            }
            if(i + B <= N){

                dp[i+B][1] = true;
            }
        }
    }
    int max = 0;
    for(int i = N; i >= 0; i--){
        if(dp[i][1]){
            max = i;
            break;
        }
    }
    cout << max << endl;


}

