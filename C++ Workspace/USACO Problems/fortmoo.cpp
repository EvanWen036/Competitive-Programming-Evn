#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){
    //freopen("fortmoo.in", "r",stdin);
    //freopen("fortmoo.out" ,"w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    int mat[N][M];
    int prefix[N][M];
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        for(int j = 0; j < M; j++){
            mat[i][j] = (s[j] == 'X' ? 1:0);
        }
    }
    memset(prefix, 0, sizeof(prefix));
    for(int i = 0; i < N ;i++){
        for(int j = 0; j < M; j++){
            
            prefix[i][j] += mat[i][j];
            if(i != 0)prefix[i][j] += prefix[i-1][j];          
        }
        //cout << endl;
    }
    //cout << prefix[3][0] << endl;
    int ans = 0;
    for(int r1 = 0; r1 < N; r1++){
        for(int r2 = r1; r2 < N; r2++){
            
            int col1 = 0;
            int col2 = 0;
            for(; col2 < M; col2++){
                if(col1 > col2)continue;
                if(mat[r1][col1] == 1 || mat[r2][col2] == 1){
                    col1 = col2+1;
                    //col1++;
                }
                if(prefix[r2][col1] - (r1 == 0 ? 0 : prefix[r1-1][col1]) != 0){
                    col1++;
                    continue;
                }
                if(prefix[r2][col2] - (r1 == 0 ? 0 : prefix[r1-1][col2]) != 0)continue;
                else{
                    //cout << r1 << " " << r2 << " " << col1 << " " << col2 << endl;
                    ans = max(ans, (r2-r1+1) * (col2 - col1+1));
                }
            }
        }
    }
    cout << ans << endl;

}

