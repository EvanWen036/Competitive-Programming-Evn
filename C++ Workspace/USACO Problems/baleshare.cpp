#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
    cin >> N;
    int bales[N];
    int sum = 0;
    for(int i = 0 ; i < N; i++){
        cin >> bales[i];
        sum += bales[i];
    }
    bool dp[2][1001][1001];
    dp[0][0][0] = true;
    for(int i = 0; i < N; i++){
        for(int b1 = 0; b1 <= 1000; b1++){
            for(int b2 = 0; b2 <= 1000; b2++){
                if(dp[i%2][b1][b2]){
                    if(b1+bales[i] <= 1000){
                        dp[(i+1)%2][b1+bales[i]][b2] = true;
                    }
                    if(b2 + bales[i] <= 1000){
                        dp[(i+1)%2][b1][b2+bales[i]] = true;
                    }
                    dp[(i+1)%2][b1][b2] = true;
                }
            }
        }
    }
    int ans = 1000000000;
    for(int b1 =0; b1 <= 1000; b1++){
        for(int b2 = 0; b2 <= 1000; b2++){
            if(dp[N%2][b1][b2]){
                int third = sum - (b1+b2);
                if(b1 >= b2 && b2 >= third){
                    ans = min(ans, b1);
                }
            }
        }
    }
    cout << ans << endl;


}

