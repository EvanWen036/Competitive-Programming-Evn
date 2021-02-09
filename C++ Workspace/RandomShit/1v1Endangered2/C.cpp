#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ld long double
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
	ld x1, x2;
	cin >> x1 >> x2;
	x1 = x1 + 0.0000000000000001;
	x2 = x2 - 0.0000000000000001;
	vector<pair<ld,ld>> lines(n);
	for(int i = 0; i < n; i++){
		ld k, b;
		cin >> k >> b;
		lines[i] = {k,b};

	}
	
	vector<pair<ld,ld>> inv;
	for(int i = 0; i < n; i++){
		ld p1 = lines[i].f * x1 + lines[i].s;
		ld p2=  lines[i].f * x2 + lines[i].s;
		inv.pb({p1, -1*p2});
	}
	sort(inv.begin(), inv.end());
	ld mx = -1 * 1e18;
	for(int i = 0; i < inv.size(); i++){
		cout << inv[i].f << " " << inv[i].s << "\n";
		if(mx > inv[i].f){
			cout << "Yes";
			return 0;
		}
		mx = max(mx, -1 * inv[i].s);
	}
	cout << "No"; 




}
