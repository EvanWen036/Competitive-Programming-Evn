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

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q, k;
	cin >> n >> q >> k;
	vector<int> mat(n+1);
	for(int i =  1; i <= n; i++){
		cin >> mat[i];
	}
	for(int i =1; i <= q;i ++){
		int a, b;
		cin >> a >> b;
		int diff = mat[b]-mat[a];
		int gaps = b-a;
		cout << (k - mat[b]) + (mat[a] - 1) + ((diff-gaps)*2) << '\n';
	}


}
