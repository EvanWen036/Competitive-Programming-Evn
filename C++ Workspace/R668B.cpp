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
vector<int> adj[100005];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, a, b, da, db;
	cin >> N >> a >> b >> da >> db;
	for(int i = 0; i < N-1; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}



}
