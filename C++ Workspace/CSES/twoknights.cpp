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
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		//i*i choose 2 - (i choose 3 * i * 2)
		ll sq = i * i;
		ll choose = sq*(sq-1)/2;
		cout << choose - 1LL * 4 * (i-1)*(i-2) << '\n';
	}


}
