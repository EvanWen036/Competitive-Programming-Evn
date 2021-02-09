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
int N, D;
vector<pii> cows;
bool le[50005];
bool ri[50005];
multiset<int> curr;
int main(){
	freopen("crowded.in", "r", stdin);
	freopen("crowded.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> D;
	for(int i = 0; i < N;i ++){
		int a, b;
		cin >> a >> b;
		cows.pb({a,b});
	}
	sort(cows.begin(), cows.end());
	int lp = 0;
	for(int rp = 0; rp < N; rp++){
		curr.insert(cows[rp].s);
		while(cows[rp].f - cows[lp].f > D){
			curr.erase(curr.find(cows[lp].s));
			lp++;
		}
		if(*(--curr.end()) >= 2 * cows[rp].s){
			le[rp] = true;
		}
	}
	int rp = N-1;
	curr.clear();
	for(int lp = N-1; lp >= 0; lp--){
		curr.insert(cows[lp].s);
		while(cows[rp].f - cows[lp].f > D){
			curr.erase(curr.find(cows[rp].s));
			rp--;
		}
		if(*(--curr.end()) >= 2 * cows[lp].s){
			ri[lp] = true;
		}
	}
	int ans = 0;
	for(int i = 0; i < N;i ++){
		if(le[i] && ri[i])ans++;
	}
	cout << ans << '\n';

}
