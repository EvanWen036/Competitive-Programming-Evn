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
	vector<ll> a(n);
	multiset<ll> even;
	multiset<ll> odd;
	for(int i = 0; i < n;i ++){
		cin >> a[i];
		if(a[i] % 2 == 0){
			even.insert(a[i]);
		}
		else{
			odd.insert(a[i]);
		}
	}
	int turn = 0;
	ll al = 0;
	ll bo = 0;
	while(even.size() || odd.size()){
		ll mx = 0;
		ll my = 0;
		if(even.size()){
			mx = *(--even.end());
			//even.erase(--even.end());
		}
		if(odd.size()){
			my = *(--odd.end());
			//odd.erase(--odd.end());
		}
		if(mx > my){
			if(turn % 2 == 0){
				al += mx;
			}
			even.erase(even.find(mx));
		}
		if(mx < my){
			if(turn % 2 == 1){
				bo += my;
			}
			odd.erase(odd.find(my));
		}
		if(mx == my){
			if(turn % 2 == 0){
				al+=mx;
				even.erase(even.find(mx));
			}
			else{bo += my; odd.erase(odd.find(my));}
		}
		turn++;
		//cout << mx << " " << my << " " << al << " " << bo << '\n';

	}
	if(al > bo)cout << "Alice\n";
	else if(al < bo)cout << "Bob\n";
	else{cout << "Tie\n";}
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--)solve();


}
