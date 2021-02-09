#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
vector<int> adj[10005];
vector<vector<int>> components;
bool vis[10005];
stack<int> S;
void dfsUtil(int v){
    vis[v] = true;
    for(int u : adj[v]){
        if(!vis[u]){
            dfsUtil(u);
        }
    }
}
void fillOrder(int v){
    vis[v] = true;
    for(int u : adj[v]){
        if(!vis[u]){
            fillOrder(u);
        }
    }
    S.push(v);
}
int getSCC(vector<int> component){
    for(int u : component){
        if(!vis[u]){
            fillOrder(u);
        }
    }
    vector<pii> edges;
    for(int v : component){
        vis[v] = false;
        while(adj[v].size() != 0){
            edges.pb(mp(v,adj[v].back()));
            //cout << adj[v].back() << " " << v << endl;
            adj[v].pop_back();
        }
    }
    for(auto it: edges){
        adj[it.s].pb(it.f);
    }
    int count = 0;
    while(!S.empty()){
        int v = S.top();
        S.pop();
        if(vis[v] == false){
            count ++;
            dfsUtil(v);
        }
    }
    if(count == 0)count = 1;
    return count;
}
void dfs(int u){
    //cout << u << endl;
    vis[u] = true;
    components[components.size()-1].pb(u);
    for(int v : adj[u]){
        if(!vis[v]){
            dfs(v);
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
        cin >> a >> b; a--; b--;
        adj[a].pb(b);
    }
    memset(vis, false,sizeof(vis));
    for(int i = 0; i < N; i++){
        if(!vis[i]){
            vector<int> v;
            components.pb(v);
            dfs(i);
        }
    }
    /**
    for(int j = 0; j < components.size(); j++){
        for(int i = 0; i < components[j].size(); i++){
            cout << components[j][i] << " ";
        }
        cout << endl;
    }
    **/
    memset(vis, false,sizeof(vis));
    int ans =0;
    cout << components.size() << endl;
    for(int i = 0; i < components.size(); i++){
        if(getSCC(components[i]) == 1){
            ans++;
        }
        memset(vis,false,sizeof(vis));
    }
    cout << components.size()-1 << endl;
    
}

