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
ll cnt[27];
ll se[27];
ll ans = 0;
string pa, te;
int k, n;
int main(){
	//p1
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> pa >> te;
	k = pa.length(); 
	n = te.length();
	for(int i = 0; i <k ;i++){
		cnt[pa[i]-'a']++;
	}

	for(int i = k-1; i >= 0; i--){
		ans += cnt[te[i]-'a'] - se[te[i]-'a'];
		se[pa[i]-'a']++;
	}
	//cout << ans << '\n';
	int i = k;
	for(; i < n && n-i >= k; i++){
		ans += cnt[te[i]-'a'];
	}
	//cout << ans << '\n';
	memset(se, 0, sizeof(se));
	se[pa[0]-'a']++;
	int v=1;
	i = min(i, n-k+1);
	for(;i < n;i ++){
		if(i >= k){
			ans += cnt[te[i]-'a'];
		}
		ans -= se[te[i]-'a'];
		assert(v < k);
		se[pa[v]-'a']++;
		v++;
	}
	cout << ans << '\n';

}
