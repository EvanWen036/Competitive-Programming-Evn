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
vector<pair<ll, pair<ll,ll>>> circles;
vector<pair<ll, pii>> edges;
vector<pair<ll, pii>> visitors;
ll dist(int a, int b){
	return 1LL * ceil(sqrt((long double)((circles[a].s.f - circles[b].s.f)* (long double)((circles[a].s.f - circles[b].s.f)) + (long double)(circles[a].s.s - circles[b].s.s)*(long double)(circles[a].s.s - circles[b].s.s))));
}
int dsu[2105];
int sz[2105];
int find(int u){
	if(dsu[u] == u)return u;
	return dsu[u] = find(dsu[u]);
}
void merge(int u, int v){
	u = find(u);
	v = find(v);
	if(u == v)return;
	if(sz[v] > sz[u])swap(u,v);
	dsu[v] = u;
	sz[u] += sz[v];
}
bool same(int u, int v){
	return find(u) == find(v);
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m; ll w, h;
	cin >> n >> m >> w >> h;
	vector<string> answer(m);
	for(int i = 0; i < n; i++){
		ll a, b, c;
		cin >> a >> b >> c;
		circles.pb({c,{a,b}});
	}
	for(int i = 0; i < m; i++){
		ll r; int e; cin >> r >> e;
		visitors.pb({r,{e,i}});
	}
	//n is top, n+1 is right, n+2 is bottom, n+3 is left
	for(int i = 0; i < n;i ++){
		for(int j=i+1; j < n; j++){
			//dist from i to j
			ll di = dist(i, j);
			di -= circles[i].f;
			di -= circles[j].f;
			//cout << i << " " << j << " " << di << '\n';
			edges.pb({di, {i,j}});
		}
		edges.pb({h-circles[i].s.s-circles[i].f,{i, n}});
		edges.pb({w-circles[i].s.f - circles[i].f, {i,n+1}});
		edges.pb({circles[i].s.s - circles[i].f, {i, n+2}});
		edges.pb({circles[i].s.f - circles[i].f, {i, n+3}});
	}
	for(int i = 0;i <= n+3; i++){
		dsu[i] = i;
		sz[i] = 1;
	}
	sort(edges.begin(), edges.end());
	sort(visitors.begin(), visitors.end());
	int j = 0;
	for(auto it : visitors){
		while(j < edges.size() && edges[j].f <= 2*it.f){
			merge(edges[j].s.f, edges[j].s.s);
			j++;
		}
		cout << j << '\n';
		int ind = it.s.s;
		if(it.s.f == 1){
			string ans = "";
			ans += "1";
			if(!same(n, n+2) && !same(n+1,n+2) && !same(n+3, n+2)){
				ans += "2";
			}
			if(!same(n, n+2) && !same(n+1, n+3) && !same(n+3, n+2) && !same(n+2, n+1)){
				ans += "3";
			}
			if(!same(n+1, n+3) && !same(n, n+3) && !same(n+2, n+3)){
				ans += "4";
			}
			answer[ind] = ans;
		}
		if(it.s.f == 2){
			string ans = "";
			if(!same(n,n+2) && !same(n+3, n+2) && !same(n+1, n+2)){
				ans += "1";
			}
			ans += "2";
			if(!same(n+3, n+1) && !same(n,n+1) && !same(n+2, n+1)){
				ans += "3";
			}
			if(!same(n, n+2) && !same(n+1, n+3) && !same(n+1, n+2) && !same(n, n+3)){
				ans += "4";
			}
			answer[ind] = ans;
		}
		if(it.s.f == 3){
			string ans = "";
			if(!same(n,n+2) && !same(n+1, n+3) && !same(n, n+1) && !same(n+2, n+3)){
				ans += "1";
			}
			if(!same(n+1, n+3) && !same(n, n+1) && !same(n+1, n+2)){
				ans += "2";
			}
			ans += "3";
			if(!same(n, n+2) && !same(n,n +1) && !same(n, n+3)){
				ans += "4";
			} 
			answer[ind] = ans;
		}
		if(it.s.f == 4){
			string ans = "";
			if(!same(n+1, n+3) && !same(n, n+3) && !same(n+2,n+3)){
				ans += "1";
			}
			if(!same(n,n+2) && !same(n+3, n+1) && !same(n,n+3) && !same(n+1,n+2)){
				ans += "2";
			}
			if(!same(n,n+2) && !same(n,n+3) && !same(n,n+1)){
				ans += "3";
			}
			ans += "4";
			answer[ind] = ans;
		}
	}
	for(auto it : answer){
		cout << it << '\n';
	}
}
