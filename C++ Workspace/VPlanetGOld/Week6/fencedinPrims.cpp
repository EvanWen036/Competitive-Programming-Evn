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
ll horz[2005];
ll vert[2005];
pii pos[2005*2005];
bool vis[2005*2005];
ll dist[2005*2005];
int main(){

	ifstream cin("fencedin.in");
	ofstream cout("fencedin.out");
	int A, B, n, m;
	cin >> A >> B >> n >> m;
	vert[0] = 0;
	for(int i = 1; i <= n; i ++){
		int x;
		cin >> x;
		vert[i] = x;
	}
	vert[n+1] = A;
	horz[0] = 0;
	for(int i = 1; i <= m; i++){
		int x;
		cin >> x;
		horz[i] = x;
	}
	horz[m+1] = B;
	int cnt = 0;
	for(int i = 0; i <= n; i++){
		for(int j= 0;j <= m; j++){
			pos[cnt] = {i,j};
			dist[cnt] = 1e15;
			cnt++;
		}
	}
	sort(horz, horz+m+2);
	sort(vert, vert+n+2);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dist[0] = 0;
	pq.push({0,0});
	ll ans=0;
	while(!pq.empty()){
		if(vis[pq.top().s]){
			pq.pop();
			continue;
		}
		ans += pq.top().f; 
		int curr = pq.top().s; pq.pop();
		//cout << curr << " " << pos[curr].f << " " << pos[curr].s << '\n';
		vis[curr] = true;
		//try left
		if(pos[curr].s != 0){
			if(!vis[curr-1]){
				int wt = horz[pos[curr].f+1]-horz[pos[curr].f];
				if(wt < dist[curr-1]){
					pq.push({dist[curr-1] = wt, curr-1});
				}
			}
		}
		//try down
		if(pos[curr].f != 0){
			if(!vis[curr - n - 1]){
				int wt = vert[pos[curr].s+1] - vert[pos[curr].s];
				if(wt < dist[curr-n-1]){
					pq.push({dist[curr-n-1] = wt, curr-n-1});
				}
			}
		}
		//try up
		if(pos[curr].f != m){
			if(!vis[curr+n+1]){
				int wt = vert[pos[curr].s+1] - vert[pos[curr].s];
				if(wt < dist[curr+n+1]){
					pq.push({dist[curr+n+1]=wt, curr+n+1});
				}
			}
		}
		//try right
		if(pos[curr].s != n){
			if(!vis[curr+1]){
				int wt = horz[pos[curr].f+1] - horz[pos[curr].f];
				if(wt < dist[curr+1]){
					pq.push({dist[curr+1]=wt, curr+1});
				}
			}
		}
	}
	cout << ans << '\n';
}
