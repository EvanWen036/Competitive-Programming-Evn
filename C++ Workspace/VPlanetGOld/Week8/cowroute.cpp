#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define sz(a) a.size()
typedef long long ll;
typedef pair<ll, int> pii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int A, B, N;
vector<pair<int,pii>> adj[1005];
pii mim[1005][1005];
pii dist[1005];
priority_queue<pair<pii,int>, vector<pair<pii,int>>, greater<pair<pii,int>>> pq;
vector<int> v(105);
int main(){
	freopen("cowroute.in", "r", stdin);
	freopen("cowroute.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> A >> B >> N;
	for(int i = 0; i <= 1000; i++){
		for(int j = 0;j <= 1000;j ++){
			mim[i][j] = {1e15, 1e9};
		}
	}
	for(int i=0;i<N;i++){
		int x, c;
		cin >> x >> c;
		for(int j=0;j<c;j++){
			cin >> v[j];
			v[j]--;
		}
		for(int j=0;j<c;j++){
			for(int k=j+1;k<c;k++){
				assert(v[j] <= 1000);
				if(mp(1LL * x,k-j) < mim[v[j]][v[k]]){
					mim[v[j]][v[k]] = {1LL * x,k-j};
					adj[v[j]].pb({v[k], {x, k-j}});
				}
			}
		}
	}
	
	A--; B--;
	for(int i = 0; i <= 1000; i++){
		dist[i] = {1e15,1e9};
	}
	pq.push({{0,0}, A});
	dist[A] = {0,0};
	while(!pq.empty()){
		auto c = pq.top(); pq.pop();
		if(c.f != dist[c.s])continue;
		for(auto it : adj[c.s]){
			pii newW = c.f;
			newW.f += it.s.f;
			newW.s += it.s.s;
			if(newW < dist[it.f]){
				dist[it.f] = newW;
				pq.push({{newW.f,newW.s}, it.f});
			}
		}
	}
	if(dist[B].f == 1e15){
		cout << -1 << " " << -1 << '\n';
		return 0;
	}
	
	cout << dist[B].f << " " << dist[B].s << '\n';

}
