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
int degree[1000005];
vector<int> adj[1000005];
bool vis[1000005];
int N, L;
multiset<int> degrees;
int deg2=0;
int cmp =0;
int re = 0;
bool wrk = true;
bool canwrk[1000005];
int deg4 = 0;
void Link(int a, int b){
	if(degrees.find(degree[a]) != degrees.end())degrees.erase(degrees.find(degree[a]));
	if(degrees.find(degree[b]) != degrees.end())degrees.erase(degrees.find(degree[b]));
	degree[a]++;
	degree[b]++;
	adj[a].pb(b);
	adj[b].pb(a);
	if(adj[a].size() == 4)deg4++;
	if(adj[b].size() == 4)deg4++;
	degrees.insert(degree[a]);
	degrees.insert(degree[b]);
}

void dfs(int u){
	vis[u] = true;
	cmp++;
	int deg = 0;
	for(int v : adj[u]){
		if(v != re)deg++;
		if(!vis[v] && v != re){
			dfs(v);
		}
	}
	//cout << u << " " << deg << '\n';
	if(deg > 2)wrk = false;
	if(deg == 2)deg2++;
}
int CountCritical(){
	/**
	int cnt4 = 0;
	for(int i = 0; i < N;i ++){
		if(degrees[i] >= 4)cnt4++;
	}	
	if(cnt4 > 1)return 0;
	if(cnt4 == 1)return 1;
	//check for degrees of 3 
	multiset<int> set;
	for(int i = 0; i < N;i ++)set.insert(degrees[i]);
	for(int i = 0; i < N;i ++){
		if(degrees[i] == 3){
			for(int u : adj[i]){
				//check if removing this makes chains
				vector<int> removes;
				for(int v : adj[u]){
					degrees[v]--;
				}	


			}	
		}
	}
	int mxDeg = 0;
	for(int i  =0; i < N;i ++){
		mxDeg = max(mxDeg, degrees[i]);
	}
	if(mxDeg <= 2)return N;
	**/
	if(deg4 == 1)return 1;
	if(deg4 > 1)return 0;
	int ans = 0;
	for(int i = 0; i < N;i ++){
		re = i;
		wrk = true;
		if(canwrk[i] == false)continue;
		memset(vis, false, sizeof(vis));
		for(int j = 0;j < N; j++){
			if(!vis[j] && j != i){
				deg2=0;
				cmp = 0;
				dfs(j);
				if(cmp == 1)continue;
				if(deg2 > cmp-2)wrk = false;
				//cout << i << " " << j << " " << cmp << " " << deg2 << '\n';
			}
			if(!wrk)break;
		}
		if(wrk)ans++;
		canwrk[i] = wrk;
	}
	//cout << '\n';
	return ans;

}
int main(){
	memset(canwrk, true, sizeof(canwrk));
	cin >> N >> L;
	for(int i = 0; i < L;i ++){
		int x;
		cin >> x;
		if(x == -1){
			cout << CountCritical() << '\n';
		}
		else{
			int y;
			cin >> y;
			Link(x,y);
		}
	}
}