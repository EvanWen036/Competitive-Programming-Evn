#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
struct State{
    int r, c, placed;
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int M,N;
    cin >> M >> N;
    int mat[M][N];
    int startR = 0;
    int startC = 0;
    int endR = 0;
    int endC = 0;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> mat[i][j];
            if(mat[i][j] == 3){
                startR = i;
                startC = j;
            }
            if(mat[i][j] == 4){
                endR = i;
                endC = j;
            }
        }
    }
    bool vis[M][N][1005];
    queue<State> q;
    q.push(State(startR,startC, 0));
    int dr[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    while(!q.empty()){
        State u = q.front(); q.pop();
        
    }



}

