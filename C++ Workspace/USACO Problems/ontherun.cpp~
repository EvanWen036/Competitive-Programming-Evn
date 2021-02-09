#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int N, L;
int pos[1005];
int memo[1005][1005][2];
int t[1005][1005][2];
int dp(int l, int r, int c){
    //cout << l << " " << r << " " << c << endl;
    if(memo[l][r][c] == -1){
        if(l == r){
            memo[l][r][c] = abs(L - pos[l]);
            t[l][r][c] = abs(L-pos[l]);
        }
        else if(c == 0){
            int a = dp(l+1,r,0) + t[l+1][r][0] + abs(pos[l+1]-pos[l]);
            int b = dp(l+1,r,1) + t[l+1][r][1] + abs(pos[r]-pos[l]);
            if(a < b){
                memo[l][r][c] = a;
                t[l][r][c] = t[l+1][r][0] + abs(pos[l+1]-pos[l]);
            }
            else{
                memo[l][r][c] = b;
                t[l][r][c] = t[l+1][r][1] + abs(pos[r]-pos[l]);
            }
        }
        else if(c == 1){
            int a = dp(l,r-1,1) + t[l][r-1][1] + abs(pos[r]-pos[r-1]);
            int b = dp(l,r-1,0) + t[l][r-1][0] + abs(pos[r]-pos[l]);
            if(a<b){
                memo[l][r][c] = a;
                t[l][r][c] = t[l][r-1][1] + abs(pos[r]-pos[r-1]);
            }
            else{
                memo[l][r][c]=b;
                t[l][r][c]=t[l][r-1][0] + abs(pos[r]-pos[l]);


            }
        }
    }
    //cout << l << " " << r << " " << c << " " << memo[l][r][c] << endl;
    return memo[l][r][c];
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> N >> L;
    for(int i = 0; i < 1005; i++){
        for(int j = 0; j < 1005; j++){
            memo[i][j][0] = -1;
            memo[i][j][1] = -1;
        }
    }
    for(int i = 0; i < N; i++){
        cin >> pos[i];
    }
    cout << min(dp(0,N-1, 0), dp(0, N-1, 1));

}


