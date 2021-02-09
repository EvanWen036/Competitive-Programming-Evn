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
	string s;
	cin >> s;
	int op = 0;
	int ob = 0;
	int ans = 0;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '(')op++;
		if(s[i] == '[')ob++;
		if(s[i] == ')'){
			if(op > 0){
				op--;
				ans++;
			}
		}
		if(s[i] == ']'){
			if(ob > 0){
				ob--;
				ans++;
			}
		}
	}

	cout << ans << '\n';
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}


}
