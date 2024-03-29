#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
struct State{
    int r;
    int c;
    int dir;
    bool smell;
    int steps;
    bool operator<(const State other){
        return steps < other.steps;
    }
};
int main(){
    freopen("dream.in", "r", stdin);
    freopen("dream.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    int mat[N][N];
    for(int i = 0; i < N; i ++){
        for(int j = 0; j < N; j++){
            cin >> mat[i][j];
        }
    }
    queue<State> q;
    q.push(State{0,0, -1, false, 0});
    int rDir[4] = {0,1,0,-1};
    int cDir[4] = {1,0,-1,0};
    int dist[N][M][5][2];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            for(int x = 0; x < 4; x++){
                dist[i][j][x][0] = 1000000000;
                dist[i][j][x][1] = 1000000000;
            }
        }
    }
    for(int i = 0; i < 4; i++){
        dist[0][0][i][0] = 0;
    }
    while(!q.empty()){
        State curr = q.front(); q.pop();
        for(int i =0; i < 4;i ++){
            int newR = curr.r+rDir[i];
            int newC = curr.c + cDir[i];
            //check to see if we can move there
            if(newR < 0 || newR >= N || newC < 0 || newC >= N || mat[newR][newC] == 0 || (mat[newR][newC] == 3 && curr.smell == false))continue;
            if(mat[newR][newC] != 4){
                //not purple tile we can go here
                bool smell = curr.smell;
                if(mat[newR][newC] == 2)smell = true;
                if(curr.steps+1 < dist[newR][newC][i][smell]){
                    q.push(State{newR,newC, i, smell, curr.steps+1});
                    dist[newR][newC][i][smell] = curr.steps+1;
                }
            }
            if(mat[newR][newC] == 4){
                //purple tile
                int slides = 1;
                while(newR+rDir[i] >= 0 && newC+cDir[i] >= 0 && newR+rDir[i] < N && newC+cDir[i] < N && (mat[newR+rDir[i]][newC+cDir[i]] == 4 || mat[newR+rDir[i]][newC+cDir[i]] == 1 || mat[newR+rDir[i]][newC+cDir[i]] == 2)){
                    //while we are in bounds and we keep hitting purple tiles   
                    slides++;
                    newR += rDir[i];
                    newC += cDir[i];
                    if(mat[newR][newC] != 4)break;
                }
                //we are done sliding
                bool smell = mat[newR][newC] == 2;
                if(curr.steps+slides < dist[newR][newC][i][smell]){
                    q.push(State{newR,newC, i, smell, curr.steps + slides});
                    dist[newR][newC][i][smell] = curr.steps + slides;
                }
            }
        }
    }
    int ans = 1000000000;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 2; j++){
            ans = min(ans, dist[N-1][M-1][i][j]);
        }
    }
    if(ans == 1000000000)ans = -1;
    cout << ans << endl;
    



}

