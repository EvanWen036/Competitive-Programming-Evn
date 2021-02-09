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

int main(){
	freopen("msched.in", "r", stdin);
	freopen("msched.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	vector<pii> cows(N);
	for(int i = 0; i < N;i ++){
		int a, b;
		cin >> a >> b;
		cows[i] = {a,b};
	}
	set<int> times;
	for(int i = 0; i <= 10000;i ++)times.insert(i);
	sort(cows.begin(), cows.end());
	reverse(cows.begin(), cows.end());
	int ans = 0;
	for(int i = 0; i < N;i ++){
		set<int>::iterator it = times.upper_bound(cows[i].s-1);
		if(it == begin(times))continue;
		it--;
		ans += cows[i].f;
		times.erase(it);
	}
	cout << ans << '\n';

}
