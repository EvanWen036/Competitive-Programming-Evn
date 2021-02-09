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
	int n;
	cin >> n;
	vector<pair<pii,int>> st(n);
	vector<pair<pii,int>> lay(n);
	vector<int> ans(n+1);
	for(int i = 0; i < n;i ++){
		ans[i] = -1;
		int a, b;
		cin >> a >> b;
		st[i] = {{max(a,b),min(a,b)},i};
	}
	sort(st.begin(), st.end());
	set<pii> mins;
	int pt = 0;
	for(int i = 0;i < n;i ++){
		while(pt < n && st[pt].f.f < st[i].f.f){
			mins.insert({st[pt].f.s, st[pt].s});
			pt++;
		}
		//answer this guy
		if(mins.size() && (*mins.begin()).f < st[i].f.s){
			ans[st[i].s] = (*mins.begin()).s+1;  
		}
	}
	/**
	sort(lay.begin(), lay.end());
	for(int i = 0; i < n; i++){
		if(lay[0].f.f < st[i].f.f && lay[0].f.s < st[i].f.s){
			ans[st[i].s] = lay[0].s+1;
		}
		if(st[0].f.f < st[i].f.f && st[0].f.s < st[i].f.s){
			ans[st[i].s] = st[0].s+1;
		}
	}
	for(int i = 0; i < n;i ++){
		if(lay[0].f.f < lay[i].f.f && lay[0].f.s < lay[i].f.s){
			ans[lay[i].s]=lay[0].s+1;
		}
		if(st[0].f.f < lay[i].f.f && st[0].f.s < lay[i].f.s){
			ans[lay[i].s] = st[0].s+1;
		}
	}
	**/
	for(int i = 0; i < n;i ++){
		cout << ans[i] << " ";
	}
	cout << '\n';
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--)solve();


}
