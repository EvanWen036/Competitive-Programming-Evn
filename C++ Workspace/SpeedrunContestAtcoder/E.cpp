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
	ll x, y;
	cin >> x >> y;
	ll a, b;
	//cin >> a >> b;
	if(x == y){
		cout << -1 << '\n';
	}
	else if(x > y){
		a = x;
		cout << a << " " << a + y << '\n';
		assert((a+y)%a == y && a % (a+y) == x);
	}
	else{
		cout << y + x << " " << y << '\n';
		assert((y+x)%y == x && y % (y+x) == y);
	}


}
