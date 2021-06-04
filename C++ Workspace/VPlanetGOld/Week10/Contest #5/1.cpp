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
bool hasG[1005];
int mst = 0;
int bar = 1e9;
int main(){
	//freopen("cowrect.in", "r", stdin);
	//freopen("cowrect.out", "w", stdout);
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
	sort(pt.begin(), pt.end());
	for(int i = 0; i < N;i ++){
		//cout << pt[i][0] << " " << pt[i][2] << " " << pt[i][1] << '\n';
		set<int> gp;
		oset<pii> hp;
		if(pt[i][1] == 0)continue;
		//hp.insert({pt[i][2], i});
		for(int j = i+1; j < N;j ++){
			if(pt[j][1] == 0)continue;
			for(int x = 0; x < N; x++){
				if(pt[x][0] >= pt[i][0] && pt[x][0] <= pt[j][0]){
					if(pt[x][1] == 1){
						//holstein
						hp.insert({pt[x][2], x});
					}
					else{
						gp.insert(pt[x][2]);
					}
				}
			}
		
			//if(j != N-1 && pt[j+1][0] == pt[j][0])continue;
			//if(!added)continue;
			if(gp.lower_bound(min(pt[j][2], pt[i][2])) != gp.end()){
				if(*(gp.lower_bound(min(pt[j][2], pt[i][2]))) <= pt[j][2])continue;
			}
			set<int>::iterator it1 = gp.lower_bound(max(pt[i][2], pt[j][2]));
			set<int>::iterator it2 = gp.lower_bound(min(pt[i][2], pt[j][2]));
			int fb = 0;
			int fa = 1000;
			if(it1 != gp.end())fa = (*it1)-1;
			if(it2 != gp.begin())fb = *(--it2) + 1;
			int amt = hp.order_of_key({fa,1005}) - hp.order_of_key({fb-1,1005});
			mst = max(mst, amt);
			if(amt == 4)cout << i << " " << j << '\n';
			int area = pt[j][0]-pt[i][0];
			int y1 = (*hp.lower_bound({fb, 0})).f;
			int y2 = (*(--hp.lower_bound({fa+1,0}))).f;
			area = area * (y2-y1);
			if(amt == mst){
				bar = min(bar, area);
			}
		}
	}
	if(mst == 0){
		mst = 1;
		bar = 0;
	}
	cout << mst << '\n';
	cout << bar << '\n';
}
