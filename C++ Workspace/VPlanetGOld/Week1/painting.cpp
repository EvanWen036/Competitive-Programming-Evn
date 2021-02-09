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
	freopen("painting.in", "r", stdin);
	freopen("painting.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	vector<int> yHigh(N);
	vector<int> yLow(N);
	vector<tuple<int,int,int>> events;
	for(int i = 0;i  < N;i ++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		yHigh[i] = d;
		yLow[i] = b;
		events.pb(make_tuple(a, i, 1));
		events.pb(make_tuple(c, i, -1));
	}	
	sort(events.begin(), events.end());
	int answer = 0;
	set<pii> curr;
	for(tuple<int,int,int> u : events){
		//cout << u.f << " " << u.s << '\n';
		if(get<2>(u) == 1){
			//open interval
			set<pii>::iterator it = curr.upper_bound({yHigh[get<1>(u)], 0});
			if(it == curr.end()){
				answer++;
				curr.insert({yHigh[get<1>(u)], get<1>(u)});
				continue;				
			}
			int index = (*it).s;
			if(yLow[index] < yLow[get<1>(u)]){
				//this is contained
				continue;
			}
			answer++;
			curr.insert({yHigh[get<1>(u)], get<1>(u)});
		}
		if(get<2>(u) == -1){
			//end interval remove if it exists in set
			if(curr.find({yHigh[get<1>(u)], get<1>(u)}) != curr.end()){
				curr.erase({yHigh[get<1>(u)], get<1>(u)});
			}	
		}
	}
	cout << answer << '\n';

}
