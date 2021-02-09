#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
vector<int> adj[100005];
int dp[100005][2];
void dfs(int u, int v){
    for(int child : adj[u]){
        if(child != v){
            dfs(child, u);
        }
    }
    int sum = 1;
    for(int child: adj[u]){
        sum += dp[child][0];
    }
    dp[u][1] = sum;
    sum = 0;
    for(int child : adj[u]){
        sum += max(dp[child][1], dp[child][0]);
    }
    dp[u][0] = sum;    
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N;
    cin >> N;
    for(int i =0; i< N-1;i ++){
        int x, y;
        cin >> x >> y; x--; y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(0,-1);
    cout << max(dp[0][0],dp[0][1]) << endl;
}

