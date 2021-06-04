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
int mat[105][105];
bool vis[105][105][105][105];
int dist[105][105][105][105];
int dr[5] = {0, 1, 0, -1, 0};
int dc[5] = {1, 0, -1, 0, 0};
void solve(){

	int n, m;
	string l1;
	getline(cin, l1);
	int sp = l1.find(" ");
	m = stoi(l1.substr(0, sp));
	n = stoi(l1.substr(sp+1));
	int mx, my;
	int tx, ty;
	int ex, ey;
	for(int i = 0; i < n;i ++){
		string line;
		getline(cin, line);
		//cout << line << endl;
		for(int j = 0;j < m;j ++){
			if(line[j] == 'X')mat[i][j] = 1;
			else{mat[i][j] = 0;}
			if(line[j] == 'M'){
				mx = i;
				my = j;
			}
			if(line[j] == 'T'){
				tx = i;
				ty = j;
			}
			if(line[j] == 'E'){
				ex = i;
				ey = j;
			}
		}
	}
	//cout << mx << " " << my << "\n";
	//cout << tx << " " << ty << '\n';
	//cout << ex << " " << ey << '\n';
	memset(vis, false, sizeof(vis));
	vis[tx][ty][mx][my] = true;
	memset(dist, 0, sizeof(dist));
	queue<array<int, 5>> q;
	q.push({tx,ty,mx,my,0});
	int ans = 1e9;
	while(!q.empty()){
		array<int, 5> c = q.front(); q.pop();
		//cout << c[0] << " " << c[1] << " " << c[2] << " " << c[3] << " " << c[4] << '\n';
		if(c[0] == ex && c[1] == ey)ans = min(ans, c[4]);
		for(int j = 0;j < 5;j ++){
			int ctx = c[0];
			int cty = c[1];
			ctx += dr[j];
			cty += dc[j];
			if(ctx >= 0 && ctx < n && cty >= 0 && cty < m && mat[ctx][cty] == 0){
				int mdist = abs(ctx - c[2]) + abs(cty - c[3]);
				int bdir = -1;
				for(int mj = 0; mj < 4; mj++){
					int cmx = c[2];
					int cmy = c[3];
					cmx += dr[mj];
					cmy += dc[mj];
					//cout << "minosaur" << " " << cmx << " " << cmy << '\n';
					if(cmx >= 0 && cmx < n && cmy >= 0 && cmy <  m && mat[cmx][cmy] == 0){
						int dist = abs(cmx-ctx) + abs(cmy-cty);
						//cout << ctx << " " << cty << " " << cmx << " " << cmy << " " << dist << '\n';
						if(dist < mdist){	
							bdir = mj;
							mdist = dist;
						}
						if(dist == mdist){
							if(mj == 0 || mj == 2)bdir = mj;
						}
					}
				}
				int cmx = c[2];
				int cmy = c[3];
				//cout << ctx << " " << cty << " " << cmx << " " << cmy << " " << bdir << '\n';
				if(bdir != -1){
					cmx += dr[bdir];
					cmy += dc[bdir];
				}
				if(!vis[ctx][cty][cmx][cmy] && (ctx != cmx || cty != cmy)){
					vis[ctx][cty][cmx][cmy] = true;
					dist[ctx][cty][cmx][cmy] = c[4]+1;
					q.push({ctx,cty,cmx,cmy,c[4]+1});
				}
			}
		}
	}
	cout << ans << '\n';

}
int main(){
	freopen("Prob28.in.txt", "r", stdin);
	int t;
	string l1;
	getline(cin, l1);
	t = stoi(l1);
	while(t--){
		solve();
	}

}