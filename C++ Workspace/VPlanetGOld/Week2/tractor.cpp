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
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool vis[505][505];
int N;
int cnt = 0;
void dfs(int r, int c, int x){
	if(vis[r][c])return;
	vis[r][c]=true;
	cnt++;
	for(int i = 0; i < 4;i ++){
		int newR = r + dy[i];
		int newC = c + dx[i];
		if(newR < 0 || newR >= N || newC < 0 || newC >= N || vis[newR][newC])continue;
		if(abs(mat[newR][newC] - mat[r][c]) <= x){
			dfs(newR,newC, x);
		}
	}
}
bool ok(int x){
	queue<pii> q;
	q.push({0,0});
	//vis[0][0] = true;
	memset(vis, false,sizeof(vis));
	for(int i = 0; i < N;i ++){
		for(int j = 0;j < N;j ++){
			if(!vis[i][j]){
				cnt = 0;
				dfs(i,j, x);
				if(cnt >= (N*N+1)/2)return true;
			}
		}
	}
	return false;
}
int main(){
	freopen("tractor.in", "r", stdin);
	freopen("tractor.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;	
	for(int i = 0; i < N;i ++){
		for(int j = 0;j < N;j ++){
			cin >> mat[i][j];
		}
	}
	int lo = 0;
	int hi = 1e9;
	while(lo < hi){
		int mid = (lo+hi)/2;
		if(ok(mid)){
			//we can try lower
			hi = mid;
		}
		else{
			lo = mid+1;
		}
	}
	cout << lo << '\n';

}
