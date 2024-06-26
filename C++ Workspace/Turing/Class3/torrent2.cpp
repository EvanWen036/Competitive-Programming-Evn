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
vector<pii> edges;
int a, b;
bool found = false;
int dist[300005];
int ans = 100000000;
int  temp = 0;
void dfs1(int v, int p){
    if(v == b){
        found = true;
        return;
    }
    for(int u : adj[v]){
        if(u != p){
            edges.pb(mp(v, u));
            dfs1(u, v);
            if(found)return;
            edges.pop_back();
        }
    }
}

int dfs2(int v, int p){
    //cuut << v << " " << dist[v] << "\n";
    vector<int> values;
    for(int u : adj[v]){
        if(u == p)continue;
        values.pb(dfs2(u,v));
    }
    
    sort(values.begin(), values.end(), greater<int>());
    int ret = 0;
    for(int i = 0; i < values.size(); i++){
        ret = max(ret, values[i] + 1 + i);
    }
    return ret;
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n;
    cin >> n >> a >> b; 
    a--; b--;
    for(int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    dfs1(a, -1);
    /**
    for(pii u : edges){
        //cout << u.f << " " << u.s << "\n";
        //erase this edge
        adj[u.f].erase(u.s);
        adj[u.s].erase(u.f);
        //do stuff
        int ans1 = dfs2(a, -1);
        int ans2 = dfs2(b, -1);
        ans = min(ans, max(ans1,ans2));
        //add it back
        memset(dist, 0,sizeof(dist));
        adj[u.f].insert(u.s);
        adj[u.s].insert(u.f);
    }**/
    int lo = 0;
    int hi = edges.size()-1;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        pii u = edges[mid];
        adj[u.f].erase(u.s);
        adj[u.s].erase(u.f);
        int ans1 = dfs2(a,-1);
        int ans2 = dfs2(b, -1);
        ans = min(ans, max(ans1, ans2));
        //a is greater than b
        adj[u.f].insert(u.s);
        adj[u.s].insert(u.f);
        if(ans1 > ans2){
            //try an edge closer to b
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }
    cout << ans << "\n";
}

