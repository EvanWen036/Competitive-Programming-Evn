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
	vector<pair<int, pii>> so;
	for(int i = 0;i < N; i++){
		int a, b;
		cin >> a >> b;
		so.pb({-1 * (a-b),{-1 * a,b}});
	}
	sort(so.begin(), so.end());
	ll curr = 0;
	ll total = 0;
	for(int i = 0;i < N; i++){
		so[i].s.f *= -1;
		total += 1LL * max(0, so[i].s.f - curr);
		curr = max(curr, so[i].s.f);
		curr -= so[i].s.s;
	}
	cout << total << '\n';


}
