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
int val[105][105];
bool vis[105*105];
int dist[105*105];
int mat[105][105];
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
		}
	}	
	dist[1] = mat[0][0];
	queue<pii> q;
	q.push({0,0});
	while(!q.empty()){
		pii top = q.front(); q.pop();
		vis[val[top.f][top.s]] = true;
		if(top.f != N-1){
			int hoursWait = mat[top.f+1][top.s] - dist[val[top.f][top.s]];
			if(!vis[val[top.f+1][top.s]]){
				dist[val[top.f+1][top.s]] = max(0,hoursWait) + dist[val[top.f][top.s]];
				q.push({top.f+1, top.s});				
			}
		}
		if(top.s != N-1){
			int hoursWait = mat[top.f][top.s+1] - dist[val[top.f][top.s]];
			if(!vis[val[top.f][top.s+1]]){
				dist[val[top.f][top.s+1]] = max(0,hoursWait) + dist[val[top.f][top.s]];
				q.push({top.f, top.s+1});				
			}
		}
	}
	cout << dist[val[N-1][N-1]] << '\n';


}
