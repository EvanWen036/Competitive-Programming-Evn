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
	string s;
	cin >> s;
	int strk = 0;
	int ans = 1;
	for(int i = 0; i < s.length(); i++){
		if(i != 0 && s[i]==s[i-1]){
			strk++;
			ans=max(ans,strk);
		}
		else{
			strk = 1;
		}
	}
	cout << ans
	 << '\n';


}
