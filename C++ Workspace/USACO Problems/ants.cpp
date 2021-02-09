#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll T, A, S, B;
    cin >> T >> A >> S >> B;
    ll count[1005];
    memset(count, 0, sizeof(count));
    for(int i = 0; i < A; i++){
        int a;
        cin >> a;
        count[a]++;
    }
    
    ll dp[1005][205];
    for(int i = 0; i <= T; i++){
        for(int j = 0; j <= B; j++){
            dp[i][j] = 0;
        }
    }
    //cout << " HI " << endl;
    for(int i = 0; i <= T; i++){
        dp[i][0] = 1;
    }
     
    for(int i = 1; i <= T; i++){
        //cout << i << " " << count[i-1] << endl;
        for(int j = 1; j <= B; j++){
            //dp[i][j] += dp[i-1][j];
            for(int y = j; y >= j-count[i] && y >= 0; y--){
                dp[i][j] += dp[i-1][y] % 1000000;
            }
            //cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    ll sum = 0;
    for(int i = S; i <= B; i++){
        sum += dp[T][i];
    }
    cout << sum % 1000000; 
    


}

