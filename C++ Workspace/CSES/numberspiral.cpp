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
	int t;
	cin >> t;
	while(t--){
		ll x, y;
		cin >> x >> y;
		ll band = max(x,y);
		if(x == band){
			if(band % 2 == 0){
				cout << band*band - y + 1;
			}
			else{
				cout << (band-1)*(band-1) + y;
			}
		}
		else{
			if(band % 2 == 0){
				cout << (band-1)*(band-1) + x;
			}
			else{
				cout << band*band-x+1; 
			}
		}
		cout << '\n';
	}


}
