#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
int N, M;
array<int, 10005> dijkstra(vector<vector<pii>> graph, int src){
    //cout<< src << endl;
    array<int, 10005> dist;
    for(int i = 0; i < 10005;i ++)dist[i] = 1000000000;
    dist[src] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(mp(0, src));
    while(!pq.empty()){
        int u = pq.top().s; pq.pop();
        //cuut << u << endl;
        for(auto it : graph[u]){
            //cout << it.f << " " << it.s << endl;
            if(dist[u] + it.second < dist[it.f]){
                dist[it.f] = dist[u]+it.second;
                pq.push(mp(dist[it.f], it.f));
            }
        }
    }
    return dist;
}

int main(){
	freopen("gpsduel.in", "r", stdin);
	freopen("gpsduel.out", "w", stdout);
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
    vector<vector<pii>> graphP(N);
    vector<vector<pii>> graphQ(N);
    for(int i = 0; i < M; i++){
        int a, b, p, q;
        cin >> a >> b >> p >> q;
        a--; b--; 
        graphP[b].pb(mp(a,p));
        //graphP[b].pb(mp(a,p));
        graphQ[b].pb(mp(a,q));
        //graphQ[b].pb(mp(a,q));
    }
    for(int i = 0; i < N;i ++){
        for(auto it : graphP[i]){
            //cout << i << " " << it.f << endl;
        }
    }
    array<int, 10005> dijkstraP = dijkstra(graphP, N-1);
    array<int, 10005> dijkstraQ = dijkstra(graphQ, N-1);
    //cout << dijkstraP << " " << dijkstraQ << endl;
    for(int i = 0; i < N; i++){
        //cout << dijkstraP[i] << " " << dijkstraQ[i] << endl;
    }
    //return 0;
    vector<vector<pii>> conflicts(N);
    for(int i = 0; i < N; i++){
        //cout << "hi" << endl;
        //if there is only one 
        //build the third graph
        //int pNode = 0;
        int pMin = 1000000000;
        for(auto it : graphP[i]){
            if(it.s + dijkstraP[it.f] < pMin){
                pMin = it.s+dijkstraP[it.f];
                //pNode = it.f;
            }
        }
        //int qNode = 0;
        int qMin = 1000000000;
        for(auto it : graphQ[i]){
            if(it.s + dijkstraQ[it.f] < qMin){
                qMin = it.s+dijkstraQ[it.f];
                //qNode = it.f;
            }
        }
        for(int j = 0;j < graphP[i].size();j ++){
            int count = 0;
            if(graphP[i][j].s + dijkstraP[graphP[i][j].f] > pMin)count++;
            if(graphQ[i][j].s + dijkstraQ[graphQ[i][j].f] > qMin)count ++;
            conflicts[i].pb(mp(graphP[i][j].f, count));
        }
    }
    array<int, 10005> dijkstraR = dijkstra(conflicts, N-1);
    cout << dijkstraR[0] << endl;
}

