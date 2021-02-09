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
//dp i,j,k is max sum on the i'th element of the row using j elements and having remainder of k
int dp[75][75][75];
//results for row i, k
int rows[75][75];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n;i ++){
        for(int j = 1; j <= m; j++){
            cin >> mat[i][j];
            rows[i][j] = -1;
        }
    }
    for(int i = 1; i <= n;i ++){
        for(int j = 1; j<= m; j++){
            for(int x = 0; x <= k; x++){
                dp[i][j][x] = -1;
            }
        }
    }
    for(int i = 1;  i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int ch = 1; ch <= n/2; ch++){
                if(ch == 1){
                    //first element in this row
                    for(int y =0; y < k; y++){
                        if(rows[i-1][y] == -1)continue;
                        dp[j][ch][(y+mat[i][j])%k] = max(dp[j][ch][(y+mat[i][j])%k], rows[i-1][y] + mat[i][j]);
                    }
                }
                for(int x = 1; x < i; x++){
                    //otherwise it is not the first element in this row 
                    //look at back at something from prev
                    for(int y = 0; y < k; y++){
                        if(dp[x][ch-1][y] != -1){
                            //transition
                            dp[j][ch][(y+mat[i][j])%k] = max(dp[j][ch][(y+mat[i][j])%k], dp[x][ch-1][y] + mat[i][j]); 
                        }
                    }
                }
            }
        }
        //next row
        //reset all dp values
        //put them into rows
        for(int j = 1; j <
    }
    cout << dp[n][n/2][0];

}

