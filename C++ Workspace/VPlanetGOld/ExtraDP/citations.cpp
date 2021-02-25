#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define sz(a) a.size()
typedef long long ll;
typedef pair<ll, ll> pii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
int N; 
vector<int> adj[100005];
int stz[100005];
ll dp[100005];
ll ti[100005];
ll sum[100005];
void dfs(int v){
    stz[v] = 1;
    sum[v] = ti[v];
    vector<pair<ll,ll>> child;
    for(int u : adj[v]){
        dfs(u);
        sum[v] += sum[u];
        stz[v] += stz[u];
        child.pb({stz[u]+sum[u], u});
    }
    //do the dp calculations
    ll cw = 1;
    sort(child.begin(), child.end());
    for(int i = 0; i < child.size(); i++){
        dp[v] += dp[child[i].s] + cw * stz[child[i].s];
        cw += stz[child[i].s]+sum[child[i].s];
    }
    //cout << dp[v] << " " << stz[v] << " " << sum[v] << '\n';
	dp[v] += stz[v] + sum[v];
}
main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N;i ++){
        cin >> ti[i];
        int x;
        cin >> x;
        for(int j = 0;j < x;j ++){
            int y;
            cin >> y;
            adj[i].pb(y-1);
        }
    }
    dfs(0);
    cout << dp[0] << '\n';
}