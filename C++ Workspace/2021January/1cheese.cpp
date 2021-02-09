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
int cnt[30];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	assert(s.length() <= 100);
	int ans = 0;
	for(int i = 0; i < s.length(); i++){
		int x = s[i]-'a';
		cnt[x]++;
		ans = max(ans, cnt[x]);
	}
	cout << ans << '\n';


}
