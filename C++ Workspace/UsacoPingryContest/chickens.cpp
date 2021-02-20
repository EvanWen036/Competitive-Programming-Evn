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

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	vector<pii> pts(N);
	for(int i = 0; i < N;i ++){
		cin >> pts[i].f >> pts[i].s;
	}
	int ans = 1e9;
	for(int i = 0; i < N ;i++){
		for(int j = i + 1; j < N; j++){
			for(int k = j+1; k < N; k++){
				int x1 = max(pts[i].f, max(pts[j].f, pts[k].f));
				int x2 = min(pts[i].f, min(pts[j].f, pts[k].f));
				int y1 = max(pts[i].s, max(pts[j].s, pts[k].s));
				int y2 = min(pts[i].s, min(pts[j].s, pts[k].s));
				ans = min(ans, (y1-y2)*(x1-x2));
			}
		}
	}
	cout << ans << '\n';


}
