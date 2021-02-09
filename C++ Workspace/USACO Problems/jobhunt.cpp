#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int D, P, C, F, S;
    cin >> D >> P >> C >> F >> S;
    S--;
    vector<pii> adj[C];
    for(int i =0; i < P; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].pb(make_pair(b, -1 * D));
    }
    for(int i = 0; i < F; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        adj[a].pb(make_pair(b, c-D));
    }
    queue<pii> q;
    q.push(make_pair(S, 0));
    int visited[C];
    int dist[C];
    memset(visited, 0, sizeof(visited));
    for(int i= 0; i < C; i++){
        dist[i] = 1000000000;
    }
    dist[S] = -1 * D;
    int ans = 0;
    while(!q.empty()){
       int u = q.front().first; q.pop();
       //cout << u << endl;
       visited[u]++;
       if(visited[u] == C){
           ans = -1;
           break;
       }
       for(pii e : adj[u]){
           if(dist[u] + e.second < dist[e.first]){
               dist[e.first] = dist[u]+e.second;
               q.push(make_pair(e.first, dist[e.first]));
           }
       }
    }
    if(ans == -1){
        cout << ans << endl;
        return 0;
    }
    for(int i = 0; i < C; i++){
        if(visited[i] ==0)continue;
        ans = max(ans, abs(dist[i]));
    }
    cout << ans<< endl;


}

