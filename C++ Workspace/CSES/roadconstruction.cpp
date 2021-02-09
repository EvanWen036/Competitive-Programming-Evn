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
int dsu[100005];
int sz[100005];
int cmp;
int find(int u){
	if(dsu[u] == u){
		return u;
	}
	return dsu[u] = find(dsu[u]);
}
void merge(int u, int v){
	u = find(u);
	v = find(v);
	if(u == v)return;
	if(sz[v] > sz[u])swap(u,v);
	cmp--;
	dsu[v] = u;
	sz[u] += sz[v];
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	cmp = n;
	for(int i = 0; i <n ;i++){
		dsu[i] = i;
		sz[i] = 1;
	}
	int mx = 1;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		merge(a,b);
		mx = max(mx, sz[find(a)]);
		cout << cmp << " " << mx << '\n';
	}



}
