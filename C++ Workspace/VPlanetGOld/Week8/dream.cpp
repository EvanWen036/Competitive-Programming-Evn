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
int mat[1005][1005];
int dist[1005][1005][2];
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
priority_queue<array<int, 4>, vector<array<int,4>>, greater<array<int,4>>> pq;
int ans = 1e9;
int main(){
	freopen("dream.in", "r", stdin);
	freopen("dream.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	for(int i =0; i < N;i ++){
		for(int j = 0;j < M;j ++){
			cin >> mat[i][j];
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0;j < M; j++){
			dist[i][j][0] = 1e9;
			dist[i][j][1] = 1e9;
		}
	}
	dist[0][0][0] = 0;
	pq.push({0,0,0,0});
	while(!pq.empty()){
		array<int, 4> c = pq.top(); pq.pop();
		if(c[0] != dist[c[1]][c[2]][c[3]])continue;
		//cout << c[0] << " " << c[1] << " " << c[2] << " " << c[3] << '\n';
		assert(mat[c[1]][c[2]] != 0);
		if(c[1] == N-1 && c[2] == M-1){
			ans = min(ans, c[0]);
		}
		int cs = c[3];
		for(int j = 0;j < 4;j ++){
			int nr = dr[j] + c[1];
			int nc = dc[j] + c[2];
			if(nr < 0 || nr >= N || nc < 0 || nc >= M)continue;
			if(mat[nr][nc] == 0)continue;
			if(mat[nr][nc] == 3 && c[3] != 1)continue;
			if((mat[nr][nc] == 1 || mat[nr][nc] == 3) && dist[nr][nc][cs] > c[0]+1){
				dist[nr][nc][cs] = c[0]+1;
				pq.push({c[0]+1, nr, nc, cs});
			}
			if(mat[nr][nc] == 2 && dist[nr][nc][1] > c[0]+1){
				dist[nr][nc][1] = c[0]+1;
				pq.push({c[0]+1, nr, nc, 1});
			}
			if(mat[nr][nc] == 4){
				int step = 1;
				//cout << "at: " << nr << " " << nc << '\n';
				while(nr+dr[j] >= 0 && nr+dr[j] < N && nc+dc[j] >= 0 && nc+dc[j] < M && mat[nr+dr[j]][nc+dc[j]] != 0 && mat[nr+dr[j]][nc+dc[j]] != 3){
					nr += dr[j];
					nc += dc[j];
					step++;
					if(mat[nr][nc] != 4){
						break;
					}
				}
				//cout << "slid to: " << nr << " " << nc << '\n';
				int s = 0;
				//if(mat[nr][nc] == 2)s=1;
				if(dist[nr][nc][0] > c[0]+step){
					dist[nr][nc][0] = c[0]+step;
					pq.push({c[0]+step,nr,nc,s});
				}
			}
		}
	}
	cout << (ans == 1e9 ? -1:ans) << '\n';
}
