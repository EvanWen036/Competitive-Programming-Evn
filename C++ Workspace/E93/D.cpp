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
    int R, G, B;
    cin >> R >> G >> B;
    vector<ll> red(R);
    vector<ll> green(G);
    vector<ll> blue(B);
    //map<int, int> count;
    //vector<int> pairs;

    for(int i = 0; i < R;i ++){
        cin >> red[i];
    }
    for(int i = 0; i < G; i ++){
        cin >> green[i];
    }
    for(int i = 0; i < B; i++){
        cin >> blue[i];
    }
    sort(red.begin(), red.end(), greater<int>());
    sort(green.begin(), green.end(), greater<int>());
    sort(blue.begin(), blue.end(), greater<int>());
    ll dp[R+1][G+1][B+1];
    memset(dp, 0, sizeof(dp));
    ll ans =0;
    for(int i = 0; i <= R; i ++){
        for(int j = 0; j <= G; j++){
            for(int k = 0; k <= B; k++){
                if(i != 0 && j != 0){
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k] + red[i-1]*green[j-1]);
                }
                if(j != 0 && k != 0){
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1] + green[j-1] * blue[k-1]);
                }
                if(i != 0 && k != 0){
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1] + red[i-1] * blue[k-1]);
                }
                ans = max(ans, dp[i][j][k]);
            }
        }
    }
    cout << ans << endl;


}

