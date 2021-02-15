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
int N, C;
pii points[2005];
int mst[2005];
bool vis[2005];
int dist(pii a, pii b){
	return abs(a.f - b.f) * abs(a.f - b.f) + abs(a.s-b.s) * abs(a.s - b.s);
}
int main(){
	freopen("irrigation.in", "r", stdin);
	freopen("irrigation.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> C;
	for(int i = 0; i < N;i ++){
		cin >> points[i].f >> points[i].s;
		mst[i] = 2e9;
	}	
	mst[0] = 0;
	int ans = 0;
	for(int i = 0; i < N;i ++){
		int mi = -1;
		for(int j = 0;j < N;j ++){
			if(vis[j])continue;
			if(mi == -1 || (mst[j] < mst[mi])){
				mi = j;
			}
		}
		vis[mi] = true;
		ans += mst[mi];
		for(int j = 0;j < N;j ++){
			if(j == mi)continue;
			int wt = dist(points[mi],points[j]);
			//cout << mi << " " << j << " " << wt << '\n';
			if(wt < C)continue;
			mst[j] = min(mst[j], wt);
		}
	}
	for(int i = 0; i < N;i ++){
		if(mst[i] == 2e9){
			cout << -1 << '\n';
			return 0;
		}
	}
	cout << ans << '\n';

}
