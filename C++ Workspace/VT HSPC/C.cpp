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
int mat[105][105];
vector<pii> adj[105*105];
ll dist[105*105];
int val[105][105];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int cnt = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> mat[i][j];
			val[i][j]=++cnt;
			dist[val[i][j]] = 1e18;
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0;j  < N; j++){
			if(i != N-1){
				adj[val[i][j]].pb({val[i+1][j], max(0, mat[i+1][j] - mat[i][j])});
			}
			if(j != N-1){
				adj[val[i][j]].pb({val[i][j+1], max(0, mat[i][j+1]-mat[i][j])});
			}
		}
	}
	dist[1] = mat[0][0];
	priority_queue<pair<long, int>> pq;
	pq.push({dist[1], 1});
	while(!pq.empty()){
		pair<long,int> fir = pq.top(); pq.pop();
		if(fir.f != dist[fir.s])continue;
		cout << fir.f << " " << fir.s << '\n';
		for(auto it : adj[fir.s]){
			//cout << it.f << " " << it.s << '\n';
			if(fir.f + it.s < dist[it.f]){
				dist[it.f] = fir.f + it.s;
				pq.push({dist[it.f], it.f});
			}
		}
	}
	cout << dist[val[N-1][N-1]] << '\n';
}	
