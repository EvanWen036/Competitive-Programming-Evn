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
	//p3	
	//cout << "11\n0\n4\n3\n1\n2\n2\n1000000000000000001\n";
	int Q;
	cin >> Q;
	for(int i = 1; i <= Q;i ++){
		ll d, x, y;
		cin >> d >> x >> y;
		if(abs(x-y)%3 == 0){
			if((d+1)%3 != 0)d++;
			cout << d << '\n';
			continue;
		}
		if(abs(x-y) % 3 == 1){
			cout << 0 << '\n';
			continue;
		}
		if(abs(x-y)%2 == 0){
			cout << (d-1)/2 << '\n';
		}

	}
}
