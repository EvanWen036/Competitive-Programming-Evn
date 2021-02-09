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
vector<int> adj[200005];
int stz[200005];
void dfs(int u, int p){
	stz[u] = 1;
	for(int v : adj[u]){
		if(v != p){
			dfs(v,u);
			stz[u] += stz[v];
		}
	}
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for(int i = 1; i <= N-1; i++){
		int a;
		cin >> a;
		a--;
		adj[a].pb(i);
	}	
	dfs(0, -1);
	for(int i = 0; i < N; i++){
		cout << stz[i]-1 << ' ';
	}
	cout << '\n';

}
