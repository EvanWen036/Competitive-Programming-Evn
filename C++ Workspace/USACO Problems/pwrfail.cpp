#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N;
    cin >> N;
    int M;
    cin >> M;
    double K;
    cin >> K;
    pii points[N];
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        
        points[i] = make_pair(a,b);
    }
    bool hasEdge[N][N];
    memset(hasEdge, false, sizeof(hasEdge));
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        hasEdge[a][b] = true;
        hasEdge[b][a] = true;
    }
    vector<pair<long double, int>> adj[N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i != j){
                long double dist = sqrt((points[j].second-points[i].second)*(points[j].second-points[i].second)+(points[j].first-points[i].first)*(points[j].first-points[i].first));
                if(hasEdge[i][j]){
                    adj[i].push_back(make_pair(0, j));
                }
                else if(dist < K){
                    adj[i].push_back(make_pair(dist, j));

            }
        }
    }
    }
    priority_queue<pair<long double, int>> pq;
    long double dist[N];
    for(int i = 0; i < N; i++){
        dist[i] = 100000000000;
    }
    dist[0] = 0;
    pq.push(make_pair(0,0));
    while(!pq.empty()){
        pair<long double, int> cur = pq.top();
        pq.pop();
        for(pair<long double, int> edge : adj[cur.second]){
            int v = edge.second;
            if(dist[v] > dist[cur.second] + edge.first){
                dist[v] = dist[cur.second] + edge.first;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    cout << dist[N-1] << endl;
    ll ans = (int)(1000*dist[N-1]);
    if(dist[N-1] == 1000000000)ans = -1;
    cout << ans << endl;
    


}

