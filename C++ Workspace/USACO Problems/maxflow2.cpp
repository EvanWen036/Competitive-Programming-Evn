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
int preorder[500005];
pii range[500005];
int r = 0;

void dfs(int v, int p){
    preorder[v] = ++r;
    range[v].f = preorder[v];
    for(int u : adj[v]){
        if(u != p){
            anc[u][0] = v;
            depth[u] = depth[v]+1;
            dfs(u,v);
        }
    }
    range[v].s = r;
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
    for(int i = 0 ; i < N; i++){
        for(int j = 0; j <= 24; j++){
            anc[i][j] = -1;
        }
    }
    dfs(0, -1);
    calc();
    /**
    for(int i = 0; i < N; i++){
        cout << preorder[i] << " " << range[i].f << " " << range[i].s << endl;
    }
    **/
    int sum[N+1];
    memset(sum, 0, sizeof(sum));
    for(int i = 0; i < K; i++){
        int a, b;
        cin >> a >> b; a--; b--;
        sum[a]++;
        sum[b]++;
        sum[lca(a,b)]--;
        if(lca(a,b) != 0){
            sum[anc[lca(a,b)][0]]--;
        }
    }
    int ans = 0;
    for(int i =1; i < N; i++){
        sum[i] += sum[i-1];
        cout << sum[i] << endl;
        //ans = max(ans, sum[i]);
    }
    sum[N] = sum[N-1];
    for(int i = 0; i < N;i ++){
        ans = max(ans, sum[range[i].s]-sum[range[i].f-1]); 
    }
    cout << ans << endl;
}

