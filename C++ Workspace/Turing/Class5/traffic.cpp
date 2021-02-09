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
bool vis[300005];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, A, B;
	cin >> N >> M >> A >> B;
	vector<pii> pts(N+1);
	vector<int> adj[N+1];
	vector<pii> left;
	for(int i = 0;i < N; i++){
		int x, y;
		cin >> x >> y;
		if(x == 0){
			left.pb({-1 * y, i});
		}
		pts[i] = {x,y};
	}
	for(int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b; a--; b--;
		int type; cin >> type;
		adj[a].pb(b);
		if(type == 2){
			adj[b].pb(a);
		}
	}
	sort(left.begin(), left.end());
	for(int i = 0; i < left.size(); i++){
		queue<int> q;
		memset(vis, false, sizeof(vis));
		vis[left[i].s] = true;
		q.push(left[i].s);
		int cnt = 0;
		while(!q.empty()){
			int top = q.front(); q.pop();
			if(pts[top].f == A)cnt++;
			vis[top] = true;
			for(int u : adj[top]){
				if(!vis[u]){
					q.push(u);
					vis[u] = true;
				}
			}
		}
		cout << cnt << '\n';
	}

}
