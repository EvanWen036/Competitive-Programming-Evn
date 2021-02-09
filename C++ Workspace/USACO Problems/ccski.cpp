#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int M, N;
    cin >> N >> M;
    int mat[M][N];
    for(int i = 0 ; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> mat[i][j];
        }
    }
    vector<pii> waypoints;
    for(int i = 0; i < M; i++){
        for(int j= 0; j < N; j++){
            int x;
            cin >> x;
            if(x == 1){
                waypoints.push_back(make_pair(i,j));
            }
        }
    }
    int low = 0;
    int high = 1000000000;
    if(waypoints.size()==0 || waypoints.size() == 1){
        cout << 0 << endl;
        return 0;
    }
    int dr[4] = {0,1,0,-1};
    int dc[4] = {1,0,-1,0};
    while(low < high){
        int mid = (low+high)/2;
        queue<pii> q;
        set<pii> visited;
        q.push(waypoints[0]);
        while(!q.empty()){
            pii current = q.front(); q.pop();
            visited.insert(current);
            for(int i = 0; i < 4; i++){
                int newR = current.first + dr[i];
                int newC = current.second + dc[i];
                if(newR < 0 || newC < 0 || newR >= M || newC >= N || visited.count(make_pair(newR, newC)) > 0 || abs(mat[newR][newC] - mat[current.first][current.second]) > mid)continue;
                q.push(make_pair(newR, newC));
            }
        }
        bool contains = true;
        for(pii x : waypoints){
            if(visited.count(x) == 0){
                contains = false;
                break;
            }
        }
        if(contains){
            high =mid;
        }
        else{
            low = mid+1;
        }
    }
    cout << low+1 << endl;


}

