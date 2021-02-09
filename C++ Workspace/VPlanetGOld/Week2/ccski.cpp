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
int mat[505][505];
int starting[505][505];
int N, M;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool ok(int d){
	queue<pii> q;
	bool vis[M][N];
	memset(vis, false,sizeof(vis));
	for(int i = 0; i < M;i ++){
		for(int j = 0;j < N;j ++){
			if(starting[i][j] && q.empty()){
				q.push({i,j});
			}
		}
	}

	while(!q.empty()){
		pii cur = q.front(); q.pop();
		vis[cur.f][cur.s] = true;
		for(int i = 0; i < 4; i++){
			int newR = dy[i] + cur.f;
			int newC = dx[i] + cur.s;
			if(newR < 0 || newR >= M || newC < 0 || newC >= N || vis[newR][newC])continue;
			if(abs(mat[newR][newC]-mat[cur.f][cur.s]) <= d){
				vis[newR][newC] = true;
				q.push({newR,newC});
			}
		}
	}
	for(int i = 0; i < M;i ++){
		for(int j =0;j < N;j ++){
			if(starting[i][j] && !vis[i][j])return false;
		}
	}
	return true;
}
int main(){
	freopen("ccski.in", "r", stdin);
	freopen("ccski.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> M >> N;
	for(int i = 0; i < M;i ++){
		for(int j = 0;j < N;j ++){
			cin >> mat[i][j];
		}
	}
	for(int i = 0; i < M;i ++){
		for(int j = 0;j < N;j ++){
			cin >> starting[i][j];
		}
	}
	int lo = 0;
	int hi = 1e9;
	while(lo < hi){
		int mid = (lo+hi)/2;
		if(ok(mid)){
			hi = mid;
		}
		else{
			lo = mid+1;
		}
	}
	cout << lo << '\n';

}
