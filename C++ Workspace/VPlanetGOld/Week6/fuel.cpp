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
#define int long long
vector<pair<ll, ll>> stations;
int firstLess[50005];
main(){
	freopen("fuel.in", "r", stdin);
	freopen("fuel.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, G, B, D;
	cin >> N >> G >> B >> D;
	for(int i = 0;i < N;i ++){
		int a, b;
		cin >> a >> b;
		stations.pb({a, b});
	}	
	sort(stations.begin(), stations.end());
	vector<pair<ll,ll>> stack;
	memset(firstLess, -1 ,sizeof(firstLess));
	for(int i = 0;i < N;i ++){
		while(stack.size() > 0 && stack.back().s > stations[i].s){
			firstLess[stack.back().f] = i;
			stack.pop_back();
		}
		stack.pb({i, stations[i].s});
		//cout << firstLess[i] << '\n';
	}
	ll ans = 0;
	B -= stations[0].f;
	if(B < 0){
		cout << -1 << '\n';
		return 0;
	}
	int i =  0;
	while(i < N-1){
		//cerr << i << " " << stations[i].f << " " << stations[i].s << " " <<  B << " " << ans << '\n';
		//assert(i > 0 || stations[i].f != stations[i-1].f);
		//cerr << i << " " << B << " " << ans << '\n';
		if(stations[i+1].f - stations[i].f > G){
			cout << -1 << '\n';
			return 0;
		}
		if(firstLess[i] == -1 || stations[firstLess[i]].f - stations[i].f > G){
			//fill all the way up

			if(D - stations[i].f <= G){
				if(B < D - stations[i].f){
					ans += stations[i].s * (D - stations[i].f - B);
				}
				cout << ans << '\n';
				return 0;
			}
			ans += stations[i].s * (G-B);
			//cerr << i << '\n';
			B = G;
			B -= (stations[i+1].f - stations[i].f);
			i++;
		}
		else{
			int dist = stations[firstLess[i]].f - stations[i].f;
			int add = 0;
			if(B < dist){
				add = dist-B;
				B = dist;
			}
			ans += stations[i].s * add;
			B -= dist;
			i = firstLess[i];
		}
	}
	//cerr << B << '\n';
	//cerr << N-1 << " " << stations[N-1].f << " " << B << " " << ans << '\n';
	if(D - stations[N-1].f > G){
		cout << - 1 << '\n';
		return 0;
	}
	ll dist = D - stations[N-1].f;
	//cout << B << '\n';
	if(B < dist){
		ans += stations[N-1].s * (dist-B);
	}
	cout << ans << '\n';

}
 