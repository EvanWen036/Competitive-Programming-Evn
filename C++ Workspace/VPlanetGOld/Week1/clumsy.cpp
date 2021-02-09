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
	freopen("clumsy.in", "r", stdin);
	freopen("clumsy.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int ans = 0;
	int bal = 0;
	for(int i = 0; i < s.length();i ++){
		if(bal == 0 && s[i] == ')'){
			s[i] = '(';
			ans++;
		}
		int charLeft = s.length() - i - 1;
		if(s[i] == '(' && bal + 1 > charLeft){
			ans++;
			s[i] = ')';
		}
		if(s[i] == '(')bal++;
		else{bal--;}
	}	
	assert(bal == 0);
	cout << ans << '\n';

}
