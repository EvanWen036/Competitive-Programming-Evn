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

ll minDist[50005][1005];
//m1 stores the two smallest distances from children
ll m1[1005][2];
ll ans[1005];
//which type each node is 
int t[50005];
int M;
vector<pair<int,long>> adj[50005];
void dfs(int node, int par){
	//cout << node << " " << par << endl;
	for(pii pi : adj[node]){
		int u = pi.f;
		if(u == par)continue;
		dfs(u, node);
	}
	//set m1 to inifinity
	for(int i = 1;i <= M; i++){
		m1[i][0] = 1e18;
		m1[i][1] = 1e18;
	}
	//m1 for every color stores the shortest distance from the current node to a node of the given color
	for(pii e : adj[node]){
		int u = e.f;
		for(int j = 1; j <= M; j++){
			
			if(minDist[u][j]+e.s < m1[j][0]){
				swap(m1[j][0], m1[j][1]);
				m1[j][0] = minDist[u][j]+e.s;
			}
			else if(minDist[u][j]+e.s < m1[j][1]){
				m1[j][1] = minDist[u][j]+e.s;
			}
		}
	}
	minDist[node][t[node]] = 0;
	for(int i = 1; i <= M; i++){
		//if current node is of desired color
		//can pair up the shortest of this color with the current node
		if(i == t[node] && m1[i][0] != 1000000){
			ans[t[node]] = min(ans[i],m1[i][0]);
		}
		//pair up two nodes from subtree
		if(m1[i][0] != 1000000 && m1[i][1] != 1000000){
			ans[i] = min(ans[i], m1[i][0] + m1[i][1]);
		}
		//update minDist
		if(m1[i][0] != 1000000){
			minDist[node][i] = min(minDist[node][i], m1[i][0]);
		}
	}
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//cout << "hi" << endl;
	int N;
	cin >> N >> M;
	for(int i = 0; i< N; i++){
		cin >> t[i];
		for(int j = 0; j<= M; j++){
			minDist[i][j] = 1e18;
			ans[j] = 1e18;
		}
	}
	for(int i = 0; i < N-1; i++){
		int a, b; long t;
		cin >> a >> b >> t;
		a--; b--;
		adj[a].pb({b,t});
		adj[b].pb({a,t});
	}
	dfs(0, -1);
	for(int i = 1; i <= M;i ++){
		cout << (ans[i] != 1e18 ? ans[i]:-1) << " ";
	}
	cout << endl;	
}
