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
	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	int pos = 0;
	vector<pii> events;	
	for(int i = 0; i < N;i ++){
		int x; char c;
		cin >> x >> c;
		int newPos = pos;
		if(c=='R')newPos += x;
		else{newPos -= x;}
		events.pb({min(pos,newPos), 1});
		events.pb({max(pos,newPos), -1});
		pos = newPos;
	}
	sort(events.begin(), events.end());
	int curr = 0;
	int entr = 0;
	int ans = 0;
	for(auto it : events){
		//cout << it.f << " " << it.s << '\n';
		if(it.s == 1){
			//opening
			curr++;
			if(curr == K)entr = it.f;
		}
		else{
			//closing
			curr--;
			if(curr == K-1){
				ans += it.f - entr;
			}
		}
	}
	cout << ans << '\n';

}
