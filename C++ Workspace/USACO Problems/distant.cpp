#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
struct Edge{
    int r;
    int c;
    int edgeweight;
};

struct State{
    int r;
    int c;
    int currentWeight;
};
bool operator<(const State& s1, const State& s2){
    return s1.currentWeight < s2.currentWeight;
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    freopen("distant.in", "r", stdin);
    freopen("distant.out", "w", stdout);
    int N, A, B;
    cin >> N >> A >> B;
    string mat[N][N];
    for(int i = 0; i < N;i ++){
        string s;
        cin >> s;
        for(int j = 0; j < N;j ++){
            mat[i][j] = s[j];  
        }
    }
    vector<Edge> adj[N][N];
    for(int i = 0; i < N;i ++){
        
        for(int j = 0; j < N; j++){

            if(i != 0){
                Edge e;
                e.r = i-1;
                e.c = j;
                e.edgeweight = (mat[i-1][j] == mat[i][j] ? A:B); 
                adj[i][j].push_back(e);
            }
            if(j != 0){
                Edge e;
                e.r = i;
                e.c = j-1;
                e.edgeweight = (mat[i][j-1] == mat[i][j] ? A:B);
                adj[i][j].push_back(e);
            }
            if(i != N-1){
                Edge e;
                e.r = i+1;
                e.c = j;
                e.edgeweight = (mat[i+1][j] == mat[i][j] ? A:B);
                adj[i][j].push_back(e);
            }
            if(j != N-1){
                Edge e;
                e.r = i;
                e.c = j+1;
                e.edgeweight = (mat[i][j+1] == mat[i][j] ? A:B);
                adj[i][j].push_back(e);
            }
        }
        
    }
    int ans = 0;
    for(int i =0; i < N; i++){
        for(int j = 0; j < N; j++){
            priority_queue<State> pq;
            State s;
            s.r = i;
            s.c = j;
            s.currentWeight = 0;
            pq.push(s);
            int dist[N][N];
            for(int x =0; x < N; x++){
                for(int y = 0 ; y < N; y++){
                    dist[x][y] = 1000000000;
                }
            }
            dist[i][j] = 0;
            bool vis[N][N];
            memset(vis, false, sizeof(vis));
            vis[i][j] = true;
            while(!pq.empty()){
                State curr = pq.top();
                pq.pop();
                for(Edge e : adj[curr.r][curr.c]){
                    
                    if(dist[e.r][e.c] > curr.currentWeight + e.edgeweight){
                        dist[e.r][e.c] = curr.currentWeight + e.edgeweight;
                        State newS;
                        newS.r = e.r;
                        newS.c = e.c;
                        newS.currentWeight = dist[e.r][e.c];
                        pq.push(newS);
                    }
                }
            }
            for(int x = 0; x < N; x++){
                for(int y =0;y < N; y++){
                    
                    ans = max(ans, dist[x][y]);
                }
            }
        }
    }
    cout << ans << endl;


}

