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
    int K, N;
    cin >> K >> N;
    int coins[K+1];
    for(int i = 1; i <= K;i ++){
       cin >> coins[i]; 
    }
    int costs[N+1];
    for(int i  =1 ; i<=N; i++){
        cin >> costs[i];
    }
    int prefix[N+1];
    prefix[0] = 0;
    for(int i =1 ; i<= N; i++){
        prefix[i] = prefix[i-1] + costs[i];
    }
    int dp[1 << K];
    for(int i = 1; i < 1<<K; i++)dp[i] = -1;
    dp[0] = 0;
    
    for(int j = 0; j < 1 << K; j++){

        if(dp[j] != -1){
            
            //visited this state
            for(int i = 1; i <= K; i++){
                //if i'th bit is not on
                if(!(j & (1<<(i-1)))){
                    //cout << dp[j] << " " << coins[i] << " " << upper_bound(prefix, prefix + N + 1, prefix[dp[j]] + coins[i]) - prefix -1<< endl;
                    dp[j ^ (1<<(i-1))] =  max(dp[j^(1<<(i-1))], upper_bound(prefix, prefix + N + 1, prefix[dp[j]] + coins[i]) - prefix-1);
                }

            }
            
        }
    }
    int ans = -1;
    for(int j = 0; j < 1 << K; j++){
        if(dp[j] == N){
            int sum = 0;
            for(int k = 1; k <= K; k++){
                if(!(j & (1<<(k-1))))sum += coins[k];
            }
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
    

}

