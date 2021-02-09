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
int N, B;
vector<pii> bales;
int main(){
	freopen("trapped.in", "r", stdin);
	freopen("trapped.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> B;
	for(int i = 0; i < N; i++){
		int a, b;
		cin >> a >> b;
		bales.pb({b,a});
	}
	sort(bales.begin(), bales.end());
	int lp = 0;
	if(B > bales[N-1].f || B < bales[0].f){
		cout << -1 << '\n';
		return 0;
	}
	int rp = 0;
	for(int i = 0; i < N; i++){
		if(B > bales[i].f)rp = i;
	}
	rp++;
	lp = rp-1;
	int ans = 1e9;
	for(; rp < N; rp++){
		assert(lp <= rp);
		//try making the "unbreakable" range lp to rp
		while(lp >= 0 && bales[rp].f - bales[lp].f >= bales[lp].s){
			lp--;
		}
		if(lp >= 0){

			int change = bales[rp].f - bales[lp].f - bales[rp].s; 
			if(bales[rp].f - bales[lp].f >= max(bales[lp].s, bales[rp].s)){
				continue;
			}
			change = max(change, 0);
			//cout << lp << " " << rp << " " << change << '\n';
			ans = min(ans, change);
		}
	}
	lp = -1;
	for(int i = 0; i < N;i ++){
		if(bales[i].f < B)lp = i;
	}
	rp = lp+1;
	for(; lp >= 0; lp--){
		//try making the "unbreakable" range lp to rp
		//cout << lp << " " << rp << endl;
		assert(lp <= rp);
		while(rp < N && bales[rp].f - bales[lp].f >= bales[rp].s){
			rp++;
		}
		if(rp <= N-1){
			int change = bales[rp].f - bales[lp].f - bales[lp].s; 
			if(bales[rp].f - bales[lp].f >= max(bales[lp].s, bales[rp].s)){
				continue;
			}
			change = max(change, 0);
			//cout << lp << " " << rp << " " << change << '\n';
			ans = min(ans, change);
		}
	}
	cout << (ans == 1e9 ? -1:ans) << '\n';

}
