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
    int t;
    cin >> t;
    while(t--){
        int N, M;
        cin >> N >> M;
    
        char mat[N][M];
        int ans = 0;
        for(int i = 0;i  < N; i++){
            string s;
            cin >> s;
           
            for(int j = 0; j < M; j++){
                mat[i][j] = s[j];
                //cout  << mat[i][j] << " ";
                if(i == N-1 && mat[i][j] == 'D'){
                    //cout << i << " " << j << endl;
                    ans ++;
                }
                if(j == M-1 && mat[i][j] == 'R')ans++;
            }
            //cout << "\n";
        }
        cout << ans << endl;
    }

}

