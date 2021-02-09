#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
vector<int> adj[100005];
int anc[100005][25];
int depth[100005];
int preorder[100005];
pii range[100005];
int r = 0;
int N;
void dfs(int v, int p){
    //cout << v << " " << p << endl;
    preorder[v] = ++r;
    range[v].f = r;
    for(int u : adj[v]){
        if(u != p){
            anc[u][0] = v;
            depth[u] = depth[v]+1;
            dfs(u,v );
        }
    }
    range[v].s = r;
}
void fillTable(){
    for(int k = 1; k <= 24; k++){
        for(int i = 0; i < N; i++){
            int mid = anc[i][k-1];
            if(mid != -1){
                anc[i][k] = anc[mid][k-1];
            }
        }
    }
}
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
void update(int index, int addVal){
    for(int i = index; i <= 100000; i+= i&-i){
        BIT[i] += addVal;
    }
}
int query(int index){
    int sum = 0;
    for(int i = index; i>= 1; i-= i & -i){
        sum += BIT[i];
    }
    return sum;
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int  M;
    cin >> N >> M;
    for(int i  =0 ; i< N - 1; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    depth[0] = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0;j <= 21; j++){
            anc[i][j] = -1;
        }
    }
    dfs(0, -1);
    fillTable();
    memset(BIT, 0, sizeof(BIT));
    for(int i = 0; i < N; i++){
        //cout << depth[i] << endl;
        //cout << preorder[i] << " " << range[i].f << " " << range[i].s << endl;
    }
    for(int i = 0; i < M; i++){
        string c;
        cin >> c;
        if(c == "P"){
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            //cout << lca(x,y) << endl;
            update(preorder[lca(x,y)], -2);
            //cout << lca(x,y) << endl;
            update(preorder[x], 1);
            update(preorder[y],1);
        }
        else{
            int x, y;
            cin >> x >> y; x--; y--;
            if(depth[y] > depth[x]){
                swap(x,y);
            }
            //x is greater depth
            cout << query(range[x].s) - query(range[x].f-1) << endl;
        }    
    }
}

