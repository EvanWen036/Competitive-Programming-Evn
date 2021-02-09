#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
set<int> special[100005];
vector<int> adj[100005];
int preorder[100005];
pii ranges[100005];
int stz[100005];
int r= 0;
struct SegTree{
    ll t[800005];
    ll lazy[800005];
    void build(int v, int l, int r){
        if(l == r){
            t[v] = 0;
        }
        else{
            int mid = (l+r)/2;
            build(v*2, l, mid);
            build(v*2+1, mid + 1, r);
            t[v] = t[v*2] + t[v*2+1];
        }
    }
    long long sum(int v,int lr, int rr, int l, int r){
        if(r < lr || l > rr || lr > rr)return 0;
        if(lazy[v] != 0){
            t[v] += (rr -lr+1) * lazy[v];
            if (lr != rr) {                                     // update lazy[] for children nodes
                lazy[2 * v] += lazy[v];
                lazy[2 * v + 1] += lazy[v];
            }
            lazy[v] = 0;
        }
        if(l <= lr && r >= rr){
            return t[v];
        }
        
        else{
            int tm = (lr + rr)/2;
            return sum(v*2, lr, tm, l, r) + sum(v*2+1, tm+1, rr, l, r);
        }
    }

    void updateRange(int v, int lr, int rr, int l, int r, long long val){
        //cout << v << " " << lr << " " << rr << " " << l << " " << r << " " << val << "\n";
        if(lazy[v] != 0){
            t[v] += (rr -lr+1) * lazy[v];
            if (lr != rr) {                                     // update lazy[] for children nodes
                lazy[2 * v] += lazy[v];
                lazy[2 * v + 1] += lazy[v];
            }
            lazy[v] = 0;
        }
        if(lr > rr || l > rr || r < lr )return;
        if(l <= lr && r >= rr){
            t[v] += (rr - lr+1) * val;
            //t[v].first += val;
            if(lr != rr){
                lazy[2*v] += val;
                lazy[2*v+1] += val;
            }
            return;
        }
        int tm = (lr+rr)/2;
        updateRange(2*v, lr, tm, l, r, val);
        updateRange(2*v+1, tm+1, rr, l ,r, val);
        t[v] = t[2*v] + t[2*v+1];
    }
};
void dfs(int v, int p){
    preorder[v] = ++r;
    ranges[v].f = preorder[v];
    stz[v] = 1;
    for(int u : adj[v]){
        if(u != p){
            dfs(u, v);
            stz[v] += stz[u];
        }
    }
    
    ranges[v].s = r;
}
int main(){
    freopen("snowcow.in", "r", stdin);
    freopen("snowcow.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, Q;
    cin >> N >> Q;
    for(int i = 0; i < N-1; i ++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(0, -1);
    /**
    for(int i = 0; i < N; i++){
        cout << i << " " << stz[i] << endl;
    }
    **/
    SegTree above;
    SegTree below;
    above.build(1, 1, N);
    below.build(1, 1, N);
    for(int i = 0; i < Q; i++){
        int o;
        cin >> o;
        if(o == 1){
            //update
            int x, c;
            cin >> x >> c; x--;
            //cout << x << " " << preorder[x] << " " << ranges[x].f << " " << ranges[x].s << endl;
            //update above
            //above.updateRange(1, 1, N, ranges[x].f, ranges[x].s, 1);
            //below.updateRange(1,1,N,preorder[x], preorder[x], stz[x]);
            set<int> removePls;
            bool inc = true;
            for(auto it : special[c]){
                
                if(preorder[it] >= ranges[x].f && preorder[it] <= ranges[x].s){
                    //cout << it << endl;
                    below.updateRange(1, 1, N, preorder[it], preorder[it], -1 * stz[it]);
                    above.updateRange(1,1,N, ranges[it].f, ranges[it].s, -1);
                    removePls.insert(it);
                }
                if(preorder[x] >= ranges[it].f && preorder[x] <= ranges[it].s){
                    inc = false;
                }
            }
            for(auto it : removePls){
                special[c].erase(it);
            }
            //cout << inc << endl;
            if(inc){
                above.updateRange(1,1,N,ranges[x].f, ranges[x].s, 1);
                below.updateRange(1,1,N,preorder[x],preorder[x], stz[x]);
                special[c].insert(x);
            }
        }
        else{
            int x;
            cin >> x; x--;
            cout << stz[x] * above.sum(1,1,N,preorder[x],preorder[x]) + below.sum(1,1,N,ranges[x].f+1, ranges[x].s) << endl;
        }

    }


}

