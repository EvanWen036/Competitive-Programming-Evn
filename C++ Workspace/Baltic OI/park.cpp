#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define y second
#define x first
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll, ll> pii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
long double dist(pii p1, pii p2){
	return sqrt(((p2.y-p1.y)*(p2.y-p1.y)) + ((p2.x-p1.x)*(p2.x-p1.x)));
}
int dsu[2100];
int sz[2100];
int find(int u){
	if(dsu[u] == u){
		return u;
	}
	return dsu[u] = find(dsu[u]);
}
void merge(int a, int b){
	a = find(a);
	b = find(b);
	if(a==b)return;
	if(sz[b] > sz[a])swap(a,b);
	//a has bigger size
	dsu[b] = a;
	sz[a] += sz[b];
}
 
bool same(int u, int v){
	return find(u) == find(v);
}
bool canGet[5][5];
signed main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, w, h;
	cin >> n >> m >> w >> h;	
	vector<pair<pii,int>> trees;
	for(int i = 0; i < n; i++){
		int a, b, c;
		cin >> a >> b >> c;
		trees.pb({{a,b},c});
	}
	//borders are nodes n(top), n+1(right), n+2(down), n+3(left)
	vector<pair<pii, int>> visitors;
	for(int j = 0;j < m; j++){
		int a, b;
		cin >> a >> b;
		visitors.pb({{a,b},j});
	}
	vector<pair<long double, pii>> edges;
	//calculate the edges
	for(int i = 0;i < n; i++){
		//cout << trees[i].f.f << " " << trees[i].f.s << " " << trees[i].s << "\n";
		for(int j = i+1;j < n; j++){
			//edge between
			long double distance = dist(trees[i].f, trees[j].f);
			//cout << i << " " << j << " " << distance << "\n";
			distance -= trees[i].s;
			distance -= trees[j].s;
			edges.pb({distance,{i,j}});
		}
		//distance to left
		edges.pb({sqrt(trees[i].f.f * trees[i].f.f) - trees[i].s, {i, n+3}});
		//distance to top
		edges.pb({sqrt((h-trees[i].f.s)*(h-trees[i].f.s)) - trees[i].s, {i,n}});
		//distance to right
		edges.pb({sqrt((w-trees[i].f.f) * (w-trees[i].f.f)) - trees[i].s, {i, n+1}});
		//distance to bottom
		edges.pb({sqrt(trees[i].f.s * trees[i].f.s) - trees[i].s, {i,n+2}});
	}
	sort(edges.begin(),edges.end());
	sort(visitors.begin(), visitors.end());
	vector<string> answer(100005);
	for(int i = 0; i <= n+3; i++){
		dsu[i] = i;
		sz[i] = 1;
	}
	int j = 0;
	for(int i = 0; i < m; i++){
		int ind = visitors[i].s;
		while(j < edges.size() && edges[j].f < 2*visitors[i].f.f){
			//cout << edges[j].s.f << " " << edges[j].s.s << endl;
			assert(edges[j].f >= 0);
			merge(edges[j].s.f, edges[j].s.s);
			j++;
		}
		//casework
		if(visitors[i].f.s == 1){
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
		if(visitors[i].f.s == 2){
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
		if(visitors[i].f.s == 3){
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
		if(visitors[i].f.s == 4){
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
	for(int i = 0; i < m ;i++){
		cout << answer[i] << "\n";
	}
 
}