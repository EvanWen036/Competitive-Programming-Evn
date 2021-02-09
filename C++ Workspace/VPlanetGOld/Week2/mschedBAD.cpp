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
vector<pii> cows;
map<int, vector<int>> add;
int main(){
	freopen("msched.in", "r", stdin);
	freopen("msched.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	vector<int> deadlines;
	deadlines.pb(0);
	for(int i = 0; i < N;i ++){
		int a, b;
		cin >> a >> b;
		deadlines.pb(b);
		cows.pb({b, a});
	}
	sort(cows.begin(), cows.end());
	sort(deadlines.begin(), deadlines.end());
	for(int i = 0; i < N;i ++){
		vector<int>::iterator it = lower_bound(begin(deadlines), end(deadlines), cows[i].f);
		it--;
		add[*it].pb(cows[i].s);
	}
	int mx = deadlines[N];
	int ans = 0;
	map<int,vector<int>>::iterator it = add.begin();
	while(it != add.end()){ 
		map<int,vector<int>>::iterator lb = next(it);
		int ne = 0;
		if(lb == add.end()){
			//cout << "hi " << mx << '\n';
			ne = mx - (*it).f;
		}
		else{
			ne = (*lb).f - (*it).f;
		}
		vector<int> curr = (*it).s;
		//cout << (*it).f << " " << curr.size() << " " << ne << '\n';
		sort(curr.begin(), curr.end());
		reverse(curr.begin(), curr.end());
		for(int i = 0;i < ne && i < curr.size();i ++){
			ans += curr[i];
		}
		//cout << ans << '\n';
		it++;
	}
	cout << ans << '\n';
}
