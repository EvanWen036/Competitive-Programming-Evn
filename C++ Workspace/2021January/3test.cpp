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
int cmpSize[100005];
int cmp[100005];
int r = 0;
bool vis[100005];
vector<int> adj[100005];
void dfs(int u){
	cmp[u] = r;
	cmpSize[r]++;
	for(int v : adj[u]){
		if(cmp[v] == 0){
			dfs(v);
		}
	}
}
void print(vector<int> A){
	for(int u : A){
		cout << u << " ";
	}
	cout << '\n';
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	ll M;
	cin >> N >> K >> M;
	set<int> positions[N+1];
	vector<int> A(N+1);
	for(int i = 1; i <= N;i ++){
		A[i-1] = i;
		positions[i].insert(i-1);
	}	
	vector<pii> swaps(K);
	for(int i  =0 ;i < K; i++){
		int a, b;
		cin >> a >> b; a--; b--;
		swaps[i] = {a,b};
	}
	if(M == 1e18){
		//just print all cycle sizes
		for(int i = 0; i < K;i ++){
			//adj[swaps[i].f].pb(swaps[i].s);
			adj[swaps[i].s].pb(swaps[i].f);
		}
		for(int i = 0; i < N;i ++){
			if(cmp[i] == 0){
				r++;
				dfs(i);
			}
		}
		for(int i = 0; i < N;i ++){
			assert(cmpSize[cmp[i]] > 0);
			cout << cmpSize[cmp[i]] << '\n';
		}
		//return 0;
	}
	//print(A);
	//assert(M != 1e18);
	for(int i = 0; i < 1000;i ++){
		positions[A[swaps[i%K].f]].insert(swaps[i%K].s);
		positions[A[swaps[i%K].s]].insert(swaps[i%K].f);
		swap(A[swaps[i%K].f], A[swaps[i%K].s]);
		//print(A);
	}
	for(int i = 1; i <= N;i ++){
		cout << positions[i].size() << '\n';
	}

}
