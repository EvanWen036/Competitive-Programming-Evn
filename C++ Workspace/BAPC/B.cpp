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
int n, m;
int tr, tc;
int mat[505][505];
bool vis[505][505];
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
int ans[505][505];
set<int> fa;
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> tr >> tc;
	for(int i = 0; i < n;i ++){
		for(int j = 0;j < m;j ++){
			cin >> mat[i][j];
		}
	}
	tr--; tc--;
	int v = mat[tr][tc];
		for(int p = 2; p * p <= v; p++){
			if(v%p == 0){
				fa.insert(p);
			}
			while(v%p == 0){
				v /= p;
			}
		}
		if(v != 1){
			fa.insert(v);
		}
	
	for(auto p : fa){
		//cout << it << '\n';
		memset(vis, false, sizeof(vis));
		queue<pii> q;
		vis[tr][tc] = true;
		if(mat[tr][tc]%p == 0){
			q.push({tr,tc});
		}
		while(!q.empty()){
			auto it = q.front(); q.pop();
			ans[it.f][it.s]++;
			for(int i = 0; i < 4; i++){
				int nr = it.f + dr[i];
				int nc = it.s + dc[i];

				if(nr < 0 || nr >= n || nc < 0 || nc >= m)continue;
				if(mat[nr][nc] < mat[it.f][it.s] && mat[nr][nc] % p == 0 && !vis[nr][nc]){
					q.push({nr,nc});
					vis[nr][nc] = true;
				}
			}
		}
	}
	for(int i = 0; i < n;i ++){
		for(int j = 0;j < m;j ++){
			cout << ans[i][j] << " ";
		}
		cout << '\n';
	}

}
