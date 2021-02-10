#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define sz(a) a.size()
typedef long long ll;
typedef pair<int, int> pii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int R, C, P;
vector<pair<int,pii>> edges;
vector<pii> connec;
int dsu[100005];
int sz[100005];
int find(int u){
	if(dsu[u] == u)return u;
	return dsu[u] = find(dsu[u]);
}
void merge(int u, int v){
	u = find(u);
	v = find(v);
	if(u == v)return;
	if(sz[u] < sz[v])swap(u,v);
	//u is bigger
	dsu[v] = u;
	sz[u] += sz[v];
}
bool ok(int x){
	for(int i = 1; i <= R;i ++){
		dsu[i] = i;
		sz[i] = 1;
	}
	for(int i = 0; i < edges.size();i ++){
		if(edges[i].f <= x){
			merge(edges[i].s.f, edges[i].s.s);
		}
	}
	for(int i = 0; i < P; i++){
		if(find(connec[i].f) != find(connec[i].s))return false;
	}
	//cout << x << '\n';
	return true;
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> R >> C;
	for(int i = 0 ;i < C;i ++){
		int a, b, c;
		cin >> a >> b >> c;
		edges.pb({c,{a,b}});	
	}
	sort(edges.begin(), edges.end());
	cin >> P;
	for(int i = 0; i < P; i++){
		int a, b;
		cin >> a >> b;
		connec.pb({a,b});
	}
	int lo = 0;
	int hi = 1e6;
	if(!ok(1e6)){
		cout << "MISSION IMPOSSIBLE\n";
		return 0;
	}
	while(lo < hi){
		int mid = (lo+hi)/2;
		if(ok(mid)){
			//ans potentially lower
			hi = mid;
		}
		else{
			lo = mid+1;
		}
	}
	cout << lo << '\n';


}
