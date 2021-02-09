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
	vector<int> a(n+1);
	for(int i = 1; i <= n; i++){
		a[i] = i;
	}
	vector<pii> operations;
	while(n > 2){
		int temp = ceil(sqrt(n));
		for(int i = temp+1; i < n; i++){
			operations.pb({a[i], n});
			a[i] = 1;
		}
		operations.pb({n, temp});
		operations.pb({n, temp});
		n = temp;
	}
	cout << operations.size() << '\n';
	for(pii p : operations){
		cout << p.f << " " << p.s << '\n';
	}
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--)solve();


}
