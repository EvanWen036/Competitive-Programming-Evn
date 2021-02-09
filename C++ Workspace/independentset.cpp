#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
vector<int> adj[100005];
ll mod = 1e9+7;
int dp[100005][2];
ll dfs(int node, int color, int parent){
    //cout << node << " " << color << parent << endl;
    if(dp[node][color] != -1)return dp[node][color];
    ll ways = 1;
    for(int v : adj[node]){
        ll curr = 0;
        if(v != parent){
            if(color == 0){
                curr += dfs(v,1,node);
                curr %= mod;
            }
            curr += dfs(v,0,node);
            curr %= mod;
            ways *= curr;
            ways %= mod;
        }
        //ways *= curr;
    }
    //cput << node << " " << culor << " " << ways << endl;
    return dp[node][color] = ways;


}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N;
    cin >> N;
    for(int i = 0; i < N-1; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i = 0; i < N; i++){
        dp[i][0] = -1;
        dp[i][1] = -1;
    }
    cout << (dfs(0, 0, -1) + dfs(0,1,-1))%mod<< endl; 

}

