#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
vector<int> adj[200005];
int in[200005];
int out[200005];
int parent[200005];
int depth[200005];
int T = 0;
void dfs(int v, int par){
    in[v] = T;
    T++;
    for(int u : adj[v]){
        if(u != par){ 
            depth[u] = depth[v]+1;
            parent[u] = v;
            dfs(u, v);
        }
    }
    out[v] = T;
    T++;
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n;
    cin >> n;
    int q;
    cin >> q;
    for(int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(parent, 0 ,sizeof(parent));
    memset(depth, 0, sizeof(depth));
    
    dfs(0,0);
    
    for(int i =0; i < q; i++){
        int k;
        cin >> k;
        vector<int> query(k);
        for(int i = 0; i < k; i++){
            int x;
            cin >> x;
            query[i] = parent[x];
        }
   
        int first = query[0];
        for(int i = 0; i < k; i++){
            if(depth[first] < depth[query[i]]){
                first= query[i];
            }
        }
        bool works = true;
        for(int i = 0; i < k; i++){
            if(!(in[query[i]] <= in[first] && out[first] >= out[query[i]])){
                works = false;
            }
        }
        cout << (works ? "YES":"NO") << endl;

    }
    

}

