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
int N;
vector<array<int,3>> pt;

set<int> xpt;
int main(){

	freopen("cowrect.in", "r", stdin);
	freopen("cowrect.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//p1	
	cin >> N;
	for(int i = 0; i < N;i ++){
		int x, y;
		char c;
		cin >> x >> y >> c;
		int type = (c == 'H' ? 1:0);
		pt.pb({x,type,y});
		xpt.insert(x);
	}
	int ans = 0;
	int ar = 1e9;
	sort(pt.begin(), pt.end());
	set<int>::iterator it = xpt.begin();
	while(it != xpt.end()){
		int l = *it;
		set<int>::iterator it2 = it;
		while(it2 != xpt.end()){
			vector<pii> s;
			int r = *it2;
			for(int i = 0; i < N;i ++){
				if(pt[i][0] >= l && pt[i][0] <= r){
					s.pb({pt[i][2], pt[i][1]});
				}
			}
			sort(s.begin(), s.end());
			int currs = 0;
			int best = 0;
			int ba = 1e9;
			int fy = 0;
			bool hg = false;
			for(int i = 0; i < s.size(); i++){
				if(s[i].s == 1 && (i == 0 || s[i-1].f != s[i].f || hg == false)){
					currs++;
					if(currs == 1)fy = s[i].f;
					hg = false;
				}
				else{
					//bad.insert(s[i].f);
					currs=0;
					hg=true;
				}
				if(currs > 0 && (i==s.size()-1 || s[i+1].f != s[i].f)){
					if(currs == best){
						ba = min(ba, (r-l) * (s[i].f - fy));
					}
					if(currs > best){
						best = currs;
						ba = (r-l) * (s[i].f - fy);
					}
				}
			}
			//cout << l << " " << r << " " << best << '\n';
			if(ans == best){
				ar = min(ar, ba);
			}
			if(best > ans){
				ans = best;
				ar = ba; 
			}
			
			it2++;
		}
		it++;
	}
	cout << ans << '\n';
	cout << ar << '\n';
}
