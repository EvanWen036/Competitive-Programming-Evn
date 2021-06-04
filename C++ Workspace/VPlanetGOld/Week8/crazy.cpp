#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define sz(a) a.size(
typedef long double ll;
typedef pair<ll, ll> pii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int N, C;
vector<vector<pii>> polygons;
set< pair<ll, ll> > vis;
map<pii, vector<pii>> adj;
string s[1005];
vector<pii> cows;
#define int long long
bool inPolygon(pii x, vector<pii> pol){
	int cnt = 0;
	bool col = false;
	long double rSlope = 1e9+5;
	long double rInt = x.s - (x.f * rSlope);
	for(int i=0;i < pol.size();i ++){
		pii p1 = pol[i];
		int ind2 = (i+1)%(pol.size());
		pii p2 = pol[ind2];
		//cout << p1.f << " " << p1.s << " " << p2.f << " " << p2.s << '\n';
		if(p1.f == p2.f){
            //vertical segment
            long double intpy = p1.f * rSlope + rInt;
            if(max(p1.s, p2.s) >= intpy && min(p1.s,p2.s) <= intpy)cnt++;
        }
        else{
            long double slope = (1.0 * p2.s - p1.s) / (p2.f - p1.f);
            long double yInt = p2.s - p2.f*slope;
            long double intP = (rInt-yInt)/(slope - rSlope);
            if(intP >= x.f && intP <= max(p1.f, p2.f) && intP >= min(p1.f,p2.f)){
                cnt++;
            } 
        }
	}
	//cout << cnt << " " <<  x.f << " " << x.s << " " << pol[0].f << " " << pol[0].s << '\n';
	return cnt%2 == 1;
}
void traverse(pair<int, int> curr){
    vis.insert(curr);
    for(auto it : adj[curr]){
        if(vis.count(it) == 0){
            polygons[polygons.size()-1].push_back(it);
            traverse(it);
        }
    }
}
main(){
	freopen("crazy.in", "r", stdin);
	freopen("crazy.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> C;
	for(int i = 0; i < N;i ++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		adj[{x1,y1}].pb({x2,y2});
		adj[{x2,y2}].pb({x1,y1});
	}
	for(auto it : adj){
        if(vis.count(it.first) == 0){
            vector< pair<ll, ll> > x;
            polygons.push_back(x);
            polygons[polygons.size()-1].push_back(it.first);
            traverse(it.first);
        }
    }
    for(int i = 0; i < C;i ++){
    	int x, y;
    	cin >> x >> y;
    	cows.pb({x,y});
    }
    for(int i = 0;i < C;i ++){
    	string c = "";
    	for(auto it : polygons){
    		if(inPolygon(cows[i], it)){
    			c += "1";
    			//cout << i << " " << it[0].f << " " << it[0].s << '\n';
    		}
    		else{
    			c += "0";
    		}
    	}
    	s[i]=c;

    }
    map<string, int> cnt;
    int ans = 0;
    for(int i = 0; i < C ;i ++ ){
    	cnt[s[i]]++;
    	ans = max(ans, cnt[s[i]]);
    }
    cout << ans << '\n';
}
