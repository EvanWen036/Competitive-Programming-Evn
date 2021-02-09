#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int N, Nop, F, M;
int C[55];
bool isFavorite[40005];
set<int> vis;
int dp[100005];
int calc(int x){
    //cout << x << endl;
    if(dp[x] == -1){
        if(isFavorite[x]){
            if(vis.count(x) != 0){
                cout << -1 << endl;
                exit(0);
            }
            vis.insert(x);
            dp[x] = calc(x+M);
        }
        for(int i = 0; i < Nop; i++){
            if(x < C[i])continue;
            if(dp[x] == -1){
                dp[x] = C[i] + calc(x-C[i]);
            }
            else{
                dp[x] = max(dp[x], C[i] +  calc(x-C[i]));

            }
        }
        if(dp[x] == -1)dp[x] = 0;
    }
    return dp[x];
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> Nop >> F >> M;
    memset(isFavorite, false, sizeof(isFavorite));
    for(int i = 0; i < Nop; i++){
        cin >> C[i];
    }
    for(int i = 0; i <= 100000; i++){
       dp[i] = -1;
    }
    for(int i = 0; i < F; i++){
        int a;
        cin >> a;
        isFavorite[a] = true;
    }
    dp[0] = 0;
    cout << calc(N);


}

