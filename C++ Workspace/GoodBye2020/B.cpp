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
int cnt[2*100005];
void solve(){
	int n;
	cin >> n;
	vector<int> x(n);
	for(int i = 0; i < n; i++){
		cin >> x[i];
	}
	set<int> seen;
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(seen.count(x[i]) > 0){
			seen.insert(x[i]+1);
		}
		else{
			seen.insert(x[i]);
		}
	}
	cout << seen.size() << '\n';
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--)solve();


}
