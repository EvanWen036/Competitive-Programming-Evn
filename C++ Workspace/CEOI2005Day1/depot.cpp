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
const int maxN = 405;
const int maxM = 405;
vector<int> adj[maxN*maxM];
bool vis[maxN*maxM];
int ans = 0;
void dfs(int u){
	for(int v:adj[u]){
		if(!vis[v]){
			vis[v]=true;
			dfs(v);
		}
	}
}
bool seen[maxM];
bool need[maxM];
vector<int> val(maxN*maxM);
vector<int> extra[maxN];
int main(){
	//freopen("depot.in","r",stdin);
	//freopen("depot.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	for(int i = 0; i < N*M; i++){
		cin >> val[i];
		assert(val[i] <= M);
	}
	//cout <<"hi"<<endl;
	//number of special nodes - # of cycles + 1
	for(int i = 0; i < N; i++){
		//cout << i << endl;
		memset(seen,false,sizeof(seen));
		memset(need,false,sizeof(need));
		for(int j = M*i;j<M*(i+1); j++){
			assert(j < N*M && val[j] <= M);
			if(seen[val[j]]){
				ans++;
				extra[val[j]].pb(j);
				//cout<<j<<'\n';
			}
			seen[val[j]]=true;
		}
		for(int j=1;j<=M;j++){
			if(!seen[j]){
				need[j]=true;
				//ans++;
			}
		}
		for(int j = 0; j < M*i;j++){
			assert(j < N*M);
			if(need[val[j]]){
				//adj[i].pb();
				for(int u : extra[val[j]]){
					adj[u].pb(j);
				}
			}
		}
		for(int j=M*(i+1)+1; j < N*M;j++){
			assert(j < N*M);
			if(need[val[j]]){
				//adj[i].pb();
				for(int u : extra[val[j]]){
					adj[u].pb(j);
				}
			}
		}
	}

	for(int i=0;i<N*M;i++){
		if(!vis[i]&&adj[i].size() > 0){
			dfs(i);
			ans++;
		}
	}		
	cout<<ans-1<<'\n';
}
