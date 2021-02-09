#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
int N;
vector<int> adj[100005];
int anc[100005][25];
int depth[100005];
int preorder[100005];
pii ranges[100005];
int r = 0;
void dfs(int v, int p){
    preorder[v] = ++r;
    ranges[v].f = r;
    for(int u : adj[v]){
        if(u != p){
            anc[u][0] = v;
            depth[u] = depth[v]+1;
            dfs(u, v);
        }
    }
    ranges[v].s = r;
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
int BIT[100005];
void update(int idx, int val){
    for(int i = idx; i <= 100005; i += i&-i){
        BIT[i] += val;
    }
}
int query(int idx){
    int sum = 0;
    for(int i = idx; i >= 1; i-=i&-i){
        sum += BIT[i];
    }
    return sum;
}
int main(){
    freopen("maxflow.in", "r", stdin);
    freopen("maxflow.out", "w", stdout);
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
    depth[0] = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= 24; j++){
            anc[i][j] = -1;
        }
    }
    dfs(0, -1);
    calc();
    memset(BIT, 0, sizeof(BIT));
    for(int i = 0; i < K; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        update(preorder[a], 1);
        update(preorder[b], 1);
        update(preorder[lca(a,b)], -1);
        if(anc[lca(a,b)][0] != -1){
            update(preorder[anc[lca(a,b)][0]], -1);
        } 
        //cuut << a << " " << b << " " << lca(a,b) << endl;
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        if(i == 0){
            ans = max(ans, query(ranges[i].s));
        }
        else{
            ans = max(ans, query(ranges[i].s) - query(ranges[i].f-1));
        }
    }
    cout << ans << endl;
    


}

