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
	freopen("cowjog.in", "r", stdin);
	freopen("cowjog.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, T;
	cin >> N >> T;
	vector<ll> end(N+1);
	for(int i = 0;i  < N;i ++){
		int a, b;
		cin >> a >> b;
		end[i] = 1LL * a + 1LL * T * b;
	}	
	ll currEnd = end[N-1];
	ll ans = 1;
	for(int i = N-1; i >= 0;i --){
		if(end[i] < currEnd){
			ans++;
			currEnd = end[i];
		}
	}
	cout << ans << '\n';



}
