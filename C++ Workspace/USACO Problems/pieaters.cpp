#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
int N, M;
ll maxW[305][305][305];
ll dp[305][305];
long long go(int l, int r){
    if(dp[l][r] != -1)return dp[l][r];
        for(int i = l; i+1 <= r; i++){
            dp[l][r] = max(dp[l][r], go(l,i) + go(i+1,r));
        }
        for(int i = l; i <= r; i++){
            long long left = 0;
            if(i != l) left = go(l, i-1);
            long long right = 0;
            if(i != r)right = go(i+1, r);
            dp[l][r] = max(dp[l][r], left+right+maxW[l][r][i]);
        }
        return dp[l][r];
}
int main(){
    freopen("pieaters.in", "r", stdin);
    freopen("pieaters.out", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> N >> M;
    for(int i = 0 ; i <= N; i ++){
        for(int j = 0;j <= N; j++){
            for(int k = 0; k <= N; k++){
                maxW[i][j][k] = 0;
            }
        }
    }
    for(int i = 0; i < M; i++){
        ll weight;
        
        int l, r;
        cin >>weight >> l >> r;l--; r--;
        for(int j = l; j <= r; j++){
            maxW[l][r][j] = max(maxW[l][r][j], weight);
        }
    }
    for(int len = 0; len < N; len++){
        for(int s = 0; s + len < N; s++){
            int end = s+len;
            for(int i = s; i < end; i++){
                //calculate maxW for [s][end][i]
                maxW[s][end][i] = max(maxW[s][end][i], maxW[s][end-1][i]);
            }
            for(int i = s+1; i <= end; i++){
                maxW[s][end][i] = max(maxW[s][end][i], maxW[s+1][end][i]);
            }
            for(int i = s; i <= end; i++){
                //cout << s << " " << end << " " << i << " " << maxW[s][end][i]<< endl;
            }
        }
    }
    for(int i = 0; i <= N;  i++){
        for(int j = 0; j <= N; j++){
            dp[i][j] = -1;
        }
    }
    cout << go(0, N-1);


}

