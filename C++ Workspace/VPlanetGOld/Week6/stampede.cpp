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
int N;
ll yVal[50005];
bool seen[50005];
map<ll, vector<pii>> events;
main(){
	freopen("stampede.in", "r", stdin);
	freopen("stampede.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for(int i = 0; i < N;i ++){
		int a, b, c;
		cin >> a >> b >> c;
		assert(a <= -1);
		yVal[i] = b;
		int firstOver = (-1 - a) * c;
		int gone = (0 - a)*c;
		//cerr << firstOver << " " << gone-1 <<  '\n';
		events[firstOver].pb({i, 0});
		events[gone].pb({i,1});
	}
	set<pair<ll,int>> y;
	for(auto it : events){
		for(auto it2 : it.s){
			if(it2.s == 1){
				//remove
				y.erase({yVal[it2.f],it2.f});
			}
			else{
				y.insert({yVal[it2.f], it2.f});
			}
		}
		if(y.size() > 0){
			seen[(*y.begin()).s]=true;
		}
	}
	int cnt = 0;
	for(int i = 0; i < N;i ++){
		if(seen[i])cnt++;
	}
	cout << cnt << '\n';
}
