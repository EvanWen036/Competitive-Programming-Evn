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
	freopen("input.in", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll ans = 1;
	vector<int> r;
	r.pb(0);
	r.pb(0);
	r.pb(0);
	r.pb(0);
	r.pb(0);
	vector<int> cnt(5);
	for(int i = 1; i <= 323;i ++){
		string s;
		cin >> s;
		for(int j =0; j < 5;j ++){
			//cout << r[j] << " ";
			if(s[r[j] % s.length()] == '#'){
				if(j == 4 && i % 2 == 0)continue;
				if(j==4){
					cout << i << " " << r[j] << '\n';
				}
				cnt[j]++;
			}
		}
		//cout << '\n';
		r[0]++; 
		r[1] += 3;
		r[2] += 5;
		r[3] += 7;
		if(i % 2){
			r[4]++;
		}
	}	
	for(int i = 0; i < 5;i ++){
		cout << cnt[i] << '\n';
		ans *= cnt[i];
	}
	cout << ans << '\n';

}
