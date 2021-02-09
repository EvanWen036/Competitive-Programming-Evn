#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
int search(int max, int start, int N, int costs[]){
    int sum =0;
    if(costs[start-1] > max)return start;
    sum += costs[start-1];
    for(int i = start-1; i < N; i++){
        if(sum + costs[i+1] > max){
            //cout << max << " " << start << " " << i << endl;
            return i;
        }
    }
    return N;
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N, K;
    cin >> K >> N;
    int coins[K];
    int prefix[N+1];
    for(int i = 0; i  <  K; i++){
        cin >> coins[i];
    }
    prefix[0] = 0;
    int costs[N];
    for(int i = 0; i < N; i++){
        cin >> costs[i];
        prefix[i+1] = prefix[i] + costs[i];
    }
    int dp[1<<17];
    for(int i = 0; i <= 1<<K; i++){
        dp[i] = -1;
    }
    dp[0] = 0;
    for(int i = 1; i <= N;i ++){
        //try toggling some bits
        for(int j = 0; j <= 1<<K; j++){
            
            if(dp[j] != -1){
                //cout << j << endl;
                //gooooooooooouoooooooooo
                for(int k = 0; k < K; k++){
                    if(!(j & (1 << k))){
                        //try tu toggle this bit
                        int val = coins[k];
                        cout << i << " " << val << " " << search(val, i , N, costs) << endl;
                        dp[j ^ 1<<k] = search(val, i, N, costs);
                    }
                    
                }
            }
        }
            
    }
    int ans = 0;
    for(int i = 0; i <= 1<<K; i++){
        if(dp[i] == N){
            int count = 0;
            for(int k = 0; k < K; k++){
                if(!(i & (1<<k))){
                    count += coins[k];
                }
            }
            ans = max(ans, count);
        }
    }
    cout << ans << endl;




}

