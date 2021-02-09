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
    int N, T;
    cin >> N >> T;
    int v[N];
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    int c[N];
    for(int i = 0; i < N; i++){
        cin >> c[i];
    }
    int fJ[N+1][T+125];
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= T+120;j ++){
            fJ[i][j] = 100000000;
        }
    }
    fJ[0][0] = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 0;j <= T+120; j++){
            if(fJ[i-1][j] != 100000000){
                fJ[i][j] = min(fJ[i][j] ,fJ[i-1][j]);
                for(int x = 1; x <= c[i-1]; x++){
                    if(j + x*v[i-1] <= T+120){
                    fJ[i][j+x*v[i-1]] = min(fJ[i][j+x*v[i-1]], fJ[i-1][j] + x);
                    }
                }
            }
        }
    }
    //cout << fJ[1][5] << endl;
    //cout << fJ[1][10] << endl;
    //cout << fJ[2][25] << endl;
    //cout << fJ[2][30] << endl;
    int cash[T+1];
    for(int i = 1; i<= T;i++){
        cash[i] = 100000000;
    }
    cash[0] = 0;
    for(int i=  0; i <= T; i++){
        if(cash[i] != 100000000){
            for(int j = 0; j< N ;j++){
                if(i + v[j] <= T){
                    cash[i+v[j]] = min(cash[i+v[j]], cash[i]+1);
                }
            }
        }
    }
    int ans = 100000000;
    for(int d= 0; d <= 120; d++){
        if(cash[d]+fJ[N][T+d] < ans){
           ans = min(ans, cash[d] + fJ[N][T+d]);
            //cout << d << endl;
        }
     }
    //cout << fJ[N][75] << " " << cash[5] << endl;
    if(ans == 100000000)ans = -1;
    cout << ans << endl;


}

