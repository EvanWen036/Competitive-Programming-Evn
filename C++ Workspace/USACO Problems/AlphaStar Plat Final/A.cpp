#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

vector<int> adj[100005];
int pl[100005];
int mi[100005];
int r = 1;
void dfs(int v, int p){
    pl[v] = r; 
    r++;
    for(int u : adj[v]){
        if(u != p){
            dfs(u, v);
        }
    }
    mi[v] = r;
    r++;
}
int BIT[200005];
void update(int idx, int val){
    for(int i = idx; i <= 200000; i+= i&-i){
        BIT[i] += val;
    }
}
int query(int idx){
    int sum = 0;
    for(int i = idx; i >= 1; i-= i & -i){
        sum += BIT[i];
    }
    return sum;
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N;
    cin >> N;
    for(int i = 0; i < N-1; i++){
        int a, b; cin >> a >> b; a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(0,-1);
    for(int i = 0; i < N; i++){
        //cout << pl[i] << " " << mi[i] << endl;
    }
    memset(BIT, 0, sizeof(BIT));
    for(int i = 0; i < N; i++){
        int x;
        cin >> x; x--;
        cout << query(pl[x]) << endl;
        update(pl[x], 1);
        update(mi[x], -1);
    }

}

