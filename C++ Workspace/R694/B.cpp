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
	int n, x;
	cin >> n >> x;
	vector<ll> a(n);
	ll sum = 0;
	vector<ll> times(n);
	queue<pii> q;
	for(int i =0; i<n;i++){
		cin >> a[i];
		q.push({a[i],1});
		sum += a[i];
		//cout << sum << '\n';
	}
	while(!q.empty()){
		pii top = q.front(); q.pop();
		//cout << top.f << " " << top.s << '\n';
		if(top.f % x != 0)break;
		q.push({top.f/x, top.s*x});
		sum += top.f * top.s;
	}
	cout << sum << '\n';
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--)solve();


}
