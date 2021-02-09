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
vector<pii> pts;
int N;
int ans = 0;
int eq = 0;
void solve(){
	//try everything between i and j as leftmost/rightmost points
	sort(pts.begin(), pts.end());
	for(int i = 0; i < N; i++){
		set<int> y;
		y.insert(pts[i].s);
		//set of active y coords
		for(int j = i+1; j < N; j++){
			int dx = pts[j].f - pts[i].f;
			y.insert(pts[j].s);
			//possible places where the bottom of the square can be
			int lo = max(pts[j].s, pts[i].s) - (pts[j].f - pts[i].f);
			int hi = min(pts[j].s, pts[i].s);
			//cout << i << " " << j << " " << lo << " " << hi << '\n';
			//assume deltaX <= deltaY
 			if(lo > hi)continue;
 			//cout << lo << " " << hi << '\n';
 			assert(lo <= hi);
			//bottom of the rectangle is somewhere between lo and hi
			vector<int> sortedY;
			int u = 0;
			//window of size deltaX from d+1 to u
			set<int> tr;
			tr.insert(lo);

			for(auto it : y){
				sortedY.pb(it);
				//in is what the y coord of the bottom of square when this cow enters
				//out is what the y coord of the bottom is when this cow leaves
				int in = it - dx;
				int out = it+1;
				if(in > hi || out < lo)continue;
				//adjust hi to the bounds of lo/hi
				in = max(in, lo);
				out = min(out, hi);
				if(in > out)continue;
				tr.insert(in);
				tr.insert(out);
			}
			//assert(sortedY.size() == j-i-1);
			set<pii> squaresPossible;
			//try all important y coords
			for(auto it : tr){
				//upper is the highest point within the square
				//lower is the lowest point within the square
				int upper = upper_bound(begin(sortedY), end(sortedY), it + dx) - begin(sortedY);
				int lower = lower_bound(sortedY.begin(), sortedY.end(), it) - sortedY.begin();
				upper--;
				//if nothing is inside the square
				if(lower == sortedY.size() || sortedY[lower] > it+dx){
					squaresPossible.insert({-1,-1});
					continue;
				}
				assert(lower <= upper);
				//insert lower,upper pairs
				squaresPossible.insert({lower, upper});
			}
			ans += squaresPossible.size();
			//cout << squaresPossible.size() << '\n';
			for(auto it : squaresPossible){
				//cout << it.f << " " << it.s << '\n';
				//assert(it.s < sortedY.size());
				//increase the number of "bounding squares"
				if(it.f == -1 && it.s == -1){
					if(pts[j].s - pts[i].s == dx)eq++;
				}
				else if(sortedY[it.s] - sortedY[it.f] == dx)eq++;
			}
		}
	}
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for(int i = 0; i < N;i ++){
		pii x;
		cin >> x.f >> x.s;
		pts.pb(x);
	}
	solve();
	for(int i = 0; i < N;i ++){
		swap(pts[i].f, pts[i].s);
	}
	solve();
	//cout << ans << " " << eq << '\n';
	cout << N+1+ans-eq/2 << '\n';
}
                     	