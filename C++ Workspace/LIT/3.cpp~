#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
int N, M, t;
vector<pii> adj[10005];
int cost[10005];
int dijk[10005][31];
priority_queue<pair<int, pii>, vector<pair<int,pii>>, greater<pair<int,pii>>> pq;
//priority_queue<pair<int,pii>> pq;
void dijkstra(){
    pq.push(mp(0, mp(0, t)));
    for(int i = 0; i <= 10000; i ++){
        for(int j = 0; j <= 30; j++){
            dijk[i][j] = 100000000;
        }
    }
    dijk[0][t] = 0;
    while(!pq.empty()){
        pair<int, pii> curr = pq.top(); pq.pop();        
        if(curr.first!=dijk[curr.second.first][curr.second.second]) continue;
        int energy = curr.s.s;
        assert(energy <= t);
        
        if(cost[curr.s.f] != 0 && energy != t && dijk[curr.s.f][energy+1] > curr.f + cost[curr.s.f]){
            pq.push(mp(curr.f+cost[curr.s.f], mp(curr.s.f, energy+1)));
            dijk[curr.s.f][energy+1] = curr.f + cost[curr.s.f];
        }
        for(auto it : adj[curr.s.f]){
            if(curr.s.s >= it.s && dijk[it.f][curr.s.s - it.s] > curr.f){
                pq.push(mp(curr.f, mp(it.f, curr.s.s - it.s)));
                dijk[it.f][curr.s.s-it.s] = curr.f;
            }
        }
    }
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cin >> N >> M >> t;
    for(int i = 0; i < N; i++){
        cin >> cost[i];
    }
    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c; a--; b--;
        if(c <= t){
            adj[a].pb(mp(b,c));
            adj[b].pb(mp(a,c));
        }
    }
    dijkstra();
    for(int i = 1; i < N; i++){
        int mi = 100000000;
        for(int j = 0; j <= t; j++){
            mi = min(mi, dijk[i][j]);
        }
        if(mi == 100000000)mi = -1;
        cout << mi << " ";
    }

}

