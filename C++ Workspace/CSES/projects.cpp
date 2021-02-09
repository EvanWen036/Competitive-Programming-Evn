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
	int n;
	cin >> n;
	vector<pair<int,pii>> events;
	int val[n];
	for(int i = 0; i < n;i ++){
		int a, b, c;
		cin >> a >> b >> c;
		events.pb({a,{1,i}});
		events.pb({b+1,{-1,i}});
		val[i] = c;
	}
	sort(events.begin(), events.end());
	ll ans[n];
	ll curr = 0;
	for(pair<int,pii> x: events){
		if(x.s.f==1){
			ans[x.s.s] = 1LL* curr + val[x.s.s];
		}
		else{
			curr = max(curr,ans[x.s.s]);
		}
		//cout << curr << '\n';
	}
	cout << curr << '\n';
}
