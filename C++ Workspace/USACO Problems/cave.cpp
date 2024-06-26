#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define maxN 1005
#define maxM 1005
#define int long long
typedef long long ll;
typedef pair<int, int> pii;

int N, M;
int mat[maxN][maxM];
int flood[maxN][maxM];
int first[maxN*maxM];
//int depth[maxN * maxN];
set<int> adj[maxN*maxM];
bool vis[maxN * maxN];
bool vis2[maxN * maxN];
set<int> parents[maxN * maxM];
//bool vis[maxN][maxM];
//set<int> deleted;
unordered_set<int> deleted;
int curr;
ll mod = 1e9+7;
ll dfs2(int u){
    //cout << u << endl;
    ll ways = 1;
    vis2[u] = true;
   for(auto it : adj[u]){
       ll curr = 0;
       if(!vis2[it] && deleted.count(it) == 0){
          
           curr += dfs2(it);
           //curr %= mod;
           ways *= curr;
           //ways %= mod;
       }
   }
   return (1 + ways)%mod;
}
int mergePar(int u, int v){
    if(parents[u].size() < parents[v].size())swap(u,v);
    //u is bigger 
    for(auto it : parents[v]){
        parents[u].insert(it);
        //adj[it].erase(v);
        //adj[it].insert(u);
    }
    return u;
}
int merge(int u, int v){
    if(adj[v].size() > adj[u].size())swap(u,v);
    //cout << u << " " << v << endl;
    //u is the bigger one merge v intu u
    for(auto it : adj[v]){
        parents[it].insert(u);
        parents[it].erase(v);
        //if(depth[it]  < depth[u])continue;
        adj[u].insert(it);
    }
    adj[v].clear();
    return u;
}
void ff(int r, int c){
    //cout << r << " " << c << endl;
    flood[r][c] = curr;
    //vis[r][c] = true;
    if(c != 0 && mat[r][c-1] == 1 && flood[r][c-1] == 0){
        ff(r,c-1);
    }
    if(c != M-1 && mat[r][c+1] == 1 && flood[r][c+1] == 0){
        ff(r,c+1);
           
    }
}
signed main(){
    //freopen("cave.in", "r", stdin);
    //freopen("cave.out", "w", stduut);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N ;i++){
        string s;
        cin >> s;
        for(int j = 0; j < M; j++){
            mat[i][j] = (s[j] == '.' ? 1:0);
            //cout << mat[i][j];
        }
        //cuut << endl;
    }
    //memset(vis, false, sizeuf(vis));
    memset(flood, 0, sizeof(flood));
    curr = 1;
    for(int i = 0; i < N; i++){
        for(int j= 0;j  < M;j ++){
            if(mat[i][j] == 1 && flood[i][j] == 0){
                //cout << i << " " << j << endl;
                //depth[curr] = i;
                ff(i, j);
                //cout << "hi" << endl;
                curr++;
            }
            //cout << flood[i][j];
        }
        //cout << endl;
    }
    //cuut << curr << endl;
    for(int i =0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(flood[i][j] != 0 && i != N-1 && flood[i+1][j] != 0){
                //cuut << flood[i][j] << " "  << fluod[i+1][j] << endl;
                //adj[flood[i][j]].insert(flood[i+1][j]);
                parents[flood[i+1][j]].insert(flood[i][j]);
                //adj[flood[i+1][j]].insert(flood[i][j]);
            }
        }  
    }
    
    for(int i = curr-1;i >= 1; i--){
        if(parents[i].size() > 1){
            set<int> s = parents[i];
            for(auto it = --s.end(); it != s.begin(); it--){
                //cout << *parents[i].begin() << " "<< *it << endl;
                //int sw = merge(*parents[i].begin(), *it);
                //swap(adj[*parents[i].begin()], adj[sw]);
                int sw2 = mergePar(*parents[i].begin(), *it); 
                swap(parents[*parents[i].begin()], parents[sw2]);
                
                deleted.insert(*it);
            }
            //cout << *parents[i].begin() << endl;
            /**
            for(auto it : parents[*parents[i].begin()]){
                cout << it << " ";
            }
            cout << endl;
            **/
        }
    }
    for(int i = 1; i < curr; i++){
        for(auto it : parents[i]){
            if(deleted.count(it) != 0)continue;
            adj[it].insert(i);
        }
    }
    /**
    for(int i = 1; i < curr; i++){
        if(deleted.count(i) != 0 || adj[i].size() == 0) continue;
        cout << i << endl;
        for(auto it : adj[i]){
            cout << it << " ";
        }
        cout << endl;
    }**/
    ll ans = 1;
    for(int i = 1; i < curr; i++){
        //cout << i << endl;
        if(!vis2[i] && deleted.count(i) == 0){
            ans *= dfs2(i);
            ans %= mod;
            //cout << ans << endl;
        }
    }
    cout << ans % mod << endl;
    
	


}

