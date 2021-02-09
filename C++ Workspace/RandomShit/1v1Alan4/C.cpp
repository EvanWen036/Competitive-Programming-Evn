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
	int T, s, q;
	cin >> T >> s >> q;
	int amt = s-1;
	int pos = -1;
	int sec = 0;
	int ans = 0;
	while(amt < T){
		//progress one second
		sec++;
		pos++;
		if(sec % q){
			amt += q-1;
		}
		if(pos > amt){
			ans++;
			pos=0;
		}
	}
	cout<<ans+1<<'\n';


}
