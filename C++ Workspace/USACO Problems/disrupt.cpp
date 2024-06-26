#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
vector<pii> adj[50005];
set<pair<int, pii>> s[50005];
//set<pair<int, pii>> *ptr[500005];
int ans[50005];
int merge(int u, int v){
    if(s[v].size() > s[u].size())swap(v,u);
    //u is the bigger one
    for(auto it : s[v]){
        if(s[u].count(it) > 0){
            s[u].erase(it);
        }
        else{
            s[u].insert(it);   
        }
    }
    s[v].clear();
    //s[v] = s[u];
    return u;
}
void dfs(int v, int p){
    //cout << v << "  " << p << endl;
    for(pii u : adj[v]){
        if(u.f != p){
            dfs(u.f, v);
            //query the child
            if(s[u.f].size() == 0){
                ans[u.s] = -1;
            }
            else{
                ans[u.s] = (*(s[u.f].begin())).f;
            }
            int newS= merge(v, u.f);
            //s[v] = *set;
            swap(s[v], s[newS]);
            
        }
    }
}
int main(){
    freopen("disrupt.in", "r", stdin);
    freopen("disrupt.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N-1; i++){
        int x, y;
        cin >> x >> y; x--; y--;
        adj[x].pb(mp(y,i));
        adj[y].pb(mp(x,i));
    }
    for(int i = 0; i < M; i++){
        int x, y, t;
        cin >> x >> y >> t; x--; y--;
        s[x].insert(mp(t, mp(x,y)));
        s[y].insert(mp(t, mp(x,y)));
    }
    dfs(0, -1);
    for(int i = 0; i < N-1; i++){
        cout << ans[i] << endl;
    }

}
