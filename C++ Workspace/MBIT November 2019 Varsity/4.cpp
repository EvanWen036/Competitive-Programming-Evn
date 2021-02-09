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
vector<pii> adj[105];
bool vis[105][105];
int ans[105][105];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, C, A, B;
	cin >> N >> M >> C >> A >> B; A--; B--;
	vector<int> P(N);
	for(int i =0;i < N; i++){
		cin >> P[i];
	}
	for(int i = 0;i < M; i++){
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		adj[a].pb({b,c});
		adj[b].pb({a,c});
	}
	queue<pii> q;
	vis[A][0]= true;
	ans[A][0] = 0;
	q.push({A, 0});
	int answ = 1e9;
	while(!q.empty()){
		pii state = q.front(); q.pop();
		int pos = state.f;
		int energy = state.s;
		if(pos == B){
			answ = min(answ, ans[pos][energy]);
		}
		vis[pos][energy] = true;
		//try refilling
		int newEnergy = min(C, energy+P[pos]);
		if(!vis[pos][newEnergy]){
			ans[pos][newEnergy] = ans[pos][energy]+1;
			q.push({pos,newEnergy});
			vis[pos][newEnergy] = true;
		}

		for(auto it : adj[pos]){
			if(energy >= it.s){
				int newEnergy = energy - it.s;
				if(!vis[it.f][newEnergy]){
					vis[it.f][newEnergy] = true;
					q.push({it.f,newEnergy});
					ans[it.f][newEnergy] = ans[pos][energy]+1;
				}
			}
		}
	}
	cout << answ << '\n';
}
