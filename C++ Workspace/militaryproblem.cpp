#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
int N;
vector<int> adj[200005];
int stSize[200005];
int pre[200005];
vector<int> preorder;
void dfs(int u){
    pre[u] = preorder.size();
    preorder.pb(u);
    stSize[u] = 1;
    for(int v : adj[u]){
        dfs(v);
        stSize[u] += stSize[v];
    }
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> N;
    int q;
    cin >> q;
    for(int i = 1; i < N; i++){
        int x;
        cin >> x;
        x--;
        adj[x].pb(i);
    }
    dfs(0);
    /**
    for(int nodes : preorder){
        cout << nodes << endl;
    }
    **/
    /**
    for(int i = 0; i < N; i++){
        cout << stSize[i] << endl;
    }
    **/
    for(int i =0; i< q; i++){
        int u, k;
        cin >> u >> k;
        u--;
        if(stSize[u] < k){
            cout << -1 << endl;
        }
        else{
            cout << preorder[pre[u] + k -1]+1 << endl;
        }
    }
    

	


}

