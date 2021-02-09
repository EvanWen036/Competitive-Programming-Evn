#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int mat[75][75];
int dp[75][75][75];
int maxR[75];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;   
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> mat[i][j];
            for(int y = 1; y <= n; y++){
                dp[i][j][y] = -1;
            }
        }
    }
    int ans = 0;

    for(int i = 1;i  <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int ch = 1; ch <= j && ch <= m/2; ch++){
                if(ch == 1){
                    //first one in this group
                    dp[i][j][ch] = maxR[i-1] + mat[i][j];
                    maxR[i] = dp[i][j][ch];
                }
                for(int x = 1; x < j; x++){
                    if(dp[i][x][ch-1] != -1){
                        dp[i][j][ch] = max(dp[i][j][ch], dp[i][j][ch-1] + mat[i][j]);
                    }
                    if(dp[i][x][ch] != -1){
                        dp[i][j][ch] = max(dp[i][j][ch], dp[i][x][ch]);
                    }
                    maxR[i] = max(maxR[i], dp[i][j][ch]);
                    //ans = max(ans, maxR[i]);
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int ch = 1; ch <= m/2; ch++){
                cout << i << " " << j << " " << ch << " " << dp[i][j][ch] << "\n";
                if(dp[i][j][ch]%k == 0){
                    ans = max(ans, dp[i][j][ch]);
                }
            }
        }
    }
    cout << ans << "\n";
}

