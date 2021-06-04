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
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<array<int,3>> bl;
		int ans = 0;
		for(int i = 0; i < n; i++){
			string line;
			cin >> line;
			int pre = 0;
			vector<int> v;
			for(int j = 0;j  < line.length();j ++){
				if(line[j] == 'x'){
					v.pb(stoi(line.substr(pre, j-pre)));
					pre = j+1;
				}
			}
			v.pb(stoi(line.substr(pre)));
			sort(v.begin(), v.end());
			bl.pb({v[0],v[1],v[2]});
		}
		for(int i = 0; i < (1 << n); i++){
			vector<array<int,3>> curr;
			for(int j = 0;j  < n;j ++){
				if(i & (1 << j)){
					curr.pb(bl[j]);
				}	
			}
			sort(curr.begin(), curr.end());
			int ch = 0;
			int prew = 1e9;
			int prel = 1e9;
			for(int j = curr.size()-1;j >=0;j --){
				if(curr[j][0] <= prel && curr[j][1] <= prew){
					ch += curr[j][2];
					prel = curr[j][0];
					prew = curr[j][1];
				}
			}
			ans = max(ans, ch);
		}
		cout << ans << '\n';
	}


}
