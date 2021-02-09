#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    int indegree[N];
    vector<int> adj[N];
    int sol[N][N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N;j ++){
            sol[i][j] = 0;
        }
    }
    fill(indegree, indegree+N, 0);
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        indegree[b]++;
        adj[a].push_back(b);
    }
    queue<int> q;
    for(int i = 0; i < N; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        int sum = 0;
        for(int i = 0; i < u; i++){
            sum += sol[i][u];
        }
        if(sum == 0)sum =1;
        for(int i : adj[u]){
            sol[u][i] = sum;
            indegree[i]--;
            if(indegree[i] <= 0){
                q.push(i);
            }
        }
    }
    int answer = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            answer =max(answer, sol[i][j]);
        }
    }
    cout << answer << endl;


}

