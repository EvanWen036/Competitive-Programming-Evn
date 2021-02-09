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
set<int> adj[300005];
bool deleted[300005];
bool vis[300005];
int dist[300005];
int dist2[300005];
void dfs(int u){
    //cout << u << "\n";
    vis[u] = true;
    for(int v: adj[u]){
        //cerr << "hi\n";
        if(!vis[v]){
            dist2[v] = max(dist2[v], dist2[u]+1);
            dfs(v);
        }
        dist[u] = max(dist[u], 1 + dist[v]);
    }
}
int par[300005];
int find(int u){
    if(par[u] == u){
        return u;
    }
    return par[u] = find(par[u]);
}

int mergeTogether(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v)return -1;
    if(adj[u].size() < adj[v].size())swap(u,v);
    par[v] = u;
    //u is the bigger one
    for(int x : adj[v]){
        adj[u].insert(x);
    }
    adj[v].clear();
    return u;
} 
//int par[300005];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n, m, v;
    cin >> n >> m >> v;
    vector<pii> merge;
    for(int i = 0; i <m ;i ++){
        par[i] = i;
    }
    for(int i = 0; i < v;i ++){
        string line; cin >> line;
        int a, b;
        //bool type = false;
        for(int i = 0; i < line.size(); i++){
            if(line[i] == '<' || line[i] == '='){
                a=stoi(line.substr(0, i));
                b=stoi(line.substr(i+1));
                a--; b--;
                //cout << a << " " << b << "\n";
                //break;
                if(line[i] == '=')merge.pb({min(a,b),max(a,b)});
                else{
                    adj[a].insert(b);
                }
                break;
            }
        }
        //cout << a << " " << b << "\n";
    }
    //sort(merge.begin(), merge.end(), greater<pii>()); 
    for(pii u : merge){
        int newS = mergeTogether(u.f, u.s);
        //par[u.s] = u.f;
        if(newS == -1)continue;
        swap(adj[u.f], adj[newS]);
        //deleted[u.s] = true;
    }
    int src = 0;
    for(int i =0 ;i  < m;i++){
        //cout << "bonjour\n";
        //cout << adj[i].size() << "\n";
        if(!vis[i]){
            dfs(i);
            //break;
        }
    } 
    for(int i=  0; i < m; i++){
        //cout << i << " " << find(i) << " " <<  dist[i] << " " << dist2[i] << "\n";
        int node = i;
        node = find(node); 
        if(dist[node] + dist2[node] == n-1){
            cout << "K" << dist2[node]+1 << "\n";
        }
        else{
            cout << "?\n";
        }
    }

    

}

