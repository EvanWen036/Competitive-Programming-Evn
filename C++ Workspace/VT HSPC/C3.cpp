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
int mat[105][105];
bool vis[105][105];
int N;
bool ok(ll te){
	queue<pii> q;
	if(mat[0][0] > te)return false;
	q.push({0,0});
	memset(vis, false,sizeof(vis));
	while(!q.empty()){
		pii fir = q.front(); q.pop();
		if(vis[fir.f][fir.s])continue;
		vis[fir.f][fir.s] = true;
		if(fir.f != N-1){
			if(mat[fir.f+1][fir.s] <= te){
				q.push({fir.f+1,fir.s});
			}
		}
		if(fir.s != N-1){
			if(mat[fir.f][fir.s+1] <= te){
				q.push({fir.f, fir.s+1});
			}
		}
		if(fir.s != 0){
			if(mat[fir.f][fir.s-1] <= te){
				q.push({fir.f, fir.s-1});
			}
		}
		if(fir.f != 0){
			if(mat[fir.f-1][fir.s] <= te){
				q.push({fir.f-1, fir.s});
			}
		}
	}
	return vis[N-1][N-1];
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0;j < N; j++){
			cin >> mat[i][j];
		}
	}
	int lo = 0;
	int hi = 1e9;
	ll ans = 1e9;
	while(lo < hi){
		ll mid = (lo+hi)/2; 
		//cout << lo << " " << hi << " " << mid << '\n';
		if(ok(mid)){
			ans = min(ans, mid);
			hi = mid;
		}
		else{
			lo = mid+1;
		}
	}
	assert(lo == ans);
	cout << ans << '\n';


}
