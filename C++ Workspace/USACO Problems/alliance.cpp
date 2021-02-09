#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int N, M;
vector<int> adj[100005];
set<int> vis;
int edges;
int nodes;
void dfs(int u){
    vis.insert(u);
    nodes++;
    edges += adj[u].size();
    for(int u : adj[u]){
        if(vis.count(u) == 0){
            dfs(u);    
        }
    }
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll ans = 1;
    for(int i = 0; i < N; i++){
        if(vis.count(i) == 0){
            dfs(i);
            edges/= 2;
            if(edges == nodes)ans *= 2;
            if(edges == nodes-1)ans *= nodes;
            if(nodes < edges) ans *= 0;
            edges = 0;
            nodes = 0;
            ans %= 1000000007;
        }
    }
    cout << ans << endl;


}

