#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> adj[100005];
bool isLeaf[100005];
int leafs[100005];
bool vis[100005];
int depth[100005];
vector<int> containsLeaf;
bool add[100005];
int root;
void dfs(int v){
    vis[v] = true;
    for(int u : adj[v]){
        if(!vis[u]){
            depth[u] = depth[v]+1;
            dfs(u);
            if(isLeaf[u]){
                leafs[v] += leafs[u];
                if(!add[v]){
                     containsLeaf.push_back(v);
                     add[v] = true;
                 }
            }
        }
    }
    if(adj[v].size() == 1 && v != root){
        isLeaf[v] = true;
        leafs[v] = 1;
    }
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i < n; i++){
        if(adj[i].size() > 1){
            root = i;
            break;
        }
    }
    
    
    
    
    memset(vis, false, sizeof(vis));
    memset(leafs, 0 ,sizeof(leafs));
    memset(depth, 0 , sizeof(depth));
    memset(isLeaf,false,sizeof(isLeaf));
    memset(add, false, sizeof(add));
    dfs(root);
    int min = n-1;
    int max = n-1;
    bool par1 = 0;
    bool par2 = 0;
    int leafs = 0;
    for(int i = 0; i < n; i++){
        if(isLeaf[i]){
            leafs++;
            //cout << depth[i] << endl;
            if(depth[i] % 2==0)par1 =true;
            else{par2= true;}
        }
    }
    if(par1 ^ par2)min = 1;
    else{min = 3;}
    max = max - leafs + containsLeaf.size();
    cout << min << " " << max;
    
}

