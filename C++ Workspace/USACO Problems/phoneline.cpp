#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

vector<pii> adj[1005];
vector<int> dijkstra(int src, int bound){
    vector<int> dijkstra(1005);
    for(int i = 0; i < src; i++){
        dijkstra[i] = 1000000000;
    }
    dijkstra[src] = 0;
    priority_queue<pii> q;
    q.push(mp(0, src));
    while(!q.empty()){
        int u = q.top().s; q.pop();
        for(pii e : adj[u]){
            int weight = (e.s > bound ? 1:0);
            if(weight + dijkstra[u] < dijkstra[e.f]){
                dijkstra[e.f] = weight + dijkstra[u];
                q.push(mp(dijkstra[e.f], e.f));
            }
        }
    }
    return dijkstra;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N, P, K;
    cin >> N >> P >> K;
    for(int i = 0; i < P; i++){
        int a, b, l; cin >> a >> b >> l; a--; b--;
        adj[a].pb(mp(b,l));
        adj[b].pb(mp(a,l));
    }
    //vector<int> curr = dijkstra(N-1, 4);
    //cout << curr[0];
    int low = 0;
    int high = 1000000;
    while(low < high){
        int mid = (low+high)/2;
        //cout << mid << endl;
        if(dijkstra(N-1, mid)[0] <= K){
            //answer is probably lower
            high = mid;
        }
        else{
            low = mid+1;
        }
    }
    cout << low << endl;
}

