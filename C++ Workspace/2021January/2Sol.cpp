#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define sz(a) a.size()
typedef long long ll;
typedef pair<ll, int> pii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
vector<int> adj[50005];
vector<int> of[55];
int mxType[55];
int mnType[55];
int mat[55][55];
int type[50005];
int dist[50005];
int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	memset(mnType, -1, sizeof(mnType));
	for(int i = 0; i < N;i ++){
		int y;
		cin >> y;
		type[i] = y-1;
		if(mnType[y-1] == -1){
			mnType[y-1] = i;
		}
		mnType[y-1] = min(mnType[y-1], i);
		mxType[y-1] = max(mxType[y-1], i);
		of[y-1].pb(i);
	}
	for(int i = 0; i < K;i ++){
		string s;	
		cin >> s;
		for(int j = 0;j < K;j ++){
			mat[i][j] = s[j] - '0';
		}
		sort(begin(of[i]), end(of[i]));
	}
	for(int i =0;i < N;i ++){
		for(int j = 0;j < K;j ++){
			if(j == type[i])continue;
			if(mat[type[i]][j] == 1){
				adj[i].pb(mxType[j]); 
				adj[i].pb(mnType[j]);
				vector<int>::iterator it = lower_bound(begin(of[j]), end(of[j]), i);
				if(it != of[j].end()){
					adj[i].pb(*it);
				}
			}
		}
		if(mat[type[i]][type[i]] == 0)continue;
		vector<int>::iterator it = lower_bound(begin(of[type[i]]), end(of[type[i]]), i);
		if(it != end(of[type[i]])){
			it++;
			if(it != end(of[type[i]])){
				adj[i].pb(*it);
			}
		}
		if(it != begin(of[type[i]])){
			it--;
			adj[i].pb(*it);
		}

	}
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, 0});
	for(int i = 1; i< N;i ++){
		dist[i] = LLONG_MAX;
	}
	while(!pq.empty()){
		pii cur = pq.top(); pq.pop();
		int u = cur.s;
		if(cur.f != dist[u])continue;
		//cout << u << " " << dist[u] << endl;
		for(int v : adj[u]){
			int weight = abs(u-v);
			if(dist[u] + weight < dist[v]){
				dist[v] = dist[u]+weight;
				pq.push({dist[v],v});
			}
		}
	}
	cout << (dist[N-1] == LLONG_MAX ? -1 : dist[N-1]) << '\n';

}
