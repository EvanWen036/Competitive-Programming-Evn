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
#define int long long
int N, M, Q;
int P[100005];
int goTo[100005];
int dist[100005];
bool vis[100005];
int ans[100005];
int cycleSize[100005];
int stepsAway[100005];
vector<vector<int>> inC;
vector<int> cc;
int x = 0;
bool in[100005];
void dfs(int v){
	if(vis[v])return;
	vis[v] = true;
	dist[goTo[v]] = dist[v]+1;
	dfs(goTo[v]);
}
void dfs2(int v){
	if(vis[v])return;
	x++;
	in[v] = true;
	vis[v] = true;
	cc.pb(v);
	dfs2(goTo[v]);
}
main(){
	freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> Q;
	//build the graph with reverse edges to make distance computation easier
	//edge from p[i]-1 to i
	for(int i = 1; i <= M;i ++){
		cin >> P[i];
		goTo[P[i]-1] = i;
		dist[i] = 1e9;
	}
	dist[0] = 0;
	dfs(0);
	//build the graph
	//edge from i to p[i]-1
	for(int i = 1; i <= M;i ++){
		goTo[i] = P[i]-1;
	}
	if(N == M){
		//one shuffle only

	}
	//inC stores vectors where each vectore is a cycle
	for(int i = 1; i <= M;i ++){
		if(dist[i] == 1e9 && !vis[i]){
			//this is in some sort of cycle
			dfs2(i);
			inC.pb(cc);
			cc.clear();
		}
	}
	//the beginning. anything that is not in a cycle will have a lower distance than distance from 0 to M
	//cerr << dist[M] << " " << N-M+1 << '\n';
	//cerr << M-x << " " << N-M << '\n';
	//this is the first(lowest card) element in the last M elements.
	//X is the number of elements in cycles
	int last = N-(M-x)+1;

	for(int i = 1; i <= M;i ++){
		if(i >= last)break;
		if(dist[i] != 1e9 && N-M+1 >= dist[i]){
			//cout << i << " " << dist[i] << '\n';
			assert(dist[M] >= dist[i]);
			ans[dist[i]] = i;
		}
	}
	for(int i = 1; i <= M;i ++){
		//figure out what happens when you are a certain amt of steps away
		if(dist[i] == 1e9)continue;
		stepsAway[dist[M]-dist[i]]=i;
	}
	//the middle
	//the middle is an increasing subsequence
	//cerr << last << '\n';
	//cerr << dist[M] << '\n';
	for(int i = M+1; i < last;i ++){
		ans[dist[M]+(i-M)] = i;
		//cerr << dist[M] + (i-M) << '\n';
	}
	//the end that is not in cycle
	//assert(last >= M);
	//for the values at the end that aren't in a cycle 
	//figure 
	for(int i = last; i <= N; i++){
		//if(N-M + stepsAway[N-i+1] )
		//will actually be last
		
		ans[N-M+stepsAway[N-i+1]+1] = i;
		

		//cerr << N-M+stepsAway[N-i+1]+1 << " " << i << '\n';
	}
	//cycles at the end
	//cerr << x << '\n';
	for(auto it : inC){
		for(int i = 0; i < it.size(); i++){
			//cerr << it[i] << " ";
			int newPos = (i+N-M+1) % it.size();
			ans[N-M+it[newPos]+1] = it[i];
			//cerr << N-M+it[newPos]+1 << '\n';
		}
		//cerr << '\n';
		//cout << '\n';
	}

	//cout << "4\n5\n3\n1\n2";
	for(int i = 1;i <= Q; i++){
		int y;
		cin >> y;
		cout << ans[N-y+1] << '\n';
		//assert(ans[N-y+1] != 0);
	}
}
