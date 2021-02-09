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
bool dp[1005][3005];
bool dp2[1005][3005];
vector<int> adj[1005];
vector<int> adj2[1005];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, N2, M, M2;
	cin >> N >> N2 >> M >> M2;
	for(int i = 0; i < M; i++){
		int a, b;cin >> a >> b; a--; b--;
		adj[a].pb(b);
	}
	for(int i = 0; i < M2; i++){
		int a, b;
		cin >> a >> b; a--; b--;
		adj2[a].pb(b);
	}
	dp[0][0] = true;
	dp2[0][0] = true;
	for(int i = 0; i < N;i ++){
		for(int j = 0;j <= 3000;j ++){
			if(dp[i][j]){
				for(int u : adj[i]){
					dp[u][j+1] = true;
				}
			}
		}
	}
	for(int i = 0; i < N2;i ++){
		for(int j = 0;j <= 3000;j ++){
			if(dp2[i][j]){
				for(int u : adj2[i]){
					dp2[u][j+1] = true;
				}
			}
		}
	}
	vector<int> poss1;
	for(int i =0;i  <= 3000; i++){
		if(dp[N-1][i]){
			poss1.pb(i);
		}
	}
	vector<int> poss2;
	for(int j = 0; j <= 3000; j++){
		if(dp2[N2-1][j]){
			poss2.pb(j);
		}
	}
	set<int> possible;
	for(auto it : poss1){
		for(auto it2 : poss2){
			possible.insert(it + it2);
		}
	}
	int Q; cin >> Q;
	for(int i = 0; i < Q;i ++){
		int x; cin >> x;
		cout << (possible.count(x) ? "Yes":"No") << '\n';
	}
}
