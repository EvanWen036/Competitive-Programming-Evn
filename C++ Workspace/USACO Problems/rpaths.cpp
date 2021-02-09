#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
vector<int> adj[5005];
vector<int> tree[5005];
bool vis[5005];
int F;
queue<int> Q[5005];
set<pii> bridges;
int cmp = 0;
void dfs1(int v){

    //cout << v << endl;
    int current = cmp;
    Q[current].push(v);
    vis[v] = true;
    while(!Q[current].empty()){
        int u = Q[current].front();
        Q[current].pop();
        for(int a : adj[u]){
            if(vis[a])continue;
            if(bridges.count(mp(a,u)) != 0 || bridges.count(mp(u,a)) != 0){
                cmp++;
                tree[current].pb(cmp);
                tree[cmp].pb(current);
                dfs1(a);
            }
            else{
                Q[current].push(a);
                vis[a] = true;
            }
        }
    }
}
void dfs(int u, int i, int j){
    vis[u] = true;
    for(int v: adj[u]){
        if(!((v == j && u == i) || (v== i && u == j))){
            if(!vis[v]){
                dfs(v,i,j);
            }
        }
    }
}
int countComponents(int i, int j){
    int count = 0;
    //cout << i << " " << j << endl;
    for(int u = 0; u < F; u++){
        if(!vis[u]){
            count++ ;
            dfs(u, i, j);
        }
    }
    //cout << count << endl;
    return count;
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int  R;
    cin >> F >> R;
    for(int i = 0; i < R; i++){
        int a, b;
        cin >> a >> b; a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    //vector<pii> bridges;
    for(int i = 0; i < F; i++){
        for(int j = 0; j < adj[i].size(); j++){
            memset(vis, false,sizeof(vis));
            if(adj[i][j] < i)continue;
            if(countComponents(i, adj[i][j]) != 1){
                bridges.insert(mp(i,adj[i][j]));
            }
        }
    }
    //cout << bridges.size() << endl;

    memset(vis, false,sizeof(vis));
    dfs1(0);
    //cout << "HI"<<endl;
    int cnt = 0;
    for(int i = 0; i < F; i++){
       if(tree[i].size() == 1){
           cnt++;
       }
    }
    //cout << cnt << endl;
    cout << ceil(cnt/2.0);
    
}

