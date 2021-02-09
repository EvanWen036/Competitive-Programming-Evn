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
int N, M, X, Y;
ll mod = 1e9+7;
vector<pii> adj[1505];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >>  X >> Y;
	for(int i = 0; i < M; i++){
		int a, b, x;
		cin >> a >> b >> x;
		a--; b--;
		adj[a].pb({b,x});
		adj[b].pb({a,x});
	}
}
