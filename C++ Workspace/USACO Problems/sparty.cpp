#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int N;
vector<int> dijk(vector<pii> adj[], int src){
    vector<int> dijkstra(N);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0,src));
    bool vis[1005];
    vis[src] = true;
    for(int i = 0; i < N; i++){
        dijkstra[i] = 100000000;
    }
    dijkstra[src] = 0;
    while(!pq.empty()){
        int v = pq.top().second; pq.pop();
        vis[v] = true;
        for(pii e : adj[v]){
            if(!vis[e.first] && dijkstra[v] + e.second < dijkstra[e.first]){
                dijkstra[e.first] = e.second + dijkstra[v];
                
                pq.push(make_pair(dijkstra[e.first], e.first));
            }
        }
    }
    return dijkstra;
    
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int M, X;
    cin >> N >> M >> X;
    X--;
    vector<pii> adj1[N];
    vector<pii> adj2[N];
    for(int i = 0; i < M; i++){
        int a, b, t;
        cin >> a >> b >> t;
        a--; b--;
        adj1[a].push_back(make_pair(b,t));
        adj2[b].push_back(make_pair(a,t));
    }
    vector<int> d1 = dijk(adj1, X);
    

    vector<int> d2 = dijk(adj2, X);
    
    int ans = 0;
    for(int i = 0; i < N; i++){
        ans = max(ans, d1[i]+d2[i]);
    }
    cout << ans << endl;


}

