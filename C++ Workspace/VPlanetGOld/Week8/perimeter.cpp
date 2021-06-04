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
int ans = 0;
map<pii, bool> bales;
map<pii, bool> vis;
int sx, sy;
int mx, my;
void go(int cx, int cy){
	if(bales[{cx,cy}]){
		ans++;
		return;
	}
	if(vis[{cx,cy}])return;
	//cout << cx << " " << cy << endl;
	vis[{cx,cy}] = true;
	if(!bales[{cx-1,cy}] && !bales[{cx+1,cy}] && !bales[{cx,cy-1}] && !bales[{cx,cy+1}] && !bales[{cx-1,cy-1}] && !bales[{cx-1,cy+1}] && !bales[{cx+1,cy-1}] && !bales[{cx+1,cy+1}])return;
	go(cx-1,cy);
	go(cx+1,cy);
	go(cx,cy-1);
	go(cx,cy+1);
}
int main(){
	freopen("perimeter.in", "r", stdin);
	freopen("perimeter.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int sx = 1000000;
	int sy = 0;
	for(int i = 0; i < N;i ++){
		pii c;
		cin >> c.f >> c.s;
		bales[c] = true;
		if(c.f < sx){
			sx = c.f;
			sy = c.s;
		}
	}
	go(sx-1, sy);
	cout << ans << '\n';
}
