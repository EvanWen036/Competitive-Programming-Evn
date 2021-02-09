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
int N, M;
vector<int> obs[100005];
int indegree[100005];
vector<int> adj[100005];
vector<int> current;
bool ok(int u){
	current.clear();
	memset(indegree, 0, sizeof(indegree));
	for(int i = 0; i < u;i ++){
		for(int y = 0; y < obs[i].size()-1; y++){
			adj[obs[i][y]].pb(obs[i][y+1]);
			indegree[obs[i][y+1]]++;
		}
	}
	priority_queue<int, vector<int>, greater<int>> q;
	for(int i = 0; i < N; i++){
		if(indegree[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int fi = q.top(); q.pop();
		current.pb(fi+1);
		for(int u : adj[fi]){
			indegree[u]--;
			if(indegree[u] == 0){
				q.push(u);
			}
		}
	}
	for(int i = 0; i < N;i ++){
		adj[i].clear();
	}
	if(current.size() == N){
		return true;
	}
	return false;
}
int main(){
	freopen("milkorder.in", "r", stdin);
	freopen("milkorder.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		int x;
		cin >> x;
		for(int j = 1; j <= x; j++){
			int y;
			cin >> y;
			y--;
			obs[i].pb(y);
		}
	}
	int lo = 0;
	int hi = M-1;
	while(lo < hi){
		int mid = (lo+hi+1)/2;
		if(ok(mid)){
			//answer might be higher
			lo = mid;
		}
		else{
			//answer is def lower
			hi = mid-1;
		}
	}
	ok(lo);
	for(int i =0; i < current.size(); i++){
		cout << current[i];
		if(i == current.size()-1){
			cout << "\n";
		}
		else{
			cout << " ";
		}
	}

}
