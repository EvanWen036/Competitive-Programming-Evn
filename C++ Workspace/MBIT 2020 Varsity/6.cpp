#include <iostream>
#include <set>
#include <vector>
using namespace std;

typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define F0R(i, x) FOR(i, 0, x)
const int MAX_N = 1001;
const ll MOD = 1000000007;

int n, m, k, b;
int par[MAX_N*MAX_N], sz[MAX_N*MAX_N];
int dirx[4] = {1, 0, 0, -1}, diry[4] = {0, -1, 1, 0}, dir[256];
bool done[MAX_N*MAX_N];
vector<int> query;
set<int> components, edges[MAX_N*MAX_N][4];

int root(int v){ return v^par[v] ? par[v] = root(par[v]):v; }
void join(int u, int v){
    if((u=root(u)) == (v=root(v))) return;
    components.erase(components.find(v));
    sz[u] += sz[v]; par[v] = u;
}
bool out(int i, int j){
    if(i >= n || j >= m) return true;
    if(i < 0 || j < 0) return true;
    return false;
}

int main(int argc, const char * argv[]) {
//    setIO();
    cin >> n >> m >> k >> b;
    dir['N'] = 0, dir['W'] = 1, dir['E'] = 2, dir['S'] = 3;
    F0R(i, n) F0R(j, m){
        par[m*i+j] = m*i+j;
        sz[m*i+j] = 1;
    }
    F0R(i, b){
        char x; cin >> x;
        query.push_back(dir[x]);
    }
    F0R(i, k){
        int a, b; cin >> a >> b; a--, b--;
        done[a*m+b] = 1;
        components.insert(a*m+b);
        F0R(j, 4){
            int x = a+dirx[j], y = b+diry[j];
            if(out(x, y)) continue;
            if(done[x*m+y])
                join(x*m+y, a*m+b);
        }
    }
    F0R(i, n*m){
        if(!done[i]) continue;
        F0R(j, 4){
            if(out(i/m+dirx[j], i%m+diry[j])) continue;
            int ni = m*(i/m+dirx[j])+i%m+diry[j];
            if(!done[ni]) edges[root(i)][j].insert(ni);
        }
    }
    for(int i = 0; i < b;i ++){
        
    }
    return 0;
}