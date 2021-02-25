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
vector<int> pos(100005);
int goTo[100005];
int dist[100005];
bool vis[100005];
void dfs(int curr){
	if(vis[curr])return;
	vis[curr] = true;
	if(curr == 0){
		dist[curr] = 0;
	}
	else{
		dfs(goTo[curr]);
		dist[curr] = dist[goTo[curr]]+1;
	}
}
int main(){
	//freopen("shuffle.in", "r", stdin);
	//freopen("shuffle.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, Q;
	cin >> N >> M >> Q;
	for(int i = 1; i <= M;i ++){
		cin >> goTo[i];
		goTo[i]--;
	}
	for(int i = M; i >= 1;i --){
		dfs(i);
		//cout << i << " " << dist[i] << '\n';
	}
	for(int i = 1; i < M;i ++){
		cout << dist[i] << '\n';
	}
	cout << dist[M] << '\n';
	for(int i = 0; i < Q;i ++){
		int a;
		cin >> a;
		if(a <= M){
			//first
			cout << '\n';
		}
		else if(a >= N-(M-1)){
			//doesn't get shuffled out
			cout << '\n';
		}
		else{
			//in the middle not difficult to compute
			cout << dist[M] + (i - M) -1 << '\n';
		}
	}



}
