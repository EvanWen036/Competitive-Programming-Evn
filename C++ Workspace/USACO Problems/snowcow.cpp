#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
vector<int> adj[100005];
int preorder[100005];
pii ranges[100005];
int r = 0;
pair<long long, long long> t[800005];
long long lazy[800005];

void build(int v, int l, int r){
	if(l == r){
		t[v].first = 0;
		//t[v].second = 0;
	}
	else{
		int mid = (l+r)/2;
		build(v*2, l, mid);
		build(v*2+1, mid + 1, r);
		t[v].first = t[v*2].first + t[v*2+1].first;
		//t[v].second = min(t[v*2].second, t[v*2+1].second);
	}
}
long long sum(int v,int lr, int rr, int l, int r){
	if(r < lr || l > rr || lr > rr)return 0;
	if(lazy[v] != 0){
		t[v].first += (rr -lr+1) * lazy[v];
		//t[v].second += lazy[v];
		if (lr != rr) {
            // update lazy[] for children nodes
            lazy[2 * v] += lazy[v];
            lazy[2 * v + 1] += lazy[v];
        }
		lazy[v] = 0;
	}
	if(l <= lr && r >= rr){
		return t[v].first;
	}
	
	else{
		int tm = (lr + rr)/2;
		return sum(v*2, lr, tm, l, r) + sum(v*2+1, tm+1, rr, l, r);
	}
}
void updateRange(int v, int lr, int rr, int l, int r, long long val){
	//cout << v << " " << lr << " " << rr << " " << l << " " << r << " " << val << "\n";
	if(lazy[v] != 0){
		t[v].first += (rr -lr+1) * lazy[v];
		//t[v].second += lazy[v];
		if (lr != rr) {                                     // update lazy[] for children nodes
            lazy[2 * v] += lazy[v];
            lazy[2 * v + 1] += lazy[v];
        }
		lazy[v] = 0;
	}
	if(lr > rr || l > rr || r < lr )return;
	if(l <= lr && r >= rr){
		t[v].first += (rr - lr+1) * val;
		t[v].second += val;
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
	t[v].first = t[2*v].first + t[2*v+1].first;
	//t[v].second = min(t[2*v].second, t[2*v+1].second);
}

void dfs(int u, int p){
    preorder[u] = ++r;
    ranges[u].f = preorder[u];
    for(int v : adj[u]){
        if(v != p){
            dfs(v, u);
        }
                
    }
    ranges[u].s = r;    
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, Q;
    cin >> N >> Q;
    for(int i = 0; i < N-1; i++){
        int a, b;
        cin >> a >> b; a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(0, -1);
    /**
    for(int i = 0; i < N;i ++){
        cout << preorder[i] << " " << ranges[i].f << " " << ranges[i].s << endl;
    }
    **/

    build(1, 1, N);
    for(int i = 0; i < Q;i ++){
        int o;
        cin >> o;
        if(o == 1){
            int a, b;
            cin >> a >> b; a--;
            updateRange(1, 1, N, ranges[a].f, ranges[a].s, b);
        }
        else{
            int x;
            cin >> x;
            x--;
            cout << sum(1, 1, N, ranges[x].f, ranges[x].s) << endl;
        }
    }

}

