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
    int N, M;
    cin >> N >> M;
    vector<int> a(N);
    for(int i = 0; i < N;i ++){
        cin >> a[i];
    }
    vector<int> b(M);
    for(int i = 0; i < M; i++){
        cin >> b[i];
    }
    //cout << (1 << 10)+5 << endl;
    bool dp[N+1][1 << 11];
    memset(dp, false,sizeof(dp)); 
    dp[0][0] = true;
    //cout << (0 | 1) << endl;
    //min ans you can get using the first i and tuggled some set of the bits
    for(int i = 0; i < N; i++){
        for(int j = 0; j < (1 << 10); j++){
            if(dp[i][j]){
                //cout << i << " " << j << endl;
                for(int x = 0; x < M; x++){
                    //cout <<1<< " " << j << " " <<   (a[i] & b[j]) << endl; 
                    //cout << j << " " << (a[i] & b[j]) << " " << (j | (a[i] & b[j])) << endl;
                    //assert((j|(a[i] & b[j])) >= j);
                    //if((j|(a[i] & b[x])) < (1<<11)){ 
                        dp[i+1][(j|(a[i]&b[x]))] = true;
                    
                    //cuut << i + 1 << " " <<  (j|(a[i] & b[j])) << " "  << dp[i+1][j | a[i] & b[j]] << endl;
                }
            }
        }
    }
    int ans = 1000000000;
    for(int i = 0; i < (1 << 10); i++){
        if(dp[N][i] == false)continue;
        ans = min(ans, i);
    }
    cout << ans << endl;


}

