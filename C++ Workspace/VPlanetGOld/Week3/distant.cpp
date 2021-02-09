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
int N, A, B;
int mat[35][35];
vector<pair<pii, int>> adj[35][35];
int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};
int dist[35][35];
int cnt[35][35];
int ans = 0;
int main(){
	freopen("distant.in", "r", stdin);
	freopen("distant.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> A >> B;
	for(int i = 0; i < N;i ++){
		string s;
		cin >> s;
		for(int j = 0;j < N;j ++){
			mat[i][j] = s[j];
		}
	}
	for(int i = 0;i < N;i ++){
		for(int j = 0;j <  N;j ++){
			for(int x = 0; x < 4; x++){
				int newR = i + dr[x];
				int newC = j + dc[x];
				if(newR < 0 || newR >= N || newC < 0 || newC >= N)continue;
				int weight = (mat[newR][newC] == mat[i][j] ? A:B);
				adj[i][j].pb({{newR,newC}, weight});
			}
		}
	}
	for(int i = 0; i < N;i ++){
		for(int j = 0;j < N;j ++){
			priority_queue<pair<int, pii>, vector<pair<int,pii>>, greater<pair<int,pii>>> pq;
			pq.push({0,{i,j}});
			memset(cnt, 0, sizeof(cnt));
			dist[i][j] = 0;
			while(!pq.empty()){
				pair<int, pii> curr = pq.top(); pq.pop();
				pii node = curr.s;
				if(curr.f != dist[node.f][node.s])continue;
				//cout << curr.f << " " << node.f << " " << node.s << '\n';
				for(auto it : adj[node.f][node.s]){
					if(it == *(adj[node.f][node.s].begin()))cnt[node.f][node.s]++;
					if(dist[node.f][node.s] + it.s < dist[it.f.f][it.f.s]){
						dist[it.f.f][it.f.s] = dist[node.f][node.s]+it.s;
						pq.push({dist[it.f.f][it.f.s], {it.f.f, it.f.s}});
					}
				}
			}
			for(int r = 0;r < N;r ++){
				for(int c =0;c < N;c ++){
					//cout << cnt[r][c] << " ";
					ans = max(ans, dist[r][c]);
					dist[r][c] = 2e9;
				}
				//cout << '\n';
			}
		}
	}
	cout << ans << '\n';

}
