#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N;
    cin >> N;
    //cout << N << endl;
    int P[N+1];
    int ans[N+1];
    for(int i = 0; i < N;i ++){
        cin >> P[i];
        ans[i] = 0;
    }
    int edgeweight[N+1][N];
    for(int i = 0; i < N;i ++){
        for(int j = 0; j < N; j++){
            cin >> edgeweight[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        edgeweight[N][i] = edgeweight[0][i];
    }
    //int ans[N+1];
    
    ans[N] = 0;
    P[N] = 0;
    queue<int> q;
    q.push(N);
    while(!q.empty()){
        int u = q.front(); q.pop();
        cout << u << "HELLO"  << endl;
        for(int i = 0; i < N; i++){
            if(P[u] + edgeweight[u][i] <= P[i]){
                    ans[i] = ans[u]+1;
                    q.push(i);
                
            }
        }
    }
    int answer = 0;
    for(int i = 0; i < N; i++){
        answer = max(answer, ans[i]);
    }
    cout << answer << endl;



}

