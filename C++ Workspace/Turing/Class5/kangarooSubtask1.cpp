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
	int n, cs, cf;
	cin >> n >> cs >> cf;
	vector<int> a;
	for(int i = 1; i <= n; i++){
		a.pb(i);
	}
	int cnt = 0;
	while(next_permutation(a.begin(), a.end())){
		if(a[0] != cs){
			continue;
		}
		if(a[n-1] != cf){
			continue;
		}
		bool bad =false;
		for(int i = 1; i < n-1;i ++){
			bool b1 = false;
			bool b2 = false;
			if(a[i] > a[i-1])b1 = true;
			if(a[i+1] > a[i])b2 = true;
			if(b1 == b2){
				bad = true;
				break;
			}
		}
		if(!bad)cnt++;
	}
	cout << cnt << '\n';

}
