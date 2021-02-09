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
	cout << 1 << '\n';
	cout << '\n';
	cout << 66666 << " " << 133330<< '\n';
	int cnt = 0;
	for(int i = 1; i< 66666;i ++){
		cout << i << " " << i+1 << '\n';
		cout << i+1 << " " << i << "\n";
		cnt += 2;
	}
	cout << cnt << '\n';
}
 