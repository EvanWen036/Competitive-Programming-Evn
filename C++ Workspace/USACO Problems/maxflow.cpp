#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
int N;
vector<int> adj[500005];
int anc[500005][25];
int depth[500005];
int posD[500005];
int negD[500005];
int current;
int ans ;
void dfs2(int v, int p){
    current += posD[v];
    ans = max(ans, current);
    current-=negD[v];

    
    for(int u : adj[v]){
        if(u != p){
            //add negative delta
            dfs2(u, v);
            //we're back
            //current += negD[v];
        }
    }
    //ans = max(ans, current);
    current += negD[v];
    current -= posD[v];
}
void dfs(int v, int p){
    for(int u : adj[v]){
        if(u != p){
            anc[u][0] = v;
            depth[u] = depth[v]+1;
            dfs(u,v);
        }
    }
}
void calc(){
    for(int v = 1; v <= 24; v++){
        for(int i = 0; i < N; i++){
            int mid = anc[i][v-1];
            if(mid != -1){
                anc[i][v] = anc[mid][v-1];
            }
        }
    }
}
//return when i walks k steps
int walk(int i, int k){
    for(int d =0; d <= 24 && i != -1; d++){
        if(((1<<d) & k)){
            i = anc[i][d];
        }
    }
    return i;
}
int lca(int i, int j){
    if(depth[i] > depth[j]){
        i = walk(i, depth[i] - depth[j]);
    }
    if(depth[j] > depth[i]){
        j = walk(j, depth[j] -depth[i]);
    }
    //cout << i << " " << j << endl;
    if(i == j){
        return i;
    }
    for(int d= 24; d >= 0; d--){
        if(anc[i][d] != anc[j][d]){
            i = anc[i][d];
            j = anc[j][d];
        }
    }
    return anc[i][0];
}

int main(){
    //freopen("maxflow.in", "r", stdin);
    //freopen("maxflow.out", "w", stduut);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int K;
    cin >> N >> K;
    for(int i = 0; i < N-1; i++){
        int a, b;
        cin >> a >> b; a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i = 0; i < N; i++){
        for(int j= 0; j <= 24; j++){
            anc[i][j] = -1;
        }
    }
    depth[0] = 0;
    dfs(0,-1);
    calc();
    
    memset(posD, 0, sizeof(posD));
    memset(negD, 0, sizeof(negD));
    for(int i = 0; i < K; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        //cout << lca(a,b) << endl;
        posD[lca(a,b)]++;
        if(lca(a,b) != a){
            negD[a] ++;
        }
        if(lca(a,b) != b){
            negD[b]++;
        }
    }
    for(int i = 0; i < N; i++){
        cout << posD[i] << " " << negD[i] << endl;
    }
    current = 0;
    ans = 0;
    dfs2(0, 0);
    cout << ans << endl;

}

