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
    int N;
    cin >> N;
    int dp[N+1][N+1];
    int right[N];
    int left[N];
    for(int i = 0; i < N; i++){
        cin >>left[i];
    }
    for(int i = 0; i < N; i++){
        cin >> right[i];
    }
    memset(dp, 0, sizeof(dp));
    for(int i =1; i <= N; i++){
        for(int j= 1; j <= N; j++){
            dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
            if(abs(right[j-1] - left[i-1]) <= 4){
                dp[i][j] = max(dp[i][j], 1 + dp[i-1][j-1]);
            }
        }
    }
    cout << dp[N][N] << endl;


}

