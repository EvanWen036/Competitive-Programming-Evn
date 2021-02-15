#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define sz(a) a.size()
typedef long long ll;
typedef pair<int, int> pii;
int n, m;
ll horz[2005];
ll vert[2005];
pair<ll,pii> edgesU[2005*2005];
pair<ll, pii> edgesR[2005*2005];
int pos[2005][2005];
int dsu[2005*2005];
int depth[2005*2005];
int sz[2005*2005];
vector<pair<ll,ll>> differencesH;
vector<pair<ll,ll>> differencesV;

int find(int u){
	if(dsu[u] == u)return u;
	return dsu[u]=find(dsu[u]);
}
ll ans = 0;
bool print = false;
void merge(int u, int v, ll w){
	u = find(u);
	v= find(v);
	if(u == v)return;
	if(depth[u] < depth[v])swap(u,v);
	//u has bigger depth
	ans += w;
	dsu[v] = u;
	sz[u] += sz[v];
	if(sz[u] == (n+1)*(m+1)){
		print = true;
	}
	depth[u] = max(depth[u], depth[v]+1);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	ifstream cin("fencedin.in");
	ofstream cout("fencedin.out");

	int A, B;
	cin >> A >> B >> n >> m;
	vert[0] = 0;
	for(int i = 1; i <= n; i ++){
		int x;
		cin >> x;
		vert[i] = x;
	}
	vert[n+1] = A;
	horz[0] = 0;
	for(int i = 1; i <= m; i++){
		int x;
		cin >> x;
		horz[i] = x;
	}
	//cerr << "IODONE"<< '\n';
	horz[m+1] = B;
	sort(horz, horz+m+2);
	sort(vert, vert+n+2);
	int edgesAdd = 0;
	int cnt = 0;
	for(int i = 0; i <= m; i++){
		for(int j = 0;j <= n;j ++){
			pos[i][j] = cnt++;
			depth[pos[i][j]]=1;
			dsu[pos[i][j]] = pos[i][j];
			sz[pos[i][j]]= 1;
		}
	}
	for(int i = 0; i <= m; i++){
		differencesH.pb({horz[i+1], horz[i]});
	}
	for(int i = 0; i <= n; i++){
		differencesV.pb({vert[i+1], vert[i]});
	}
	sort(differencesH.begin(), differencesH.end(), [] (const pii& a, const pii& b)
		{
			return (a.f - a.s) < (b.f - b.s);
		});
	sort(differencesV.begin(), differencesV.end(), [] (const pii& a, const pii& b){
			return (a.f - a.s) < (b.f - b.s);
	});

	int ptr1 = 0; int ptr2 = 0;
	while(ptr1 < differencesH.size() || ptr2 < differencesV.size()){
		//cerr << ptr1 << " " << ptr2 << endl;
		if(ptr1 == differencesH.size()){
			//do stuff with ptr2
			int c = lower_bound(vert, vert + n + 2, differencesV[ptr2].s) - vert;
			int r = 0;
			while(r + 1 <= m){
				merge(pos[r][c], pos[r+1][c], differencesV[ptr2].f - differencesV[ptr2].s);
				if(print){
					cout << ans << '\n';
					return 0;
				}
				r++;
			}
			ptr2++;
		}
		else if(ptr2 == differencesV.size()){
			//do stuff with ptr1
			int r = lower_bound(horz, horz + m + 2, differencesH[ptr1].s) - horz;
			int c = 0;
			while(c + 1 <= n){
				merge(pos[r][c], pos[r][c+1], differencesH[ptr1].f - differencesH[ptr1].s);
				if(print){
					cout << ans << '\n';
					return 0;
				}
				c++;
			}
			ptr1++;
		}	
		else if(differencesH[ptr1].f - differencesH[ptr1].s < differencesV[ptr2].f - differencesV[ptr2].s){
			//do stuff with ptr1
			int r = lower_bound(horz, horz + m + 2, differencesH[ptr1].s) - horz;
			int c = 0;
			while(c + 1 <= n){
				merge(pos[r][c], pos[r][c+1], differencesH[ptr1].f - differencesH[ptr1].s);
				if(print){
					cout << ans << '\n';
					return 0;
				}
				c++;
			}
			ptr1++;
		}
		else{
			//do stuff with ptr2
			int c = lower_bound(vert, vert + n + 2, differencesV[ptr2].s) - vert;
			int r = 0;
			while(r + 1 <= m){
				merge(pos[r][c], pos[r+1][c], differencesV[ptr2].f - differencesV[ptr2].s);
				if(print){
					cout << ans << '\n';
					return 0;
				}
				r++;
			}
			ptr2++;
		}
	}
	cout << ans << '\n';
}
