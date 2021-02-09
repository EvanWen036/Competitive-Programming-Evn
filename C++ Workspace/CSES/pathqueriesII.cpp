#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int n, q;
vector<int> adj[100005];
vector<int> euler;
vector<int> in(100005);
vector<int> out(100005);
int depth[100005];
int anc[100005][32];
int org[100005];
int timer=0;
void dfs(int u,int p){
	//cout<<u<<" "<<p<<'\n';
	euler.pb(u);
	for(int v:adj[u]){
		if(v != p){
			anc[v][0]=u;
			depth[v]=depth[u]+1;
			dfs(v,u);
			euler.pb(u);
		}
	}
	
}
void computeTable(){
	for(int D=1;D<=30;D++){
		for(int j=0;j<n;j++){
			int mid=anc[j][D-1];
			if(mid!=-1){
				anc[j][D]=anc[mid][D-1];
			}
		}
	}
}
int walk(int i, int k){
    for(int d =0; d <= 24 && i != -1; d++){
        if(((1<<d) & k)){
            i = anc[i][d];
        }
    }
    return i;
}
int lca(int i, int j){
    if(depth[i] > depth[j]){
        i = walk(i, depth[i] - depth[j]);
    }
    if(depth[j] > depth[i]){
        j = walk(j, depth[j] -depth[i]);
    }
    //cout << i << " " << j << endl;
    if(i == j){
        return i;
    }
    for(int d= 24; d >= 0; d--){
        if(anc[i][d] != anc[j][d]){
            i = anc[i][d];
            j = anc[j][d];
        }
    }
    return anc[i][0];
}
int segTree[4*2*2*100005];
void build(int v, int l, int r){
	if(l == r){
		segTree[v] = org[euler[l]];
		return;
	}
	int tm =(l+r)/2;
	build(v*2, l,tm);
	build(2*v+1, tm+1, r);
	segTree[v]=max(segTree[2*v],segTree[2*v+1]);
}
void update(int v, int l, int r, int pt, int val){
	if(l > pt || r < pt)return;
	if(l==r&&r==pt){
		segTree[v]=val;
		return;
	}
	int tm=(l+r)/2;
	update(2*v,l,tm,pt,val);
	update(2*v+1,tm+1,r,pt,val);
	segTree[v]=max(segTree[2*v],segTree[2*v+1]);
}
int query(int v, int lr, int rr, int l, int r){
	if(lr > r || rr < l)return 1e9;
	if(lr >= l && rr <= r){
		return segTree[v];
	}
	int tm =(lr+rr)/2;
	return max(query(2*v,lr,tm,l,r),query(2*v+1,tm+1,rr,l,r));
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> q;
	for(int i =0;i<n;i++)cin>>org[i];
	for(int i =0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	memset(anc,-1,sizeof(anc));
	depth[0]=0;
	dfs(0,-1);
	/**
	for(int i=0;i<euler.size();i++){
		cout<<euler[i]<<"\n";
	}**/
	computeTable();
	build(1,0,euler.size()-1);
	for(int i = 0; i < q;i++){
		int cmd;
		cin >> cmd;
		if(cmd == 1){
			int a, b;
			cin >> a >> b;
			a--;
			update(1,0,euler.size()-1,in[a],b);
			update(1,0,euler.size()-1,out[a],b);
		}
		else{
			int a,b;
			cin>>a>>b;
			a--;b--;
			int anc=lca(a,b);
			cout<<in[anc]<<" "<<in[a]<<" "<<in[b]<<'\n';
			int p1=query(1,0,euler.size()-1,in[anc],in[a]);
			int p2=query(1,0,euler.size()-1,in[anc],in[b]);
			cout <<max(p1,p2)<<" ";
		}
	}
}
