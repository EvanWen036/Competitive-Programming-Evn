#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N, P;
    cin >> N >> P;
    int c[N];
    int minAmount = 1005;
    int minInd = 0;
    for(int i = 0; i < N; i++){
        cin >> c[i];
        if(c[i] < minAmount){
            minAmount = c[i];
            minInd = i;
        }
    }
    //cout << minInd << endl;
    vector<pii> adj[N];
    for(int i = 0;  i < P; i++){
        int a, b, w;
        cin >> a >> b >> w; a--; b--;
        adj[a].pb(mp(b,2*w + c[a] + c[b]));
        adj[b].pb(mp(a,2*w + c[a] + c[b])); 
    }
    priority_queue<pair<int, int>, vector<pii>, greater<pii> > pq;
    vector<int> dist(N);
    for(int i = 0; i < N; i++){
        dist[i] = 100000000;
    }
    dist[minInd] = 0;
    bool inMst[N];
    memset(inMst, false, sizeof(inMst));
    pq.push(mp(0,minInd));
    while(!pq.empty()){
        int u = pq.top().s;
        pq.pop();
        if(inMst[u])continue;
        inMst[u] = true;
        for(auto it : adj[u]){
            if(!inMst[it.f] && it.s < dist[it.f]){
                dist[it.f] = it.s;
                pq.push(mp(dist[it.f],it.f));
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        ans += dist[i];
    }
    cout << ans + minAmount << endl;

}

