#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define sz(a) a.size()
typedef long long ll;
typedef pair<ll, ll> pii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
const int mxN = 50005;
vector<int> adj[mxN];
int dist[mxN];
int type[mxN];
int mat[55][55];
int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	vector<int> of[51];
	for(int i = 0; i < N;i ++){
		cin >> type[i];
		type[i]--;
		of[type[i]].pb(i);
	}
	for(int i = 0; i < K; i++){
		string s;
		cin >> s;
		for(int j = 0;j < K;j ++){
			mat[i][j] = s[j]-'0';
		}
		//cout << '\n';
	}
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	for(int i = 1; i < N; i++){
		dist[i] = LLONG_MAX;
	}
	dist[0] = 0LL;
	pq.push({0LL,0});
	while(!pq.empty()){
		pii curr = pq.top(); pq.pop();
		int u = curr.s;	
		if(curr.f != dist[u])continue;
		//cout << u << " " << dist[u] << '\n';
		assert(dist[u] >= 0);
		for(int i = 0; i < K;i ++){
			if(mat[type[u]][i] == 1){
				for(int v : of[i]){
					if(dist[u] + abs(u-v) < dist[v]){
						dist[v] = dist[u]+abs(u-v);
						pq.push({dist[v],v});
					}
				}
			}
		}
	}
	
	cout << (dist[N-1] != LLONG_MAX ? dist[N-1]:-1) << '\n';
}
