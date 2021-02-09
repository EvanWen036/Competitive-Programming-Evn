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
int d1[300005];
int d2[300005];
vector<int> adj[300005];
int a, b;
void dfs(int v, int p, int time){
    int add =1 ;
    for(int u : adj[v]){
        if(u != p && u != a && u != b){
            if(time == 1){
                d1[u] = d1[v] + add;
            }
            else{
                d2[u] = d2[v] + add;
            }
            add++;
            dfs(u,v,time);
        }
    }
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
        adj[x].pb(y);
        adj[y].pb(x);
    }
    d1[a] = 0;
    dfs(a, -1, 1); 
    d2[b] = 0;
    dfs(b,-1,2);
    int ans = 0;
    for(int i = 0; i < n; i++){
        cout << d1[i] << " " << d2[i] << "\n";;
        ans = max(ans, min(d1[i], d2[i]));
    }
    cout << ans << "\n";
}

