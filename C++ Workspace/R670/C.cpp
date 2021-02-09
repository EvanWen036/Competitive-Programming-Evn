#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
vector<int> adj[100005];
int stz[100005];
int depth[100005];
int get(int v){
    int ans = 100000000;
    if(v == 1){
            int big = 0;
            for(int u : adj[1]){
               big = max(big, stz[u]);
            }
            ans = min(ans, big);
        }
        else{
            ans = min(ans, max(stz[v]-1, stz[1] - stz[v]));
        }
    return ans;
}
void dfs(int v, int p){
    //cout << v << endl;
    stz[v] = 1;
    for(int u : adj[v]){
        if(u != p){
            depth[u] = depth[v]+1;
            dfs(u, v);
            stz[v] += stz[u];
        }
        if(u == p && u == adj[v].back()){
            adj[v].pop_back();
        }
    }
}
void solve(){
    int n;
    cin >> n;
    //cout << n << endl;
    for(int i = 0; i < n-1; i ++){
        int a, b;
        cin >> a >> b;
        //cout << a << " " << b << endl;
        //a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    /**
    for(int i = 1; i <= n; i++){
        for(int u : adj[i]){
            cout << i << " " << u << endl;
        }
    }**/
    memset(stz, 0, sizeof(stz));
    depth[0]=0;
    dfs(1, 0);
    int ans = 100000000;
   //cout << "hi" << endl;
    for(int i =1;i <= n; i++){
        ans = min(ans, get(i));
        //cout << i << " " << get(i) << endl;
    }
     
    int cnt = 0;
    vector<int> centroids;
    for(int i = 1; i <= n;i ++){
        if(get(i) == ans){
            cnt++;
            centroids.pb(i);
        }
    }
    //cout << "hi" << endl;
    assert(cnt <= 2);
    //assert(centroids.back() == centroids[0] || count(adj[centroids.back()].begin(), adj[centroids.back()].end(), centroids[0]) != 0);
    if(cnt == 1){
        cout << 1 << " " << adj[1].back() << "\n";
        cout << 1 << " " << adj[1].back() << "\n";
        
    }
    //cuut << "hi" << endl;
    else{
        //cout << centroids[0] << " " << centroids.back() << endl;
        //centroids 0 should be the lower one
        if(depth[centroids[0]] < depth[centroids.back()]){
            swap(centroids[0], centroids.back());
        }
        cout << centroids[0] << " " << adj[centroids[0]].back() << "\n";
        cout << adj[centroids[0]].back() << " " << centroids.back() << "\n";
    }
    //cout << ans << endl;
    for(int i = 1;  i <= 100000;i++){
        adj[i].clear();
    }
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }


}

