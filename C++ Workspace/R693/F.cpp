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
void solve(){
	int n, m;
	cin >> n >> m;
	vector<pii> pts(m);
	map<int, set<int>> lines;
	for(int i = 0; i < m;i ++){
		cin >> pts[i].f >> pts[i].s;
		lines[pts[i].f].insert(pts[i].s);
	}
	if((2 * n - m)%2 == 1){
		cout << "No\n";
		return;
	}
	for(auto it : lines){
		set<int> s = it.s;
		int prev = -1;
		for(int u : s){
			if(prev != -1 && u - prev == 2){
				cout << "No\n";
				return;
			}
			prev = u;
		}
	}
	cout << "Yes\n";

}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--)solve();


}
