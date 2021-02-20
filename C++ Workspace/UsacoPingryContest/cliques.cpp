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
#define int long long
int sz[100005];
int dsu[100005];
int T[100005];
int mod = 1000000007;
ll ans = 1;
int N;
vector<pii> edges[100005];
int find(int u){
	if(dsu[u] == u)return u;
	return dsu[u] = find(dsu[u]);
}
void merge(int u, int v){
	u = find(u);
	v = find(v);
	if(sz[u] < sz[v])swap(u,v);
	dsu[v] = u;
	sz[u] += sz[v];
	T[u] += T[v];
}
ll binpow(int bs, int exp){
	if(exp == 0)return 1;
	if(exp == 1)return bs;
	if(exp % 2){
		return bs * binpow(bs,exp-1) % mod;
	}
	else{
		ll temp = binpow(bs,exp/2) % mod;
		return temp * temp % mod;
	}
}
signed main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int M;
	cin >> N >> M;
	for(int i = 0;i < M;i ++){
		int a, b, t;
		cin >> a >> b >> t;
		a--; b--;
		edges[t].pb({a,b});
	}
	for(int i = 0; i < N;i ++){
		dsu[i] = i;
		sz[i] = 1;
		T[i] = 1;
	}
	for(int i = 1; i <= N;i ++){
		for(pii e : edges[i]){
			if(find(e.f) != find(e.s)){
				int c1 = T[find(e.f)];
				int c2 = T[find(e.s)];
				merge(e.f, e.s);
				T[find(e.f)] += i;
				//recalculate ans 
				//ans /= c1; //fermat's little theorem
				ans = (1LL * ans * binpow(c1, mod-2)) % mod;
				//ans /= c2;
				ans = (1LL * ans * binpow(c2, mod-2)) % mod;
				ans *= 1LL * T[find(e.f)];
				ans %= mod;
			}
		}
		assert(ans >= 0);
		cout << ans << '\n';
	}
}
