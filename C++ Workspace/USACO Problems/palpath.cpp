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
    int N;
    cin >> N;
    string mat[N][N];
    for(int i = 0; i < N; i++){
        string line; cin >> line;
        for(int j = 0; j < N; j++){
            mat[i][j] = line[j];
        }
    }
    int dpOld[N][N];
	int dpNew[N][N];
    memset(dpOld, 0, sizeof(dpOld));
    memset(dpNew,0 ,sizeof(dpNew));
    dpOld[0][N-1] = 1;
    int dist = 0;
    int dirI[] = {1, 0};
    int dirJ[] = {-1, 0};
    for(int dist = 0; dist < N-1; dist++ ){
        //we know dist
        
        for(int i = 0; i < N; i++){
            
           for(int j = N-1; j >= 0; j--){
               int newI = i;
               int newJ = j;
               for(int x = 0; x < 2; x++){
                   for(int y = 0; y < 2; y++){
                        newI += dirI[x];
                        newJ += dirJ[y];
                        if(newI >= 0 && newI < N && newJ >= 0 && newJ < N && (dist+1)-newI >= 0 && (dist+1)-newI < N && 2*N-2-(dist+1)-newJ >= 0 && 2*N-2-(dist+1)-newJ < N ){
                            if(mat[newI][(dist+1)-newI] == mat[newJ][2*N-2-(dist+1)-newJ]){
                                cout << newI << " " << (dist+1)-newI << " " << newJ << " " << 2*N-2-(dist+1)-newJ << endl;
                                dpNew[newI][newJ] += dpOld[i][j];
                            }                           
                        }
                   }
               }

           }
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                dpOld[i][j] = dpNew[i][j];
                dpNew[i][j] = 0;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0;j < N; j++){
            ans += dpOld[i][j];
        }
    }
    cout << ans << endl;


}

