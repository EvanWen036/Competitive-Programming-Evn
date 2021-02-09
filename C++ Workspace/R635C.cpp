#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
vector<int> adj[100000];
int stz[100000];
int depth[100000];
void dfs(int curr, int par){
    for(int u : adj[curr]){
        if(u != par){
            depth[u] = depth[curr]+1;
            dfs(u, curr);
            stz[curr] += stz[u];
        }
    }
    
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n;
    cin >> n;
    int k;
    cin >> k;
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i < n; i++){
        stz[i] = 1;
    }
    memset(depth, 0, sizeof(depth));
    depth[0] = 0;
    dfs(0, -1);
    int val[n];
    for(int i = 0; i < n;i ++){
        cout << depth[i] << " " << stz[i]<< endl;
        val[i] = depth[i] - (stz[i]- 1);
    }
    sort(val, val + n);
    int ans = 0;
    for(int i = n-1; i > n-1-k; i--){
        ans += val[i];
    }
    cout << ans << endl;


}

