#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N, L;
    cin >> N >> L;
    int pos[N];
    for(int i = 0; i < N; i++){
        cin >> pos[i];
        //cout << pos[i] << endl;
    }
    int D = L / N;
    //cout << D << endl;
    int dp[2][L+5];
    dp[0][0] = abs(0-pos[0]);
    for(int i = 0; i < 2; i++){
        for(int j= 0; j<=L; j++){
            if(i == 0 && j == 0)continue;
            dp[i][j] = 1000000000;
        }
    }
    for(int i =1; i < N; i++){
        for(int j = i*D; j <= i *(D+1); j++){
            int x =1000000000;
            int y =1000000000;
            if(j-D >= 0){
                x = dp[(i-1)%2][j-D];
            }
            if(j-D-1 >= 0){
                y = dp[(i-1)%2][j-D-1];
            }
            dp[i%2][j] = min(x,y) + abs(j - pos[i]);
        }
    }
    cout << dp[(N-1)%2][L];
}

