#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define maxN 1005
typedef long long ll;
typedef pair<int, int> pii;
int N, M;
int flood[1005][1005];
int mat[maxN][maxN];
set<int> parents[maxN * maxN];
set<int> deleted;
set<int> adj[maxN * maxN];
int dsu[maxN * maxN];
bool vis[maxN * maxN];
ll mod = 1e9+7;
ll dfs(int u){
    //cout << u << endl;
    vis[u] = true;
    ll ways = 1;
    for(auto it : adj[u]){
        if(!vis[it] && deleted.count(it) == 0){
            ways *= dfs(it);
            ways %= mod;
        }
    }
    return 1 + ways;
}
int find(int x){
    if(dsu[x] == x){
        return x;
    }
    return dsu[x] = find(dsu[x]);
}
int merge(int x, int y){
    if(parents[x].size() < parents[y].size())swap(x,y);
    //x is the bigger one
    dsu[y] = x;
    for(auto it : parents[y]){
        parents[x].insert(it);
    }
    parents[y].clear();
    parents[y].insert(x);
    return x;
}
int reg = 1;
void ff(int r, int c){
    flood[r][c] = reg;
    if(c != M-1 && flood[r][c+1] == 0 && mat[r][c+1] == 1){
        ff(r, c+1);
    }
    if(c != 0 && flood[r][c-1] == 0 && mat[r][c-1] == 1){
        ff(r, c-1);
    }
}
int main(){
    freopen("cave.in", "r", stdin);
    freopen("cave.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
    for(int i = 0;  i< N; i++){
        string s;
        cin >> s;
        for(int j = 0; j < M; j++){
            mat[i][j] = (s[j] == '.' ? 1 : 0);
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(flood[i][j] == 0 && mat[i][j] == 1){
                ff(i,j);
                reg++;            
            }
            //cout << flood[i][j] << " ";
        }
        //cout << endl;
    }
    for(int i = 0; i < N-1; i++){
        for(int j = 0;j < M; j++){
            if(flood[i][j] != 0 && flood[i+1][j] != 0 && flood[i][j] != flood[i+1][j]){
                parents[flood[i+1][j]].insert(flood[i][j]);
            }
        }
    }
    for(int i = 1; i < reg;i ++){
        dsu[i] = i;
    }
    for(int i = reg-1; i >= 1; i--){
        if(parents[i].size() == 0)continue;
        dsu[i] = *parents[i].begin();
        for(set<int>::iterator it = --parents[i].end(); it != parents[i].begin(); it--){
            //do stuff
            //cout << *parents[i].begin() << " " << *it << endl;
            int sw = merge(*parents[i].begin(), *it);
            swap(parents[*parents[i].begin()], parents[sw]);
            deleted.insert(*it);            
        }
    }
    for(int i = reg - 1; i >= 1;i --){
        if(parents[i].count(i) != 0){
            parents[i].erase(i);
        }
        //cuut << i << " " << *parents[i].begin() << endl;

    }
    for(int i = reg - 1; i >= 1; i--){
        int curr = i;
        while(parents[curr].size() > 0 && deleted.count(*parents[curr].begin()) != 0){
            //cout << curr << endl;
            
            curr = *parents[curr].begin();
            //cout << curr << endl;
        }
        //if(curr == i)continue;
        if(parents[curr].empty() || deleted.count(i) != 0)continue;
        curr = *parents[curr].begin();
        adj[curr].insert(i);
    }
    //cout << "bruh" << endl;
    /**
    for(int i =  1; i < reg; i++){
        cout << i << endl;
        for(auto it : adj[i]){
            cout << it << " ";
        }
        cout << endl;
    }
    **/
    ll ans = 1;
    for(int i = 1; i < reg; i++){
        if(!vis[i] && deleted.count(i) == 0){
            ans *= dfs(i);
            ans %= mod;
        }
    }
    cout << ans << endl;


}

