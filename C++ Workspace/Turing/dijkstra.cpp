#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
vector<pii> adj[100005];
int dijkstra[100005];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N, M, S;
    cin >> N >> M >> S;
    for(int i = 0; i < M;i  ++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].pb(mp(b,w));
        adj[b].pb(mp(a,w));
    }
    for(int i = 1; i <= N; i++)dijkstra[i] = 100000000;
    dijkstra[S] = 0;
    priority_queue<pair<int,int>, vector<pii>, greater<pii>> pq;
    pq.push(mp(0,S));
    while(!pq.empty()){
        int u = pq.top().s; pq.pop();
        //if(pq.top().f != dijkstra[u])continue;        
        for(auto it : adj[u]){
            if(dijkstra[it.f] > dijkstra[u] + it.s){
                dijkstra[it.f] = dijkstra[u] + it.s;
                pq.push(mp(dijkstra[it.f], it.f));
            }
        }
    }
   
    for(int i = 1; i <= N;i ++){
        //ans += dijkstra[i];
        if(dijkstra[i] == 100000000)cout << -1 << "\n";
        else{cout << dijkstra[i] << "\n";}
    }
    //cout << ans << "\n";

}

