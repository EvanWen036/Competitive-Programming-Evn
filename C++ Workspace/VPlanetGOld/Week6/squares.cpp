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
int N, K;
vector<array<int,4>> events;
pii points[50005];
vector<pii> overlaps;
int main(){
	freopen("squares.in", "r", stdin);
	freopen("squares.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	for(int i = 0; i < N;i ++){
		int a, b;
		cin >> a >> b;
		points[i] = {a,b};
		array<int, 4> a1= {a - K/2, 1, b-K/2, i};
		array<int, 4> a2 = {a + K/2, 0, b - K/2, i};
		events.pb(a1);
		events.pb(a2);
	}
	sort(events.begin(), events.end());
	set<pii> y;
	for(auto it : events){
		//cerr << it[0] << " " << it[1] << " " << it[2] << " " << it[3] << '\n';
		if(it[1] == 1){
			//if not overlapped 

			int up = it[2] + K;
			//cerr << it[2] << " " << it[3] << '\n';
			if(y.empty()){
				y.insert({it[2],it[3]});
				continue;
			}
			set<pii>::iterator it2 = y.lower_bound({up, 0});
			if(it2 == y.begin()){
				//this is below everything
				y.insert({it[2],it[3]});
				continue;
			}
			assert(it2 != y.begin());
			it2--;
			while(true){
				//cerr << (*it2).f << " " << it[2] << " " << it[3] << '\n';
				if((*it2).f + K > it[2]){
					overlaps.pb({(*it2).s,it[3]});
					if(overlaps.size() > 1){
						cout << -1 << '\n';
						return 0;
					}
				}
				if(it2 == y.begin())break;
				it2--;
			}
			y.insert({it[2],it[3]});

		}
		else{
			if(y.find({it[2],it[3]}) != y.end()){
				y.erase({it[2],it[3]});
			}
		}
	}
	if(overlaps.size() > 1){
		cout << -1 << '\n';
		return 0;
	}
	if(overlaps.size() == 0){
		cout << 0 << '\n';
		return 0;	
	}
	//cout << overlaps[0].f << " " << overlaps[0].s << '\n';
	int left = max(points[overlaps[0].f].f, points[overlaps[0].s].f) - K/2;
	int right = min(points[overlaps[0].f].f, points[overlaps[0].s].f) + K/2;
	int up = min(points[overlaps[0].f].s, points[overlaps[0].s].s) + K/2;
	int down = max(points[overlaps[0].f].s, points[overlaps[0].s].s) - K/2;
	//cout << left << " " << right << " " << up << " " << down << '\n';
	cout << (right-left) * (up-down) << '\n';
}
