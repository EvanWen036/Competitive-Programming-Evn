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
#define int long long
ll val[2000005];
int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for(int i = 0;i  < k;i ++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if(a == 1){
			for(int i  =b; i <= c; i++){
				val[i] = max(val[i], d);
			}
		}
		else{
			for(int i =b;i <= c; i++){
				val[i] =min(val[i], d);
			}
		}
	}
	for(int i = 0; i < n;i ++){
		cout << val[i] << '\n';
	}


}
