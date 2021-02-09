#include<bits/stdc++.h>
#define pii pair<ll, int>
#define ll long long
#define f first
#define s second
using namespace std;
ll dijkstra[100005];
ll cnt[100005];
ll mi[100005];
ll mx[100005];
vector<pair<int, int>> adj[100005];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		ll c;
		cin >> a >> b >> c;
		a--; b--;
		adj[a].push_back({b,c});
	}
	for(int i = 1; i < n;i ++){
		dijkstra[i] = 100000000000000;
		mi[i] = 100000000000000;
	}
	dijkstra[0] = 0;
	cnt[0] = 1;
	ll MOD = 1e9+7;
	priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
	pq.push({0,0});
	while(!pq.empty()){
		pii curr = pq.top(); pq.pop();
		ll weight = curr.f;
		int node = curr.s;
		if(weight != dijkstra[node])continue;
		assert(weight == dijkstra[node]);
		//cout << node << " " << weight << "\n";
		for(auto it : adj[node]){
			ll newWeight = weight + it.s;
			if(newWeight < dijkstra[it.f]){
				dijkstra[it.f] = newWeight;
				pq.push({newWeight,it.f});
				cnt[it.f] = cnt[node];
				mi[it.f] = mi[node]+1;
				mx[it.f] = mx[node]+1;
			}
			else if(newWeight == dijkstra[it.f]){
				cnt[it.f] = (cnt[it.f] + cnt[node])%MOD;
				mi[it.f] = min(mi[node]+1, mi[it.f]);
				mx[it.f] = max(mx[it.f], mx[node]+1);
			}
		}
	}
	cout << dijkstra[n-1] << " " << cnt[n-1] << " " << mi[n-1] << " " << mx[n-1];
}